/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/mem_utils.C $                                  */
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
#include <isteps/mem_utils.H>
#include <targeting/common/target.H>
#include <targeting/common/utilFilter.H>
#include <errl/hberrltypes.H>
#include <secureboot/smf_utils.H>
#include <stdint.h>

namespace ISTEP
{

/**
 * @brief Utility function to obtain the highest known address in the system
 */
uint64_t get_top_mem_addr()
{
    uint64_t l_top_addr = 0;

    do
    {
        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        TARGETING::getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);
        assert(l_cpuTargetList.size() != 0, "Empty proc list returned!");

        for (auto l_pProc : l_cpuTargetList)
        {
            l_top_addr = std::max(l_top_addr, get_top_mem_addr(l_pProc));
        }

    } while(0);

    return l_top_addr;
}

/**
 * @brief Utility function to obtain the highest known address in a given proc
 */
uint64_t get_top_mem_addr(const TARGETING::Target* i_proc)
{
    uint64_t l_top_addr = 0;

    assert(i_proc, "nullptr passed to get_top_mem_addr");
    assert(i_proc->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC,
           "Invalid target passed to get_top_mem_addr (need TYPE_PROC)");

    //Not checking success here as fail results in no change to
    // top_addr
    uint64_t l_mem_bases[8] = {0,};
    uint64_t l_mem_sizes[8] = {0,};
    i_proc->tryGetAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_mem_bases);
    i_proc->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_mem_sizes);

    for (size_t i=0; i< 8; i++)
    {
        if(l_mem_sizes[i]) //non zero means that there is memory present
        {
            l_top_addr = std::max(l_top_addr,
                                l_mem_bases[i] + l_mem_sizes[i]);
        }
    }

    return l_top_addr;
}

/**
 * @brief Utility function to obtain the lowest known address in the system
 */
uint64_t get_bottom_mem_addr()
{
    uint64_t l_bottom_addr = UINT64_MAX;

    do
    {
        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        TARGETING::getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        for (const auto l_pProc : l_cpuTargetList)
        {
            l_bottom_addr =std::min(l_bottom_addr,get_bottom_mem_addr(l_pProc));
        }
    }while(0);

    // There's no reason the lowest address should be the largest
    // 64 bit value
    assert(l_bottom_addr < UINT64_MAX,
           "Lowest address is maximum 64-bit value, probably have no memory");

    return l_bottom_addr;
}

/**
 * @brief Utility function to obtain the lowest known address in a given proc
 */
uint64_t get_bottom_mem_addr(const TARGETING::Target* i_proc)
{
    uint64_t l_bottom_addr = UINT64_MAX;

    assert(i_proc, "nullptr passed to get_bottom_mem_addr");
    assert(i_proc->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC,
           "Invalid target passed to get_bottom_mem_addr (need TYPE_PROC)");

    uint64_t l_mem_bases[8] = {};
    uint64_t l_mem_sizes[8] = {};
    assert(i_proc->tryGetAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_mem_bases),
           "Unable to get ATTR_PROC_MEM_BASES attribute");

    assert(i_proc->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_mem_sizes),
           "Unable to get ATTR_PROC_MEM_SIZES attribute");

    for (size_t i=0; i< 8; i++)
    {
        if(l_mem_sizes[i]) //non zero means that there is memory present
        {
            l_bottom_addr = std::min(l_bottom_addr, l_mem_bases[i]);
        }
    }

    return l_bottom_addr;
}

/**
 * @brief Utility function to obtain the highest known SMF base address on
 *        the system
 */
uint64_t get_top_smf_mem_addr()
{
    uint64_t l_top_addr = 0;
    // Get all functional proc chip targets
    TARGETING::TargetHandleList l_cpuTargetList;
    TARGETING::getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);
    assert(l_cpuTargetList.size() != 0, "Empty proc list returned!");

    for (const auto l_pProc : l_cpuTargetList)
    {
        l_top_addr = std::max(l_top_addr, get_top_smf_mem_addr(l_pProc));
    }

    return l_top_addr;
}

/**
 * @brief Utility function to obtain the highest SMF base address on the
 *        given proc
 */
uint64_t get_top_smf_mem_addr(const TARGETING::Target* i_proc)
{
    uint64_t l_top_addr = 0;

    assert(i_proc, "nullptr passed to get_top_smf_mem_addr");
    assert(i_proc->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC,
           "Invalid target passed to get_top_smf_mem_addr (need TYPE_PROC)");

    auto l_smf_bar =
                   i_proc->getAttr<TARGETING::ATTR_PROC_SMF_BAR_BASE_ADDR>();
    auto l_smf_size =
                   i_proc->getAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>();

    l_top_addr = l_smf_bar + l_smf_size;

    return l_top_addr;
}

/**
 * @brief Utility function to fetch the top of the HOMER memory;
 *        when SMF is enabled, the function will return the highest
 *        available SMF BAR on a proc, so the top of the HOMER memory
 *        will be pointed to the top of SMF memory, and all of the
 *        contents will be put in secure memory space. When SMF is not
 *        enabled, the function will return the highest known address
 *        on the system.
 */
uint64_t get_top_homer_mem_addr()
{
    uint64_t l_top_homer_addr = 0;
    do
    {
        if(SECUREBOOT::SMF::isSmfEnabled())
        {
            l_top_homer_addr = get_top_smf_mem_addr();
        }
        else
        {
            l_top_homer_addr = get_top_mem_addr();
        }

    }while(0);

    return l_top_homer_addr;
}

} // namespace ISTEP
