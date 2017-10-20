/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilrsvdmem.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <targeting/common/trace.H>
#include <trace/interface.H>
#include <util/utilrsvdmem.H>

namespace Util
{
    /**
     *  @brief Get the address of a label's section based on table of contents
     *
     *  @param[in] i_label              - HBRT_MEM_LABEL_... constant
     *  @param[in] i_hb_data_toc_addr   - pointer to the table of contents
     *  @param[out] o_size              - size of returned region in bytes
     *
     *  @return virtual address of region or 0
     *  @platform FSP, OpenPOWER
     **/
    uint64_t hb_find_rsvd_mem_label(hbrt_mem_label_t i_label,
                                    hbrtTableOfContents_t * i_hb_data_toc_addr,
                                    uint64_t & o_size)
    {
        // initialize to not return anything
        uint64_t l_label_data_addr = 0;
        o_size = 0;

        TRACFCOMP(TARGETING::g_trac_targeting,
            ENTER_MRK"hb_find_rsvd_mem_label(0x%llX, %p)",
            i_label, i_hb_data_toc_addr);

        hbrtTableOfContents_t * toc_ptr = i_hb_data_toc_addr;
        switch(i_label)
        {
            case HBRT_MEM_LABEL_VPD:
            case HBRT_MEM_LABEL_ATTR:
            case HBRT_MEM_LABEL_ATTROVER:
            case HBRT_MEM_LABEL_PADDING:
            case HBRT_MEM_LABEL_HYPCOMM:
                // Find offset of label section
                for (uint16_t i = 0; i < toc_ptr->total_entries; i++)
                {
                    if (toc_ptr->entry[i].label == i_label)
                    {
                        l_label_data_addr =
                            reinterpret_cast<uint64_t>(i_hb_data_toc_addr) +
                                            toc_ptr->entry[i].offset;
                        o_size = toc_ptr->entry[i].size;
                        TRACFCOMP(TARGETING::g_trac_targeting,
                            "hb_find_rsvd_mem_label: "
                            "Entry found at offset 0x%.16llX, size %ld",
                            toc_ptr->entry[i].offset, o_size);
                        break;
                    }
                }

                if (0 == o_size)
                {
                    TRACFCOMP(TARGETING::g_trac_targeting,
                        "hb_find_rsvd_mem_label: Entry %.16llX not found",
                        i_label);
                }
                break;
            default:
                // unknown label?
                TRACFCOMP(TARGETING::g_trac_targeting,
                    "hb_find_rsvd_mem_label: unknown label 0x%.16llX",
                    i_label);
                break;
        }

        TRACFCOMP(TARGETING::g_trac_targeting,
            EXIT_MRK"hb_find_rsvd_mem_label(0x%.16llX, %lld) -> 0x%.16llX",
            i_label, o_size, l_label_data_addr);

        return l_label_data_addr;
    }

};
