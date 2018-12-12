/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/nvram/nvram_interface.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <nvram/nvram_interface.H>
#include <nvram/import/nvram.h>
#include <nvram/nvram_reasoncodes.H>
#include <pnor/pnorif.H>

static bool g_is_nvram_checked = false;

namespace NVRAM_TRACE
{
    trace_desc_t * g_trac_nvram = nullptr;
    // NVRAM won't be read too often in hostboot, so 1KB should be enough.
    TRAC_INIT(&g_trac_nvram, NVRAM_COMP_NAME, KILOBYTE);
}

namespace NVRAM
{

const char TEST_KEY[]        = "test";
const char SMF_MEM_AMT_KEY[] = "smf_mem_amt";

/*
 * @brief Searches NVRAM partition for the i_key and puts the value in
 *        o_val. An error is returned if NVRAM can't be loaded or if
 *        it's formatted incorrectly.
 */
errlHndl_t nvramRead(const char* const i_key, const char*& o_val)
{
    errlHndl_t l_errl = nullptr;

    do {

    if(i_key == nullptr)
    {
        /*@ errorlog
         * @errortype     ERRL_SEV_UNRECOVERABLE
         * @moduleid      NVRAM::MOD_NVRAM_READ
         * @reasoncode    NVRAM::RC_NVRAM_READ_NULL_KEY
         * @devdesc       A nullptr was passed for i_key to nvramRead
         * @custdesc      Error occurred during system boot.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         NVRAM::MOD_NVRAM_READ,
                                         NVRAM::RC_NVRAM_READ_NULL_KEY,
                                         0,
                                         0);
        break;
    }

    if(!g_is_nvram_checked)
    {
        PNOR::SectionInfo_t l_nvramSectionInfo;
        l_errl = PNOR::getSectionInfo(PNOR::NVRAM, l_nvramSectionInfo);
        if(l_errl)
        {
            break;
        }

        // Skiboot function to check NVRAM for integrity.
        // This function will also populate the inner skiboot_part_hdr
        // pointer to point to the start of the NVRAM. nvram_query will
        // then attempt to index into skiboot_part_hdr to find the K/V
        // pairs.
        int l_rc = nvram_check(
                           reinterpret_cast<uint8_t*>(l_nvramSectionInfo.vaddr),
                           l_nvramSectionInfo.size);
        if(l_rc)
        {
           /*@ errorlog
            * @errortype       ERRL_SEV_INFORMATIONAL
            * @moduleid        NVRAM::MOD_NVRAM_READ
            * @reasoncode      NVRAM::RC_NVRAM_CHECK_FAILED
            * @userdata1       rc from nvram_check
            * @userdata2       NVRAM virtual address
            * @devdesc         nvram_check failed during an attempt to read the
            *                  NVRAM PNOR partition.
            * @custdesc        Error occurred during system boot.
            */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                             NVRAM::MOD_NVRAM_READ,
                                             NVRAM::RC_NVRAM_CHECK_FAILED,
                                             l_rc,
                                             l_nvramSectionInfo.vaddr);
            l_errl->collectTrace(NVRAM_COMP_NAME);
            l_errl->collectTrace(PNOR_COMP_NAME);
            break;
        }

        g_is_nvram_checked = true;
    }

    o_val = nvram_query(i_key);

    }while(0);

    return l_errl;
}

} // namespace NVRAM
