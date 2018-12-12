/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/smf/smf.C $                                */
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
#include <secureboot/smf.H>
#include <assert.h>
#include <targeting/common/target.H>
#include <targeting/common/utilFilter.H>

#include <trace/interface.H>
#include <initservice/isteps_trace.H>

#include <limits.h>
#include <secureboot/secure_reasoncodes.H>
#include <targeting/common/targetservice.H>
#include <secureboot/smf_utils.H>

#include <isteps/mem_utils.H>

namespace SMF_TRACE
{
    trace_desc_t* g_trac_smf = nullptr;
    TRAC_INIT(&g_trac_smf, SMF_COMP_NAME, 4*KILOBYTE);
}

namespace SECUREBOOT
{
namespace SMF
{

/**
 * @brief structure to define the relationships between the procs, the memory
 *        available behind the procs, the memory to be allocated as secure, and
 *        the flag indicating whether the proc still has memory that can be
 *        allocated
 */
struct ProcToMemAssoc
{
    TARGETING::Target* proc;
    uint64_t           memToAllocate;
    uint64_t           availableMem;
    bool               useProc;

    ProcToMemAssoc(TARGETING::Target* i_proc,
                   uint64_t i_memToAllocate,
                   uint64_t i_availableMem,
                   bool     i_useProc) :
                   proc(i_proc), memToAllocate(i_memToAllocate),
                   availableMem(i_availableMem), useProc(i_useProc)
    {
    }
};

/**
 * @brief helper function to return the total amount of memory available behind
 *        the given proc
 *
 * @param[in] i_proc the proc target to calculate the total memory for
 *
 * @return the total amount of memory, in bytes, available behind the input proc
 */
uint64_t getTotalProcMemSize(const TARGETING::Target* const i_proc)
{
    TARGETING::ATTR_PROC_MEM_SIZES_type l_procMemSizes = {};
    uint64_t l_totProcMem = 0;

    assert(i_proc->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_procMemSizes),
           "Could not get ATTR_PROC_MEM_SIZES from a proc target!");

    for(size_t i = 0; i < sizeof(l_procMemSizes)/sizeof(l_procMemSizes[0]); ++i)
    {
        l_totProcMem += l_procMemSizes[i];
    }

