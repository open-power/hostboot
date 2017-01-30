/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/drtm.C $                               */
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

#include <stdint.h>
#include <config.h>
#include <builtins.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <algorithm>

#include <sys/mm.h>
#include <sys/task.h>
#include <util/align.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/commontargeting.H>
#include <arch/pirformat.H>
#include <initservice/mboxRegs.H>
#include <util/utilmbox_scratch.H>
#include <secureboot/settings.H>
#include <secureboot/service.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/drtm.H>

#include "../common/securetrace.H"

// Set to "1" to enable unit tracing
#if 0
  // Enable SB_UNIT
  #define TRACUCOMP(args...) TRACFCOMP(args)
  // Enable SB_UNIT_BIN
  #define TRACUBIN(args...) TRACFBIN(args)
#else
  #define TRACUCOMP(args...)
  #define TRACUBIN(args...)
#endif

// Makes the math more intuitive
#define BYTES_PER_MEGABYTE MEGABYTE

namespace SECUREBOOT
{

namespace DRTM
{

#ifdef CONFIG_DRTM_TRIGGERING

// RIT protection DRTM payload address in megabytes
// Use reserved area immediately before payload base
const uint32_t DRTM_RIT_PAYLOAD_PHYS_ADDR_MB = 256-1;

// RIT protection payload
const char DRTM_RIT_PAYLOAD[] = {'D','R','T','M'};

const char* const DRTM_RIT_LOG_TEXT = "DrtmPayload";

#endif

errlHndl_t discoverDrtmState(
    const INITSERVICE::SPLESS::MboxScratch7_t& i_scratchReg7,
    const INITSERVICE::SPLESS::MboxScratch8_t& i_scratchReg8)
{
    SB_ENTER("discoverDrtmState: i_scratchReg7=0x%08X, "
        "i_scratchReg8 = 0x%08X",
        i_scratchReg7.data32,i_scratchReg8.data32);

    errlHndl_t pError = nullptr;

    do
    {

    TARGETING::Target* pSysTarget = nullptr;
    TARGETING::targetService().getTopLevelTarget(pSysTarget);

    if(pSysTarget == nullptr)
    {
        // TODO: RTC 167205: GA error handling
        assert(false,"discoverDrtmState: BUG! nullptr system target detected.");
        break;
    }

    TARGETING::Target* pMasterProc = nullptr;
    pError = TARGETING::targetService().queryMasterProcChipTargetHandle(
                 pMasterProc);
    if(pError)
    {
        SB_ERR("discoverDrtmState: Failed in call to "
            "queryMasterProcChipTargetHandle().");
        break;
    }

    uint64_t securitySwitches = 0;
    pError = SECUREBOOT::getSecuritySwitch(securitySwitches,
                 pMasterProc);
    if(pError)
    {
        SB_ERR("discoverDrtmState: Failed in call to getSecuritySwitch() for "
            "proc = 0x%08X.",
            get_huid(pMasterProc));
        break;
    }

    const bool masterProcL4A = securitySwitches
        & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::L4ABit);
    const bool masterProcLQA = securitySwitches
        & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::LQABit);
    const bool masterProcLLP = securitySwitches
        & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::LLPBit);

    const bool drtmPayloadValid = i_scratchReg8.validDrtmPayloadAddr;
    const bool isMpiplBoot = pSysTarget->getAttr<TARGETING::ATTR_IS_MPIPL_HB>();
    const bool securebootEnabled = SECUREBOOT::enabled();

    SB_INF("discoverDrtmState: masterProcL4A = %d, drtmPayloadValid = %d, "
           "isMpiplBoot = %d, securebootEnabled = %d, "
           "masterProcLQA = %d, i_scratchReg7 = 0x%08X, "
           "masterProcLLP = %d.",
           masterProcL4A,drtmPayloadValid,isMpiplBoot,
           securebootEnabled,masterProcLQA,i_scratchReg7.drtmPayloadAddrMb,
           masterProcLLP);

