/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/bios_attr_accessors/bios_attr_setters.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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

/** @file  bios_attr_setters.C
 *  @brief This file contains the implementations of the functions that
 *         determines the value that needs to be set to a PLDM BIOS attribute
 *         Then uses the appropriate API from hb_bios_attrs.H to set it.
 */

// Local Module
#include <isteps/bios_attr_accessors/bios_attr_setters.H>

// Userspace Modules
#include <errl/errlmanager.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/pldm_errl.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <trace/interface.H>

using namespace TARGETING;

namespace ISTEP
{

uint64_t get_sys_memory_size()
{
    uint64_t l_memSizeGB = 0;
    // For each functional proc under the target find the configured memory
    TARGETING::TargetHandleList l_procList;
    TARGETING::getAllChips(l_procList, TARGETING::TYPE_PROC);

    for(auto l_proc : l_procList)
    {
        // This array will have an entry for each memory controller channel
        // under this processor target. The values are determined by the memory
        // grouping process in p10_mess_eff_grouping.
        auto l_procMemSizesBytes =
            l_proc->getAttrAsStdArr<TARGETING::ATTR_PROC_MEM_SIZES>();

        // Min size of an OCMB is 32 GB so it should be safe to divide by GB
        for(auto mcc_size_bytes : l_procMemSizesBytes)
        {
            l_memSizeGB += (mcc_size_bytes/GIGABYTE);
        }
    }

    return l_memSizeGB;
}

errlHndl_t get_huge_page_size(uint64_t &o_hugePageSizeGB)
{
    const auto l_sys = TARGETING::UTIL::assertGetToplevelTarget();
    const auto huge_page_size = l_sys->getAttr<ATTR_HUGE_PAGE_SIZE>();
    errlHndl_t l_errl = nullptr;
    switch(huge_page_size)
    {
        /* Translation is per Hypervisor Interface Data Specifications (HDAT Spec) */
        case TARGETING::HUGE_PAGE_SIZE_PAGE_IS_16_GB:
            o_hugePageSizeGB = 16;
            break;
        default:
            o_hugePageSizeGB = 0;
            break;
    }

    if(!o_hugePageSizeGB)
    {
        /*@
        * @errortype
        * @severity   ERRL_SEV_UNRECOVERABLE
        * @moduleid   ISTEP::MOD_BIOS_ATTR_SETTERS
        * @reasoncode ISTEP::RC_INVALID_HUGE_PAGE_SIZE
        * @userdata1  Value of ATTR_HUGE_PAGE_SIZE
        * @userdata2  unused
        * @devdesc    Software problem, bad data from BMC
        * @custdesc   A software error occurred during system boot
        */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               ISTEP::MOD_BIOS_ATTR_SETTERS,
                               ISTEP::RC_INVALID_HUGE_PAGE_SIZE,
                               huge_page_size,
                               0,
                               ErrlEntry::NO_SW_CALLOUT);
        PLDM::addBmcErrorCallouts(l_errl);
    }

    return l_errl;
}

void set_hb_max_number_huge_pages(std::vector<uint8_t>& io_string_table,
                                  std::vector<uint8_t>& io_attr_table,
                                  ISTEP_ERROR::IStepError & io_stepError)
{
    errlHndl_t l_errl = nullptr;
    uint64_t l_max_num_huge_pages = 0, l_mem_size_gb = 0, l_huge_page_size_gb = 0;

    // Lookup total system memory
    l_mem_size_gb = get_sys_memory_size();

    // Lookup the huge page size
    l_errl = get_huge_page_size(l_huge_page_size_gb);
    if(l_errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                "set_hb_max_number_huge_pages(): An error occurred getting "
                "the huge page size from the BMC. Set hb_max_number_huge_pages to 0");
        l_errl->collectTrace("ISTEPS_TRACE",256);
        errlCommit( l_errl, ISTEP_COMP_ID );
    }
    else
    {
        assert(l_huge_page_size_gb != 0,
               "get_huge_page_size should have generated an error if l_huge_page_size_gb is 0");
        l_max_num_huge_pages = l_mem_size_gb/l_huge_page_size_gb;
    }

    l_errl = PLDM::setMaxNumberHugePages(io_string_table,
                                         io_attr_table,
                                         l_max_num_huge_pages);
    if(l_errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                "set_hb_max_number_huge_pages(): An error occurred setting "
                "hb_max_number_huge_pages. Attempted to set hb_max_number_huge_pages to %ld",
                l_max_num_huge_pages);
        l_errl->collectTrace("ISTEPS_TRACE",256);
        errlCommit( l_errl, ISTEP_COMP_ID );
    }

    return;
}

void set_hb_effective_secure_version(std::vector<uint8_t>& io_string_table,
                                     std::vector<uint8_t>& io_attr_table,
                                     ISTEP_ERROR::IStepError & io_stepError)
{
    errlHndl_t l_errl = nullptr;
    const auto l_sys = TARGETING::UTIL::assertGetToplevelTarget();
    const auto l_sec_ver_num = l_sys->getAttr<ATTR_SECURE_VERSION_NUM>();

    l_errl = PLDM::setEffectiveSecureVersion(io_string_table,
                                             io_attr_table,
                                             l_sec_ver_num);
    if(l_errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
            "set_hb_effective_secure_version(): An error occurred setting hb_effective_secure_version to %ld",
            l_sec_ver_num);
        l_errl->collectTrace("ISTEPS_TRACE",256);
        errlCommit( l_errl, ISTEP_COMP_ID );
    }

    return;
}

void set_hb_cap_freq_mhz_min_max(std::vector<uint8_t>& io_string_table,
                                 std::vector<uint8_t>& io_attr_table,
                                 ISTEP_ERROR::IStepError & io_stepError)
{
    errlHndl_t l_errl = nullptr;
    const auto l_sys = TARGETING::UTIL::assertGetToplevelTarget();
    const auto l_min_freq = l_sys->getAttr<ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_ORIGINAL>();
    const auto l_max_freq = l_sys->getAttr<ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_ORIGINAL>();

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "set_hb_cap_freq_mhz_min_max(): original values (%ld to %ld)",
            l_min_freq, l_max_freq );
    l_errl = PLDM::setCapFreqMhzMin(io_string_table, io_attr_table, l_min_freq);
    if (l_errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
            "set_hb_cap_freq_mhz_min_max(): An error occurred setting hb_cap_freq_mhz_min to %ld",
            l_min_freq);
        l_errl->collectTrace("ISTEPS_TRACE",256);
        errlCommit( l_errl, ISTEP_COMP_ID );
    }
    l_errl = PLDM::setCapFreqMhzMax(io_string_table, io_attr_table, l_max_freq);
    if (l_errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
            "set_hb_cap_freq_mhz_min_max(): An error occurred setting hb_cap_freq_mhz_max to %ld",
            l_max_freq);
        l_errl->collectTrace("ISTEPS_TRACE",256);
        errlCommit( l_errl, ISTEP_COMP_ID );
    }
}



}
