/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_ppe_lib.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_io_ppe_lib.H
/// @brief Class definitions for manipulating PPE SRAM registers
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#ifndef _P10_IO_PPE_LIB_H
#define _P10_IO_PPE_LIB_H

#include <p10_scom_pauc_6.H>
#include <p10_scom_pauc_3.H>
#include <fapi2.H>
#include <map>

class p10_io_ppe_scom_regs
{
    public:
        const uint64_t csar_scom_addr;
        const uint64_t csdr_scom_addr;

        p10_io_ppe_scom_regs(uint64_t i_csar, uint64_t i_csdr) :
            csar_scom_addr(i_csar), csdr_scom_addr(i_csdr) {}

        ///
        /// @brief Reads 8 bytes from the PPE sram at the specified address
        ///
        /// @param[in]  i_target    PAUC target
        /// @param[in]  i_addr      Address to read from
        /// @param[out] o_data      The data read
        ///
        /// @return FAPI_RC_SUCCESS if arguments are valid
        fapi2::ReturnCode getData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target, const uint64_t i_addr,
                                  fapi2::buffer<uint64_t>& o_data);

        ///
        /// @brief Writes 8 bytes to the PPE sram at the specified address
        ///
        /// @param[in]  i_target    PAUC target
        /// @param[in]  i_addr      Address to write to
        /// @param[in]  i_data      The data to write
        ///
        /// @return FAPI_RC_SUCCESS if arguments are valid
        fapi2::ReturnCode putData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target, uint64_t i_addr,
                                  const fapi2::buffer<uint64_t>& i_data);


};

class p10_io_ppe_cache
{
    public:
        p10_io_ppe_scom_regs* scom_regs;
        const uint64_t section_address;
        std::map < fapi2::Target<fapi2::TARGET_TYPE_PAUC>, std::map <uint64_t, uint64_t> > cache;
        std::map < fapi2::Target<fapi2::TARGET_TYPE_PAUC>, std::map <uint64_t, bool> > dirty;

        p10_io_ppe_cache(p10_io_ppe_scom_regs* i_regs, uint64_t i_sec) :
            scom_regs(i_regs), section_address(i_sec) {}

        ///
        /// @brief Flushes dirty cache data to the PPE SRAM
        ///
        /// @return FAPI_RC_SUCCESS if arguments are valid
        fapi2::ReturnCode flush();

};

class p10_io_ppe_sram_reg
{
    public:
        p10_io_ppe_cache* cache;
        // These values come directly from the PPE image
        // include files.  They represent the location of the
        // field/register within a given section of PPE sram
        const uint32_t address;
        const uint32_t mask;
        const uint32_t shift;

        p10_io_ppe_sram_reg(p10_io_ppe_cache* i_cache, uint32_t i_address, uint32_t i_mask, uint32_t i_shift) :
            cache(i_cache), address(i_address), mask(i_mask), shift(i_shift) {}

        ///
        /// @brief Read a PPE SRAM register from the cache,
        ///        with option to invalidate the cache first
        ///
        /// @param[in]   i_target    PAUC target
        /// @param[out]  o_data      The data read for the register
        /// @param[in]   i_inv       Invalidate cache data before read if true
        ///
        /// @return FAPI_RC_SUCCESS if arguments are valid
        fapi2::ReturnCode getData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target,
                                  fapi2::buffer<uint64_t>& o_data, const bool i_inv = false);

        ///
        /// @brief Write data to a PPE SRAM register to the cache,
        ///        with option to write through the cache
        ///
        /// @param[in]   i_target    PAUC target
        /// @param[in]   i_data      The data to write to the register
        /// @param[in]   i_write     Write through the cache forcing write the PPE SRAM if true
        ///
        /// @return FAPI_RC_SUCCESS if arguments are valid
        fapi2::ReturnCode putData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target,
                                  fapi2::buffer<uint64_t> i_data, const bool i_write = false);

        ///
        /// @brief Read a PPR SRAM lane register from the cache
        ///        with option to invalidate the cache first
        ///
        /// @param[in]   i_target    PAUC target
        /// @param[out]  o_data      The data read for the register
        /// @param[in]   i_lane      The lane to read from
        /// @param[in]   i_inv       Invalidate cache data before read if true
        ///
        /// @return FAPI_RC_SUCCESS if arguments are valid
        fapi2::ReturnCode getData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target,
                                  fapi2::buffer<uint64_t>& o_data, const int i_lane, const bool i_inv = false);

        ///
        /// @brief Write data to a PPE SRAM lane register to the cache,
        ///        with option to write through the cache
        ///
        /// @param[in]   i_target    PAUC target
        /// @param[in]   i_data      The data to write to the register
        /// @param[in]   i_lane      The lane to write
        /// @param[in]   i_write     Write through the cache forcing write the PPE SRAM if true
        ///
        /// @return FAPI_RC_SUCCESS if arguments are valid
        fapi2::ReturnCode putData(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_target,
                                  fapi2::buffer<uint64_t> i_data, const int i_lane, const bool i_write = false);

};

extern p10_io_ppe_scom_regs p10_io_phy_ppe_scom_regs;

#endif