    TARGETING::ATTR_IS_DRTM_MPIPL_HB_type drtmMpIpl = false;
    if(masterProcL4A || drtmPayloadValid)
    {
        // Note: We don't care if trusted boot is not enabled, if not, the
        // measurement will simply be ignored later
        if(   !masterProcL4A
           || !drtmPayloadValid
           || !isMpiplBoot
           || !securebootEnabled
           || !masterProcLQA
           || masterProcLLP)
        {
            // TODO: RTC 167205: GA error handling
            assert(false,"discoverDrtmState: BUG! Inconsistent DRTM state "
                "detected. masterProcL4A = %d, drtmPayloadValid = %d, "
                "isMpiplBoot = %d, securebootEnabled = %d, "
                "masterProcLQA = %d, masterProcLLP = %d.",
                masterProcL4A,drtmPayloadValid,isMpiplBoot,
                securebootEnabled,masterProcLQA,masterProcLLP);
            break;
        }
        else
        {
            drtmMpIpl = true;
        }
    }

    if(   drtmMpIpl
       && (i_scratchReg7.drtmPayloadAddrMb == 0))
    {
        // TODO: RTC 167205: GA error handling
        assert(false,"discoverDrtmState: BUG! DRTM payload address "
               "should not be 0 on a DRTM boot.");
        break;
    }

    const auto drtmPayloadAddrMb = drtmMpIpl ?
        i_scratchReg7.drtmPayloadAddrMb : 0;

    pSysTarget->setAttr<TARGETING::ATTR_IS_DRTM_MPIPL_HB>(drtmMpIpl);
    pSysTarget->setAttr<TARGETING::ATTR_DRTM_PAYLOAD_ADDR_MB_HB>(
        drtmPayloadAddrMb);

    // NOTE: It should be SBE job to clear the DRTM scratch regs
    // on any given non-DRTM boot flow, hence Hostboot never has to clear them.

    } while(0);

    if(pError)
    {
        SB_ERR("discoverDrtmState: plid=0x%08X, eid=0x%08X, reason=0x%04X",
               ERRL_GETPLID_SAFE(pError),
               ERRL_GETEID_SAFE(pError),
               ERRL_GETRC_SAFE(pError));
    }

    SB_EXIT("discoverDrtmState");

    return pError;
}

void isDrtmMpipl(bool& o_isDrtmMpipl)
{
    TARGETING::Target* pSysTarget = nullptr;
    TARGETING::targetService().getTopLevelTarget(pSysTarget);

    if(pSysTarget == nullptr)
    {
        // TODO: RTC 167205: GA error handling
        assert(false,"isDrtmMpipl: BUG! nullptr system target detected");
    }

    o_isDrtmMpipl = pSysTarget->getAttr<TARGETING::ATTR_IS_DRTM_MPIPL_HB>();
}

