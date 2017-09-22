/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilmclmgr.C $                                   */
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
#include <util/utilmclmgr.H>
#include <util/utillidmgr.H>
#include <util/util_reasoncodes.H>
#include "utilbase.H"
#include <sys/mm.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <initservice/initserviceif.H>

namespace MCL
{

const size_t MclCompSectionPadSize = 16;

// Defines to simplify list initialzer syntax
#define COMP_MSTCONT {0x4d,0x53,0x54,0x43,0x4f,0x4e,0x54}
#define COMP_POWERVM {0x50,0x4f,0x57,0x45,0x52,0x56,0x4d}
const ComponentID g_MclCompId = COMP_MSTCONT;
const ComponentID g_PowervmCompId = COMP_POWERVM;

////////////////////////////////////////////////////////////////////////////////
// CompInfo
////////////////////////////////////////////////////////////////////////////////

void CompInfo::print() const
{
    UTIL_FT("  - Flags: 0x%04X", flags);
    UTIL_FT("  - Mainstore Addr: 0x%llX", mainstoreAddr);
    UTIL_FT("  - Total Size: 0x%llX", totalSize);
    UTIL_FT("  - Protected Size: 0x%llX", protectedSize);
    UTIL_FT("  - Unprotected Size: 0x%llX", unprotectedSize);
    UTIL_FT("  - LidIds:");
    for (auto lidInfo : lidIds)
    {
        UTIL_FT("    - 0x%08X, size 0x%X", lidInfo.id, lidInfo.size);
    }
}

////////////////////////////////////////////////////////////////////////////////
// MasterContainerLidMgr
////////////////////////////////////////////////////////////////////////////////

MasterContainerLidMgr::MasterContainerLidMgr()
: iv_mclAddr(MCL_ADDR), iv_mclSize(MCL_SIZE), iv_tmpAddr(MCL_TMP_ADDR),
  iv_tmpSize(MCL_TMP_SIZE), iv_pMclVaddr(nullptr), iv_pTempVaddr(nullptr),
  iv_compInfoCache{}
{
    initMcl();
}

MasterContainerLidMgr::MasterContainerLidMgr(const void* i_pMcl,
                                             const size_t i_size)
: iv_mclAddr(MCL_ADDR), iv_mclSize(MCL_SIZE), iv_tmpAddr(MCL_TMP_ADDR),
  iv_tmpSize(MCL_TMP_SIZE), iv_pMclVaddr(nullptr), iv_pTempVaddr(nullptr),
  iv_compInfoCache{}
{
    initMcl(i_pMcl, i_size);
}

MasterContainerLidMgr::~MasterContainerLidMgr()
{
    // Release all address spaces
    releaseMem(iv_tmpAddr, iv_pTempVaddr);
}

void MasterContainerLidMgr::initMcl(const void* i_pMcl, const size_t i_mclSize)
{
    UTIL_FT(ENTER_MRK"MasterContainerLidMgr::initMcl");

    // Add MCL itself to Cache but don't add to comp order
    CompInfo l_compHdrInfo(CompFlags::SIGNED_PRE_VERIFY);
    LidInfo l_hdrLidInfo(Util::MCL_LIDID);
    l_compHdrInfo.lidIds.push_back(l_hdrLidInfo);
    iv_compInfoCache.insert(std::make_pair(g_MclCompId, l_compHdrInfo));

    // Initialize MCL address space
    initMem(iv_mclAddr, iv_mclSize, iv_pMclVaddr);

    if(i_pMcl != nullptr)
    {
        // set cached MCL pointer with custom MCL
        memcpy(iv_pMclVaddr, i_pMcl, i_mclSize);
    }
    else
    {
        // Load Lid
    }

    // Parse all Components in MCL
    parseMcl();

    // Initialize temporary space for processing lids
    initMem(iv_tmpAddr, iv_tmpSize, iv_pTempVaddr);

    UTIL_FT(EXIT_MRK"MasterContainerLidMgr::initMcl");
}

void MasterContainerLidMgr::releaseMem(const uint64_t i_physAddr,
                                       void *&io_pVaddr)
{
    UTIL_FT(ENTER_MRK"MasterContainerLidMgr::releaseMem");

    errlHndl_t l_errl = nullptr;
    assert(i_physAddr != 0, "MasterContainerLidMgr physical address to release cannot be 0");

    do {
    if ( io_pVaddr != nullptr)
    {
        int l_mm_rc = mm_block_unmap(io_pVaddr);
        if(l_mm_rc != 0)
        {
            UTIL_FT("Fail from mm_block_unmap for Mcl Mgr, rc=%d Addr 0x%.16llX",
                    l_mm_rc, i_physAddr);
            /*@
             * @errortype
             * @moduleid          Util::UTIL_MCL_REL_MEM
             * @reasoncode        Util::UTIL_MM_BLOCK_UNMAP_FAILED
             * @userdata1         Address being removed
             * @userdata2         rc from mm_block_unmap
             * @devdesc           Error calling mm_block_unmap for Mcl Mgr
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           Util::UTIL_MCL_REL_MEM,
                           Util::UTIL_MM_BLOCK_UNMAP_FAILED,
                           i_physAddr,
                           l_mm_rc,
                           true); //software callout
            l_errl->collectTrace(UTIL_COMP_NAME);
            break;
        }
        io_pVaddr = nullptr;
    }
    } while(0);

    if (l_errl)
    {
        uint64_t l_reasonCode = l_errl->reasonCode();
        errlCommit(l_errl,UTIL_COMP_ID);
        INITSERVICE::doShutdown(l_reasonCode);
    }

    UTIL_FT(EXIT_MRK"MasterContainerLidMgr::releaseMem");
}

void MasterContainerLidMgr::initMem(const uint64_t i_physAddr,
                                    const size_t i_size,
                                    void *&io_pVaddr)
{
    UTIL_FT(ENTER_MRK"MasterContainerLidMgr::initMem");

    errlHndl_t l_errl = nullptr;
    assert(i_physAddr != 0, "MasterContainerLidMgr physical address cannot be 0");

    do {
    //Check if we already initialized vm space
    if (io_pVaddr == nullptr)
    {
        io_pVaddr = mm_block_map(reinterpret_cast<void*>(i_physAddr), i_size);
        if(io_pVaddr == nullptr)
        {
            UTIL_FT("MasterContainerLidMgr::initMem mm_block_map failed for Addr 0x%.16llX and size=0x%X ",
                    i_physAddr, i_size);
            /*@
             * @errortype
             * @moduleid          Util::UTIL_MCL_INIT_MEM
             * @reasoncode        Util::UTIL_MM_BLOCK_MAP_FAILED
             * @userdata1         Address being allocated
             * @userdata2         Size of block allocation
             * @devdesc           Error calling mm_block_map for Mcl Mgr
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           Util::UTIL_MCL_INIT_MEM,
                           Util::UTIL_MM_BLOCK_MAP_FAILED,
                           i_physAddr,
                           i_size,
                           true); //software callout
            l_errl->collectTrace(UTIL_COMP_NAME);
            break;
        }
        memset(io_pVaddr, 0, i_size);
    }
    } while(0);

    if (l_errl)
    {
        uint64_t l_reasonCode = l_errl->reasonCode();
        errlCommit(l_errl,UTIL_COMP_ID);
        INITSERVICE::doShutdown(l_reasonCode);
    }

    UTIL_FT(EXIT_MRK"MasterContainerLidMgr::initMem");
}

void MasterContainerLidMgr::parseMcl()
{
    UTIL_FT(ENTER_MRK"MasterContainerLidMgr::parseMcl");

    assert(iv_pMclVaddr != nullptr);

    auto l_pMcl = reinterpret_cast<const uint8_t*>(iv_pMclVaddr);

    // Parse MCL header
    auto l_pMclHdr = reinterpret_cast<const MclHeader*>(l_pMcl);
    uint8_t l_totalComponents = l_pMclHdr->numComponents;
    uint32_t l_offsetToCompSection =  l_pMclHdr->offsetToCompSection;
    l_pMcl += l_offsetToCompSection;

    // Parse Each Component in MCL header
    for (uint8_t comp = 0; comp < l_totalComponents; ++comp)
    {
        auto l_pMclSec = reinterpret_cast<const MclCompSection*>(l_pMcl);

        // Construct Comp Info with a subset of information
        CompInfo l_compInfo (l_pMclSec->flags);

        // Parse all lids
        auto l_pId = l_pMclSec->lidArray;
        for (uint8_t lid = 0; lid < l_pMclSec->numLids; ++lid)
        {
            LidInfo l_lidInfo(*l_pId);
            l_compInfo.lidIds.push_back(l_lidInfo);
            l_pId++;
        }

        // Insert component into Comp Info Cache
        iv_compInfoCache.insert(std::make_pair(l_pMclSec->compId, l_compInfo));

        // Increment past current component
        l_pMcl +=  l_pMclSec->sizeCompList;
    }

    printCompInfoCache();

    UTIL_FT(EXIT_MRK"MasterContainerLidMgr::parseMcl");
}

void MasterContainerLidMgr::printCompInfoCache()
{
    UTIL_FT("> MCL Comp Info cache:");
    for (const auto &i : iv_compInfoCache)
    {
        UTIL_FBIN("- Comp Id:", &i.first, sizeof(ComponentID));
        i.second.print();
    }
}

} // end namespace MCL
