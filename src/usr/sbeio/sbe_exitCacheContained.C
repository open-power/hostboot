/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_exitCacheContained.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

/**
 * @file sbe_exitCatcheContain.C
 * @brief SBE PSU Chip OP Messages to execute exit cache
 *        containment functionality on the SBE
 */

#include <fapi2.H>
#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>
#include <targeting/common/targetservice.H>
#include <sys/mm.h>     // mm_virt_to_phys
#include <errno.h>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"exitCacheContain: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"exitCacheContain: " printf_string,##args)


// Argument pointer lay-out
struct cacheContainedArgData_t
{
   fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> proc_target;
   size_t numEntries;
   std::pair<uint64_t, uint64_t> *xscom_inits;
   uint8_t  stepCommand;

};

namespace SBEIO
{

/**
 * @brief Send Exit Cache Contained Op to the SBE
 *
 * @param[in] i_argPtr  -- List of args passed from original HWP call
 * @param[in] i_argSize -- Size (bytes) of total args passed in
 *
 * @return errlHndl_t Error log handle on failure.
 *
 */

errlHndl_t sendExitCacheContainedOp(const uint8_t * i_argPtr,
                                    size_t   i_argSize)
{
    errlHndl_t l_errl = nullptr;

    SBE_TRACF(ENTER_MRK "sendExitCacheContainedOp");

#if DEBUG_TRACE
    for (uint32_t ii = 0; ii < i_argSize; ii++)
    {
        SBE_TRACF("sendExitCacheContainedOp - i_argPtr[%d] = 0x%.2X", ii, i_argPtr[ii]);
    }
#endif

    // Map input arg pointer into the expected
    // exit cache contained op datastructure
    const cacheContainedArgData_t * l_argPtr =
                reinterpret_cast<const cacheContainedArgData_t*>(i_argPtr);
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapiTarget
                                                 = l_argPtr->proc_target;
    TARGETING::Target * l_target = l_fapiTarget.get();
    std::pair<uint64_t, uint64_t> *l_xscom_inits = l_argPtr->xscom_inits;
    size_t l_numEntries = l_argPtr->numEntries;
    uint8_t l_stepCommand = l_argPtr->stepCommand;

    SBEIO::sbeAllocationHandle_t l_scomRegInitAllocation { };
    uint64_t l_alignedRegInitsPhysAddr = 0;

    // We don't have to allocate any memory for register inits when there are no
    // writes for the SBE to perform
    if (l_numEntries)
    {
        //Allocate and align memory due to SBE requirements
        void* l_sbeMemAlloc = nullptr;
        l_scomRegInitAllocation = sbeMalloc(sizeof(*l_xscom_inits)*l_numEntries,
                                            l_sbeMemAlloc);

        const auto l_alignedRegInits
            = static_cast<std::pair<uint64_t, uint64_t>*>(l_sbeMemAlloc);

        //Copy data from input data structure into aligned memory
        std::copy(l_xscom_inits,
                  l_xscom_inits + l_numEntries,
                  l_alignedRegInits);

        // SBE consumes a physical address. NOTE: We assume that the virtual
        // pages returned by malloc() are backed by contiguous physical pages.
        l_alignedRegInitsPhysAddr = mm_virt_to_phys(l_alignedRegInits);

        assert(static_cast<int>(l_alignedRegInitsPhysAddr) != -EFAULT,
               "sendExitCacheContainedOp: mm_virt_to_phys failed");
    }

    SBE_TRACF("Placed Xscom init data at address: 0x%lx", l_alignedRegInitsPhysAddr);

    //Create/Setup Exit Cache Contained Xscom Init PSU message
    SbePsu::psuCommand l_psuCommand(
                SbePsu::SBE_REQUIRE_RESPONSE |
                SbePsu::SBE_REQUIRE_ACK,                 //control flags
                SbePsu::SBE_PSU_CLASS_CORE_STATE,        //command class
                SbePsu::SBE_CMD_EXIT_CACHE_CONTAINED);   //command
    l_psuCommand.cd1_exitCacheContain_NumXscoms = l_numEntries;
    l_psuCommand.cd1_exitCacheContain_StepDetails = l_stepCommand;
    l_psuCommand.cd1_exitCacheContain_DataAddr = l_alignedRegInitsPhysAddr;

    // Create a PSU response message
    SbePsu::psuResponse l_psuResponse;

    do
    {
        // Make the call to perform the PSU Chip Operation
        l_errl = SbePsu::getTheInstance().performPsuChipOp(
                        l_target,
                        &l_psuCommand,
                        &l_psuResponse,
                        SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                        SbePsu::SBE_EXIT_CACHE_CONTAINED_REQ_USED_REGS,
                        SbePsu::SBE_EXIT_CACHE_CONTAINED_RSP_USED_REGS);

        if (l_errl)
        {
            l_errl->collectTrace(SBEIO_COMP_NAME);
            TRACFCOMP(g_trac_sbeio,
                      "sendExitCacheContainedOp: "
                      "Call to performPsuChipOp failed, error returned");

            break;
        }
    } while(0);

    //Free the Buffer
    sbeFree(l_scomRegInitAllocation);

    SBE_TRACF(EXIT_MRK "sendExitCacheContainedOp");

    return l_errl;
}

};