errlHndl_t validateDrtmHwSignature()
{
    SB_ENTER("validateDrtmHwSignature");

    errlHndl_t pError = nullptr;

    do
    {
        bool drtmMpIpl = false;
        isDrtmMpipl(drtmMpIpl);

        if(drtmMpIpl)
        {
            SB_DBG("validateDrtmHwSignature: DRTM active, checking L4A, LQA, "
                "SUL, LLS and LLP on node's functional proc chips.");

            TARGETING::TargetHandleList funcProcChips;
            TARGETING::getAllChips(funcProcChips,
                                   TARGETING::TYPE_PROC);
            for(auto &pFuncProc :funcProcChips)
            {
                uint64_t securitySwitches = 0;
                pError = SECUREBOOT::getSecuritySwitch(securitySwitches,
                             pFuncProc);
                if(pError)
                {
                    SB_ERR("validateDrtmHwSignature: getSecuritySwitch() "
                        "failed for proc = 0x%08X.",
                        get_huid(pFuncProc));
                    break;
                }

                const bool L4A = securitySwitches
                    & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::L4ABit);
                const bool LQA = securitySwitches
                    & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::LQABit);
                const bool SUL = securitySwitches
                    & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::SULBit);
                const bool LLP = securitySwitches
                    & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::LLPBit);
                const bool LLS = securitySwitches
                    & static_cast<uint64_t>(SECUREBOOT::ProcSecurity::LLSBit);

                SB_INF("validateDrtmHwSignature: Proc 0x%08X has L4A = %d, "
                    "LQA = %d, SUL = %d, LLP = %d, LLS = %d.",
                    get_huid(pFuncProc),L4A,LQA,SUL,LLP,LLS);

                if(!L4A || !LQA || !SUL || LLP || LLS)
                {
                    // TODO: RTC 167205: GA error handling, including whether
                    // to attempt on every processor
                    assert(false,"validateDrtmHwSignature: BUG! In DRTM flow, "
                        "all functional proc chips should have L4A, LQA, and "
                        "SUL set + LLP and LLS clear, however proc 0x%08X has "
                        "L4A = %d, LQA = %d, SUL = %d, LLP = %d, LLS = %d.",
                        get_huid(pFuncProc),L4A,LQA,SUL,LLP,LLS);
                    break;
                }
            }

            if(pError)
            {
                break;
            }
        }
        else
        {
            SB_INF("validateDrtmHwSignature: DRTM not active, skipping check "
                "for L4A, LQA, SUL, LLP and LLS on node's functional procs");
        }

    } while(0);

    if(pError)
    {
        SB_ERR("validateDrtmHwSignature:  plid=0x%08X, eid=0x%08X, "
            "reason=0x%04X",
            ERRL_GETPLID_SAFE(pError),
            ERRL_GETEID_SAFE(pError),
            ERRL_GETRC_SAFE(pError));
    }

    SB_EXIT("validateDrtmHwSignature");

    return pError;
}

