/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_common.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
#ifndef PNOR_COMMON_H
#define PNOR_COMMON_H

#include <pnor/pnorif.H>
#include "pnor_utils.H"
#include "ffs.h"
#include <secureboot/service.H>

/************************************************************
*   Provides common functions for Hostboot IPL and runtime
*   code access to PNOR
************************************************************/
namespace PNOR {
    /**
     * @brief parse the TOC read from memory and store section
     *        information if the TOC is valid
     * @param[in] i_tocBuffer      Pointer to buffer containing a TOC
     * @param[in] i_pnorInitialized PNOR::init() has completed
     * @param[out] o_TOC            sectionInformation of the TOC used
     * @return Error
     */
    errlHndl_t parseTOC(uint8_t* i_tocBuffer, PNOR::SectionData_t * o_TOC,
                        bool i_pnorInitialized = true);

#ifdef CONFIG_FILE_XFER_VIA_PLDM

    /**
     * @brief Request the PLDM file table from the BMC and use it to fill
     *        in information about the various PNOR sections in the iv_TOC
     *        member of PnorRP.
     * @param[out] o_TOC           sectionInformation of the TOC used
     * @param[in] i_lid_ids        array of length NUM_SECTION that all the
     *                             lid id mappings we can find for SectionIds
     * @param[in] i_pnorInitialized PNOR::init() has completed
     * @return Contains the error, if one occurred, returned from the getFileTable
     *         PLDM request. Otherwise it will return nullptr.
     */
    errlHndl_t populateTOC( SectionData_t * o_TOC ,
                              std::array<uint32_t, PNOR::NUM_SECTIONS> & i_lid_ids,
                              bool i_pnorInitialized = true);

#endif

    /**
     *  @brief: determine the physical offset of ffs entry
     *          (to be used before readTOC is called)
     *  @param[in] i_tocAddress - ffs hdr pointing to a valid TOC
     *  @param[in] i_entryName  - Name of the ffs entry to find the offset of
     *  @param[out] o_offset    - physical offset of the ffs entry
     */
    void findPhysicalOffset(ffs_hdr* i_tocAddress,
                                  const char* i_entryName,
                                  uint64_t & o_offset);

    /**
     * @brief used to translate mmio offset stored in mbox scratch 2
     *        to physical offset of HBB Image
     * @param[out] o_hbbAddress Physical Offset of HB Base Image
     *                          associated with the current boot
     * @return Error
     */
    errlHndl_t mmioToPhysicalOffset(uint64_t& o_hbbAddress);


    /**
     * @brief used to translate HBB Address to MMIO offset
     * @param[in] i_hbbAddress  - Physical Offset of the HB Base image
     * @param[out] o_mmioOffest - MMIO Offset of the HB Base image
     */
     void physicalToMmioOffset(uint64_t  i_hbbAddress,
                               uint64_t& o_mmioOffset);

}

#endif
