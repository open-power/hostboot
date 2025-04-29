/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbe/errlud_sbe.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2025                             */
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
#include "errlud_sbe.H"
#include <sbe/sbereasoncodes.H>
#include <p10_ipl_image.H>
#include <trace/interface.H>

constexpr uint8_t NUM_SECTIONS = P9_XIP_SECTIONS_SBE;
constexpr uint8_t SECT_NAME_SIZE = 16;

extern trace_desc_t* g_trac_sbe;
extern const char* g_sectionNamesSbe[NUM_SECTIONS];

namespace SBE
{

//------------------------------------------------------------------------------
//  SBE XIP section size User Details
//------------------------------------------------------------------------------
UdXIPSectionSizeParms::UdXIPSectionSizeParms(const void * i_image)
{
    // Set up Ud instance variables
    iv_CompId = SBE_COMP_ID;
    iv_Version = 0;
    iv_SubSection = SBE_UDT_XIP_SECTION_SIZES;

    //***** Memory Layout *****
    // 4 Bytes  :  Num sections
    // For Num sections:
    //      16 Bytes : XIP section name
    //      4 Bytes  : XIP section size

    const size_t l_entrySize = sizeof(char[SECT_NAME_SIZE]) + sizeof(uint32_t);
    const size_t l_bufSize = l_entrySize * NUM_SECTIONS + sizeof(uint32_t);
    char * l_pBuf = reinterpret_cast<char *>(reallocUsrBuf(l_bufSize));

    // set beginning of buf to num sections
    uint32_t num_sections = NUM_SECTIONS;
    memcpy(l_pBuf, &num_sections, sizeof(uint32_t));

    for (int id = 0; id < NUM_SECTIONS; ++id)
    {
        P9XipSection l_xipSection;
        uint8_t xip_rc;

        // get xip section
        p9_xip_section_sbe_t l_section = (p9_xip_section_sbe_t)id;
        memset(&l_xipSection, 0, sizeof(l_xipSection));
        xip_rc = p9_xip_get_section(i_image, l_section, &l_xipSection);

        // get section name str
        char l_section_str[40] = {};
        strcpy(l_section_str, P9_XIP_SECTION_NAME(g_sectionNamesSbe, l_section));

        // truncate section name to fit better, skip "." at start of each name
        char l_section_str_trunc[SECT_NAME_SIZE] = {};
        memcpy(&l_section_str_trunc, &l_section_str[1],
                std::min(sizeof(l_section_str_trunc), strlen(l_section_str)-1));

        // Check the return code and move data to buffer
        char * l_pCurData = l_pBuf + sizeof(uint32_t) + id*l_entrySize;
        memcpy(l_pCurData, &l_section_str_trunc, sizeof(l_section_str_trunc));

        // if no error move size to buffer otherwise use 0xFF...
        if (xip_rc == 0)
        {
            memcpy(l_pCurData + sizeof(l_section_str_trunc), &l_xipSection.iv_size, sizeof(uint32_t));

            TRACDCOMP(g_trac_sbe, "UdXIPSectionSizeParms(): "
                "p9_xip_get_section %s found of size 0x%X (rc=0x%X)",
                l_section_str, l_xipSection.iv_size, xip_rc);
        }
        else
        {
            memset(l_pCurData + sizeof(l_section_str_trunc), 0xFF, sizeof(uint32_t));

            TRACDCOMP(g_trac_sbe, "UdXIPSectionSizeParms(): "
                    "p9_xip_get_section NOT FOUND (rc=0x%X) "
                    "(id=%d)",
                    xip_rc, id);
        }
    }
}

//------------------------------------------------------------------------------
UdXIPSectionSizeParms::~UdXIPSectionSizeParms()
{
}

} // end SBE namespace
