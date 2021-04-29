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
    enum TraitBitMap : uint32_t
    {
        READ_ONLY  = 0x00000001,
        READ_WRITE = 0x00000002,
        PRESERVED  = 0x00000004,
    };

    /**
    * @brief Given SectionId enum value lookup the lid id associated
    *        with that section. This function also validates that
    *        the given SectionId is valid and the mapping is also
    *        valid. This function will lookup the lid_ids mapping and call
    *        the overload of this function that takes i_lid_ids as a param
    *
    * @param[in]  i_sectionId SectionId we want to know the lid id of.
    * @param[out] o_lidId A uint32 representing the lid id assigned
    *                     to this pnor section on the service processor.
    * @return nullptr if no error is found. Will return error if i_sectionId
    *         maps to INVALID_LID
    */
  errlHndl_t sectionIdToLidId(const PNOR::SectionId i_sectionId,
                              uint32_t & o_lidId);

  /**
  * @brief Given SectionId enum value and the list of lid_id mappings,
  *        lookup the lid id associated with that section. This function
  *        also validates that the given SectionId is valid and
  *        the mapping is also valid.
  *
  * @param[in]  i_sectionId SectionId we want to know the lid id of.
  * @param[out] o_lidId A uint32 representing the lid id assigned
  *                     to this pnor section on the service processor.
  * @return nullptr if no error is found. Will return error if i_sectionId
  *         maps to INVALID_LID
  */
  errlHndl_t sectionIdToLidId(const PNOR::SectionId i_sectionId,
                              uint32_t & o_lidId,
                              const std::array<uint32_t, PNOR::NUM_SECTIONS> & i_lid_ids);


    /**
    * @brief Given virtual address in PNOR VMM space, return what
    *        IPL-time lid id the address maps to, and what offset
    *        into that lid id that virtual address would be.
    *
    * @param[in]  i_vaddr A virtual address in PNOR space
    * @param[out] o_lidId The lid id associated with this virtual address
    * @param[out] o_offset The offset the input address would be
    *                      into the lid id that is returned
    * @return nullptr on success; errorlog if unable to find valid lid id
    */
    errlHndl_t vaddrToLidId(const uint64_t i_vaddr,
                            uint32_t &o_lidId,
                            uint32_t &o_offset);

}

#endif
