/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_phy_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file ody_phy_utils.C
/// @brief Odyssey PHY utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <lib/phy/ody_phy_utils.H>
#include <lib/phy/ody_ddrphy_phyinit_config.H>
#include <ody_scom_mp_apbonly0.H>
#include <ody_scom_mp_drtub0.H>
#include <generic/memory/lib/utils/poll.H>
#include <lib/phy/ody_draminit_utils.H>
#include <mss_odyssey_attribute_setters.H>
#include <generic/memory/lib/utils/fapi_try_lambda.H>

namespace mss
{
namespace ody
{
namespace phy
{

///
/// @brief Configure the PHY to allow/disallow register accesses via scom
/// @param[in] i_target the target on which to operate
/// @param[in] i_state the state to set the PHY to - either mss::states::ON_N (scom access) or mss::states::OFF_N (training access)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode configure_phy_scom_access(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const mss::states i_state)
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL, l_data));

    l_data.writeBit<scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL_MICROCONTMUXSEL>(i_state);
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_APBONLY0_MICROCONTMUXSEL, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Loads two contiguous 8-bit fields into the DMEM register format
/// @param[in] i_even_field field at the even byte offset
/// @param[in] i_odd_field field at the odd byte offset
/// @param[in,out] io_data the register data
///
void load_dmem_8bit_fields( const uint8_t i_even_field, const uint8_t i_odd_field, fapi2::buffer<uint64_t>& io_data)
{
    constexpr uint64_t ODD_DATA = 48;
    constexpr uint64_t EVEN_DATA = 56;
    io_data.insertFromRight<ODD_DATA, BITS_PER_BYTE>(i_odd_field)
    .insertFromRight<EVEN_DATA, BITS_PER_BYTE>(i_even_field);
}

///
/// @brief Reads two contiguous 8-bit fields from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_even_field field at the even byte offset
/// @param[out] o_odd_field field at the odd byte offset
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint32_t i_addr,
                                   uint8_t& o_even_field, uint8_t& o_odd_field)
{
    constexpr uint64_t ODD_DATA = 48;
    constexpr uint64_t EVEN_DATA = 56;
    o_even_field = 0;
    o_odd_field = 0;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(getScom_synopsys_addr_wrapper(i_target, i_addr, l_data));

    l_data.extractToRight<ODD_DATA, BITS_PER_BYTE>(o_odd_field)
    .extractToRight<EVEN_DATA, BITS_PER_BYTE>(o_even_field);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads a 16-bit field from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_field the 16-bit field
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint32_t i_addr,
                                   uint16_t& o_field)
{
    constexpr uint64_t SYNOPSYS_DATA = 48;
    constexpr uint64_t DATA_16B_LEN = 16;
    o_field = 0;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(getScom_synopsys_addr_wrapper(i_target, i_addr, l_data));

    l_data.extractToRight<SYNOPSYS_DATA, DATA_16B_LEN>(o_field);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads a 32-bit field from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_field the 32-bit field, read in from two registers
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint32_t i_addr,
                                   uint32_t& o_field)
{
    constexpr uint64_t SYNOPSYS_DATA = 48;
    constexpr uint64_t DATA_16B_LEN = 16;
    o_field = 0;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(getScom_synopsys_addr_wrapper(i_target, i_addr, l_data));
    l_data.extractToRight<SYNOPSYS_DATA, DATA_16B_LEN>(o_field);
    o_field <<= DATA_16B_LEN;

    FAPI_TRY(getScom_synopsys_addr_wrapper(i_target, i_addr + 1, l_data));
    l_data.extractToRight<SYNOPSYS_DATA, DATA_16B_LEN>(o_field);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Reads a 64-bit field from the DMEM
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the starting address to read from
/// @param[out] o_field the 64-bit field, read in from four registers
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode read_dmem_field( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target, const uint32_t i_addr,
                                   uint64_t& o_field)
{
    constexpr uint64_t SYNOPSYS_DATA = 48;
    constexpr uint64_t DATA_16B_LEN = 16;
    o_field = 0;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(getScom_synopsys_addr_wrapper(i_target, i_addr, l_data));
    l_data.extractToRight<SYNOPSYS_DATA, DATA_16B_LEN>(o_field);
    o_field <<= DATA_16B_LEN;

    FAPI_TRY(getScom_synopsys_addr_wrapper(i_target, i_addr + 1, l_data));
    l_data.extractToRight<SYNOPSYS_DATA, DATA_16B_LEN>(o_field);
    o_field <<= DATA_16B_LEN;

    FAPI_TRY(getScom_synopsys_addr_wrapper(i_target, i_addr + 2, l_data));
    l_data.extractToRight<SYNOPSYS_DATA, DATA_16B_LEN>(o_field);
    o_field <<= DATA_16B_LEN;

    FAPI_TRY(getScom_synopsys_addr_wrapper(i_target, i_addr + 3, l_data));
    l_data.extractToRight<SYNOPSYS_DATA, DATA_16B_LEN>(o_field);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief A helper to check if loads to two DMEM fields are needed
/// @param[in] i_attr the attribute value dictating if this is the first load or not
/// @param[in] i_data_even even address data
/// @param[in] i_data_odd odd address data
/// @return true if the data should be loaded, otherwise false
/// @note the DMEM should be guaranteed to be initialized to zeroes via a reset function
/// As such, we can gain performance benefits by only loading non-zero data on the first load
/// the data for these addresses will be loaded if:
/// 1. this is not the first time the DMEM have been loaded this boot
/// 2. this is the first DMEM load and the data for one of the addresses is non-zero
///
bool phy_mem_load_helper( const uint8_t i_attr,
                          const uint64_t i_data_even,
                          const uint64_t i_data_odd)
{
    // If this is not first load, then always load the data
    if(i_attr == fapi2::ENUM_ATTR_ODY_DMEM_FIRST_LOAD_NO)
    {
        return true;
    }

    // If at least one register has non-zero data, then load the data
    if(i_data_even != 0 || i_data_odd != 0)
    {
        return true;
    }

    // Otherwise, this is the first load and both pieces of data are 0, no load needed
    return false;
}

///
/// @brief A helper to load two DMEM fields only if needed
/// @param[in] i_target the target on which to operate
/// @param[in] i_attr the attribute value dictating if this is the first load or not
/// @param[in] i_addr the starting address to write to - must be the even address
/// @param[in] i_data_even even address data
/// @param[in] i_data_odd odd address data
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note the DMEM should be guaranteed to be initialized to zeroes
/// As such, we can gain performance benefits by only loading non-zero data on the first load
/// the data for these addresses will be loaded if:
/// 1. this is not the first time the DMEM have been loaded this boot
/// 2. this is the first DMEM load and the data for one of the addresses is non-zero
///
fapi2::ReturnCode phy_mem_load_helper( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                       const uint8_t i_attr,
                                       const uint64_t i_addr,
                                       const uint64_t i_data_even,
                                       const uint64_t i_data_odd)
{
    // If no load is needed, then just exit out, no need for the data load
    if(phy_mem_load_helper( i_attr, i_data_even, i_data_odd) == false)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // DMEM addresses are always loaded in pairs
    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, i_addr, i_data_even));
    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, i_addr + 1, i_data_odd));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Resets the DMEM values to all 0's
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///

