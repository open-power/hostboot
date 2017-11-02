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
#include <secureboot/trustedbootif.H>
#include <runtime/preverifiedlidmgr.H>
#include <limits.h>
#include <util/utiltce.H>

namespace MCL
{

const size_t MclCompSectionPadSize = 16;

const ComponentID g_MclCompId {"MSTCONT"};
const ComponentID g_PowervmCompId {"POWERVM"};

void compIdToString(const ComponentID i_compId, CompIdString o_compIdStr)
{
    memcpy(o_compIdStr,
           i_compId.data(),
           sizeof(ComponentID));
}

uint64_t compIdToInt(const ComponentID i_compId)
{
    uint64_t l_compId {};

    memcpy(&l_compId, i_compId.data(), sizeof(l_compId));

    return l_compId;
}

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
  iv_tmpSize(MCL_TMP_SIZE), iv_maxSize(0), iv_pMclVaddr(nullptr),
  iv_pTempVaddr(nullptr), iv_pVaddr(nullptr), iv_compInfoCache{},
  iv_hasHeader(true)
{
    initMcl();
}

MasterContainerLidMgr::MasterContainerLidMgr(const void* i_pMcl,
                                             const size_t i_size)
: iv_mclAddr(MCL_ADDR), iv_mclSize(MCL_SIZE), iv_tmpAddr(MCL_TMP_ADDR),
  iv_tmpSize(MCL_TMP_SIZE), iv_maxSize(0), iv_pMclVaddr(nullptr),
  iv_pTempVaddr(nullptr), iv_pVaddr(nullptr), iv_compInfoCache{},
  iv_hasHeader(false)
{
    initMcl(i_pMcl, i_size);
}

MasterContainerLidMgr::~MasterContainerLidMgr()
{
    // Release all address spaces
    releaseMem(iv_tmpAddr, iv_pMclVaddr);
    releaseMem(iv_tmpAddr, iv_pTempVaddr);
}

void MasterContainerLidMgr::initMcl(const void* i_pMcl, const size_t i_mclSize)
{
    UTIL_DT(ENTER_MRK"MasterContainerLidMgr::initMcl");

    errlHndl_t l_errl = nullptr;

    // Add MCL itself to Cache but don't add to comp order
    CompInfo l_compHdrInfo(CompFlags::SIGNED_PRE_VERIFY);
    LidInfo l_hdrLidInfo(Util::MCL_LIDID);
    l_compHdrInfo.lidIds.push_back(l_hdrLidInfo);
    iv_compInfoCache.insert(std::make_pair(g_MclCompId, l_compHdrInfo));

    // Cache Component ID string
    compIdToString(g_MclCompId, iv_curCompIdStr);

    // Initialize MCL address space
    initMem(iv_mclAddr, iv_mclSize, iv_pMclVaddr);

    // Use MCL address and size for parsing
    iv_pVaddr = iv_pMclVaddr;
    iv_maxSize = iv_mclSize;

    if(i_pMcl != nullptr)
    {
        // set cached MCL pointer with custom MCL
        memcpy(iv_pMclVaddr, i_pMcl, i_mclSize);
    }
    else
    {
        // No custom MCL, load default way
        l_errl = processComponent(g_MclCompId,
                                  iv_compInfoCache.at(g_MclCompId));
        if (l_errl)
        {
            uint64_t l_reasonCode = l_errl->reasonCode();
            UTIL_FT(ERR_MRK"MasterContainerLidMgr::initMcl failed to process MCL shutting down rc=0x%08X",
                    l_reasonCode);
            errlCommit(l_errl,UTIL_COMP_ID);
            INITSERVICE::doShutdown(l_reasonCode);
        }
    }

    // Parse all Components in MCL
    parseMcl();

    // Initialize temporary space for processing other components
    initMem(iv_tmpAddr, iv_tmpSize, iv_pTempVaddr);

    // Switch to temp address and size for all other components
    iv_pVaddr = iv_pTempVaddr;
    iv_maxSize = iv_tmpSize;

    UTIL_DT(EXIT_MRK"MasterContainerLidMgr::initMcl");
}

void MasterContainerLidMgr::releaseMem(const uint64_t i_physAddr,
                                       void *&io_pVaddr)
{
    UTIL_DT(ENTER_MRK"MasterContainerLidMgr::releaseMem");

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
        UTIL_FT(ERR_MRK"MasterContainerLidMgr::releaseMem failed to release memory rc=0x%08X",
                l_reasonCode);
        errlCommit(l_errl,UTIL_COMP_ID);
        INITSERVICE::doShutdown(l_reasonCode);
    }