errlHndl_t validateDrtmPayload()
{
    SB_ENTER("validateDrtmPayload");

    errlHndl_t pError = nullptr;
    const void* drtmPayloadVirtAddr = nullptr;

    do
    {
        bool drtmMpIpl = false;
        isDrtmMpipl(drtmMpIpl);

        if(drtmMpIpl)
        {
            SB_DBG("validateDrtmPayload: DRTM active, validating DRTM payload."
                "proc chips.");

            TARGETING::Target* pSysTarget = nullptr;
            TARGETING::targetService().getTopLevelTarget(pSysTarget);

            if(pSysTarget == nullptr)
            {
                // TODO: RTC 167205: GA error handling
                assert(false,"validateDrtmPayload: BUG! nullptr system target "
                    "detected");
                break;
            }

            const auto drtmPayloadPhysAddrMb = pSysTarget->getAttr<
                TARGETING::ATTR_DRTM_PAYLOAD_ADDR_MB_HB>();

            if(drtmPayloadPhysAddrMb == 0)
            {
                assert(false,"validateDrtmPayload: BUG! DRTM payload physical "
                    "address should not be 0.");
                break;
            }

            const uint64_t drtmPayloadPhysAddr =
                drtmPayloadPhysAddrMb*BYTES_PER_MEGABYTE;

            SB_INF("validateDrtmPayload: DRTM payload available at physical "
                "address of %d MB (0x%16llX).",
                drtmPayloadPhysAddrMb,drtmPayloadPhysAddr);

            // Compute DRTM payload size
            // TODO: RTC 167205: Once the DRTM save area is known/defined,
            // need to figure out a better initial size to map.  For example,
            // perhaps we map just one page to begin with, in order to read out
            // the actual total size.  Also, a size is available, assert if the
            // size is 0.
            uint64_t drtmPayloadSize = 0;
            #ifdef CONFIG_DRTM_TRIGGERING
            drtmPayloadSize = ALIGN_PAGE(sizeof(DRTM_RIT_PAYLOAD));
            #endif

            // Map in the physical memory to virtual memory
            drtmPayloadVirtAddr = mm_block_map (
                reinterpret_cast<void*>(drtmPayloadPhysAddr),drtmPayloadSize);
            if(drtmPayloadVirtAddr == nullptr)
            {
                // TODO: RTC 167205: GA error handling
                assert(false,"validateDrtmPayload: BUG! mm_block_map returned "
                    "nullptr for physical address 0x%016llX and size "
                    "0x%016llX.",
                    drtmPayloadPhysAddr,drtmPayloadSize);
                break;
            }

            #ifdef CONFIG_DRTM_TRIGGERING

            // Verify the payload matches expected result
            if(memcmp(drtmPayloadVirtAddr,DRTM_RIT_PAYLOAD,
                   sizeof(DRTM_RIT_PAYLOAD) != 0))
            {
                const uint32_t* pAddrAct = reinterpret_cast<const uint32_t*>(
                    drtmPayloadVirtAddr);
                const uint32_t* pAddrExp = reinterpret_cast<const uint32_t*>(
                    &DRTM_RIT_PAYLOAD);

                SB_ERR("validateDrtmPayload: DRTM RIT: payload content at "
                    "0x%16llX was not as expected.  Expected value = 0x%08X, "
                    "actual = 0x%08X",
                    drtmPayloadVirtAddr,
                    *pAddrAct,
                    *pAddrExp);

                // TODO: RTC 167205: GA error handling
                assert(false,"validateDrtmPayload: BUG: DRTM payload content "
                    "at 0x%16llX was not as expected.  Expected value = "
                    "0x%08X, actual = 0x%08X",
                    drtmPayloadVirtAddr,
                    *pAddrAct,
                    *pAddrExp);
                break;
            }

            // Extend (arbitrary) measurement to PCR17
            SHA512_t hash = {0};
            memcpy(hash,DRTM_RIT_PAYLOAD,sizeof(DRTM_RIT_PAYLOAD));
            pError = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_DRTM_17, hash,
                                          sizeof(SHA512_t),DRTM_RIT_LOG_TEXT);
            if(pError)
            {
                SB_ERR("validateDrtmPayload: Failed in pcrExtend() for PCR 17");
                break;
            }

            #else

            // TODO: RTC 167205: Securely verify the measured launch environment
            // TODO: RTC 167205: Really measure+extend the payload

            #endif
        }
        else
        {
            SB_INF("validateDrtmPayload: DRTM not active, skipping DRTM "
                "payload verification ");
        }

    } while(0);

    if(drtmPayloadVirtAddr)
    {
        auto rc = mm_block_unmap(const_cast<void*>(drtmPayloadVirtAddr));
        if(rc != 0)
        {
            // TODO: RTC 167205: GA error handling
            assert(false,"validateDrtmPayload: BUG! mm_block_unmap failed for "
                "virtual address 0x%16llX.",
                drtmPayloadVirtAddr);

        }
    }

    if(pError)
    {
        SB_ERR("validateDrtmPayload: plid=0x%08X, eid=0x%08X, reason=0x%04X",
               ERRL_GETPLID_SAFE(pError),
               ERRL_GETEID_SAFE(pError),
               ERRL_GETRC_SAFE(pError));
    }

    SB_EXIT("validateDrtmPayload");

    return pError;
}

errlHndl_t completeDrtm()
{
    SB_ENTER("completeDrtm");

    errlHndl_t pError = nullptr;

    do
    {
        bool drtmMpIpl = false;
        isDrtmMpipl(drtmMpIpl);

        if(drtmMpIpl)
        {
            SB_INF("completeDrtm: Clearing L4A and LQA on node's functional "
                   "proc chips.");

            const std::vector<SECUREBOOT::ProcSecurity> bitsToClear {
                SECUREBOOT::ProcSecurity::L4ABit,
                SECUREBOOT::ProcSecurity::LQABit
            };

            TARGETING::TargetHandleList funcProcChips;
            TARGETING::getAllChips(funcProcChips,
                                   TARGETING::TYPE_PROC);

            for(auto &pFuncProc :funcProcChips)
            {
                pError = SECUREBOOT::clearSecuritySwitchBits(bitsToClear,
                             pFuncProc);
                if(pError)
                {
                    // TODO: RTC 167205: GA error handling to attempt on every
                    // processor
                    SB_ERR("completeDrtm: clearSecuritySwitchBits() failed for "
                        "proc = 0x%08X. Tried to clear LQA + L4A.",
                        get_huid(pFuncProc));
                    break;
                }
            }

            if(pError)
            {
                break;
            }

        }
        else
        {
            SB_INF("completeDrtm: DRTM not active, not clearing LQA or L4A "
                "bits.");
        }

    } while(0);

    if(pError)
    {
        SB_ERR("completeDrtm: plid=0x%08X, eid=0x%08X, reason=0x%04X",
               ERRL_GETPLID_SAFE(pError),
               ERRL_GETEID_SAFE(pError),
               ERRL_GETRC_SAFE(pError));
    }

    SB_EXIT("completeDrtm");

    return pError;
}

