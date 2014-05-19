/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/runtime/attrrp_rt.C $                       */
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
#include <runtime/interface.h>
#include <errl/errlentry.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/targplatreasoncodes.H>

#include "../attrrp_common.C"

using namespace ERRORLOG;

namespace TARGETING
{
    void AttrRP::startup(errlHndl_t& io_taskRetErrl)
    {
        errlHndl_t l_errl = NULL;

        do
        {
            TargetingHeader* l_header = reinterpret_cast<TargetingHeader*>(
                g_hostInterfaces->get_reserved_mem("ibm,hbrt-target-image"));

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
