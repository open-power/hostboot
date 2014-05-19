/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrrp_common.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#include <targeting/attrrp.H>
#include <targeting/common/trace.H>
#include <util/align.H>

namespace TARGETING
{
    /** @struct AttrRP_Section
     *  @brief Contains parsed information about each attribute section.
     */
    struct AttrRP_Section
    {
        // Section type
        SECTION_TYPE type;

        // Desired address in Attribute virtual address space
        uint64_t     vmmAddress;

        // Location in PNOR virtual address space
        uint64_t     pnorAddress;

        // Section size
        uint64_t     size;
    };

    AttrRP::~AttrRP()
    {
        if (iv_sections)
        {
            delete[] iv_sections;
        }
#ifndef __HOSTBOOT_RUNTIME
        msg_q_destroy(iv_msgQ);
#endif

        TARG_ASSERT(false);
    }

    void AttrRP::init(errlHndl_t &io_taskRetErrl)
    {
        // Call startup on singleton instance.
        Singleton<AttrRP>::instance().startup(io_taskRetErrl);
    }

    bool AttrRP::writeSectionData(
        const std::vector<TARGETING::sectionRefData>& i_pages) const
    {
        TARG_INF(ENTER_MRK "AttrRP::writeSectionData");

        uint8_t * l_dataPtr = NULL; // ptr to Attribute virtual address space
        bool      l_rc = true;      // true if write to section is successful

        // for each page
        for (std::vector<TARGETING::sectionRefData>::const_iterator
                pageIter = i_pages.begin();
                (pageIter != i_pages.end()) && (true == l_rc);
                ++pageIter)
        {
            // search for the section we need
            for ( size_t j = 0; j < iv_sectionCount; ++j )
            {
                if ( iv_sections[j].type == (*pageIter).sectionId )
                {
                    // found it..
                    TARG_DBG( "Writing Attribute Section: ID: %u, "
                        "address: 0x%lx size: 0x%lx page: %u",
                        iv_sections[j].type,
                        iv_sections[j].vmmAddress,
                        iv_sections[j].size,
                        (*pageIter).pageNumber);

                    // check that page number is within range
                    uint64_t l_pageOffset = (*pageIter).pageNumber * PAGESIZE;
                    if ( iv_sections[j].size < (l_pageOffset + PAGESIZE) )
                    {
                        TARG_ERR("page offset 0x%lx is greater than "
                            "size 0x%lx of section %u",
                            l_pageOffset,
                            iv_sections[j].size,
                            iv_sections[j].type);

                        l_rc = false;
                        break;
                    }

                    // adjust the pointer out by page size * page number
                    l_dataPtr =
                        reinterpret_cast<uint8_t *>
                        (iv_sections[j].vmmAddress) + l_pageOffset;

                    memcpy( l_dataPtr, (*pageIter).dataPtr, PAGESIZE );
                    break;
                }
            }

            if (false == l_rc)
            {
                break;
            }
        }

        TARG_INF( EXIT_MRK "AttrRP::writeSectionData" );
        return l_rc;
    }

    void AttrRP::readSectionData(
              std::vector<TARGETING::sectionRefData>& o_pages,
        const TARGETING::SECTION_TYPE                 i_sectionId,
        const NODE_ID                                 i_nodeId) const
    {
        sectionRefData sectionData;
        uint16_t count              =  0;
        uint16_t pages              =  0;

        // search for the section we need
        for (size_t i = 0; i < iv_sectionCount; ++i )
        {
            if ( iv_sections[i].type == i_sectionId )
            {
                // found it..
                // now figure out how many pages - rounding up to the
                // the next full page and dividing by the page size
                pages = ALIGN_PAGE( iv_sections[i].size )/PAGESIZE;

                TRACFCOMP(g_trac_targeting,
                        "Reading Attribute Section: ID: %d, \
                        address: 0x%lx size: 0x%lx pages: %d",
                        iv_sections[i].type,
                        iv_sections[i].vmmAddress,
                        iv_sections[i].size,
                        pages);

                // populate and push the structure for each page
                while( count != pages  )
                {
                    // duplicate the same section id in each structure
                    sectionData.sectionId = i_sectionId;

                    // update the current page number
                    sectionData.pageNumber = count;

                    // addjust the pointer out by page size * count each
                    // iteration
                    sectionData.dataPtr =
                             reinterpret_cast<uint8_t *>
                             (iv_sections[i].vmmAddress) + (count * PAGESIZE );

                    count++;

                    // pushing the actual structure to the vector
                    o_pages.push_back( sectionData );

                }

                break;
            }
        }
    }
}
