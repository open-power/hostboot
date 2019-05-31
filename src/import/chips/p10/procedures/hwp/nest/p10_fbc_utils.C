/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_utils.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p10_fbc_utils.C
/// @brief Fabric library functions/constants (FAPI2)
///
/// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: SBE,HB,FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_scomt.H>
#include <p10_scom_c.H>
#include <p10_scom_proc.H>
#include <p10_fbc_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

namespace topo
{
namespace
{
// Several fabric units have a set of SCOM registers which hold the topology id
// table. There is a set of 4x40b registers where each register holds 8x4b
// entries along with 8x1b valid bits (1 per entry).
const size_t NUM_TOPO_SCOMS = 4;
const size_t NUM_TOPO_ENTRIES_PER_SCOM = 8;

// The register layout is common but the SCOM headers to access them are not.
// To simplify programming, shove function pointers to each SET_* field function
// into an array.
using TopoSetValidScom = fapi2::buffer<uint64_t>& (*)(const uint64_t, fapi2::buffer<uint64_t>&);
const TopoSetValidScom SET_TOPO_VALID_SCOM[] =
{
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID
};

using TopoSetEntryScom = fapi2::buffer<uint64_t>& (*)(const uint64_t, fapi2::buffer<uint64_t>&);
const TopoSetEntryScom SET_TOPO_ENTRY_SCOM[] =
{
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6,
    scomt::c::SET_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7
};

enum topo_scom_fld
{
    ENTRY,
    VALID
};

///
/// @brief Set the valid bit or entry field corresponding to a topology table
///        id according to the 40b common FBC unit topology table SCOM format.
///        Note: The layout of these registers is identical across all units,
///              but the generated SCOM headers are unique. This function provides
///              a common wrapper to avoid code duplication and still use the
///              scomt checking facilities.
/// @param[in]  i_target        Reference to processor chip target
/// @param[in]  fld             Field to modify: ENTRY or VALID
/// @param[in]  n               Topology id table entry index, each SCOM register
///                             stores 8 entries and their valid bits.
///                             assert(n >= 0 && n < 8)
/// @param[in]  value           Value to set field to
/// @param[out] regval          Data (representing register layout) to modify
/// @return void
///
void set_topo_scom(fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> chip,
                   enum topo_scom_fld fld, size_t n, uint64_t value,
                   fapi2::buffer<uint64_t>& regval)
{
#ifdef SCOM_CHECKING
    // Save the scomt internal state (ie. maintain scomt PREP_* state)
    auto last_scom = scomt::last_scom;
#endif
    // PREP so we can make use of the nice scomt checking
    scomt::c::PREP_L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD(chip);

    if (fld == ENTRY)
    {
        SET_TOPO_ENTRY_SCOM[n](value, regval);
    }
    else
    {
        SET_TOPO_VALID_SCOM[n](value, regval);
    }

#ifdef SCOM_CHECKING
    // Restore the scomt internal state
    scomt::last_scom = last_scom;
#endif
}
};

fapi2::ReturnCode get_topology_idx(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_fbc_utils_addr_mode& i_addr_mode,
    uint8_t& o_topology_idx)
{
    FAPI_DBG("start");

    fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_Type l_fabric_topology_id = 0;
    fapi2::ATTR_PROC_FABRIC_TOPOLOGY_MODE_Type l_fabric_topology_mode = 0;

    //Determine which Topology ID to use (EFF vs HB)
    // EFF_TOPOLOGY_ID - This would be used to provide calling HWPs with the
    //                   range of address space actually assigned for this
    //                   socket (effective topology ID of i_target)
    //
    // HB_BOOT_ID - This is intended to provide calling HWPs with an indication
    //              of which address range HB is actually going to boot into in
    //              the drawer containing this socket (group ID of i_target, chip ID=0)
    if(i_addr_mode == HB_BOOT_ID)
    {
        uint8_t l_fabric_topology_id_mask =
            (l_fabric_topology_mode == fapi2::ENUM_ATTR_PROC_FABRIC_TOPOLOGY_MODE_MODE0)
            ? 0x0E : 0x0C;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID, i_target,
                               l_fabric_topology_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_TOPOLOGY_ID)");
        l_fabric_topology_id &= l_fabric_topology_id_mask;//assume Chip field 0;
    }
    else//EFF_TOPOLOGY_ID
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID, i_target,
                               l_fabric_topology_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID)");
    }

    // map topology id (format: GGG_C) to topology index (format: GGG_0C)
    if(l_fabric_topology_mode == fapi2::ENUM_ATTR_PROC_FABRIC_TOPOLOGY_MODE_MODE0)
    {
        l_fabric_topology_id = (((l_fabric_topology_id & 0x0E) << 1)
                                | (l_fabric_topology_id & 0x01));
    }

    o_topology_idx = static_cast<uint8_t>(l_fabric_topology_id);

