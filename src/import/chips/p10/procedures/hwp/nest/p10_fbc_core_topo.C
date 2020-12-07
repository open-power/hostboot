/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_core_topo.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
//--------------------------------------------------------------------------
//
/// @file p10_fbc_core_topo.C
/// @brief Create SCOM restore HOMER entries for the EQ fabric topology tables
///
// *HWP HW Maintainer : Greg Still (stillgs@us.ibm.com)
// *HWP FW Maintainer : TBD
// *HWP Consumed by   : HB
//--------------------------------------------------------------------------
// EKB-Mirror-To: hostboot
// EKB-Mirror-To: hw/ppe

//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p10_fbc_core_topo.H>
#include <multicast_group_defs.H>
#include <p10_fbc_utils.H>
#include <p10_scom_c.H>

const size_t NUM_TOPO_SCOMS = 4;
const size_t NUM_TOPO_ENTRIES_PER_SCOM = 8;
const size_t NUM_SECTIONS = 2;
const size_t NUM_UNITS = 3;

typedef struct
{
    char                            name[4];
    stopImageSection::ScomSection_t section;
    uint32_t                        addresses[NUM_TOPO_SCOMS];
} topoStruct_t;

extern "C" {

//--------------------------------------------------------------------------
//  HWP entry point
//--------------------------------------------------------------------------
    fapi2::ReturnCode
    p10_fbc_core_topo(
        const fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST > & i_target,
        const std::vector<uint64_t>& i_topo_scoms,
        void* i_pImage,  // This needs to be point to the appropriate chip,
        const stopImageSection::ScomSection_t i_section,
        const rt_topo::rt_mode_t i_mode)
    {
        using namespace scomt::c;
        using namespace stopImageSection;

#ifndef __PPE__
        StopReturnCode_t sa_rc = STOP_SAVE_SUCCESS;
#endif

        FAPI_INF(">> p10_fbc_core_topo");

        topoStruct_t  units[] =
        {
            {
                "L2 ",
                PROC_STOP_SECTION_CORE,
                {
                    L2_L2MISC_L2CERRS_TOPOTABLE0,
                    L2_L2MISC_L2CERRS_TOPOTABLE1,
                    L2_L2MISC_L2CERRS_TOPOTABLE2,
                    L2_L2MISC_L2CERRS_TOPOTABLE3
                },
            },
            {
                "NCU",
                PROC_STOP_SECTION_CACHE,
                {
                    NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG0,
                    NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1,
                    NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2,
                    NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3

                },
            },
            {
                "L3 ",
                PROC_STOP_SECTION_CACHE,
                {
                    L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD,
                    L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD,
                    L3_MISC_L3CERRS_TOPOLOGY_TBL2_SCOM_RD,
                    L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD,
                }
            }
        };

        FAPI_DBG("Size of topo_scom vector: %u", i_topo_scoms.size());
        FAPI_ASSERT(i_topo_scoms.size() == NUM_TOPO_SCOMS,
                    fapi2::FBC_CORE_TOPO_SIZE_ERROR()
                    .set_CORE_TARGET(i_target)
                    .set_EXP_VEC_SIZE(NUM_TOPO_SCOMS)
                    .set_ACT_VEC_SIZE(i_topo_scoms.size()),
                    "Topology SCOM vector size check fail.  Expected: %u; Actual: %u",
                    NUM_TOPO_SCOMS, i_topo_scoms.size() );

        for (size_t u = 0; u < NUM_UNITS; u++)
        {
            // Process only if the sections match
            if (i_section != units[u].section)
            {
                continue;
            }

            for (size_t i = 0; i < NUM_TOPO_SCOMS; i++)
            {
                if (i_mode == rt_topo::RT_TOPO_MODE_HW)
                {
                    FAPI_INF("Putting %s Topology register 0x%08X with data 0x%016llX to hardware",
                             units[u].name, units[u].addresses[i], i_topo_scoms[i]);

                    FAPI_TRY( putScom( i_target, units[u].addresses[i], i_topo_scoms[i] ) );
                }

#ifndef __PPE__

                if (i_mode == rt_topo::RT_TOPO_MODE_HOMER)
                {

                    FAPI_ASSERT(i_target.getType() & fapi2::TARGET_TYPE_CORE,
                                fapi2::FBC_CORE_TOPO_HOMER_TARGET_ERROR()
                                .set_CORE_TARGET(i_target),
                                "Target type must be CORE for HOMER actions");

                    fapi2::ATTR_CHIP_UNIT_POS_Type l_coreId;
                    FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                   i_target,
                                   l_coreId );
                    FAPI_INF("  Processing Coreid %u", l_coreId);

                    uint32_t eq = l_coreId / 4;
                    uint32_t core_region = 8 >> (l_coreId % 4);
                    uint32_t address = units[u].addresses[i];
                    address += (0x01000000 * eq);
                    address |= (core_region << 12);
                    FAPI_DBG("EQ = %d; core = %d; core_region = %X", eq, l_coreId, core_region);

                    FAPI_INF("Putting %s Topology register 0x%08X with data 0x%016llX to HOMER",
                             units[u].name, address, i_topo_scoms[i]);
                    sa_rc = proc_stop_save_scom( i_pImage,
                                                 address,
                                                 i_topo_scoms[i],
                                                 PROC_STOP_SCOM_REPLACE,
                                                 units[u].section);

                    FAPI_ASSERT(!sa_rc,
                                fapi2::FBC_CORE_TOPO_HOMER_SCOM_ERROR()
                                .set_CORE_TARGET(i_target)
                                .set_ADDRESS(address)
                                .set_DATA(i_topo_scoms[i])
                                .set_OPERATION(PROC_STOP_SCOM_REPLACE)
                                .set_SECTION(units[u].section)
                                .set_API_RC(sa_rc),
                                "%s Topology update for PBTXTR%d failed with RC %d", units[u].name, i, sa_rc);
                }

#endif
            }
        }

        // mark HWP exit
    fapi_try_exit:
        FAPI_INF("<< p10_fbc_core_topo");
        return fapi2::current_err;
    }

} // extern "C"
