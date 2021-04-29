/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_pldm_utils.C $                              */
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

/* Local includes */
#include "pnor_pldm_utils.H"


/* Misc Userspace Module Includes */
#include <trace/interface.H>
#include <pnor/pnor_reasoncodes.H>
#include <pldm/pldm_errl.H>
#include <pnor/pnorif.H>

/* PLDM Subtree Includes */
#include <openbmc/pldm/oem/ibm/libpldm/file_io.h>
extern trace_desc_t* g_trac_pnor;

/**
 * @file pnor_pldm_utils.C
 *
 * @brief File containing the source code for translating between
 *        PLDM-isms and legacy PNOR-isms. The initial inspiriation
 *        for this file was to have a home for the code translating
 *        virtual addresses to ipl-time lid is, but any other
 *        utilities for pnor/pldm interactions can be put in here.
 */

namespace PLDM_PNOR
{
    errlHndl_t sectionIdToLidId(const PNOR::SectionId i_sectionId,
                                uint32_t & o_lidId)
    {
        auto lid_table = PNOR::getLidIds();
        return sectionIdToLidId(i_sectionId, o_lidId, lid_table);
    }

  errlHndl_t sectionIdToLidId(const PNOR::SectionId i_sectionId,
                              uint32_t & o_lidId,
                              const std::array<uint32_t, PNOR::NUM_SECTIONS> & i_lid_ids)
    {
        errlHndl_t errl = nullptr;
        assert(i_sectionId < PNOR::NUM_SECTIONS,
              "sectionIdToLidId attempting to lookup invalid SectionId" );
        o_lidId = i_lid_ids[i_sectionId];
        if(o_lidId == INVALID_LID)
        {
            TRACFCOMP(g_trac_pnor,
                      "PLDM_PNOR::sectionIdToLidId: Error, unable to find mapping for section %d dumping lid id table",
                      i_sectionId);
            for(size_t i = 0; i < PNOR::NUM_SECTIONS; i++)
            {
                TRACFCOMP(g_trac_pnor, "PLDM_PNOR::sectionIdToLidId: i_lid_ids[%d] = 0x%08x",
                          i , i_lid_ids[i]);
            }
            /*@
            * @errortype
            * @moduleid     PNOR::MOD_PNOR_PLDM_SEC_TO_LID
            * @reasoncode   PNOR::RC_INVALID_SECTION
            * @userdata1    Section ID we are looking up
            * @userdata2    unused
            * @devdesc      PLDM_PNOR::sectionIdToLidId> looking up a pnor section's
            *               lid mapping that does not exist
            * @custdesc     A problem occurred while accessing the boot firmware.
            */
            errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                        PNOR::MOD_PNOR_PLDM_SEC_TO_LID,
                        PNOR::RC_INVALID_SECTION,
                        i_sectionId,
                        0,
                        ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
            PLDM::addBmcErrorCallouts(errl);
        }

        return errl;
    }

    errlHndl_t vaddrToLidId(const uint64_t i_vaddr,
                            uint32_t &o_lidId,
                            uint32_t &o_offset)
    {
        // i_vaddr is an offset into the PNOR_RP VMM space.
        // Ensure i_vaddr does not exceed the end of PNOR_RP VMM space.
        assert(i_vaddr <= VMM_VADDR_PNOR_RP_MAX_SIZE,
                "Address we are trying to lookup not in PNOR VMM range");
        // Set the offset output parameter
        o_offset = i_vaddr % VMM_SIZE_RESERVED_PER_SECTION;

        const auto section_id =
          static_cast<PNOR::SectionId>(i_vaddr / VMM_SIZE_RESERVED_PER_SECTION);

        return sectionIdToLidId(section_id, o_lidId);
    }
}