fapi_try_exit:
    FAPI_DBG("exit");
    return fapi2::current_err;
}

fapi2::ReturnCode init_topology_id_table(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("start");

    uint8_t l_topo_idx;
    fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE_Type l_topo_tbl;
    fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_Type l_topo_id;

    FAPI_TRY(get_topology_idx(i_target, EFF_TOPOLOGY_ID, l_topo_idx));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID, i_target, l_topo_id));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE, i_target,
                           l_topo_tbl));

    l_topo_tbl[l_topo_idx] = l_topo_id;

    FAPI_DBG("Set topology id table[%zu]=%02x", l_topo_idx, l_topo_id);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE, i_target,
                           l_topo_tbl));

fapi_try_exit:
    FAPI_DBG("exit");
    return fapi2::current_err;
}

fapi2::ReturnCode init_topology_id_table(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets)
{
    FAPI_DBG("start");

    for (const auto& chip : i_targets)
    {
        FAPI_TRY(init_topology_id_table(chip));
    }

fapi_try_exit:
    FAPI_DBG("exit");
    return fapi2::current_err;
}

fapi2::ReturnCode get_topology_table_scoms(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    std::vector<uint64_t>& o_topology_id_table_scoms)
{
    FAPI_DBG("start");

    size_t l_topo_tbl_len = 0;
    fapi2::buffer<uint64_t> regval;
    fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE_Type l_topo_tbl;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE, i_target,
                           l_topo_tbl));

    l_topo_tbl_len = sizeof(l_topo_tbl) / sizeof(l_topo_tbl[0]);

    if (!o_topology_id_table_scoms.empty())
    {
        o_topology_id_table_scoms.clear();
    }

    o_topology_id_table_scoms.reserve(l_topo_tbl_len);

    for (auto i = 0u; i < NUM_TOPO_SCOMS; ++i)
    {
        regval.flush<0>();

        for (auto j = 0u; j < NUM_TOPO_ENTRIES_PER_SCOM; ++j)
        {
            auto idx = i * NUM_TOPO_ENTRIES_PER_SCOM + j;
            auto val = l_topo_tbl[idx];

            if (val == fapi2::ENUM_ATTR_PROC_FABRIC_TOPOLOGY_ID_TABLE_INVALID)
            {
                FAPI_DBG("Skipped TOPOLOGY_ID_TABLE[%02zu]=INVALID regval=%016llx",
                         idx, regval);
                continue;
            }

            set_topo_scom(i_target, VALID, j, 1, regval);
            set_topo_scom(i_target, ENTRY, j, val, regval);
            FAPI_DBG("Set     TOPOLOGY_ID_TABLE[%02zu]=%02x      regval=%016llx",
                     idx, val, regval);
        }

        o_topology_id_table_scoms.emplace_back(regval);
    }

fapi_try_exit:
    FAPI_DBG("exit");
    return fapi2::current_err;
}
}; // namespace topo