fapi2::ReturnCode reset_dmem( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    fapi2::buffer<uint64_t> l_data;

    // Stalls the ARC processor to ensure it's not running
    FAPI_TRY(stall_arc_processor(i_target));

    // Toggles the start DCCM clear bit. The bit requires a 0->1 transition, so we'll do X->0->1 to be safe
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_DRTUB0_STARTDCCMCLEAR, l_data));
    l_data.setBit<scomt::mp::DWC_DDRPHYA_DRTUB0_STARTDCCMCLEAR_STARTDCCMCLEAR>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_DRTUB0_STARTDCCMCLEAR, l_data));

    // Polls for completion, where the in progress bit is a 0
    {
        mss::poll_parameters l_poll_params(50 * DELAY_1US, // Should take ~100k DFI clocks ~50k memclocks -> 50 US
                                           20000,          // Initial sim delay
                                           mss::DELAY_1US, // 1US per poll. Seems fine
                                           20000,          // Sim delay taken from draminit message block polling
                                           100);           // 100 polls. Shouldn't take this long

        // Poll for getting 0 at for the DCCM clear running in progress bit.
        const bool l_poll_return = mss::poll(i_target, l_poll_params, [&i_target]()->bool
        {
            fapi2::buffer<uint64_t> l_data;
            FAPI_TRY_LAMBDA(fapi2::getScom(i_target, scomt::mp::DWC_DDRPHYA_DRTUB0_DCCMCLEARRUNNING, l_data));
            return (!l_data.getBit<scomt::mp::DWC_DDRPHYA_DRTUB0_DCCMCLEARRUNNING_DCCMCLEARRUNNING>());

        fapi_try_exit_lambda:
            FAPI_ERR("mss::poll() hit an error in mss::getScom");
            return false;
        });

        // following FAPI_TRY to preserve the scom failure in lambda.
        FAPI_TRY(fapi2::current_err);
        FAPI_ASSERT(l_poll_return,
                    fapi2::ODY_DMEM_RESET_TIMEOUT().
                    set_PORT_TARGET(i_target),
                    TARGTIDFORMAT " poll for getting mail timed out during DCCM clear", TARGTID);
    }

    // After polling, toggle back to a 0. this is required per simulation
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::mp::DWC_DDRPHYA_DRTUB0_STARTDCCMCLEAR, l_data));

    // After the reset has completed, then toggle the DMEM attribute to note that this is a first run (should be clean now)
    FAPI_TRY(mss::attr::set_ody_dmem_first_load(i_target, fapi2::ENUM_ATTR_ODY_DMEM_FIRST_LOAD_YES));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief fapi2::putScom wrapper to help decrease code size on the SBE using the Synopsys address perspective
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the address on which to operate from the synopsys perspective
/// @param[in] i_data the data to write to the chip
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode putScom_synopsys_addr_wrapper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint32_t i_addr,
        const fapi2::buffer<uint64_t>& i_data)
{
    return fapi2::putScom(i_target, convert_synopsys_to_ibm_reg_addr(i_addr), i_data);
}

