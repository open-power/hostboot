/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utilrsvdmem.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2019                        */
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
#ifndef UTILRSVDMEM_H
#define UTILRSVDMEM_H

#include <limits.h> // for KILOBYTE definition

namespace Util
{
    /**
     *  8-byte ascii entry labels for hbrt TOC
     */
    typedef uint64_t hbrt_mem_label_t;

    // Ascii label "VPD     " in hex
    constexpr hbrt_mem_label_t HBRT_MEM_LABEL_VPD       = 0x5650442020202020;

    // Ascii label "ATTR    " in hex
    constexpr hbrt_mem_label_t HBRT_MEM_LABEL_ATTR      = 0x4154545220202020;

    // Ascii label "ATTROVER" in hex
    constexpr hbrt_mem_label_t HBRT_MEM_LABEL_ATTROVER  = 0x415454524F564552;

    // Ascii label "PADDING " in hex
    constexpr hbrt_mem_label_t HBRT_MEM_LABEL_PADDING   = 0x50414444494E4720;

    // Ascii label "HYPCOMM " in hex
    constexpr hbrt_mem_label_t HBRT_MEM_LABEL_HYPCOMM   = 0x485950434f4d4d20;

    // Ascii label "TRACEBUF" in hex
    constexpr hbrt_mem_label_t HBRT_MEM_LABEL_TRACEBUF  = 0x5452414345425546;

    // Note : may be several sections of the format 'VPD_xxxx' if support
    //  other overrides in the future
    // Ascii label "VPD_"<blank> in hex
    constexpr hbrt_mem_label_t HBRT_MEM_LABEL_VPD_XXXX  = 0x5650445F00000000;
    // Mask off specific VPD label
    constexpr hbrt_mem_label_t HBRT_MEM_LABEL_VPD_MASK  = 0x00000000FFFFFFFF;


    /** @brief A 32 byte table of contents entry */
    struct hbrtTableOfContentsEntry_t
    {
        uint64_t label;             // ASCII HBRT_LABEL_x constants
        uint64_t size;              // data entry size in bytes
        uint64_t offset;            // offset into section
        uint64_t reserved;          // incase of future change
    } __attribute__ ((packed));

    // MAX ENTRIES = (4 KB - 64 byte header) / 32 bytes per entry = 126
    #define HBRT_TOC_MAX_ENTRIES \
                (((4*KILOBYTE) - 64) / sizeof(hbrtTableOfContentsEntry_t))

    // HBRT Reserved memory size for TRACEBUF
    constexpr uint64_t HBRT_RSVD_TRACEBUF_SIZE = (64*KILOBYTE);

    /** @brief A 4KB Table of Contents */
    struct hbrtTableOfContents_t
    {
        char toc_header[32];        // "Hostboot Table of Contents"
        uint8_t toc_version;        // version
        uint16_t total_entries;     // Total entries in TOC
        uint64_t total_size;        // Total data section size (64k aligned)
        uint8_t rsvd[21];           // reserved
        hbrtTableOfContentsEntry_t entry[HBRT_TOC_MAX_ENTRIES];
    } __attribute__ ((packed));

    // Versions of table of contents
    const uint8_t HBRT_TOC_VERSION_1 = 0x01;

    /**
     *  @brief Get the address of a label's section based on TOC
     *  @param[in] i_label              - HBRT_MEM_LABEL_... constant
     *  @param[in] i_hb_data_toc_addr   - pointer to the table of contents
     *  @param[out] o_size              - size of returned region in bytes
     *  @return virtual address of region or 0
     *  @platform FSP, OpenPOWER
     **/
    uint64_t hb_find_rsvd_mem_label(hbrt_mem_label_t i_label,
                                    hbrtTableOfContents_t * i_hb_data_toc_addr,
                                    uint64_t & o_size);

};

#endif // UTILRSVDMEM_H