#ifndef __PPE_QME
////////////////////////////////////////////////////////
// p10_fbc_utils_get_fbc_state
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_utils_get_fbc_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    bool& o_is_initialized,
    bool& o_is_running)
{
    using namespace scomt::proc;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_fbc_mode_data;
    fapi2::buffer<uint64_t> l_pmisc_mode_data;

    // read PB ES3 Mode Register state
    FAPI_TRY(GET_PB_COM_SCOM_ES3_STATION_MODE(i_target, l_fbc_mode_data));

    // fabric is initialized if PB_INITIALIZED bit is one/set
    o_is_initialized = GET_PB_COM_SCOM_ES3_STATION_MODE_ES3_PBIXXX_INIT(l_fbc_mode_data);

    // read ADU PMisc Mode Register state
    FAPI_TRY(GET_TP_TPBR_AD_SND_MODE_REG(i_target, l_pmisc_mode_data));

    // fabric is running if FBC_STOP bit is zero/clear
    o_is_running = !GET_TP_TPBR_AD_SND_MODE_REG_PB_STOP(l_pmisc_mode_data);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_utils_override_fbc_stop
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_utils_override_fbc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::proc;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_pmisc_mode_data;

    // read ADU PMisc Mode Register state
    FAPI_TRY(GET_TP_TPBR_AD_SND_MODE_REG(i_target, l_pmisc_mode_data));

    // set bit to disable checkstop forwarding and write back
    SET_TP_TPBR_AD_SND_MODE_REG_DISABLE_CHECKSTOP(l_pmisc_mode_data);
    FAPI_TRY(PUT_TP_TPBR_AD_SND_MODE_REG(i_target, l_pmisc_mode_data));

    // set bit to manually clear stop control and write back
    SET_TP_TPBR_AD_SND_MODE_REG_MANUAL_CLR_PB_STOP(l_pmisc_mode_data);
    FAPI_TRY(PUT_TP_TPBR_AD_SND_MODE_REG(i_target, l_pmisc_mode_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_utils_get_chip_base_address
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_utils_get_chip_base_address(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_fbc_utils_addr_mode i_addr_mode,
    uint64_t& o_base_address_nm0,
    uint64_t& o_base_address_nm1,
    uint64_t& o_base_address_m,
    uint64_t& o_base_address_mmio)
{
    uint8_t l_fabric_topology_idx = 0;
    fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY_Type l_fabric_mirror_policy = 0;
    fapi2::buffer<uint64_t> l_base_address;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_DBG("Start");

    FAPI_TRY(topo::get_topology_idx(i_target, i_addr_mode, l_fabric_topology_idx));

    l_base_address.insertFromRight < FABRIC_ADDR_TOPO_ID_INDEX_START_BIT,
                                   (FABRIC_ADDR_TOPO_ID_INDEX_END_BIT
                                    - FABRIC_ADDR_TOPO_ID_INDEX_START_BIT
                                    + 1 ) > (l_fabric_topology_idx);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY,
                           FAPI_SYSTEM,
                           l_fabric_mirror_policy),
             "Error from FAPI_ATTR_GET (ATTR_MEM_MIRROR_PLACEMENT_POLICY)");

    if(l_fabric_mirror_policy
       == fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)
    {
        //normal => nm = 0b00/0b01 ; m = 0b10 ; mmio = 0b11
        o_base_address_nm0 = l_base_address();
        l_base_address.setBit<FABRIC_ADDR_MSEL_END_BIT>();
        o_base_address_nm1 = l_base_address();
        l_base_address.setBit<FABRIC_ADDR_MSEL_START_BIT>();
        l_base_address.clearBit<FABRIC_ADDR_MSEL_END_BIT>();
        o_base_address_m = l_base_address();
        l_base_address.setBit<FABRIC_ADDR_MSEL_END_BIT>();
        o_base_address_mmio = l_base_address();
    }
    else
    {
        //mirrored start => m = 0b00 ; nm = 0b01/0b10 ; mmi0 = 0b11
        o_base_address_m = l_base_address();
        l_base_address.setBit<FABRIC_ADDR_MSEL_END_BIT>();
        o_base_address_nm0 = l_base_address();
        l_base_address.clearBit<FABRIC_ADDR_MSEL_END_BIT>();
        l_base_address.setBit<FABRIC_ADDR_MSEL_START_BIT>();
        o_base_address_nm1 = l_base_address();
        l_base_address.setBit<FABRIC_ADDR_MSEL_END_BIT>();
        o_base_address_mmio = l_base_address();
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_utils_set_racetrack_regs
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_utils_set_racetrack_regs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_scom_addr,
    const uint64_t i_scom_data)
{
    FAPI_DBG("Start");

    for(uint8_t station = 0; station < FABRIC_NUM_STATIONS; station++)
    {
        FAPI_TRY(putScom(i_target, i_scom_addr + (station << 6), i_scom_data),
                 "Error from writing to racetrack scom register (station %d)", station);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
#endif // !__PPE_QME
