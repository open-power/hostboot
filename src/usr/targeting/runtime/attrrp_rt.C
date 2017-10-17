/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/attrrp_rt.C $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#include <targeting/attrrp.H>
#include <targeting/common/trace.H>
#include <util/align.H>
#include <runtime/interface.h>
#include <errl/errlentry.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/targplatreasoncodes.H>
#include <targeting/attrsync.H>
#include <util/runtime/util_rt.H>

#include "../attrrp_common.C"

using namespace ERRORLOG;

namespace TARGETING
{
    void AttrRP::fillInAttrRP(TargetingHeader* i_header)
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK"AttrRP::fillInAttrRP");

        do
        {
            // Create AttributeSync
            AttributeSync l_attributeSync = AttributeSync();

            // Allocate section structures based on section count in header.
            iv_sectionCount = i_header->numSections;
            iv_sections = new AttrRP_Section[iv_sectionCount]();

            // Find start to the first section:
            //          (header address + size of header + offset in header)
            TargetingSection* l_section =
                reinterpret_cast<TargetingSection*>(
                    reinterpret_cast<uint64_t>(i_header) +
                    sizeof(TargetingHeader) + i_header->offsetToSections
                );

            uint64_t l_offset = 0;

            for (size_t i = 0; i < iv_sectionCount; ++i, ++l_section)
            {
                iv_sections[i].type = l_section->sectionType;
                iv_sections[i].size = l_section->sectionSize;

                iv_sections[i].vmmAddress =
                        static_cast<uint64_t>(
                            TARG_TO_PLAT_PTR(i_header->vmmBaseAddress)) +
                        i_header->vmmSectionOffset*i;
                iv_sections[i].pnorAddress =
                        reinterpret_cast<uint64_t>(i_header) + l_offset;

                l_offset += ALIGN_PAGE(iv_sections[i].size);

                TRACFCOMP(g_trac_targeting,
                          "Decoded Attribute Section: %d, 0x%lx, 0x%lx, 0x%lx",
                          iv_sections[i].type,
                          iv_sections[i].vmmAddress,
                          iv_sections[i].pnorAddress,
                          iv_sections[i].size);
            }

            for (size_t i = 0; i < iv_sectionCount; ++i)
            {
                // get section data from current AttrRP
                std::vector <TARGETING::sectionRefData>l_pages;
                l_pages =
                    l_attributeSync.syncSectionFromAttrRP(iv_sections[i].type);

                // write section data to new AttrRP
                uint8_t * l_dataPtr = nullptr; // ptr to Attribute address space
                bool      l_rc = true;         // true if write is successful

                // for each page
                for(std::vector<TARGETING::sectionRefData>::const_iterator
                        pageIter = l_pages.begin();
                    (pageIter != l_pages.end()) && (true == l_rc);
                    ++pageIter)
                {
                    // check that page number is within range
                    uint64_t l_pageOffset = (*pageIter).pageNumber * PAGESIZE;
                    if ( iv_sections[i].size < (l_pageOffset + PAGESIZE) )
                    {
                        TARG_ERR("page offset 0x%lx is greater than "
                                 "size 0x%lx of section %u",
                                 l_pageOffset,
                                 iv_sections[i].size,
                                 iv_sections[i].type);

                        l_rc = false;
                        break;
                    }

                    // adjust the pointer out by page size * page number
                    l_dataPtr =
                        reinterpret_cast<uint8_t *>(iv_sections[i].pnorAddress)
                        + l_pageOffset;

                    memcpy( l_dataPtr, (*pageIter).dataPtr, PAGESIZE );

                }
            }
        } while(false);

        TRACFCOMP(g_trac_targeting, EXIT_MRK"AttrRP::fillInAttrRP");

        return;
    }

    void AttrRP::startup(errlHndl_t& io_taskRetErrl, bool isMpipl)
    {
        TRACFCOMP(g_trac_targeting, "AttrRP::startup");
        errlHndl_t l_errl = NULL;

        do
        {
            uint64_t attr_size = 0;
            TargetingHeader* l_header =
              reinterpret_cast<TargetingHeader*>(
                  hb_get_rt_rsvd_mem(Util::HBRT_MEM_LABEL_ATTR,0,attr_size));


            if ((NULL == l_header) ||
                (l_header->eyeCatcher != PNOR_TARG_EYE_CATCHER))
            {
                /*@
                 *   @errortype
                 *   @moduleid          TARG_MOD_ATTRRP_RT
                 *   @reasoncode        TARG_RC_BAD_EYECATCH
                 *   @userdata1         Observed Header Eyecatch Value
                 *   @userdata2         Memory address referenced.
                 *
                 *   @devdesc   The eyecatch value observed in memory does not
                 *              match the expected value of
                 *              PNOR_TARG_EYE_CATCHER and therefore the
                 *              contents of the Attribute sections are
                 *              unable to be parsed.
                 *   @custdesc  A problem occurred during the IPL of the
                 *              system.
                 *              The eyecatch value observed in memory does not
                 *              match the expected value and therefore the
                 *              contents of the attribute sections are unable
                 *              to be parsed.
                 */
                l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                       TARG_MOD_ATTRRP_RT,
                                       TARG_RC_BAD_EYECATCH,
                                       NULL == l_header ?
                                            0 : l_header->eyeCatcher,
                                       reinterpret_cast<uint64_t>(l_header));
                break;
            }

            // Allocate section structures based on section count in header.
            iv_sectionCount = l_header->numSections;
            iv_sections = new AttrRP_Section[iv_sectionCount]();

            // Find start to the first section:
            //          (header address + size of header + offset in header)
            TargetingSection* l_section =
                reinterpret_cast<TargetingSection*>(
                    reinterpret_cast<uint64_t>(l_header) +
                    sizeof(TargetingHeader) + l_header->offsetToSections
                );

            uint64_t l_offset = 0;

            for (size_t i = 0; i < iv_sectionCount; ++i, ++l_section)
            {
                iv_sections[i].type = l_section->sectionType;
                iv_sections[i].size = l_section->sectionSize;

                iv_sections[i].vmmAddress =
                        static_cast<uint64_t>(
                            TARG_TO_PLAT_PTR(l_header->vmmBaseAddress)) +
                        l_header->vmmSectionOffset*i;
                iv_sections[i].pnorAddress =
                        reinterpret_cast<uint64_t>(l_header) + l_offset;

                l_offset += ALIGN_PAGE(iv_sections[i].size);

                TRACFCOMP(g_trac_targeting,
                          "Decoded Attribute Section: %d, 0x%lx, 0x%lx, 0x%lx",
                          iv_sections[i].type,
                          iv_sections[i].vmmAddress,
                          iv_sections[i].pnorAddress,
                          iv_sections[i].size);
            }

        } while(false);

        if (l_errl)
        {
            l_errl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        }

        io_taskRetErrl = l_errl;
    }

    void* AttrRP::getBaseAddress(const NODE_ID i_nodeIdUnused)
    {
        return reinterpret_cast<void*>(iv_sections[0].pnorAddress);
    }

    void* AttrRP::translateAddr(void* i_pAddress,
                                const Target* i_pUnused)
    {
        void* l_address = NULL;

        for (size_t i = 0; i < iv_sectionCount; ++i)
        {
            if ((iv_sections[i].vmmAddress + iv_sections[i].size) >=
                reinterpret_cast<uint64_t>(i_pAddress))
            {
                l_address = reinterpret_cast<void*>(
                        iv_sections[i].pnorAddress +
                        reinterpret_cast<uint64_t>(i_pAddress) -
                        iv_sections[i].vmmAddress);
                break;
            }
        }

        TRACDCOMP(g_trac_targeting, "Translated 0x%p to 0x%p",
                  i_pAddress, l_address);

        return l_address;
    }

    void* AttrRP::translateAddr(void* i_pAddress,
                                const TARGETING::NODE_ID i_unused)
    {
        return translateAddr(i_pAddress, static_cast<Target*>(NULL));
    }
}