#ifdef CONFIG_DRTM_TRIGGERING

errlHndl_t initiateDrtm()
{
    SB_ENTER("initiateDrtm");

    errlHndl_t pError = nullptr;

    // For DRTM, the thread has to be pinned to a core (and therefore pinned to
    // a chip)
    task_affinity_pin();

    void* drtmPayloadVirtAddr = nullptr;

    do
    {
        const std::vector<SECUREBOOT::ProcSecurity> LLP {
            SECUREBOOT::ProcSecurity::LLPBit,
        };

        const std::vector<SECUREBOOT::ProcSecurity> LLS {
            SECUREBOOT::ProcSecurity::LLSBit,
        };

        // Determine which fabric group and chip this task is executing on and
        // create a filter to find the matching chip target
        auto cpuId = task_getcpuid();
        auto groupId = PIR_t::groupFromPir(cpuId);
        auto chipId = PIR_t::chipFromPir(cpuId);
        TARGETING::PredicateAttrVal<TARGETING::ATTR_FABRIC_GROUP_ID>
            matchesGroup(groupId);
        TARGETING::PredicateAttrVal<TARGETING::ATTR_FABRIC_CHIP_ID>
            matchesChip(chipId);
        TARGETING::PredicatePostfixExpr matchesGroupAndChip;
        matchesGroupAndChip.push(&matchesGroup).push(&matchesChip).And();

        // Get all the functional proc chips and find the chip we're running on
        TARGETING::TargetHandleList funcProcChips;
        TARGETING::getAllChips(funcProcChips,
                               TARGETING::TYPE_PROC);
        if(funcProcChips.empty())
        {
            // TODO: RTC 167205: GA error handling
            assert(false,"initiateDrtm: BUG! Functional proc chips is empty, "
                "yet this code is running on a functional chip!");
            break;
        }

        // NOTE: std::find_if requires predicates to be copy constructable, but
        // predicates are not; hence use a wrapper lambda function to bypass
        // that limitation
        auto pMatch =
            std::find_if(funcProcChips.begin(),funcProcChips.end(),
                [&matchesGroupAndChip] ( TARGETING::Target* pTarget )
                {
                    return matchesGroupAndChip(pTarget);
                } );

        if(pMatch == funcProcChips.end())
        {
            // TODO: RTC 167205: GA error handling
            assert(false, "initiateDrtm: BUG! No functional chip found "
                "to be running this code");
            break;
        }

        // Move the matching target to the end of the list.
        // NOTE: If reverse iterators were supported, we could have verified the
        // last element of the container is not the match, and done a
        // std::iter_swap of the match and the last element
        TARGETING::Target* const pMatchTarget = *pMatch;
        funcProcChips.erase(pMatch);
        funcProcChips.push_back(pMatchTarget);

        // Map to the DRTM payload area in mainstore
        const uint32_t drtmPayloadPhysAddrMb = DRTM_RIT_PAYLOAD_PHYS_ADDR_MB;
        drtmPayloadVirtAddr = mm_block_map(
            reinterpret_cast<void*>(drtmPayloadPhysAddrMb*BYTES_PER_MEGABYTE),
            PAGESIZE);
        if(drtmPayloadVirtAddr == nullptr)
        {
            // TODO: RTC 167205: GA error handling
            assert(false, "initiateDrtm: BUG! Failed in call to mm_block_map "
                "to map the DRTM payload.");
            break;
        }

        // Copy the DRTM payload to the DRTM payload area
        memcpy(
            reinterpret_cast<uint32_t*>(drtmPayloadVirtAddr),
            DRTM_RIT_PAYLOAD,
            sizeof(DRTM_RIT_PAYLOAD));

        // The required generic sequencing to initiate DRTM is as follows:
        // 1) Initiating task must pin itself to a core (to ensure it
        //     will not be accidentally queisced by SBE)
        // 2) It must set the DRTM payload information in the master processor
        //     mailbox scratch registers (registers 7 and 8) before it goes
        //     offline
        // 3) It must determine the processor it's currently running on
        // 4) It must set the late launch bit (LL) on all other processors
        //     4a) If the given processor is an active master, it must set
        //         late launch primary (LLP) bit
        //     4b) Otherwise it must set late launch secondary (LLS) bit
        // 5) Finally, it must its own processor's LL bit last, according to the
        //     rules of step 4.
        for(auto &pFuncProc :funcProcChips)
        {
            const auto procMasterType = pFuncProc->getAttr<
                TARGETING::ATTR_PROC_MASTER_TYPE>();

            // If master chip, set the DRTM payload address and validity
            if(procMasterType == TARGETING::PROC_MASTER_TYPE_ACTING_MASTER)
            {
                (void)setDrtmPayloadPhysAddrMb(drtmPayloadPhysAddrMb);
            }

            pError = SECUREBOOT::setSecuritySwitchBits(procMasterType ==
                         TARGETING::PROC_MASTER_TYPE_ACTING_MASTER ?
                            LLP : LLS,
                         pFuncProc);
            if(pError)
            {
                SB_ERR("initiateDrtm: setSecuritySwitchBits() failed for proc "
                    "= 0x%08X. Tried to set LLP or LLS.",
                    get_huid(pFuncProc));
                break;
            }
        }

        if(pError)
        {
            break;
        }


        SB_INF("initiateDrtm: SBE should eventually quiesce all cores; until "
            "then, endlessly yield the task");
        while(1)
        {
            task_yield();
        }

    } while(0);

    // If we -do- come back from this function (on error path only), then we
    // should unpin
    task_affinity_unpin();

    if(drtmPayloadVirtAddr)
    {
        auto rc = mm_block_unmap(const_cast<void*>(drtmPayloadVirtAddr));
        if(rc != 0)
        {
            // TODO: RTC 167205: GA error handling
            assert(false,"initiateDrtm: BUG! mm_block_unmap failed for virtual "
                "address 0x%16llX.",
                drtmPayloadVirtAddr);
        }
    }

    if(pError)
    {
        SB_ERR("initiateDrtm: plid=0x%08X, eid=0x%08X, reason=0x%04X",
               ERRL_GETPLID_SAFE(pError),
               ERRL_GETEID_SAFE(pError),
               ERRL_GETRC_SAFE(pError));
    }

    SB_EXIT("initiateDrtm");

    return pError;
}

void setDrtmPayloadPhysAddrMb(
    const uint32_t i_drtmPayloadPhysAddrMb)
{
    // Set the address
    Util::writeScratchReg(
        INITSERVICE::SPLESS::MBOX_SCRATCH_REG7,i_drtmPayloadPhysAddrMb);

    // Mark as valid if non-0, else invalid
    INITSERVICE::SPLESS::MboxScratch8_t scratch8 =
        { .data32 = Util::readScratchReg(
             INITSERVICE::SPLESS::MBOX_SCRATCH_REG8) };
    scratch8.validDrtmPayloadAddr =
        i_drtmPayloadPhysAddrMb ? true : false;
    Util::writeScratchReg(
        INITSERVICE::SPLESS::MBOX_SCRATCH_REG8,scratch8.data32);
}

#endif // CONFIG_DRTM_TRIGGERING

} // End DRTM namespace

} // End SECUREBOOT namespace

