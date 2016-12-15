/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/xlate.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file xlate.C
/// @brief Subroutines to manipulate the memory controller translation registers
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <lib/mss_attribute_accessors.H>

#include <lib/mc/mc.H>
#include <lib/mc/xlate.H>
#include <lib/utils/scom.H>
#include <lib/utils/find.H>
#include <lib/dimm/kind.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{
namespace mc
{

/// A little vector of translators. We have one of these for each DIMM we support
static const std::vector<xlate_setup> xlate_map =
{
    // 1R 4Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM16,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_8GB),
        xlate_dimm_1R1T4Gbx4
    },

    // 1R 8Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_16GB),
        xlate_dimm_1R1T8Gbx4
    },

    // 1R 16Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_32GB),
        xlate_dimm_1R1T16Gbx4
    },

    // 2R 4Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM16,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_16GB),
        xlate_dimm_2R2T4Gbx4
    },

    // 2R 8Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_32GB),
        xlate_dimm_2R2T8Gbx4
    },

    // 2R 16Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_64GB),
        xlate_dimm_2R2T16Gbx4
    },

    // 4R 4Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM16,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_32GB),
        xlate_dimm_4R4T4Gbx4
    },

    // 4R 8Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_64GB),
        xlate_dimm_4R4T8Gbx4
    },

    // 4R 16Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_128GB),
        xlate_dimm_4R4T16Gbx4
    },



    //
    // 3DS RDIMM
    //

    // 1R 2H 3DS 4Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM16,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_16GB),
        xlate_dimm_1R2T4Gbx4
    },

    // 1R 2H 3DS 8Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_32GB),
        xlate_dimm_1R2T8Gbx4
    },

    // 1R 2H 3DS 16Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_64GB),
        xlate_dimm_1R2T16Gbx4
    },

    // 1R 4H 3DS 4Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM16,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_32GB),
        xlate_dimm_1R4T4Gbx4
    },

    // 1R 4H 3DS 8Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_64GB),
        xlate_dimm_1R4T8Gbx4
    },

    // 1R 4H 3DS 16Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_128GB),
        xlate_dimm_1R4T16Gbx4
    },

    // 1R 8H 3DS 4Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_8R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM16,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_64GB),
        xlate_dimm_1R8T4Gbx4
    },

    // 1R 8H 3DS 8Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_8R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_128GB),
        xlate_dimm_1R8T8Gbx4
    },

    // 1R 8H 3DS 16Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_1R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_8R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_256GB),
        xlate_dimm_1R8T16Gbx4
    },


    // 2R 2H 3DS 4Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM16,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_32GB),
        xlate_dimm_2R4T4Gbx4
    },

    // 2R 2H 3DS 8Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_64GB),
        xlate_dimm_2R4T8Gbx4
    },

    // 2R 2H 3DS 16Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_128GB),
        xlate_dimm_2R4T16Gbx4
    },


    // 2R 4H 3DS 4Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_8R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM16,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_64GB),
        xlate_dimm_2R8T4Gbx4
    },

    // 2R 4H 3DS 8Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_8R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_128GB),
        xlate_dimm_2R8T8Gbx4
    },

    // 2R 4H 3DS 16Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_8R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_256GB),
        xlate_dimm_2R8T16Gbx4
    },


    // 2R 8H 3DS 4Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_16R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM16,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_128GB),
        xlate_dimm_2R16T4Gbx4
    },

    // 2R 8H 3DS 8Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_16R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_256GB),
        xlate_dimm_2R16T8Gbx4
    },

    // 2R 8H 3DS 16Gbx4 DDR4 RDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_16R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_512GB),
        xlate_dimm_2R16T16Gbx4
    },



    //
    // LRDIMM
    //

    // 2R 8Gbx4 32GB DDR4 LRDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_32GB),
        xlate_dimm_2R2T8Gbx4
    },

    // 4R 8Gbx4 64GB DDR4 LRDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_8G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_64GB),
        xlate_dimm_4R4T8Gbx4
    },

    //
    // 3DS LRDIMM
    //

    // 2R 2H 3DS 8Gbx4 64GB DDR4 LRDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_64GB),
        xlate_dimm_2R4T8Gbx4
    },

    // 2R 4H 3DS 8Gbx4 64GB DDR4 LRDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_8R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_4G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM17,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_128GB),
        xlate_dimm_2R8T8Gbx4
    },

    // 2R 2H 3DS 16Gbx4 128GB DDR4 LRDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_4R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_128GB),
        xlate_dimm_2R4T16Gbx4
    },

    // 2R 4H 3DS 16Gbx4 256GB DDR4 LRDIMM
    {
        dimm::kind(fapi2::ENUM_ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM_2R,
        fapi2::ENUM_ATTR_EFF_NUM_RANKS_PER_DIMM_8R,
        fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G,
        fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4,
        fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,
        fapi2::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM,
        fapi2::ENUM_ATTR_EFF_DRAM_ROW_BITS_NUM18,
        fapi2::ENUM_ATTR_EFF_DIMM_SIZE_256GB),
        xlate_dimm_2R8T16Gbx4
    },

};

