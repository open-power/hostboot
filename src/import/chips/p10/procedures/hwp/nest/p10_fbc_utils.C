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
#include <p10_scom_proc.H>
#include <p10_fbc_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

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

fapi2::ReturnCode p10_fbc_utils_get_chip_base_address(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_fbc_utils_addr_mode i_addr_mode,
    uint64_t& o_base_address_nm0,
    uint64_t& o_base_address_nm1,
    uint64_t& o_base_address_m,
    uint64_t& o_base_address_mmio)
{
    fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_Type l_fabric_topology_id = 0;
    uint8_t l_fabric_topology_id_mask = 0x0;
    fapi2::ATTR_PROC_FABRIC_TOPOLOGY_MODE_Type l_fabric_topology_mode;
    fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY_Type l_fabric_mirror_policy = 0;
    fapi2::buffer<uint64_t> l_base_address;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_DBG("Start");

    //Get Topology Mode and Mirror Policy
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_MODE,
                           FAPI_SYSTEM,
                           l_fabric_topology_mode),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_TOPOLOGY_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY,
                           FAPI_SYSTEM,
                           l_fabric_mirror_policy),
             "Error from FAPI_ATTR_GET (ATTR_MEM_MIRROR_PLACEMENT_POLICY)");

    //Determine which Topology ID to use (EFF vs HB)
    if(i_addr_mode == HB_BOOT_ID)
    {
        l_fabric_topology_id_mask =
            (l_fabric_topology_mode == fapi2::ENUM_ATTR_PROC_FABRIC_TOPOLOGY_MODE_MODE0)
            ? 0x0E : 0x0C;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID,
                               i_target,
                               l_fabric_topology_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_TOPOLOGY_ID)");
        l_fabric_topology_id &= l_fabric_topology_id_mask;//assume Chip field 0;
    }
    else//EFF_TOPOLOGY_ID
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID,
                               i_target,
                               l_fabric_topology_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID)");
    }

    //ensure that topology ID is in GGG_CC format
    //avoids the instance where TOP_MODE=0 with chip ID 1 which
    //then becomes GGG_10 (needs to be GGG_01)
    if(l_fabric_topology_mode == fapi2::ENUM_ATTR_PROC_FABRIC_TOPOLOGY_MODE_MODE0)
    {
        l_fabric_topology_id = (((l_fabric_topology_id & 0x0E) << 1) //group ID GGG
                                | (l_fabric_topology_id & 0x01));     //chip ID C
    }


    l_base_address.insertFromRight < FABRIC_ADDR_TOPO_ID_INDEX_START_BIT,
                                   (FABRIC_ADDR_TOPO_ID_INDEX_END_BIT
                                    - FABRIC_ADDR_TOPO_ID_INDEX_START_BIT
                                    + 1 ) > (l_fabric_topology_id);

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