    return l_totProcMem;
}

/**
 * @brief helper function to turn SMF mode off at the system level.
 *        Not accessible to the outside world.
 *
 * @param[in] i_enabled boolean to indicate whether SMF should be enabled or not
 */
void setSmfEnabled(bool i_enabled)
{
    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    assert(l_sys != nullptr, "The top level target is nullptr!");
    l_sys->setAttr<TARGETING::ATTR_SMF_ENABLED>(i_enabled);
}

/**
 * @brief function to distribute the requested amount of memory between procs
 *        with available memory on the system
 *
 * @param[in] i_requestedSmfMemAmtInBytes the requested amount of secure memory
 *            to distribute between the procs (in bytes)
 *
 * @return nullptr: distribution was successful
 *         non-nullptr: an error occurred during distribution (the error will
 *         never be unrecoverable)
 */
errlHndl_t distributeSmfMem(uint64_t i_requestedSmfMemAmtInBytes)
{
    errlHndl_t l_errl = nullptr;

    do {

    if(i_requestedSmfMemAmtInBytes == 0)
    {
        TRACFCOMP(SMF_TRACE::g_trac_smf, "distributeSmfMem: Requested 0 memory amount; SMF mode will be turned off.");
        setSmfEnabled(false);
        break;
    }

    std::vector<struct ProcToMemAssoc>l_procToMemVec;

    // Get all the functional procs amongs which we will distribute the
    // requested SMF memory
    TARGETING::TargetHandleList l_procList;
    TARGETING::getAllChips(l_procList, TARGETING::TYPE_PROC, true);

    assert(l_procList.size(), "distributeSmfMem: no procs were found on the system");

    // Populate the vector of processor memory associations
    for(const auto l_proc : l_procList)
    {
        struct ProcToMemAssoc l_pToM(l_proc,
                                     0,
                                     getTotalProcMemSize(l_proc),
                                     true);

        // The proc with lowest address 0 needs to have 8GB subtracted from
        // the available mem. This is done to make sure that hostboot can
        // run on that proc.
        if(ISTEP::get_bottom_mem_addr(l_proc) == 0)
        {
            if(l_pToM.availableMem >= MIN_MEM_RESERVED_FOR_HB)
            {
                l_pToM.availableMem -= MIN_MEM_RESERVED_FOR_HB;
            }
            else
            {
                l_pToM.availableMem = 0;
            }
            TRACDCOMP(SMF_TRACE::g_trac_smf, "distributeSmfMem: memory behind proc 0x%x has been reduced by 0x%x", TARGETING::get_huid(l_proc), MIN_MEM_RESERVED_FOR_HB);
        }
        l_procToMemVec.push_back(l_pToM);
    }

    TRACFCOMP(SMF_TRACE::g_trac_smf, "distributeSmfMem: distributing 0x%.16llx requested memory.", i_requestedSmfMemAmtInBytes);

    int64_t l_remainingAmtToAllocate = i_requestedSmfMemAmtInBytes;
    uint64_t l_currChunkSize = MIN_SMF_MEMORY_AMT;
    bool l_doubleChunk = false;
    uint64_t l_allocatedSoFar = 0;
    uint64_t l_totalAllocated = 0;

    // Distribute the memory. Start allocating in multiple-of-two
    // increments of 256MB on each proc. Stop if we've allocated all (or more)
    // requested memory or ran out of procs to allocate the mem on.
    while(true)
    {
        for(auto& l_member : l_procToMemVec)
        {
            // This will be recalculated every loop.
            l_allocatedSoFar = 0;

            // Skip procs that were marked as not having any more memory
            if(l_member.useProc)
            {
                // We could have allocated all requested mem on the last proc.
                // The amount could be negative due to power-of-two rounding.
                if(l_remainingAmtToAllocate <= 0)
                {
                    break;
                }

                // Check if we can't fit the current chunk in the memory space
                // of the current proc.
                if(l_currChunkSize > l_member.availableMem)
                {
                    // The proc is out of memory; we can't use it any more
                    // in the allocation algorithm
                    l_member.useProc = false;
                    // We still need to allocate the current chunk to some other
                    // proc though, so don't increment the chunks for now.
                    l_doubleChunk = false;
                    TRACDCOMP(SMF_TRACE::g_trac_smf, "distributeSmfMem: proc 0x%x ran out of memory.", TARGETING::get_huid(l_member.proc));
                }
                else
                {
                    // Can fit the current chunk.
                    l_member.memToAllocate = l_currChunkSize;

                    // We were able to allocate; now double the next chunk
                    l_doubleChunk = true;
                }

                // Tally up the total amt of memory allocated so far.
                // We need to check this on each allocation (after each proc)
                // because we may have to stop mid way through the proc loop
                // when we've allocated all requested mem.
                for(const auto& l_proc : l_procToMemVec)
                {
                    l_allocatedSoFar += l_proc.memToAllocate;
                }

                if(l_doubleChunk)
                {
                    // Only calculate the remaining amt when we've successfully
                    // allocated a chunk (which will force the boolean to
                    // be true). If we could not allocate the chunk, then the
                    // remaining amount didn't change.
                    l_remainingAmtToAllocate = i_requestedSmfMemAmtInBytes
                                              - l_allocatedSoFar;
                }
            } // useProc
        } // l_member

        if(l_doubleChunk)
        {
            // Double the amt of mem we will try to allocate on the next
            // iteration of the while loop.
            l_currChunkSize = l_currChunkSize << 1;
        }

        // Find out if we still have procs remaining. If not, then the
        // user has requested too much memory to be allocated.
        uint8_t l_procsStillRemaining = 0;
        for(const auto& l_usableProc : l_procToMemVec)
        {
            l_procsStillRemaining |= l_usableProc.useProc;
        }

        // Commit the allocated memory to each proc
        if(!l_procsStillRemaining || l_remainingAmtToAllocate <= 0)
        {
            for(auto l_Proc : l_procToMemVec)
            {
                l_Proc.proc->
                    setAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>(
                        l_Proc.memToAllocate);
                l_totalAllocated += l_Proc.memToAllocate;
            }
            break;
        }
    } // while true

    uint64_t l_totMemOnSystem = 0; // For error handling below
    for(const auto l_proc : l_procList)
    {
        TRACFCOMP(SMF_TRACE::g_trac_smf, "distributeSmfMem: proc 0x%x SMF_BAR_SIZE = 0x%.16llx",
                  TARGETING::get_huid(l_proc),
                  l_proc->getAttr<TARGETING::ATTR_PROC_SMF_BAR_SIZE>());
        l_totMemOnSystem += getTotalProcMemSize(l_proc);
    }

    // Error conditions

    // 1) Could not allocate any memory. This may happen if the only memory
    // on the system is the 8GB behind master proc or if the user requested
    // 0 memory to be allocated
    if(l_totalAllocated == 0)
    {
        TRACFCOMP(SMF_TRACE::g_trac_smf, ERR_MRK"distributeSmfMem: could not allocate any SMF memory; SMF will be disabled.");
        /*@
        * @reasoncode SECUREBOOT::RC_COULD_NOT_ALLOCATE_SMF_MEM
        * @moduleid   SECUREBOOT::MOD_SMF_SPLIT_SMF_MEM
        * @severity   ERRORLOG::ERRL_SEV_PREDICTIVE
        * @userdata1  Requested amount of SMF memory
        * @userdata2  Total amount of mem available on the system
        * @devdesc    Could not allocate any requested SMF memory. The system
        *             may not have enough available memory.
        * @custdesc   Could not allocate any requested SMF memory.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                         SECUREBOOT::MOD_SMF_SPLIT_SMF_MEM,
                                         SECUREBOOT::RC_COULD_NOT_ALLOCATE_SMF_MEM,
                                         i_requestedSmfMemAmtInBytes,
                                         l_totMemOnSystem);
        l_errl->collectTrace(SMF_COMP_NAME);

        setSmfEnabled(false);
        break;
    }

    // 2) Allocated not the exact amount the user requested. This may happen
    // if we needed to round to the power-of-two multiple of 256 MB due to
    // the hardware restrictions, or if the user requested more/less memory
    // that could be allocated.
    if(i_requestedSmfMemAmtInBytes != l_totalAllocated)
    {
        TRACFCOMP(SMF_TRACE::g_trac_smf, "distributeSmfMem: could not allocate exactly 0x%.16llx SMF mem, allocated 0x%.16llx instead.", i_requestedSmfMemAmtInBytes, l_totalAllocated);
        /*@
        * @reasoncode SECUREBOOT::RC_ALLOCATED_NE_REQUESTED
        * @moduleid   SECUREBOOT::MOD_SMF_SPLIT_SMF_MEM
        * @severity   ERRORLOG::ERRL_SEV_INFORMATIONAL
        * @userdata1  Requested amount of SMF memory
        * @userdata2  Actual allocated amount of SMF memory
        * @devdesc    The amount of SMF memory alocated does not match
        *             the requested SMF memory amount. A rounding error
        *             may have occurred or there is not enough of memory
        *             on the system.
        * @custdesc   SMF secure memory allocation request altered to satisfy
        *             memory allocation rules.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         SECUREBOOT::MOD_SMF_SPLIT_SMF_MEM,
                                         SECUREBOOT::RC_ALLOCATED_NE_REQUESTED,
                                         i_requestedSmfMemAmtInBytes,
                                         l_totalAllocated);
        l_errl->collectTrace(SMF_COMP_NAME);
        break;
    }

    } while(0);

    return l_errl;
}

} // namespace SMF
} // namespace SECUREBOOT