///
/// @brief Helper to determine if a given DIMM is the only 1R DIMM on a port
/// @param[in] i_target the DIMM in question
/// @note 1R DIMM are special. We need to handle 2 1R DIMM on a port as a special case - kind of make them look like
/// a single 2R DIMM. So we have to do a little dance here to get our partners configuration.
/// @return true iff all slots are have 1R DIMM installed
///
static bool all_slots_1R_helper(const fapi2::Target<TARGET_TYPE_DIMM>& i_target)
{
    const auto& l_mca = mss::find_target<TARGET_TYPE_MCA>(i_target);
    const auto& l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(l_mca);

    const std::vector<dimm::kind> l_dimm_kinds = dimm::kind::vector(l_dimms);
    bool l_all_slots_1R = false;

    // If we only have 1 DIMM, we don't have two slots with 1R DIMM. If we need to check, iterate
    // over the DIMM kinds and make sure all the DIMM have one master and one total ranks (not 3DS).
    if (l_dimms.size() > 1)
    {
        l_all_slots_1R = true;

        for (const auto& k : l_dimm_kinds)
        {
            l_all_slots_1R &= (k.iv_master_ranks == 1) && (k.iv_total_ranks == 1);
        }

        FAPI_INF("We have a 1R DIMM %s and more than one DIMM installed; all 1R? %s",
                 mss::c_str(i_target), (l_all_slots_1R == true ? "yes" : "no") );
    }

    return l_all_slots_1R;
}

///
/// @brief Helper to lay down the col and bank mappings.
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note This is for 16 bank DIMM, 32 bank DIMM will be different
///
static void column_and_16bank_helper(fapi2::buffer<uint64_t>& io_xlate1, fapi2::buffer<uint64_t>& io_xlate2)
{
    // These are compile time freebies, so there's no need to bother putting them in a pre-defined
    // constant and or-ing them in. Keeps things much more clear when the performance team wants to muck
    // around with the settings. Mappings taken directly from the Nimbus Workbook. The magic numbers
    // aren't; they're settings as defined in the scomdef

    constexpr uint64_t COL4_MAP(0b01101);
    constexpr uint64_t COL5_MAP(0b01100);
    constexpr uint64_t COL6_MAP(0b01011);
    constexpr uint64_t COL7_MAP(0b01010);
    constexpr uint64_t COL8_MAP(0b01001);
    constexpr uint64_t COL9_MAP(0b00111);
    constexpr uint64_t BANK0_MAP(0b01110);
    constexpr uint64_t BANK1_MAP(0b10000);
    constexpr uint64_t BG0_MAP(0b10001);
    constexpr uint64_t BG1_MAP(0b10010);

    io_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL4_BIT_MAP,
                              MCS_PORT02_MCP0XLT1_COL4_BIT_MAP_LEN>(COL4_MAP);

    io_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL5_BIT_MAP,
                              MCS_PORT02_MCP0XLT1_COL5_BIT_MAP_LEN>(COL5_MAP);

    io_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL6_BIT_MAP,
                              MCS_PORT02_MCP0XLT1_COL6_BIT_MAP_LEN>(COL6_MAP);

    io_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL7_BIT_MAP,
                              MCS_PORT02_MCP0XLT1_COL7_BIT_MAP_LEN>(COL7_MAP);

    io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_COL8_BIT_MAP,
                              MCS_PORT02_MCP0XLT2_COL8_BIT_MAP_LEN>(COL8_MAP);

    io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_COL9_BIT_MAP,
                              MCS_PORT02_MCP0XLT2_COL9_BIT_MAP_LEN>(COL9_MAP);

    io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP,
                              MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP_LEN>(BANK0_MAP);

    io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP,
                              MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP_LEN>(BANK1_MAP);

    io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP,
                              MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP_LEN>(BG0_MAP);

    io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP,
                              MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP_LEN>(BG1_MAP);

    FAPI_DBG("Set bits for column and 16 banks. MCP0XLT1: 0x%016lx, MCP0XLT2: 0x%016lx",
             uint64_t(io_xlate1), uint64_t(io_xlate2) );

}

