/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_pldm_utils.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#ifndef PNOR_PLDM_UTILS_H
#define PNOR_PLDM_UTILS_H

/* System Includes */
#include <vmmconst.h>
#include <vector>

/* PNOR Module Includes */
#include <pnor/pnor_const.H>

/* Misc Userspace Module Includes */
#include <errl/errlentry.H>

/** @file pnor_pldm_utils.H
 *  @brief Provides the utility functions used for PNOR operations using
 *         PLDM over MCTP on the LPC bus.
 */

namespace PLDM_PNOR
{
    constexpr uint32_t INVALID_LID = 0xffffffff;
    constexpr auto getipl_lid_ids ()
    {
        std::array<uint32_t, PNOR::NUM_SECTIONS> ipltime_lid_ids = {{0}};
        std::get<PNOR::TOC>(ipltime_lid_ids)            = INVALID_LID;
#ifndef BOOTLOADER
        std::get<PNOR::HB_EXT_CODE>(ipltime_lid_ids)    = 0x81E0065D;
#endif
        std::get<PNOR::HB_BASE_CODE>(ipltime_lid_ids)   = 0x81E0065A;
#ifndef BOOTLOADER
        std::get<PNOR::SBE_IPL>(ipltime_lid_ids)        = 0x81E00661;
        std::get<PNOR::HCODE>(ipltime_lid_ids)          = 0x81E00696;
        std::get<PNOR::PAYLOAD>(ipltime_lid_ids)        = 0x81E00660;
        std::get<PNOR::HB_RUNTIME>(ipltime_lid_ids)     = 0x81E0068E;
        std::get<PNOR::HB_DATA>(ipltime_lid_ids)        = 0x81E0068D;
        std::get<PNOR::GUARD_DATA>(ipltime_lid_ids)     = 0x81E00667;
        std::get<PNOR::HB_ERRLOGS>(ipltime_lid_ids)     = 0x81E00668;
        std::get<PNOR::DIMM_JEDEC_VPD>(ipltime_lid_ids) = INVALID_LID;
        std::get<PNOR::MODULE_VPD>(ipltime_lid_ids)     = INVALID_LID;
        std::get<PNOR::NVRAM>(ipltime_lid_ids)          = 0x81E0066B;
        std::get<PNOR::OCC>(ipltime_lid_ids)            = 0x81E00688;
        std::get<PNOR::FIRDATA>(ipltime_lid_ids)        = INVALID_LID;
        std::get<PNOR::ATTR_TMP>(ipltime_lid_ids)       = 0x81E00664;
        std::get<PNOR::ATTR_PERM>(ipltime_lid_ids)      = 0x81E00663;
        std::get<PNOR::CAPP>(ipltime_lid_ids)           = INVALID_LID;
        std::get<PNOR::VERSION>(ipltime_lid_ids)        = 0x81E00662;
        std::get<PNOR::HB_BOOTLOADER>(ipltime_lid_ids)  = 0x81E0065B;
        std::get<PNOR::TEST>(ipltime_lid_ids)           = INVALID_LID;
        std::get<PNOR::TESTRO>(ipltime_lid_ids)         = INVALID_LID;
        std::get<PNOR::BACKUP_PART>(ipltime_lid_ids)    = INVALID_LID;
        std::get<PNOR::RINGOVD>(ipltime_lid_ids)        = 0x81E00620;
        std::get<PNOR::WOFDATA>(ipltime_lid_ids)        = 0x81E00692;
        std::get<PNOR::SBKT>(ipltime_lid_ids)           = 0x81E0066C;
        std::get<PNOR::HB_VOLATILE>(ipltime_lid_ids)    = 0x81E0066F;
        std::get<PNOR::TESTLOAD>(ipltime_lid_ids)       = INVALID_LID;
        std::get<PNOR::HDAT>(ipltime_lid_ids)           = 0x81E00669;
        std::get<PNOR::EECACHE>(ipltime_lid_ids)        = 0x81E00679;
        std::get<PNOR::OCMBFW>(ipltime_lid_ids)         = 0x81E0067A;
#ifdef CONFIG_DEVTREE
        std::get<PNOR::DEVTREE>(ipltime_lid_ids)        = 0x81E00672;
#endif
#ifdef CONFIG_LOAD_PHYP_FROM_BOOTKERNEL
        std::get<PNOR::BOOTKERNEL>(ipltime_lid_ids)     = 0x81E00658;
#endif
        std::get<PNOR::HCODE_LID>(ipltime_lid_ids)      = 0x81E00671;
#endif
        return ipltime_lid_ids;
    }


    enum TraitBitMap : uint32_t
    {
        READ_ONLY  = 0x00000001,
        READ_WRITE = 0x00000002,
        PRESERVED  = 0x00000004,
    };

    /**
    * @brief Given virtual address in PNOR VMM space, return what
    *        IPL-time lid id the address maps to, and what offset
    *        into that lid id that virtual address would be.
    *
    * @param[in]  i_vaddr A virtual address in PNOR space
    * @param[out] o_offset The offset the input address would be
    *                      into the lid id that is returned
    * @return The IPL-time lid id associated with the virtual address
    *         that was passed in by the caller.
    */
    uint32_t vaddrToLidId(uint64_t i_vaddr,
                          uint32_t &o_offset);

    // TODO RTC 208802 remove mockup when BMC has support for host
    // access to .lid files via PLDM file i/o operations
    /**
    * @brief A temporary workaround which will return the expected reply to
    *        for a getFileTable request to the BMC. In this mockup we will
    *        return the IPL-time hostfw lids that the BMC stores. This
    *        function should be removed when the BMC adds correct support
    *        to populate the file table with the hostfw ipl time lids.
    *
    * @param[out] o_table the file table in binary format; will be cleared before
    *             populating with output data.
    * @return nullptr on success; non-nullptr on error. Other outputs are
    *         invalidated on error.
    */
    errlHndl_t getFileTableLidsMockup(std::vector<uint8_t> & o_fileTable);
}

#endif
