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
#include <pnor/pnor_pldm_utils.H>


/* Misc Userspace Module Includes */
#include <trace/interface.H>
#include <pnor/pnor_reasoncodes.H>
#include <pnor/pnorif.H>
#include <pldm/pldm_errl.H>
#include <pldm/base/hb_bios_attrs.H>
#include <errl/errludstring.H>
#include <errl/errlmanager.H>
#include <util/utillidpnor.H>

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

    /**
     * @brief This struct is used to map a PNOR::SectionId enum with
     *        a 4-byte lid id. We derive this mapping from the hb_lid_ids
     *        PLDM BIOS Attribute.
     */
    struct pnor_lid_mapping_t
    {
        PNOR::SectionId section_id;
        uint32_t lid_id;
    };

    /**
     * @brief Validate the contents of the parsed pnor to lid mapping
     *
     * @details This method will check that the section id and lid id found
     *          when parsing the hb_lid_ids attribute make sense.
     *
     * @param[in]  i_mapping           SectionId to Lid Id mapping to check
     * @param[out] o_validMapping      true if mapping is good; false otherwise
     *
     * @return Return an errorlog if an error occured, nullptr otherwise.
     */
    errlHndl_t checkPnorToLidMapping(const pnor_lid_mapping_t & i_mapping,
                                     bool & o_validMapping)
    {
        const uint32_t MIN_LID_ID_NUM = 0x80000000;
        o_validMapping = true;
        errlHndl_t errl = nullptr;
        if(i_mapping.section_id >= PNOR::INVALID_SECTION)
        {
            // We will hit this case when we find ipl ids when we are looking for runtime ids,
            // and we will hit this case when we find runtime ids but we are looking for ipl-time ids.
            TRACFCOMP(g_trac_pnor,"checkPnorToLidMapping: Could not find mapping for entry with lidId %x so we will discard the map entry",
                      i_mapping.lid_id);
            o_validMapping = false;
        }
        else if( i_mapping.lid_id < MIN_LID_ID_NUM )
        {
            // All valid lid ids should have first bit set.
            TRACFCOMP(g_trac_pnor,
                      "checkPnorToLidMapping: Invalid lid_id %lx found for section %d",
                      i_mapping.lid_id, i_mapping.section_id);
            /*@
              * @errortype
              * @severity   ERRL_SEV_PREDICTIVE
              * @moduleid   PNOR::MOD_CHECK_PNOR_LID_MAPPING
              * @reasoncode PNOR::RC_INVALID_LID_ID
              * @userdata1  Lid Id Found
              * @userdata2  Section Id Found
              * @devdesc    Software problem, incorrect data from BMC
              * @custdesc   A software error occurred during system boot
              */
            errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                 PNOR::MOD_CHECK_PNOR_LID_MAPPING,
                                 PNOR::RC_INVALID_LID_ID,
                                 i_mapping.lid_id,
                                 i_mapping.section_id,
                                 ErrlEntry::NO_SW_CALLOUT);
            ErrlUserDetailsString("hb_lid_ids").addToLog(errl);
            errl->collectTrace(PNOR_COMP_NAME);
            PLDM::addBmcErrorCallouts(errl);
            o_validMapping = false;
        }
        return errl;
    }

    template<class T>
    errlHndl_t parse_hb_lid_ids_string(T i_str_lookup_fn,
                                       std::vector<pnor_lid_mapping_t>& o_mappings_found)
    {
        std::vector<uint8_t> bios_string_table, bios_attr_table;
        std::vector<char> lid_ids_string;
        errlHndl_t errl = nullptr;
        do{

        errl = PLDM::getLidIds(bios_string_table, bios_attr_table, lid_ids_string);

        if(errl)
        {
            TRACFCOMP(g_trac_pnor, "parse_hb_lid_ids_string: An error occurred while looking up the hb_lid_ids PLDM BIOS attribute");
            break;
        }

        // setup some working variables which will be used
        // in the for-loop below
        std::vector<char> eyecatch, lid_id;
        pnor_lid_mapping_t mapping = {PNOR::INVALID_SECTION, 0};

        // parse a string of the format:
        //   <EYECATCH_a>=<lid_id_1>,<EYECATCH_b>=<lid_id_2>
        for(size_t i = 0; i < lid_ids_string.size(); i++)
        {
            char c = lid_ids_string[i];
            switch(c)
            {
                case '=' :
                    eyecatch.push_back('\0');
                    // lookup eyecatch string's SectionId mapping and
                    // set it in the mapping struct we are using to
                    //  fill mappings_found
                    for(uint32_t eye_index=PNOR::FIRST_SECTION;
                        eye_index < PNOR::NUM_SECTIONS;
                        eye_index++)
                        {
                            if(strcmp(i_str_lookup_fn(eye_index), eyecatch.data()) == 0)
                            {
                                mapping.section_id = static_cast<PNOR::SectionId>(eye_index);
                                break;
                            }
                        }
                    break;
                case ',' :
                    lid_id.push_back('\0');
                    mapping.lid_id = strtoul(lid_id.data(), nullptr, 16);
                    {
                        bool mapping_valid = true;
                        errlHndl_t map_check_err = checkPnorToLidMapping(mapping, mapping_valid);
                        if(map_check_err)
                        {
                            if(errl)
                            {
                                map_check_err->plid(errl->plid());
                                errlCommit(errl, PLDM_COMP_ID);
                            }
                            errl = map_check_err;
                            map_check_err = nullptr;
                        }
                        else if(mapping_valid)
                        {
                            o_mappings_found.push_back(mapping);
                        }

                    }
                    eyecatch.clear();
                    lid_id.clear();
                    mapping = {PNOR::INVALID_SECTION, 0};
                    break;
                default :
                    if(eyecatch.size() == 0 ||
                      eyecatch.back() != '\0')
                    {
                        eyecatch.push_back(c);
                    }
                    else
                    {
                        lid_id.push_back(c);
                    }
                    break;
            }
        }

        // catch the case where the list of entries was not terminated by ','
        if(eyecatch.size() && lid_id.size())
        {
            lid_id.push_back('\0');
            mapping.lid_id = strtoul(lid_id.data(), nullptr, 16);
            bool mapping_valid = true;
            errlHndl_t map_check_err = checkPnorToLidMapping(mapping, mapping_valid);
            if(map_check_err)
            {
                if(errl)
                {
                    map_check_err->plid(errl->plid());
                    errlCommit(errl, PLDM_COMP_ID);
                }
                errl = map_check_err;
                map_check_err = nullptr;
            }
            else if(mapping_valid)
            {
                o_mappings_found.push_back(mapping);
            }
        }

        }while(0);
        return errl;
    }

    errlHndl_t parse_ipl_lid_ids(std::array<uint32_t, PNOR::NUM_SECTIONS>& io_pnorToLidMappings)
    {
        errlHndl_t errl = nullptr;
        std::vector<pnor_lid_mapping_t> mappings_found;
        do{

        /* Initialize all entries to be invalid, we will correctly write any mappings we find below */
        constexpr uint32_t INVALID_LID = 0xffffffff;
        for(auto &entry : io_pnorToLidMappings)
        {
            entry = INVALID_LID;
        }

        errl = parse_hb_lid_ids_string(PNOR::SectionIdToString, mappings_found);
        if(errl)
        {
            TRACFCOMP(g_trac_pnor,"parse_ipl_lid_ids: an error occurred parsing hb_lid_ids bios attribute.");
            break;
        }

        for(auto mapping : mappings_found)
        {
            TRACFCOMP(g_trac_pnor,"parse_ipl_lid_ids: %s = %lx ", PNOR::SectionIdToString(mapping.section_id) , mapping.lid_id);
            io_pnorToLidMappings[mapping.section_id] = mapping.lid_id;
        }
        }while(0);

        return errl;
    }

    errlHndl_t parse_rt_lid_ids(void)
    {
        errlHndl_t errl = nullptr;
        do{
        std::vector<pnor_lid_mapping_t> mappings_found;
        errl = parse_hb_lid_ids_string(PNOR::SectionIdToRTString, mappings_found);
        if(errl)
        {
            TRACFCOMP(g_trac_pnor,"parse_rt_lid_ids: an error occurred parsing hb_lid_ids bios attribute.");
            break;
        }

        /* Update any runtime lid ids we find */
        for(auto mapping : mappings_found)
        {
            TRACFCOMP(g_trac_pnor,"parse_rt_lid_ids: %s = %lx ", PNOR::SectionIdToRTString(mapping.section_id) , mapping.lid_id);
            errl = Util::updateDataLidMapping(mapping.section_id,
                                              static_cast<Util::LidId>(mapping.lid_id));
            if(errl)
            {
                TRACFCOMP(g_trac_pnor,"parse_rt_lid_ids: An error occurred trying to update the mapping in the utillidpnor code for %s = %lx ",
                          PNOR::SectionIdToRTString(mapping.section_id) , mapping.lid_id);
                break;
            }
        }
        }while(0);
        return errl;
    }
}