///
/// @brief D Bit helper - sets the d-bit
/// The D bit is the bit in the address which tells the controller to move to the
/// other DIMM on the slot. D is short for DIMM bit.
/// @param[in] i_target, the DIMM target (for tracing only)
/// @param[in] i_largest, true if we're the largest DIMM on the port
/// @param[in] i_offset, which side of the register to setup
/// @param[in] i_map the place to map the D bit in the register
/// @param[in,out] io_xlate the translation register
/// @return FAPI2_RC_SUCCESS iff okay
///
static fapi2::ReturnCode d_bit_helper( const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                       const bool i_largest,
                                       const uint64_t i_offset,
                                       const uint64_t i_map,
                                       fapi2::buffer<uint64_t>& io_xlate0)
{
    // Setup the D-bit. If we're the largest DIMM, it is our mapping which matters.
    // Notice that we don't care if the D-value bit has been set; this mapping needs to be setup regardless
    // (SJ Powell says so)
    if (i_largest)
    {
        FAPI_INF("setting d-bit mapping (am largest) 0x%x at start: %d, len: %d for %s",
                 i_map, MCS_PORT02_MCP0XLT0_D_BIT_MAP + i_offset, MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN, mss::c_str(i_target));

        FAPI_TRY( io_xlate0.insertFromRight(i_map, MCS_PORT02_MCP0XLT0_D_BIT_MAP + i_offset,
                                            MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN) );
    }

    FAPI_DBG("d-bit %s set. MCP0XLT0: 0x%016lx", (i_largest == true ? "was" : "was NOT"), uint64_t(io_xlate0));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R2T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t M1_MAP(0b01111);
    constexpr uint64_t R15_MAP(0b00110);
    constexpr uint64_t DBIT_MAP(0b00101);

    // Set the proper bit if there is a DIMM in this slot. If there wasn't, we wouldn't see
    // this DIMM in the vector, so this is always safe.
    FAPI_TRY(set_xlate_dimm_slot(i_offset, io_xlate0) );

    // Check our master ranks, and enable the proper bits.
    // Note this seems a little backward. M0 is the left most bit, M1 the right most.
    // So, M1 changes for ranks 0,1 and M0 changes for ranks 3,4
    // 2 rank DIMM, so master bit 1 (least significant) bit needs to be mapped.
    FAPI_TRY( set_xlate_mrank<M1>(M1_MAP, i_offset, io_xlate0) );

    // Tell the MC which of the row bits are valid, and map the DIMM selector
    // We're a 16 row DIMM, so ROW15 is valid.
    FAPI_TRY( set_xlate_row<ROW15>(R15_MAP, i_offset, io_xlate0) );

    // Drop down the column assignments
    column_and_16bank_helper(io_xlate1, io_xlate2);

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R2T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R16_MAP(0b00101);
    constexpr uint64_t DBIT_MAP(0b00100);

    // We're basically a 2R 4Gbx4 with an extra row. So lets setup like we're one of those,
    // add row 16 and shift the D bit as needed.
    xlate_dimm_2R2T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2);

    // Tell the MC which of the row bits are valid, and map the DIMM selector
    // We're a 17 row DIMM, so ROW16 is valid.
    FAPI_TRY( set_xlate_row<ROW16>(R16_MAP, i_offset, io_xlate0) );

    // Column assignments happened when we called xlate_dimm_2R2T4Gbx4

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R2T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R17_MAP(0b00100);
    constexpr uint64_t DBIT_MAP(0b00011);

    // We're basically a 2R 8Gbx4 with an extra row. So lets setup like we're one of those,
    // add row 16 and shift the D bit as needed.
    FAPI_TRY( xlate_dimm_2R2T8Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // Tell the MC which of the row bits are valid, and map the DIMM selector
    // We're a 18 row DIMM, so ROW17 is valid.
    FAPI_TRY( set_xlate_row<ROW17>(R17_MAP, i_offset, io_xlate0) );

    // Column assignments happened when we called xlate_dimm_2R2T8Gbx4

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R4T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t M1_MAP(0b00110);

    // We're just like a 1R 4H 4Gbx4 so lets start there and modify for the slave ranks.
    FAPI_TRY( xlate_dimm_1R4T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    clear_xlate_srank<S1>(i_offset, io_xlate0, io_xlate1);

    FAPI_TRY( set_xlate_mrank<M1>(M1_MAP, i_offset, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R4T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R16_MAP(0b00100);
    constexpr uint64_t DBIT_MAP(0b00011);

    // We're just like a 2R 2H 4Gbx4 so lets start there and modify for the slave ranks.
    FAPI_TRY( xlate_dimm_2R4T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 17 row DIMM, so ROW16 is valid.
    FAPI_TRY( set_xlate_row<ROW16>(R16_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 2H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R4T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R17_MAP(0b00011);
    constexpr uint64_t DBIT_MAP(0b00010);

    // We're just like a 2R 2H 8Gbx4 so lets start there and modify for the slave ranks.
    FAPI_TRY( xlate_dimm_2R4T8Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 18 row DIMM, so ROW17 is valid.
    FAPI_TRY( set_xlate_row<ROW17>(R17_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R8T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t M1_MAP(0b00101);

    // We're just like a 1R 8H 4Gbx4 so lets start there and modify for the slave ranks.
    FAPI_TRY( xlate_dimm_1R8T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    clear_xlate_srank<S0>(i_offset, io_xlate0, io_xlate1);

    FAPI_TRY( set_xlate_mrank<M1>(M1_MAP, i_offset, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R8T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R16_MAP(0b00011);
    constexpr uint64_t DBIT_MAP(0b00010);

    // We're just like a 2R 4H 3DS 4Gbx4 so lets start there and modify
    FAPI_TRY( xlate_dimm_2R8T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 17 row DIMM, so ROW16 is valid.
    FAPI_TRY( set_xlate_row<ROW16>(R16_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 4H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R8T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R17_MAP(0b00010);
    constexpr uint64_t DBIT_MAP(0b0001);

    // We're just like a 2R 2H 3DS 8Gbx4 so lets start there and modify
    FAPI_TRY( xlate_dimm_2R4T8Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 18 row DIMM, so ROW17 is valid.
    FAPI_TRY( set_xlate_row<ROW17>(R17_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R16T4Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t M1_MAP(0b00100);
    constexpr uint64_t R15_MAP(0b00011);
    constexpr uint64_t DBIT_MAP(0b00010);

    // We're just like a 1R 8H 4Gbx4 so lets start there
    FAPI_TRY( xlate_dimm_1R8T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We need to setup our M1 bit
    FAPI_TRY( set_xlate_mrank<M1>(M1_MAP, i_offset, io_xlate0) );

    // We're a 16 row DIMM, so ROW15 is valid.
    FAPI_TRY( set_xlate_row<ROW15>(R15_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R16T8Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R16_MAP(0b00010);
    constexpr uint64_t DBIT_MAP(0b00001);

    // We're just like a 2R 8H 3DS 4Gbx4 DDR4 RDIMM
    FAPI_TRY( xlate_dimm_2R16T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 17 row DIMM, so ROW16 is valid.
    FAPI_TRY( set_xlate_row<ROW16>(R16_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 2R 8H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_2R16T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R17_MAP(0b00001);
    constexpr uint64_t DBIT_MAP(0b0000);

    // We're just like a 2R 8H 3DS 8Gbx4 DDR4 RDIMM
    FAPI_TRY( xlate_dimm_2R16T8Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 18 row DIMM, so ROW17 is valid.
    FAPI_TRY( set_xlate_row<ROW17>(R17_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R1T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    bool l_all_slots_1R = all_slots_1R_helper(i_kind.iv_target);

    // Set the proper bit if there is a DIMM in this slot. If there wasn't, we wouldn't see
    // this DIMM in the vector, so this is always safe.
    FAPI_TRY(set_xlate_dimm_slot(i_offset, io_xlate0) );

    // If we have all the slots filled in with 1R SDP DIMM, we build a very differnt mapping.
    if (l_all_slots_1R)
    {
        constexpr uint64_t R15_MAP(0b00110);
        constexpr uint64_t DBIT_MAP(0b01111);

        // Tell the MC which of the row bits are valid, and map the DIMM selector
        // We're a 16 row DIMM, so ROW15 is valid.
        FAPI_TRY( set_xlate_row<ROW15>(R15_MAP, i_offset, io_xlate0) );

        // Drop down the column assignments.
        column_and_16bank_helper(io_xlate1, io_xlate2);

        // Setup the D-bit. Since both DIMM are identical, we just need to setup the map
        FAPI_INF("setting d-bit mapping (all 1R DIMM) for %s", mss::c_str(i_kind.iv_target));
        io_xlate0.insertFromRight<MCS_PORT02_MCP0XLT0_D_BIT_MAP, MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN>(DBIT_MAP);

        return fapi2::FAPI2_RC_SUCCESS;
    }

    // So if we're here we have only 1 1R DIMM installed. This translation is different.

    // Tell the MC which of the row bits are valid, and map the DIMM selector
    {
        constexpr uint64_t COL4_MAP(0b01110);
        constexpr uint64_t COL5_MAP(0b01101);
        constexpr uint64_t COL6_MAP(0b01100);
        constexpr uint64_t COL7_MAP(0b01011);
        constexpr uint64_t COL8_MAP(0b01010);
        constexpr uint64_t COL9_MAP(0b01001);
        constexpr uint64_t BANK0_MAP(0b01111);
        constexpr uint64_t BANK1_MAP(0b10000);
        constexpr uint64_t BG0_MAP(0b10001);
        constexpr uint64_t BG1_MAP(0b10010);
        constexpr uint64_t R15_MAP(0b00111);

        // We're a 16 row DIMM, so ROW15 is valid.
        FAPI_TRY( set_xlate_row<ROW15>(R15_MAP, i_offset, io_xlate0) );

        // We don't just drop down the col and bank assignments, they're different.
        io_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL4_BIT_MAP,
                                  MCS_PORT02_MCP0XLT1_COL4_BIT_MAP_LEN>(COL4_MAP);

        io_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL5_BIT_MAP,
                                  MCS_PORT02_MCP0XLT1_COL5_BIT_MAP_LEN>(COL5_MAP);

        io_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL6_BIT_MAP,
                                  MCS_PORT02_MCP0XLT1_COL6_BIT_MAP_LEN>(COL6_MAP);

        io_xlate1.insertFromRight<MCS_PORT02_MCP0XLT1_COL7_BIT_MAP,
                                  MCS_PORT02_MCP0XLT1_COL7_BIT_MAP_LEN>(COL7_MAP);

        io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_COL8_BIT_MAP,
                                  MCS_PORT02_MCP0XLT2_COL8_BIT_MAP_LEN>(COL8_MAP);

        io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_COL9_BIT_MAP,
                                  MCS_PORT02_MCP0XLT2_COL9_BIT_MAP_LEN>(COL9_MAP);

        io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP,
                                  MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP_LEN>(BANK0_MAP);

        io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP,
                                  MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP_LEN>(BANK1_MAP);

        io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP,
                                  MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP_LEN>(BG0_MAP);

        io_xlate2.insertFromRight<MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP,
                                  MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP_LEN>(BG1_MAP);
    }
    // There's nothing to do for the D-bit. We're either not the largest DIMM, in which case the largest DIMM
    // will fix up our D-bit mapping, or we're the only DIMM in the port. If we're the only DIMM in the port,
    // there is no D-bit mapping for a 1 slot 1R DIMM.

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R1T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R16_MAP_ALL_1R(0b00101);
    constexpr uint64_t R16_MAP_NOT_ALL_1R(0b00110);
    const auto R16_MAP = all_slots_1R_helper(i_kind.iv_target) ? R16_MAP_ALL_1R : R16_MAP_NOT_ALL_1R;

    // We're more or less a 1R 4Gbx4 with an extra row. So lets setup like that and add our row in.
    FAPI_TRY( xlate_dimm_1R1T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // If we have all the slots filled in with 1R SDP DIMM, we build a differnt mapping.
    // We're a 17 row DIMM, so ROW16 is valid.
    FAPI_TRY( set_xlate_row<ROW16>(R16_MAP, i_offset, io_xlate0) );

    // There's nothing to do for the D-bit. We're either not the largest DIMM, in which case the largest DIMM
    // will fix up our D-bit mapping, or we're the only DIMM in the port. If we're the only DIMM in the port,
    // there is no D-bit mapping for a 1 slot 1R DIMM.

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R1T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R17_MAP_ALL_1R(0b00100);
    constexpr uint64_t R17_MAP_NOT_ALL_1R(0b00101);
    const auto R17_MAP = all_slots_1R_helper(i_kind.iv_target) ? R17_MAP_ALL_1R : R17_MAP_NOT_ALL_1R;

    // We're more or less a 1R 8Gbx4 with an extra row. So lets setup like that and add our row in.
    FAPI_TRY( xlate_dimm_1R1T8Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // If we have all the slots filled in with 1R SDP DIMM, we build a different mapping.
    // We're a 18 row DIMM, so ROW17 is valid.
    FAPI_TRY( set_xlate_row<ROW17>(R17_MAP, i_offset, io_xlate0) );

    // There's nothing to do for the D-bit. We're either not the largest DIMM, in which case the largest DIMM
    // will fix up our D-bit mapping, or we're the only DIMM in the port. If we're the only DIMM in the port,
    // there is no D-bit mapping for a 1 slot 1R DIMM.

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R2T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t S2_MAP(0b01111);

    // We're just like a 2R 4Gbx4 so lets start there and modify for the slave ranks.
    FAPI_TRY( xlate_dimm_2R2T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    clear_xlate_mrank<M1>(i_offset, io_xlate0);

    FAPI_TRY( set_xlate_srank<S2>(S2_MAP, i_offset, io_xlate0, io_xlate1) );

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R2T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R16_MAP(0b00101);
    constexpr uint64_t DBIT_MAP(0b00100);

    // We're just like a 1R 2H 4Gbx4 so lets start there
    FAPI_TRY( xlate_dimm_1R2T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 17 row DIMM, so ROW16 is valid.
    FAPI_TRY( set_xlate_row<ROW16>(R16_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 2H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R2T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R17_MAP(0b00100);
    constexpr uint64_t DBIT_MAP(0b00011);

    // We're just like a 1R 2H 8Gbx4 so lets start there
    FAPI_TRY( xlate_dimm_1R2T8Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 18 row DIMM, so ROW17 is valid.
    FAPI_TRY( set_xlate_row<ROW17>(R17_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R4T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t S1_MAP(0b00110);
    constexpr uint64_t R15_MAP(0b00101);
    constexpr uint64_t DBIT_MAP(0b00100);

    // We're just like a 1R 2H 4Gbx4 so lets start there and modify for the slave ranks.
    FAPI_TRY( xlate_dimm_1R2T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // What was row 15 is now a slave rank, and we have to add in row 15 and the d-bit
    FAPI_TRY( set_xlate_srank<S1>(S1_MAP, i_offset, io_xlate0, io_xlate1) );

    // We're a 16 row DIMM, so ROW15 is valid.
    FAPI_TRY( set_xlate_row<ROW15>(R15_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R4T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R16_MAP(0b00100);
    constexpr uint64_t DBIT_MAP(0b00011);

    // We're just like a 1R 4H 4Gbx4 so lets start there and modify
    FAPI_TRY( xlate_dimm_1R4T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 17 row DIMM, so ROW16 is valid.
    FAPI_TRY( set_xlate_row<ROW16>(R16_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 4H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R4T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R17_MAP(0b00011);
    constexpr uint64_t DBIT_MAP(0b00010);

    // We're just like a 1R 4H 8Gbx4 so lets start there and modify
    FAPI_TRY( xlate_dimm_1R4T8Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 18 row DIMM, so ROW17 is valid.
    FAPI_TRY( set_xlate_row<ROW17>(R17_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R8T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t S0_MAP(0b00101);
    constexpr uint64_t R15_MAP(0b00100);
    constexpr uint64_t DBIT_MAP(0b00011);

    // We're just like a 1R 4H 4Gbx4 so lets start there and modify for the slave ranks.
    FAPI_TRY( xlate_dimm_1R4T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );
    FAPI_TRY( set_xlate_srank<S0>(S0_MAP, i_offset, io_xlate0, io_xlate1) );

    // We're a 16 row DIMM, so ROW15 is valid.
    FAPI_TRY( set_xlate_row<ROW15>(R15_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R8T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R16_MAP(0b00011);
    constexpr uint64_t DBIT_MAP(0b00010);

    // We're just like a 1R 8H 4Gbx4 so lets start there and modify for the slave ranks.
    FAPI_TRY( xlate_dimm_1R8T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 17 row DIMM, so ROW16 is valid.
    FAPI_TRY( set_xlate_row<ROW16>(R16_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 1R 8H 3DS 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_1R8T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R17_MAP(0b00010);
    constexpr uint64_t DBIT_MAP(0b00001);

    // We're just like a 1R 8H 8Gbx4 so lets start there and modify for the slave ranks.
    FAPI_TRY( xlate_dimm_1R8T8Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 18 row DIMM, so ROW17 is valid.
    FAPI_TRY( set_xlate_row<ROW17>(R17_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 4Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_4R4T4Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R15_MAP(0b00101);
    constexpr uint64_t M0_MAP(0b00110);
    constexpr uint64_t DBIT_MAP(0b00100);

    // We're just like a 2R 4Gbx4 except we have a valid M0 and a different DIMM bit.
    FAPI_TRY( xlate_dimm_2R2T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // Our R15 is still valid, but slide it over to make room for the M0 bit
    io_xlate0.insertFromRight<MCS_PORT02_MCP0XLT0_R15_BIT_MAP, MCS_PORT02_MCP0XLT0_R15_BIT_MAP_LEN>(R15_MAP);

    FAPI_TRY( set_xlate_mrank<M0>(M0_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 8Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_4R4T8Gbx4( const dimm::kind& i_kind,
                                        const uint64_t i_offset,
                                        const bool i_largest,
                                        fapi2::buffer<uint64_t>& io_xlate0,
                                        fapi2::buffer<uint64_t>& io_xlate1,
                                        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R16_MAP(0b00100);
    constexpr uint64_t DBIT_MAP(0b00011);

    // We're just like a 4R 4Gbx4 except we have an extra row
    FAPI_TRY( xlate_dimm_4R4T4Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 17 row DIMM, so ROW16 is valid.
    FAPI_TRY( set_xlate_row<ROW16>(R16_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform initializations of the MC translation
/// @param[in] i_kind the DIMM to map
/// @param[in] i_offset the offset; whether the DIMM ins slot 0 or slot 1
/// @param[in] i_largest whether or not we're the largest DIMM on the port.
/// @param[in,out] io_xlate0 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate1 a buffer representing the xlate register to modify
/// @param[in,out] io_xlate2 a buffer representing the xlate register to modify
/// @note Called for 4R 16Gbx4 DDR4 RDIMM
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode xlate_dimm_4R4T16Gbx4( const dimm::kind& i_kind,
        const uint64_t i_offset,
        const bool i_largest,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    constexpr uint64_t R17_MAP(0b00011);
    constexpr uint64_t DBIT_MAP(0b00010);

    // We're just like a 4R 8Gbx4 except we have an extra row
    FAPI_TRY( xlate_dimm_4R4T8Gbx4(i_kind, i_offset, i_largest, io_xlate0, io_xlate1, io_xlate2) );

    // We're a 18 row DIMM, so ROW17 is valid.
    FAPI_TRY( set_xlate_row<ROW17>(R17_MAP, i_offset, io_xlate0) );

    FAPI_TRY( d_bit_helper(i_kind.iv_target, i_largest, i_offset, DBIT_MAP, io_xlate0) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper to setup the translation map - useful for testing
/// @param[in,out] io_dimm_kinds std::vector of DIMM kind's representing the DIMM (Not const as we sort the vector)
/// @param[out] fapi2::buffer<uint64_t> io_xlate00  - xlt register 0's value
/// @param[out] fapi2::buffer<uint64_t> io_xlate1  - xlt register 1's value
/// @param[out] fapi2::buffer<uint64_t> io_xlate2  - xlt register 2's value
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_xlate_map_helper( std::vector<dimm::kind>& io_dimm_kinds,
        fapi2::buffer<uint64_t>& io_xlate0,
        fapi2::buffer<uint64_t>& io_xlate1,
        fapi2::buffer<uint64_t>& io_xlate2 )
{
    if (io_dimm_kinds.size() < 1)
    {
        FAPI_ERR("seeing an empty vector in the setup_xlate_map_helper");
        fapi2::Assert(false);
    }

    // Considering the DIMM, record who gets the D bit. We make sure the *smallest* DIMM has the highest address
    // range by setting it's D bit to 1. This eliminates, or reduces, holes in the memory map.
    // However, we need to set that DIMM's D bit in the location of the largest DIMM's D-bit map (I know that's
    // hard to grok - set the D bit in the smallest DIMM but in the location mapped for the largest.) So we
    // keep track of the largest DIMM so when we set it up, we make sure to set the D-bit in the other.
    std::sort(io_dimm_kinds.begin(), io_dimm_kinds.end(), [](const dimm::kind & a, const dimm::kind & b) -> bool
    {
        return a.iv_size > b.iv_size;
    });

    FAPI_INF("DIMM with the largest size on this port is %s %dMR (%d total ranks) %dGbx%d (%dGB)",
             mss::c_str(io_dimm_kinds[0].iv_target),
             io_dimm_kinds[0].iv_master_ranks,
             io_dimm_kinds[0].iv_total_ranks,
             io_dimm_kinds[0].iv_dram_density,
             io_dimm_kinds[0].iv_dram_width,
             io_dimm_kinds[0].iv_size);

    const auto l_d_bit_target = io_dimm_kinds[0].iv_target;

    // Get the functional DIMM on this port.
    for (const auto& k : io_dimm_kinds)
    {
        // Our slot (0, 1) is the same as our general index.
        const uint64_t l_slot = mss::index(k.iv_target);

        // Our slot offset tells us which 16 bit secption in the xlt register to use for this DIMM
        // We'll either use the left most bits (slot 0) or move 16 bits to the right for slot 1.
        const uint64_t l_slot_offset = l_slot * 16;

        FAPI_INF("address translation for DIMM %s %dMR (%d total ranks) %dGbx%d (%dGB) in slot %d",
                 mss::c_str(k.iv_target),
                 k.iv_master_ranks,
                 k.iv_total_ranks,
                 k.iv_dram_density,
                 k.iv_dram_width,
                 k.iv_size,
                 l_slot);

        // Set the proper bit if there is a DIMM in this slot. If there wasn't, we wouldn't see
        // this DIMM in the vector, so this is always safe.
        FAPI_TRY(set_xlate_dimm_slot(l_slot_offset, io_xlate0) );

        // Find the proper set function based on this DIMM kind.
        const auto l_setup = std::find_if( xlate_map.begin(), xlate_map.end(), [k](const xlate_setup & x) -> bool
        {
            return x.iv_kind == k;
        } );

        // If we didn't find it, raise a stink.
        FAPI_ASSERT( l_setup != xlate_map.end(),
                     fapi2::MSS_NO_XLATE_FOR_DIMM().
                     set_DIMM_IN_ERROR(k.iv_target).
                     set_MASTER_RANKS(k.iv_master_ranks).
                     set_TOTAL_RANKS(k.iv_total_ranks).
                     set_DRAM_DENSITY(k.iv_dram_density).
                     set_DRAM_WIDTH(k.iv_dram_width).
                     set_DRAM_GENERATION(k.iv_dram_generation).
                     set_DIMM_TYPE(k.iv_dimm_type).
                     set_ROWS(k.iv_rows).
                     set_SIZE(k.iv_size),
                     "no address translation funtion for DIMM %s %dMR (%d total ranks) %dGbx%d (%dGB) in slot %d",
                     mss::c_str(k.iv_target),
                     k.iv_master_ranks,
                     k.iv_total_ranks,
                     k.iv_dram_density,
                     k.iv_dram_width,
                     k.iv_size,
                     l_slot );

        // If we did find it ...
        // If we're the smallest DIMM in the port and we have more than one DIMM, we set our D-bit.
        if( (l_d_bit_target != k.iv_target) && (io_dimm_kinds.size() > 1) )
        {
            FAPI_INF("noting d-bit of 1 for %s", mss::c_str(k.iv_target));
            FAPI_TRY( io_xlate0.setBit(MCS_PORT13_MCP0XLT0_SLOT0_D_VALUE + l_slot_offset) );

            FAPI_DBG("Set d-bit. MCP0XLT0: 0x%016lx, MCP0XLT1: 0x%016lx, MCP0XLT2: 0x%016lx",
                     uint64_t(io_xlate0), uint64_t(io_xlate1), uint64_t(io_xlate2) );
        }

        // Call the translation function to fill in the blanks.
        // The conditional argument tells the setup function whether this setup should set the D bit, as we're
        // the largest DIMM on the port.
        FAPI_TRY( l_setup->iv_func(k, l_slot_offset, (k.iv_target == l_d_bit_target), io_xlate0, io_xlate1, io_xlate2) );
    }

    FAPI_INF("cramming 0x%016lx in for MCP0XLT0", io_xlate0);
    FAPI_INF("cramming 0x%016lx in for MCP0XLT1", io_xlate1);
    FAPI_INF("cramming 0x%016lx in for MCP0XLT2", io_xlate2);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Perform initializations of the MC translation - MCA specialization
/// @param[in] i_target, the target which has the MCA to map
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode setup_xlate_map(const fapi2::Target<TARGET_TYPE_MCA>& i_target)
{
    fapi2::buffer<uint64_t> l_xlate0;
    fapi2::buffer<uint64_t> l_xlate1;
    fapi2::buffer<uint64_t> l_xlate2;

    const auto l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(i_target);

    // We need to keep around specifications of both DIMM as we set the D bit based on the sizes of the DIMM
    std::vector<dimm::kind> l_dimm_kinds = dimm::kind::vector(l_dimms);

    FAPI_INF("Setting up xlate registers for MCA%d (%d)", mss::pos(i_target), mss::index(i_target));

    FAPI_TRY( setup_xlate_map_helper(l_dimm_kinds, l_xlate0, l_xlate1, l_xlate2) );

    FAPI_TRY( mss::putScom(i_target, MCA_MBA_MCP0XLT0, l_xlate0)  );
    FAPI_TRY( mss::putScom(i_target, MCA_MBA_MCP0XLT1, l_xlate1) );
    FAPI_TRY( mss::putScom(i_target, MCA_MBA_MCP0XLT2, l_xlate2) );

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace mc
} // namespace mss