    UTIL_DT(EXIT_MRK"MasterContainerLidMgr::releaseMem");
}

void MasterContainerLidMgr::initMem(const uint64_t i_physAddr,
                                    const size_t i_size,
                                    void *&io_pVaddr)
{
    UTIL_DT(ENTER_MRK"MasterContainerLidMgr::initMem");

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
        UTIL_FT(ERR_MRK"MasterContainerLidMgr::initMem failed to initialize memory rc=0x%08X",
                l_reasonCode);
        errlCommit(l_errl,UTIL_COMP_ID);
        INITSERVICE::doShutdown(l_reasonCode);
    }

    UTIL_DT(EXIT_MRK"MasterContainerLidMgr::initMem");
}

void MasterContainerLidMgr::parseMcl()
{
    UTIL_FT(ENTER_MRK"MasterContainerLidMgr::parseMcl");

    assert(iv_pMclVaddr != nullptr);

    auto l_pMcl = reinterpret_cast<const uint8_t*>(iv_pMclVaddr);

    // If MCL has a header make sure to skip over it for parsing
    if (iv_hasHeader)
    {
        l_pMcl += PAGESIZE;
    }

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

errlHndl_t MasterContainerLidMgr::processComponents()
{
    errlHndl_t l_errl = nullptr;

    for (auto & compInfoPair : iv_compInfoCache)
    {
        // Skip the MCL itself as it's already been processed
        if (compInfoPair.first == g_MclCompId)
        {
            continue;
        }

        // Cache Component ID string
        compIdToString(compInfoPair.first, iv_curCompIdStr);

        l_errl = processComponent(compInfoPair.first, compInfoPair.second);
        if (l_errl)
        {
            UTIL_FT(ERR_MRK"MasterContainerLidMgr::processComponents - failed for componentId %s",
                    iv_curCompIdStr);
            break;
        }
        // Print Comp Info after loading lid and verifying
        UTIL_FT("MasterContainerLidMgr::processComponents %s Info",
                iv_curCompIdStr);
        iv_compInfoCache.at(compInfoPair.first).print();
    }

    return l_errl;
}

errlHndl_t MasterContainerLidMgr::processComponent(const ComponentID& i_compId,
                                                   CompInfo& io_compInfo)
{
    UTIL_FT(ENTER_MRK"MasterContainerLidMgr::processComponent %s",
            iv_curCompIdStr);

    errlHndl_t l_errl = nullptr;
    bool l_skipLoad = false;

    do {

    // Check if Component is POWERVM (aka PHYP)
    bool isPhypComp = (i_compId == g_PowervmCompId) ? true : false;

    // Check if Component is POWERVM (PHYP) and still skip if (!isTCEmode)
    if ( isPhypComp )
    {
        if (TCE::utilUseTcesForDmas())
        {
            // Skip loading, but still process POWERVM (PHYP) component
            l_skipLoad = true;
            UTIL_FT("MasterContainerLidMgr::processComponent skip load but processing POWERVM component");
        }
        else
        {
            // Skip Lid loading and processing of POWERVM (PHYP) component
            // if NOT in TCEmode
            l_skipLoad = true;
            UTIL_FT("MasterContainerLidMgr::processComponent skipping POWERVM component completely");
            break;  // break from do-while to skip processing
        }
    }

    // Only process compoenents if they are marked PRE_VERIFY
    if( (io_compInfo.flags & CompFlags::PRE_VERIFY) !=
         CompFlags::PRE_VERIFY)
    {
        UTIL_FT("MasterContainerLidMgr::processComponent not a pre-verify section skipping...");
        break;
    }

    // Total size of all Lids in component reoprted by the FSP
    size_t l_reportedSize = 0;
    if (!l_skipLoad)
    {
        // Load lids into temp mainstore memory
        l_errl = loadLids(io_compInfo, l_reportedSize);
        if (l_errl)
        {
            break;
        }
    }
    // Set total size of component.
    // Note: It will be reassigned later if a secure header is present
    io_compInfo.totalSize = l_reportedSize;

    // Verify component's lids
    l_errl = verifyExtend(i_compId, io_compInfo);
    if (l_errl)
    {
        break;
    }

    // Ensure the total size of all lids fit in the mainstore memory region
    if (io_compInfo.totalSize > iv_maxSize)
    {
        UTIL_FT(ERR_MRK"MasterContainerLidMgr::processComponent - Invalid size. Component total size=0x%X, max size =0x%X",
                io_compInfo.totalSize, iv_maxSize);
        /*@
         * @errortype
         * @moduleid          Util::UTIL_MCL_PROCESS_COMP
         * @reasoncode        Util::UTIL_LIDMGR_INVAL_SIZE
         * @userdata1[0:31]   Total Size of Component
         * @userdata1[32:63]  Max size of memory region
         * @userdata2         Component ID [truncated to 8 bytes]
         * @devdesc           Error processing component for Mcl Mgr
         * @custdesc          Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        Util::UTIL_MCL_PROCESS_COMP,
                        Util::UTIL_LIDMGR_INVAL_SIZE,
                        TWO_UINT32_TO_UINT64(
                            TO_UINT32(io_compInfo.totalSize),
                            TO_UINT32(iv_maxSize)),
                        compIdToInt(i_compId),
                        true); //software callout
        l_errl->collectTrace(UTIL_COMP_NAME);
        break;
    }

    // Ensure what was read by the FSP matches the total size found in the
    // Secure Header. If there is no secure header, this path should not be hit.
    // *NOTE: Skip check if lid loading was skipped
    if ( !l_skipLoad && (io_compInfo.totalSize != l_reportedSize))
    {
        UTIL_FT(ERR_MRK"MasterContainerLidMgr::processComponent - Size Mismatch. Component total size=0x%X, size read by FSP=0x%X",
                io_compInfo.totalSize, l_reportedSize);
        /*@
         * @errortype
         * @moduleid          Util::UTIL_MCL_PROCESS_COMP
         * @reasoncode        Util::UTIL_MCL_SIZE_MISMATCH
         * @userdata1[0:31]   Total Size of Component
         * @userdata1[32:63]  Size read by FSP
         * @userdata2         Component ID [truncated to 8 bytes]
         * @devdesc           Error processing component for Mcl Mgr
         * @custdesc          Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        Util::UTIL_MCL_PROCESS_COMP,
                        Util::UTIL_MCL_SIZE_MISMATCH,
                        TWO_UINT32_TO_UINT64(
                            TO_UINT32(io_compInfo.totalSize),
                            TO_UINT32(l_reportedSize)),
                        compIdToInt(i_compId),
                        true); //software callout
        l_errl->collectTrace(UTIL_COMP_NAME);
        break;
    }

    // Clear unused memory
    if (io_compInfo.totalSize < iv_maxSize)
    {
        // Get pointer to end of used space
        uint8_t* l_pUnused = reinterpret_cast<uint8_t*>(iv_pVaddr) +
                             io_compInfo.totalSize;
        memset(l_pUnused, 0, iv_maxSize - io_compInfo.totalSize);
    }

    // Only load lids into HB reserved memory if component is preverified
    if( (io_compInfo.flags & CompFlags::PRE_VERIFY) ==
         CompFlags::PRE_VERIFY)
    {
        auto l_curAddr =  reinterpret_cast<uint64_t>(iv_pVaddr);
        bool l_firstLid = true;
        for (auto & lidInfo : io_compInfo.lidIds)
        {
            uint64_t l_addr = 0;
            // Load Pnor section into HB reserved memory
            l_errl = PreVerifiedLidMgr::loadFromMCL(lidInfo.id,
                                                    l_curAddr,
                                                    lidInfo.size,
                                                    isPhypComp,
                                                    l_addr);
            if(l_errl)
            {
                break;
            }
            // Increment tmp address by lid size
            l_curAddr += lidInfo.size;

            // Save starting address of entire component, not each lid
            if (l_firstLid)
            {
                // Set mainstore memory address in cache
                io_compInfo.mainstoreAddr = l_addr;
                l_firstLid = false;
            }
        }
        if(l_errl)
        {
            break;
        }
    }

    } while(0);

    UTIL_FT(EXIT_MRK"MasterContainerLidMgr::processComponent");

    return l_errl;
}

errlHndl_t MasterContainerLidMgr::loadLids(CompInfo& io_compInfo,
                                           size_t& o_totalSize)
{
    UTIL_DT(ENTER_MRK"MasterContainerLidMgr::loadLids");
    errlHndl_t l_errl = nullptr;

    // Force total size to zero
    o_totalSize = 0;
    // Pointer to mainstore memory temp space
    uint8_t* l_pLidVaddr = reinterpret_cast<uint8_t*>(iv_pVaddr);
    // Remaining size to load lids into
    size_t l_remainSize = iv_maxSize;

    // Iterate through all Lids associated with a component
    // NOTE: iterate by reference to update lidInfo
    for (auto & lidInfo : io_compInfo.lidIds)
    {
        // Get Lid from FSP
        UtilLidMgr l_lidMgr(lidInfo.id);
        // Get size of current lid to be loaded
        size_t l_lidSize = 0;
        l_errl = l_lidMgr.getLidSize(l_lidSize);
        if(l_errl)
        {
            UTIL_FT(ERR_MRK"MasterContainerLidMgr::loadLids - Error getting size of lidId=0x%.8x",
                    lidInfo.id);
            break;
        }
        // Update lid size
        lidInfo.size = l_lidSize;

        // Load lid into vaddr location. API will check if remaining size is
        // enough; throwing an error if not.
        l_errl = l_lidMgr.getLid(reinterpret_cast<void*>(l_pLidVaddr),
                                 l_remainSize);
        if(l_errl)
        {
            UTIL_FT(ERR_MRK"MasterContainerLidMgr::loadLids - Error getting lidId=0x%.8x",
                    lidInfo.id);
            break;
        }

        // Increment vaddr pointer
        l_pLidVaddr += l_lidSize;

        // Decrement size remaining in mainstore memory temp space
        if (l_lidSize >= l_remainSize)
        {
            l_remainSize = 0;
        }
        else
        {
            l_remainSize -= l_lidSize;
        }

        // Increment total size
        o_totalSize += l_lidSize;
    }

    UTIL_DT(EXIT_MRK"MasterContainerLidMgr::loadLids");

    return l_errl;
}

errlHndl_t MasterContainerLidMgr::verifyExtend(const ComponentID& i_compId,
                                               CompInfo& io_compInfo)
{
    UTIL_DT(ENTER_MRK"MasterContainerLidMgr::verifyExtend");

    errlHndl_t l_errl = nullptr;

    do {
    // Only Verify and Extend if Component is Signed and Preverified
    if( (io_compInfo.flags & CompFlags::SIGNED_PRE_VERIFY) ==
         CompFlags::SIGNED_PRE_VERIFY)
    {
        // Only verify the lids if in secure mode
        if (SECUREBOOT::enabled())
        {
            // Verify Container - some combination of Lids
            l_errl = SECUREBOOT::verifyContainer(iv_pVaddr);
            if (l_errl)
            {
                UTIL_FT(ERR_MRK"MasterContainerLidMgr::verifyExtend - failed verifyContainer");
                SECUREBOOT::handleSecurebootFailure(l_errl);
                assert(false,"Bug! handleSecurebootFailure shouldn't return!");
            }
        }

        // Parse Container Header
        SECUREBOOT::ContainerHeader l_conHdr(iv_pVaddr);

        // Cache size stats into comp info cache
        io_compInfo.totalSize = l_conHdr.totalContainerSize();
        io_compInfo.protectedSize = l_conHdr.payloadTextSize();
        io_compInfo.unprotectedSize = l_conHdr.totalContainerSize() -
                                      l_conHdr.payloadTextSize();

        // @TODO RTC:181848 re-enable when component id is supported in lids
        if (0)// memcmp(l_conHdr.componentId(), i_compId.data(),
              //        SW_HDR_COMP_ID_SIZE_BYTES) != 0 )
        {
            uint64_t l_secHdrCompId {};
            uint64_t l_mclCompId {};
            memcpy(&l_secHdrCompId, l_conHdr.componentId(), SW_HDR_COMP_ID_SIZE_BYTES);
            memcpy(&l_mclCompId, i_compId.data(), SW_HDR_COMP_ID_SIZE_BYTES);

            UTIL_FT(ERR_MRK"MasterContainerLidMgr::verifyExtend - ComponentID mismatch between secure header = %.16llX and master container lid %.16llX",
                    l_secHdrCompId, l_mclCompId);
            /*@
             * @errortype
             * @moduleid          Util::UTIL_MCL_VERIFY_EXT
             * @reasoncode        Util::UTIL_MCL_COMPID_MISMATCH
             * @userdata1         Secure Header Comp ID
             * @userdata2         Master Container Lid Comp ID
             * @devdesc           Error processing component for Mcl Mgr
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           Util::UTIL_MCL_VERIFY_EXT,
                           Util::UTIL_MCL_COMPID_MISMATCH,
                           l_secHdrCompId,
                           l_mclCompId,
                           true); //software callout
            l_errl->collectTrace(UTIL_COMP_NAME);
            break;
        }

        tpmExtend(i_compId, l_conHdr);
    }
    } while(0);

    UTIL_DT(EXIT_MRK"MasterContainerLidMgr::verifyExtend");

    return l_errl;
}

errlHndl_t MasterContainerLidMgr::tpmExtend(const ComponentID& i_compId,
                            const SECUREBOOT::ContainerHeader& i_conHdr) const
{
    UTIL_DT(ENTER_MRK"MasterContainerLidMgr::tpmExtend");

    errlHndl_t l_errl = nullptr;

    // PCR 4 Message <Component ID>
    char pcr4Msg[sizeof(ComponentID)+1];
    memset(pcr4Msg, 0, sizeof(pcr4Msg));
    memcpy(pcr4Msg, &i_compId, sizeof(ComponentID));

    // PCR 5 Message <Component ID FW KEY HASH>
    char pcr5Msg[sizeof(ComponentID)+strlen(TRUSTEDBOOT::FW_KEY_HASH_EXT)+1];
    memset(pcr5Msg, 0, sizeof(pcr5Msg));
    strcat(pcr5Msg,pcr4Msg);
    strcat(pcr5Msg,TRUSTEDBOOT::FW_KEY_HASH_EXT);

    do {

    // Extend protected payload hash
    l_errl = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_4,
              TRUSTEDBOOT::EV_COMPACT_HASH,
              reinterpret_cast<const uint8_t*>(i_conHdr.payloadTextHash()),
              sizeof(SHA512_t),
              pcr4Msg);
    if (l_errl)
    {
        UTIL_FT(ERR_MRK "MasterContainerLidMgr::tpmExtend - pcrExtend() (payload text hash) failed for component %s",
                  iv_curCompIdStr);
        break;
    }

    // Extend SW keys hash
    l_errl = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_5,
              TRUSTEDBOOT::EV_COMPACT_HASH,
              reinterpret_cast<const uint8_t*>(i_conHdr.swKeyHash()),
              sizeof(SHA512_t),
              pcr5Msg);
    if (l_errl)
    {
        UTIL_FT(ERR_MRK "MasterContainerLidMgr::tpmExtend - pcrExtend() (FW key hash) failed for component %s",
                iv_curCompIdStr);
        break;
    }

    } while(0);

    UTIL_DT(EXIT_MRK"MasterContainerLidMgr::tpmExtend");

    return l_errl;
}

} // end namespace MCL