///
/// @brief fapi2::getScom wrapper to help decrease code size on the SBE using the Synopsys address perspective
/// @param[in] i_target the target on which to operate
/// @param[in] i_addr the address on which to operate from the synopsys perspective
/// @param[out] o_data the data read from the chip
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode getScom_synopsys_addr_wrapper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint32_t i_addr,
        fapi2::buffer<uint64_t>& o_data)
{
    return fapi2::getScom(i_target, convert_synopsys_to_ibm_reg_addr(i_addr), o_data);
}

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
        uint8_t& o_disables_mc)
{
    const fapi2::buffer<uint8_t> l_disables_phy_buf(i_disables_phy);
    fapi2::buffer<uint8_t> l_disables_mc_buf;

    FAPI_ASSERT(i_phy_rank < MAX_RANK_PER_PHY,
                fapi2::ODY_OUT_OF_BOUNDS_RANK_PASSED_TO_SWIZZLE().
                set_PORT_TARGET(i_target).
                set_RANK(i_phy_rank).
                set_MAX_RANK(MAX_RANK_PER_PHY - 1),
                TARGTIDFORMAT " bad rank (%d) passed to swizzle function (must be less than %d)",
                TARGTID, i_phy_rank, MAX_RANK_PER_PHY);

    FAPI_ASSERT(i_dbyte < MAX_BYTES_PER_PORT,
                fapi2::ODY_OUT_OF_BOUNDS_DBYTE_PASSED_TO_SWIZZLE().
                set_PORT_TARGET(i_target).
                set_DBYTE(i_dbyte).
                set_MAX_DBYTE(MAX_BYTES_PER_PORT - 1),
                TARGTIDFORMAT " bad dbyte (%d) passed to swizzle function (must be less than %d)",
                TARGTID, i_dbyte, MAX_BYTES_PER_PORT);

    for (uint8_t l_mc_dq = 0; l_mc_dq < BITS_PER_BYTE; l_mc_dq++)
    {
        fapi2::buffer<uint64_t> l_data;
        uint8_t l_phy_dq = 0;

        // Read swizzle regs for this rank/dbyte/dq
        FAPI_TRY(fapi2::getScom(i_target, PER_BIT_SWIZZLE_REGS[i_phy_rank][i_dbyte][l_mc_dq], l_data));

        // Extract swizzle index from reg data (all of these regs use the three bits)
        l_data.extractToRight<scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ0LNSELTG0_DQ0LNSELTG0,
                              scomt::mp::DWC_DDRPHYA_DBYTE0_BASE0_DQ0LNSELTG0_DQ0LNSELTG0_LEN>(l_phy_dq);

        // Copy value from i_disables_phy into corresponding slot in o_disables_mc
        // note the subtract from 7 in here is to change from right-to-left index order to left-to-right
        FAPI_TRY(l_disables_mc_buf.writeBit(l_disables_phy_buf.getBit(7 - l_mc_dq), l_phy_dq));
    }

    o_disables_mc = l_disables_mc_buf;
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace phy
} // namespace ody
} // namespace mss
