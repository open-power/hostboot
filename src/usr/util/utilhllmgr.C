/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilhllmgr.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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
#include <util/utilhllmgr.H>
#include <util/utillidmgr.H>
#include <util/util_reasoncodes.H>
#include "trace/interface.H"
#include "utilbase.H"
#include <sys/mm.h>
#include <sys/misc.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errlreasoncodes.H>
#include <errl/hberrltypes.H> // SrcUserData
#include <initservice/initserviceif.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/service.H>
#include <runtime/preverifiedlidmgr.H>
#include <limits.h>
#include <util/utiltce.H>
#include <runtime/runtime.H>
#include <xz/xz.h>
#include <arch/magic.H>
#include <targeting/targplatutil.H>
// #include "securerommgr.H"
#include <util/misc.H> // Util::isSimicsRunning

// The HLLMgr class is used to read in the Hash Lid List (HLL) and parse
// the content of the HLL to read and verify the PowerVM and PreVerified lids
// which are needed at various stages of the IPL.

namespace HLL
{

// When reading in the HLL TOC the entries and sections of
// the HLL are placed in the appropriate group to be handled by specific
// code logic later in the processing.
const GroupID g_HLLGroup {"FWSBHLL"};
const GroupID g_HLLPowerVM {"POWERVM"};
const GroupID g_HLLPreVerified {"PREVERIFY"};

#define V1_SIZE (4*KILOBYTE)  // 4 KB
#define V2_SIZE (16*KILOBYTE) // 16 KB

void groupIdToString(const GroupID i_groupId, GroupIdString o_groupIdStr)
{
    memcpy(o_groupIdStr,
           i_groupId.data(),
           sizeof(GroupID));
}

errlHndl_t decompressLid(const uint8_t * const i_buffer, uint8_t * io_buffer,
                     const uint64_t i_size, uint64_t& io_size)
{
    errlHndl_t l_errl = nullptr;

    do {
    struct xz_buf b = {0};
    struct xz_dec *s = nullptr;
    enum xz_ret ret = XZ_OK;
    xz_crc32_init();
    s = xz_dec_init(XZ_SINGLE, 0);
    if (s == nullptr)
    {
        UTIL_FT(ERR_MRK"Util::decompressLid XZ Embedded failed initialization i_size=0x%X (%d) io_size=0x%X (%d)",
            i_size, i_size, io_size, io_size);
        /*@
         * @moduleid          Util::UTIL_HLL_DECOMPRESS_LID
         * @reasoncode        Util::UTIL_HLL_DECOMPRESS_FAIL_INIT
         * @userdata1         i_size Size of the input data to decompress
         * @userdata2         io_size Size of the output buffer passed in
         * @devdesc           Problem with XZ compression initialization
         * @custdesc          Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                       ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                       Util::UTIL_HLL_DECOMPRESS_LID,
                       Util::UTIL_HLL_DECOMPRESS_FAIL_INIT,
                       i_size,
                       io_size,
                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(UTIL_COMP_NAME);
        break;
    }

    b.in = i_buffer;
    b.in_pos = 0;
    b.in_size = i_size;
    b.out = io_buffer;
    b.out_pos = 0;
    b.out_size = io_size;

    ret = xz_dec_run(s, &b);
    if (ret != XZ_STREAM_END)
    {
        UTIL_FT(ERR_MRK"Util::decompressLid XZ Embedded failed xz_dec_run ret=%d i_size=0x%X (%d)",
            ret, i_size, i_size);
        /*@
         * @moduleid          Util::UTIL_HLL_DECOMPRESS_LID
         * @reasoncode        Util::UTIL_HLL_DECOMPRESS_FAILED
         * @userdata1         ret XZ decompression return code
         * @userdata2         i_size Size of the input data to decompress
         * @devdesc           Problem with XZ decompression
         * @custdesc          Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                       ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                       Util::UTIL_HLL_DECOMPRESS_LID,
                       Util::UTIL_HLL_DECOMPRESS_FAILED,
                       ret,
                       i_size,
                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(UTIL_COMP_NAME);
        break;

    }

    if (b.out_pos == 0)
    {
        UTIL_FT(ERR_MRK"Util::decompressLid XZ Embedded failed EMPTY i_size=0x%X (%d) io_size=0x%X (%d)",
            i_size, i_size, io_size, io_size);
        /*@
         * @moduleid          Util::UTIL_HLL_DECOMPRESS_LID
         * @reasoncode        Util::UTIL_HLL_DECOMPRESS_EMPTY
         * @userdata1         i_size Size of the input data to decompress
         * @userdata2         io_size Size of the output buffer passed in
         * @devdesc           Decompressed LID is unexpectedly empty
         * @custdesc          Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                       ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                       Util::UTIL_HLL_DECOMPRESS_LID,
                       Util::UTIL_HLL_DECOMPRESS_EMPTY,
                       i_size,
                       io_size,
                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(UTIL_COMP_NAME);
        break;
    }
    io_size = b.out_pos;
    xz_dec_end(s);

    } while(0);
    return l_errl;
}

uint64_t groupIdToInt(const GroupID i_groupId)
{
    uint64_t l_groupId {};

    memcpy(&l_groupId, i_groupId.data(), sizeof(l_groupId));

    return l_groupId;
}

RomVerifyIds extractLidIds(const std::vector<LidInfo>& i_lidIds)
{
    RomVerifyIds l_ids {};
    for (auto const& id : i_lidIds)
    {
        l_ids.push_back(id.id);
    }

    return l_ids;
}

////////////////////////////////////////////////////////////////////////////////
// GroupInfo
////////////////////////////////////////////////////////////////////////////////

void GroupInfo::print() const
{
    UTIL_FT(" ===> GROUP INFO <===");
    UTIL_FT("  - Flags: 0x%04X", flags);
    UTIL_FT("  - Total Size: 0x%llX (%lld)", totalSize, totalSize);
    UTIL_FT("  - LidIds (if applicable compressed sizes):");
    for (auto lidInfo : lidIds)
    {
        UTIL_FT("    - 0x%08X, size 0x%X (%lld)", lidInfo.id, lidInfo.size, lidInfo.size);
    }
}

////////////////////////////////////////////////////////////////////////////////
// HLLMgr
////////////////////////////////////////////////////////////////////////////////

HLLMgr::HLLMgr(const bool i_toc_only)
: iv_HLLSize(MTOC_SIZE), iv_tmpSize(TOC_TMP_SIZE), iv_maxSize(0),
  iv_pHLLVaddr(nullptr), iv_pTempVaddr(nullptr), iv_pVaddr(nullptr),
  iv_groupInfoCache{}, iv_hasHeader(true), iv_version(0),
  iv_toc_only(i_toc_only), iv_initMetaData_required(false), iv_initTempSpace_required(false)
{
    // Need to make Memory spaces HRMOR-relative
    const uint64_t hostboot_base_address = RUNTIME::getHbBaseAddrWithNodeOffset();

    iv_tmpAddr = hostboot_base_address + TOC_TMP_ADDR;
    iv_HLLAddr = hostboot_base_address + TOC_ADDR;

    initHLL();
}

HLLMgr::HLLMgr(const void* i_pHLL, const size_t i_size)
: iv_HLLSize(MTOC_SIZE), iv_tmpSize(TOC_TMP_SIZE), iv_maxSize(0),
  iv_pHLLVaddr(nullptr), iv_pTempVaddr(nullptr), iv_pVaddr(nullptr),
  iv_groupInfoCache{}, iv_hasHeader(false), iv_version(0),
  iv_toc_only(false), iv_initMetaData_required(false), iv_initTempSpace_required(false)
{
    // Used for test cases where no iv_hasHeader
    // Need to make Memory spaces HRMOR-relative
    const uint64_t hostboot_base_address = RUNTIME::getHbBaseAddrWithNodeOffset();

    iv_HLLAddr = hostboot_base_address + TOC_ADDR;
    iv_tmpAddr = hostboot_base_address + TOC_TMP_ADDR;

    initHLL(i_pHLL, i_size);
}

HLLMgr::~HLLMgr()
{
    // Release all address spaces
    releaseMem(iv_tmpAddr, iv_pHLLVaddr);
    releaseMem(iv_tmpAddr, iv_pTempVaddr);
}

void HLLMgr::initHLL(const void* i_pHLL, const size_t i_HLLSize)
{
    errlHndl_t l_errl = nullptr;

    // Add HLL itself to Cache but don't add to group order
    GroupInfo l_groupHdrInfo(HllEntryFlags::SIGNED_PRE_VERIFY);

    LidInfo l_hdrLidInfo(Util::HLL_LIDID);
    l_groupHdrInfo.lidIds.push_back(l_hdrLidInfo);
    iv_groupInfoCache.insert(std::make_pair(g_HLLGroup, l_groupHdrInfo));


    // Cache Group ID string
    groupIdToString(g_HLLGroup, iv_curGroupIdStr);

    // Initialize HLL address space
    initMem(iv_HLLAddr, iv_HLLSize, iv_pHLLVaddr);

    // Use HLL address and size for parsing
    iv_pVaddr = iv_pHLLVaddr;
    iv_maxSize = iv_HLLSize;

    if(i_pHLL != nullptr)
    {
        // copy over the custom HLL to the instance variable location which was previously set
        memcpy(iv_pHLLVaddr, i_pHLL, i_HLLSize);
    }
    else
    {
        // No custom HLL, load default way
        // The following call will load the HLL lid into memory for TOC to be built from
        if (iv_initMetaData_required)
        {
            l_errl = initMetaData(g_HLLGroup,
                                    iv_groupInfoCache.at(g_HLLGroup));
            if (l_errl)
            {
                uint64_t l_reasonCode = l_errl->reasonCode();
                UTIL_FT(ERR_MRK"HLLMgr::initHLL failed to process HLL shutting down rc=0x%08X",
                        l_reasonCode);
                errlCommit(l_errl,UTIL_COMP_ID);
                INITSERVICE::doShutdown(l_reasonCode);
            }
            iv_initMetaData_required = false;
        }
    }

    // Parse the HLL
    l_errl = parseHLL();
    if (l_errl)
    {
        uint64_t l_reasonCode = l_errl->reasonCode();
        UTIL_FT(ERR_MRK"HLLMgr::initHLL failed to parseHLL HLL shutting down rc=0x%08X",
                l_reasonCode);
        errlCommit(l_errl,UTIL_COMP_ID);
        INITSERVICE::doShutdown(l_reasonCode);
    }

    // Initialize temporary space for processing other groups
    initMem(iv_tmpAddr, iv_tmpSize, iv_pTempVaddr);

    // Switch to temp address and size for all other groups
    iv_pVaddr = iv_pTempVaddr;
    iv_maxSize = iv_tmpSize;
}

void HLLMgr::releaseMem(const uint64_t i_physAddr,
                                       void *&io_pVaddr)
{
    errlHndl_t l_errl = nullptr;
    assert(i_physAddr != 0, "HLLMgr physical address to release cannot be 0");

    do {
    if ( io_pVaddr != nullptr)
    {
        int l_mm_rc = mm_block_unmap(io_pVaddr);
        if(l_mm_rc != 0)
        {
            UTIL_FT("Fail from mm_block_unmap for HLL Mgr, rc=%d Addr 0x%.16llX",
                    l_mm_rc, i_physAddr);
            /*@
             * @errortype
             * @moduleid          Util::UTIL_HLL_REL_MEM
             * @reasoncode        Util::UTIL_MM_BLOCK_UNMAP_FAILED
             * @userdata1         Address being removed
             * @userdata2         rc from mm_block_unmap
             * @devdesc           Error calling mm_block_unmap for HLL Mgr
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           Util::UTIL_HLL_REL_MEM,
                           Util::UTIL_MM_BLOCK_UNMAP_FAILED,
                           i_physAddr,
                           l_mm_rc,
                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(UTIL_COMP_NAME);
            break;
        }
        io_pVaddr = nullptr;
    }
    } while(0);

    if (l_errl)
    {
        uint64_t l_reasonCode = l_errl->reasonCode();
        UTIL_FT(ERR_MRK"HLLMgr::releaseMem failed to release memory rc=0x%08X",
                l_reasonCode);
        errlCommit(l_errl,UTIL_COMP_ID);
        INITSERVICE::doShutdown(l_reasonCode);
    }
}

void HLLMgr::initMem(const uint64_t i_physAddr,
                                    const size_t i_size,
                                    void *&io_pVaddr)
{
    errlHndl_t l_errl = nullptr;
    assert(i_physAddr != 0, "HLLMgr physical address cannot be 0");

    do {
    //Check if we already initialized vm space
    // io_pVaddr is mapped to the iv instance variables by the caller
    if (io_pVaddr == nullptr)
    {
        io_pVaddr = mm_block_map(reinterpret_cast<void*>(i_physAddr), i_size);
        if(io_pVaddr == nullptr)
        {
            UTIL_FT("HLLMgr::initMem mm_block_map failed for Addr 0x%.16llX and size=0x%X ",
                    i_physAddr, i_size);
            /*@
             * @errortype
             * @moduleid          Util::UTIL_HLL_INIT_MEM
             * @reasoncode        Util::UTIL_MM_BLOCK_MAP_FAILED
             * @userdata1         Address being allocated
             * @userdata2         Size of block allocation
             * @devdesc           Error calling mm_block_map for HLL Mgr
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           Util::UTIL_HLL_INIT_MEM,
                           Util::UTIL_MM_BLOCK_MAP_FAILED,
                           i_physAddr,
                           i_size,
                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(UTIL_COMP_NAME);
            break;
        }

        // Depending on the call sequence to initMem, first entry is for the TOC iv_pHLLVaddr which will allow the
        // mapping of the TOC space to see if we have already read the HLL LID, even on the second entry to initMem,
        // the instance variable iv_pHLLVaddr will be appropriately mapped to also validate the memory signature
        // of the TOC space.
        auto l_pHLL = reinterpret_cast<const uint8_t*>(iv_pHLLVaddr);
        // When class constructor is called with a real TOC sets iv_hasHeader
        if (iv_hasHeader)
        {
            l_pHLL += V1_SIZE;
        }
        auto l_pHdr = reinterpret_cast<const HLLHeader*>(l_pHLL);
        if (l_pHdr->EyeCatcher != HLL_EYE_CATCHER)
        {
            // We have to use the memory footprint to drive the decision making, not the newly created class instance vars
            // Only the first time when initMetaData is performed will the verifyContainer and tpmExtend functions be run.
            // Any future re-designs need to assure that the proper requirements are maintained to only verify and
            // tpmExtend the HLL once per IPL.
            iv_initMetaData_required = true;
            if (!iv_toc_only)
            {
                // iv_initTempSpace_required is flipped to false when the initMem is called upon the temp space
                // (so two passes go thru initMem, one time for the HLL and one time for the temp space
                iv_initTempSpace_required = true;
            }
            memset(io_pVaddr, 0, i_size);
        }
        else
        {
            if (iv_initTempSpace_required)
            {
                memset(io_pVaddr, 0, i_size);
                iv_initTempSpace_required = false;
            }
        }
    }
    } while(0);

    if (l_errl)
    {
        uint64_t l_reasonCode = l_errl->reasonCode();
        UTIL_FT(ERR_MRK"HLLMgr::initMem failed to initialize memory rc=0x%08X",
                l_reasonCode);
        errlCommit(l_errl,UTIL_COMP_ID);
        INITSERVICE::doShutdown(l_reasonCode);
    }
}

bool HLLMgr::isValid()
{
    // Currently this is only used in the test case flows where
    // we need to call into the HLLMgr class methods to validate and
    // set to perform method invocations
    // In the future if the isValid method is to be used it must
    // be used AFTER the parseHLL has validated and stored the proper
    // values from reading the HLL
    // This logic does NOT support the compatibility version

    bool l_isValid = false;
    if (iv_version == HLL_SUPPORTED_VERSION)
    {
        l_isValid = true;
    }
    UTIL_FT("HLLMgr::isValid l_isValid=%d iv_version=0x%X",
        l_isValid, iv_version);
    return l_isValid;
}
errlHndl_t HLLMgr::parseHLL()
{
    #define V1_SIZE (4*KILOBYTE)  // 4 KB
    #define V3_SIZE (16*KILOBYTE) // 16 KB

    errlHndl_t l_err = nullptr;
    uint64_t l_algo_size = V1_SIZE;
    switch (SECUREBOOT::hashSignMode())
    {
        case 0x0: // TARGETING::SB_SIGNING_V1_CONTAINER
            l_algo_size = V1_SIZE;
            break;
        case 0x2: // TARGETING::SB_SIGNING_V3_CONTAINER
            l_algo_size = V3_SIZE;
            break;
        // case 0x1 is V2 which is not used
        default:
            assert(false, "Unsupported hash algorithm");
            break;
    }

    UTIL_FT(ENTER_MRK"HLLMgr::parseHLL l_algo_size=%d", l_algo_size);
    assert(iv_pHLLVaddr != nullptr);
    do {
    auto l_pHLL = reinterpret_cast<const uint8_t*>(iv_pHLLVaddr);

    // When class constructor is called with a real TOC sets iv_hasHeader
    if (iv_hasHeader)
    {
        l_pHLL += V1_SIZE;
    }
    auto l_pHdr = reinterpret_cast<const HLLHeader*>(l_pHLL);
    uint32_t l_offsetToPowerVM =  l_pHdr->OffsetToPowerVM;
    auto l_pPowerVMHdr = reinterpret_cast<const PowerVmHeader*>(l_pHLL+l_offsetToPowerVM);
    // store the struct variable HashEntrySize to be used later (as defined in the HLL header)
    iv_HashEntrySize = l_pHdr->HashEntrySize;

    UTIL_FT("HLLMgr::parseHLL checking support for version=0x%X CompatibleVersion=0x%X",
        l_pHdr->version, l_pHdr->CompatibleVersion);

    if ((l_pHdr->version) != HLL_SUPPORTED_VERSION)
    {
        UTIL_FT("HLLMgr::parseHLL version mismatch, we expected HLL_SUPPORTED_VERSION=%d actual version=%d "
                "Oldest CompatibleVersion=%d",
                HLL_SUPPORTED_VERSION, l_pHdr->version, l_pHdr->CompatibleVersion);
        if (Util::isSimicsRunning() && TARGETING::UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_IS_STANDALONE>())
        {
            // We expect test cases to fail here so put the custom HLL values
            // in the real HLLMgr so the isValid will fail in the test case to signal success
            iv_version = l_pHdr->version;
        }
        else
        {
            if (l_pHdr->CompatibleVersion > HLL_SUPPORTED_VERSION)
            {
                UTIL_FT(ERR_MRK"HLLMgr::parseHLL incompatible version check failure expected HLL_SUPPORTED_VERSION=%d "
                    "but instead see version=%d Oldest CompatibleVersion=%d",
                    HLL_SUPPORTED_VERSION, l_pHdr->version, l_pHdr->CompatibleVersion);
                /*@
                    * @errortype
                    * @moduleid          Util::UTIL_HLL_PARSE_TOC
                    * @reasoncode        Util::UTIL_HLL_VERSION_COMPAT
                    * @userdata1[00:15]  HLL version
                    * @userdata1[16:31]  HLL compatible version
                    * @userdata2[32:47]  HLL_SUPPORTED_VERSION
                    * @devdesc           Versioning incompatibility
                    * @custdesc          Firmware Error
                    */
                l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            Util::UTIL_HLL_PARSE_TOC,
                            Util::UTIL_HLL_VERSION_COMPAT,
                            errl_util::SrcUserData(
                                errl_util::bits{0, 15}, l_pHdr->version,
                                errl_util::bits{16, 31},l_pHdr->CompatibleVersion,
                                errl_util::bits{32, 47},HLL_SUPPORTED_VERSION),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_err->collectTrace(UTIL_COMP_NAME);
                break;
            }
            else
            {
                UTIL_FT("HLLMgr::parseHLL versions are compatible, expected HLL_SUPPORTED_VERSION=%d actual version=%d "
                        "Oldest CompatibleVersion=%d",
                        HLL_SUPPORTED_VERSION, l_pHdr->version, l_pHdr->CompatibleVersion);
                iv_version = l_pHdr->version;
            }
        }
    }
    else
    {
        iv_version = l_pHdr->version;
        UTIL_FT("HLLMgr::parseHLL versions matched, expected version=%d actual version=%d oldest compatible version=%d",
            HLL_SUPPORTED_VERSION, l_pHdr->version, l_pHdr->CompatibleVersion);
    }

    uint16_t l_offsetToHashListEntries =  l_pHdr->OffsetToHashListEntries;

    auto l_pLidEntries = reinterpret_cast<const LidEntry*>(l_pHLL+l_offsetToHashListEntries);

    // Construct TOC Info with a subset of information
    GroupInfo l_HLLPowerVM (HllEntryFlags::SIGNED_PRE_VERIFY);
    auto l_pLids = reinterpret_cast<const uint32_t*>(l_pPowerVMHdr->PowerVmLids);
    // Build up the PowerVM ordered list of lids that get handled in the managePowerVMGroup
    // The PowerVM lids must be loaded in the pre-defined order specified in the HLL
    // The sizes and hashes will be filled in when cycling thru the LidEntry's below
    for (uint16_t lid = 0; lid < l_pPowerVMHdr->NumberOfPowerVmLids; ++lid)
    {
        LidInfo l_lidInfo(*l_pLids);
        l_HLLPowerVM.lidIds.push_back(l_lidInfo);
        l_pLids++;
    }

    GroupInfo l_HLLPreVerified (HllEntryFlags::SIGNED_PRE_VERIFY);
    auto l_pEntry = reinterpret_cast<const uint8_t*>(l_pLidEntries);
    uint64_t total_size = 0;
    UTIL_FT("HLLMgr::parseHLL will process NumberOfEntries=%d", l_pHdr->NumberOfEntries);
    for (uint16_t lid = 0; lid < l_pHdr->NumberOfEntries; ++lid)
    {
        auto l_offset = reinterpret_cast<const LidEntry*>(l_pEntry)->OffsetToHash;
        auto hash_calc_offset = (l_pEntry + l_offset);
        auto l_pHashCalc = reinterpret_cast<const HashEntry*>(hash_calc_offset);
        LidInfo l_HLLlidInfo(reinterpret_cast<const LidEntry*>(l_pEntry)->LidID);
        l_HLLlidInfo.PreVerified = reinterpret_cast<const LidEntry*>(l_pEntry)->PreVerified;
        l_HLLlidInfo.Unsigned = reinterpret_cast<const LidEntry*>(l_pEntry)->Unsigned;
        l_HLLlidInfo.size = reinterpret_cast<const LidEntry*>(l_pEntry)->LidSize;
        if (reinterpret_cast<const LidEntry*>(l_pEntry)->Unsigned == 0x0)
        {
            // Store off the hash calculation to use later to validate
            memcpy(&l_HLLlidInfo.hllHash, l_pHashCalc->HashCalc, sizeof(HashEntry));
        }
        // PowerVM Ordered lids, store off size and hash for secure checks later
        for (auto & id : l_HLLPowerVM.lidIds)
        {
            if (id.id == l_HLLlidInfo.id)
            {
                // populate the l_HLLPowerVM group info
                // this is the PowerVM ordered list
                id.size = l_HLLlidInfo.size;
                id.hllHash = l_HLLlidInfo.hllHash;
            }
        }
        if (reinterpret_cast<const LidEntry*>(l_pEntry)->PreVerified)
        {
            // The PreVerified lid list will be later individually validated against the hashes if secureboot is enabled
            // iv_tmpSize is where the preverified lids are worked
            if ((total_size + l_HLLlidInfo.size) > iv_tmpSize)
            {
                UTIL_FT(ERR_MRK"HLLMgr::parseHLL l_HLLlidInfo.id=0x%X total_size=%d l_HLLlidInfo.size=%d iv_maxSize=%d iv_tmpSize=%d TOTAL=%d",
                    l_HLLlidInfo.id, total_size, l_HLLlidInfo.size, iv_maxSize, iv_tmpSize, (total_size+l_HLLlidInfo.size));
                /*@
                * @errortype
                * @moduleid          Util::UTIL_HLL_PARSE_TOC
                * @reasoncode        Util::UTIL_HLL_MAX_SIZE
                * @userdata1         total_size
                * @userdata2         iv_maxSize
                * @devdesc           Error parseHLL for HLL Mgr
                * @custdesc          Firmware Error
                */
                l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                Util::UTIL_HLL_PARSE_TOC,
                                Util::UTIL_HLL_MAX_SIZE,
                                total_size,
                                iv_maxSize,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_err->collectTrace(UTIL_COMP_NAME);
                break;
            }
            l_HLLPreVerified.lidIds.push_back(l_HLLlidInfo);
            total_size += l_HLLlidInfo.size;

        }
        l_pEntry = l_pEntry + iv_HashEntrySize;
    }
    l_HLLPreVerified.totalSize = total_size;
    iv_groupInfoCache.insert(std::make_pair(g_HLLPreVerified, l_HLLPreVerified));
    iv_groupInfoCache.insert(std::make_pair(g_HLLPowerVM, l_HLLPowerVM));
    UTIL_FT(EXIT_MRK"HLLMgr::parseHLL PreVerified Current Temp Storage Usage=0x%X (%lld) of Max Temp Storage=0x%X (%lld)",
        total_size, total_size, iv_tmpSize, iv_tmpSize);
    printGroupInfoCache();
    } while (0);
    return l_err;
}

void HLLMgr::printGroupInfoCache()
{
    UTIL_FT("> HLLMgr::printGroupInfoCache:");
    for (const auto &i : iv_groupInfoCache)
    {
        GroupIdString l_curGroupIdStr = {};
        groupIdToString(i.first, l_curGroupIdStr);
        UTIL_FT("Group Name=%s", l_curGroupIdStr);
        i.second.print();
    }
}

errlHndl_t HLLMgr::verifyPowerVM(void * i_payload)
{
    errlHndl_t l_errl = nullptr;
    GroupIdString l_curGroupIdStr = {};
    groupIdToString(g_HLLPowerVM, l_curGroupIdStr);
    UTIL_FT(ENTER_MRK"HLLMgr::verifyPowerVM");
    uint8_t* l_pLidVaddr = reinterpret_cast<uint8_t*>(i_payload);
    auto groupInfoPairItr = iv_groupInfoCache.find(g_HLLPowerVM);
    if(groupInfoPairItr != iv_groupInfoCache.end())
    {
        for (auto & lidInfo : groupInfoPairItr->second.lidIds)
        {
            HashEntry hash = {0};
            SECUREBOOT::hashBlob(reinterpret_cast<void*>(l_pLidVaddr), lidInfo.size, hash.HashCalc);
            if (memcmp(hash.HashCalc, &lidInfo.hllHash, sizeof(HashEntry)) != 0)
            {
                /*@
                * @moduleid          Util::UTIL_HLL_VERIFY_POWERVM
                * @reasoncode        Util::UTIL_HLL_HASH_FAILURE
                * @userdata1         lidInfo.hllHash
                * @userdata2         HashCalc
                * @devdesc           Secure hash failure on lid
                * @custdesc          Firmware Error
                */
                l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            Util::UTIL_HLL_VERIFY_POWERVM,
                            Util::UTIL_HLL_HASH_FAILURE,
                            *((uint64_t*)&lidInfo.hllHash),
                            *((uint64_t*)hash.HashCalc),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                l_errl->collectTrace(UTIL_COMP_NAME);
                UTIL_FT(ERR_MRK"HLLMgr::verifyPowerVM failed to verify Group Name=%s", l_curGroupIdStr);
                SECUREBOOT::handleSecurebootFailure(l_errl);
                assert(false,"Bug! handleSecurebootFailure shouldn't return!");
            }
            UTIL_FT("HLLMgr::verifyPowerVM lidInfo.id=0x%X passed HashCalc", lidInfo.id);
            l_pLidVaddr += lidInfo.size;
        }
    }
    UTIL_FT(EXIT_MRK"HLLMgr::verifyPowerVM");
    return l_errl;
}

errlHndl_t HLLMgr::tpmExtendContainer(const GroupID& i_groupId,
                            const SECUREBOOT::ContainerHeader& i_conHdr)
{
    GroupIdString l_HLLStr = {};
    groupIdToString(i_groupId, l_HLLStr);
    UTIL_FT(ENTER_MRK"HLLMgr::tpmExtendContainer=%s", l_HLLStr);
    errlHndl_t l_errl = nullptr;

    // PCR 4 Message <Group ID>
    char pcr4Msg[sizeof(GroupID)+1];
    memset(pcr4Msg, 0, sizeof(pcr4Msg));
    strncpy(pcr4Msg,reinterpret_cast<const char*>(&i_groupId),sizeof(GroupID));
    const auto pcr4Len = strlen(pcr4Msg)+1;

    // PCR 5 Message <Group ID FW KEY HASH>
    char pcr5Msg[sizeof(GroupID)+strlen(TRUSTEDBOOT::FW_KEY_HASH_EXT)+1];
    memset(pcr5Msg, 0, sizeof(pcr5Msg));
    strcat(pcr5Msg,pcr4Msg);
    strcat(pcr5Msg,TRUSTEDBOOT::FW_KEY_HASH_EXT);
    const auto pcr5Len = strlen(pcr5Msg)+1;

    do {

    // Extend protected payload hash
    l_errl = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_4,
              TRUSTEDBOOT::EV_COMPACT_HASH,
              reinterpret_cast<const uint8_t*>(i_conHdr.payloadTextHash()),
              sizeof(HashEntry),
              reinterpret_cast<uint8_t*>(pcr4Msg),
              pcr4Len);
    if (l_errl)
    {
        UTIL_FT(ERR_MRK "HLLMgr::tpmExtendContainer - pcrExtend() (payload text hash) failed for group");
        break;
    }

    // Extend SW keys hash
    l_errl = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_5,
              TRUSTEDBOOT::EV_COMPACT_HASH,
              reinterpret_cast<const uint8_t*>(i_conHdr.payloadTextHash()),
              sizeof(HashEntry),
              reinterpret_cast<uint8_t*>(pcr5Msg),
              pcr5Len);
    if (l_errl)
    {
        UTIL_FT(ERR_MRK "HLLMgr::tpmExtendContainer - pcrExtend() (FW key hash) failed for group");
        break;
    }
    } while(0);

    UTIL_FT(EXIT_MRK"HLLMgr::tpmExtendContainer=%s", l_HLLStr);

    return l_errl;
}

errlHndl_t HLLMgr::managePowerVMGroup()
{
    // This logic is only applicable to BMC systems (where compression is supported).
    // managePowerVMGroup is BMC handling called in istep 20 call_host_load_payload.
    // The FSP handles the loading of the DMA.
    errlHndl_t l_errl = nullptr;
    UTIL_FT(ENTER_MRK"HLLMgr::managePowerVMGroup");
    do {

    auto groupInfoPairItr = iv_groupInfoCache.find(g_HLLPowerVM);
    if(groupInfoPairItr != iv_groupInfoCache.end())
    {

        size_t l_reportedSize = 0;
        // This is called in host_load_payload for loading lids into temp mainstore memory
        GroupIdString l_curGroupIdStr = {};
        groupIdToString(g_HLLPowerVM, l_curGroupIdStr);
        UTIL_FT("HLLMgr::managePowerVMGroup calling loadLids for %s", l_curGroupIdStr);
        l_errl = loadLids(groupInfoPairItr->second, l_reportedSize);
        if (l_errl)
        {
            UTIL_FT("HLLMgr::managePowerVMGroup problem during loadLids");
            break;
        }
        groupInfoPairItr->second.totalSize = l_reportedSize;

        l_reportedSize = 0;
        // Decompress if needed (lidInfo reflects the compressed sizes)
        l_errl = managePhypLids(groupInfoPairItr->second, l_reportedSize);
        if (l_errl)
        {
            UTIL_FT("HLLMgr::managePowerVMGroup problem during managePhypLids");
            break;
        }
        // above will be reassigned later if a secure header is present
        iv_groupInfoCache.at(groupInfoPairItr->first).print();
    }

    } while(0);

    UTIL_FT(EXIT_MRK"HLLMgr::managePowerVMGroup");

    return l_errl;

}

errlHndl_t HLLMgr::managePreVerifiedGroup()
{
    errlHndl_t l_errl = nullptr;
    UTIL_FT(ENTER_MRK"HLLMgr::managePreVerifiedGroup");
    do {
    auto groupInfoPairItr = iv_groupInfoCache.find(g_HLLPreVerified);
    if(groupInfoPairItr != iv_groupInfoCache.end())
    {
        size_t l_reportedSize = 0;
        // Load lids into temp mainstore memory first
        // This is called in populate_hbruntime to load lids into HB reserved memory
        GroupIdString l_curGroupIdStr = {};
        groupIdToString(g_HLLPreVerified, l_curGroupIdStr);
        UTIL_FT("HLLMgr::managePreVerifiedGroup calling loadLids for %s", l_curGroupIdStr);
        l_errl = loadLids(groupInfoPairItr->second, l_reportedSize);
        if (l_errl)
        {
            UTIL_FT("HLLMgr::managePreVerifiedGroup problem during loadLids");
            break;
        }
        groupInfoPairItr->second.totalSize = l_reportedSize;
        auto l_curAddr = reinterpret_cast<uint64_t>(iv_pVaddr); // load into HB reserved memory
        bool mainstore_marker = true;
        for (auto & lidInfo : groupInfoPairItr->second.lidIds)
        {
            uint64_t l_addr = 0;
            l_errl = PreVerifiedLidMgr::loadFromTOC(lidInfo.id,
                                                    l_curAddr,
                                                    lidInfo.size,
                                                    false, // not applicable
                                                    mainstore_marker,
                                                    l_addr);
            if(l_errl)
            {
                UTIL_FT("HLLMgr::managePreVerifiedGroup problem during loadFromTOC");
                break;
            }

            // ONLY if we loaded something should we bump HB reserved memory locations
            if (l_addr != 0)
            {
                // Increment tmp address by lid size
                l_curAddr += lidInfo.size;
            }
            if (mainstore_marker)
            {
                // Set mainstore memory address in cache
                groupInfoPairItr->second.mainstoreAddr = l_addr;
                mainstore_marker = false;
            }

        } // for
        if(l_errl)
        {
            UTIL_FT("HLLMgr::managePreVerifiedGroup problem during processing");
            break;
        }
        iv_groupInfoCache.at(groupInfoPairItr->first).print();
    } // if groupInfoPairItr
    } while(0);

    UTIL_FT(EXIT_MRK"HLLMgr::managePreVerifiedGroup");

    return l_errl;

}

errlHndl_t HLLMgr::initMetaData(
    const GroupID& i_groupId,
          GroupInfo&    io_groupInfo)
{

    errlHndl_t l_errl = nullptr;
    do {

    groupIdToString(i_groupId, iv_curGroupIdStr);
    UTIL_FT(ENTER_MRK"HLLMgr::initMetaData iv_curGroupIdStr=%s",
            iv_curGroupIdStr);

    // Total size of all LIDs in group reported by either the FSP or BMC.
    // The FSP and BMC load their lid content from different sources,
    // i.e. PLDM versus DMA's, so keep track and check that the sum
    // of the lids does not overrun the iv_maxSize.
    size_t l_reportedSize = 0;
    // Load lids into temp mainstore memory
    UTIL_FT("HLLMgr::initMetaData calling loadLids for %s", iv_curGroupIdStr);
    l_errl = loadLids(io_groupInfo, l_reportedSize);
    if (l_errl)
    {
        break;
    }

    // Set total size of group.
    // Note: It will be reassigned later if a secure header is present
    io_groupInfo.totalSize = l_reportedSize;

    // Ensure the total size of all lids fit in the mainstore memory region
    if (io_groupInfo.totalSize > iv_maxSize)
    {
        UTIL_FT(ERR_MRK"HLLMgr::initMetaData - Invalid size. Group total size=0x%X, max size =0x%X",
                io_groupInfo.totalSize, iv_maxSize);
        /*@
         * @errortype
         * @moduleid          Util::UTIL_HLL_INIT_METADATA
         * @reasoncode        Util::UTIL_LIDMGR_INVAL_SIZE
         * @userdata1[0:31]   Total Size of Group
         * @userdata1[32:63]  Max size of memory region
         * @userdata2         Group ID [truncated to 8 bytes]
         * @devdesc           Error processing group for HLL Mgr
         * @custdesc          Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        Util::UTIL_HLL_INIT_METADATA,
                        Util::UTIL_LIDMGR_INVAL_SIZE,
                        TWO_UINT32_TO_UINT64(
                            TO_UINT32(io_groupInfo.totalSize),
                            TO_UINT32(iv_maxSize)),
                        groupIdToInt(i_groupId),
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(UTIL_COMP_NAME);
        break;
    }

    if (io_groupInfo.totalSize != l_reportedSize)
    {
        UTIL_FT(ERR_MRK"HLLMgr::initMetaData - Size Mismatch. io_groupInfo.totalSize=0x%X l_reportedSize=0x%X",
                io_groupInfo.totalSize, l_reportedSize);
        /*@
         * @errortype
         * @moduleid          Util::UTIL_HLL_INIT_METADATA
         * @reasoncode        Util::UTIL_HLL_SIZE_MISMATCH
         * @userdata1[0:31]   Total Size of Group
         * @userdata1[32:63]  Size read by FSP
         * @userdata2         Group ID [truncated to 8 bytes]
         * @devdesc           Error processing group for HLL Mgr
         * @custdesc          Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        Util::UTIL_HLL_INIT_METADATA,
                        Util::UTIL_HLL_SIZE_MISMATCH,
                        TWO_UINT32_TO_UINT64(
                            TO_UINT32(io_groupInfo.totalSize),
                            TO_UINT32(l_reportedSize)),
                        groupIdToInt(i_groupId),
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(UTIL_COMP_NAME);
        break;
    }

    // Clear unused memory
    if (io_groupInfo.totalSize < iv_maxSize)
    {
        // Get pointer to end of used space
        uint8_t* l_pUnused = reinterpret_cast<uint8_t*>(iv_pVaddr) +
                             io_groupInfo.totalSize;
        memset(l_pUnused, 0, iv_maxSize - io_groupInfo.totalSize);
    }

    // We are loading the HLL to the 30k buffer
    auto l_curAddr =  reinterpret_cast<uint64_t>(iv_pVaddr);
    bool l_firstLid = true;
    for (auto & lidInfo : io_groupInfo.lidIds)
    {
        uint64_t l_addr = 0;
        // Load into temp mainstore
        l_errl = PreVerifiedLidMgr::loadFromTOC(lidInfo.id,
                                                l_curAddr,
                                                lidInfo.size,
                                                false, // Decision has been already made
                                                l_firstLid,
                                                l_addr);
        if(l_errl)
        {
            break;
        }
        // ONLY if we loaded something should we bump HB reserved memory locations
        if (l_addr != 0)
        {
            // Increment tmp address by lid size
            l_curAddr += lidInfo.size;
        }
        // Save starting address of entire group, not each lid
        if (l_firstLid)
        {
            // Set mainstore memory address in cache
            // When PHYP Group gets SKIPPED, l_addr will be ZERO
            io_groupInfo.mainstoreAddr = l_addr;
            l_firstLid = false;
        }
    }
    if(l_errl)
    {
        break;
    }

    if (SECUREBOOT::enabled())
    {
        // Parse the HLL Container Header
        SECUREBOOT::ContainerHeader l_conHdr;
        l_errl = l_conHdr.setHeader(iv_pHLLVaddr);  // TOC_ADDR
        if (l_errl)
        {
            UTIL_FT(ERR_MRK"HLLMgr::initMetaData - setheader failed");
            SECUREBOOT::handleSecurebootFailure(l_errl);
            assert(false,"Bug! handleSecurebootFailure shouldn't return!");
        }

        // Cache size stats into group info cache
        io_groupInfo.totalSize = l_conHdr.totalContainerSize();
        io_groupInfo.protectedSize = l_conHdr.payloadTextSize();
        io_groupInfo.unprotectedSize = l_conHdr.totalContainerSize() -
                                        l_conHdr.payloadTextSize();

        UTIL_FT("HLLMgr::initMetaData totalSize=%d protectedSize (payloadTextSize)=%d unprotectedSize=%d",
            io_groupInfo.totalSize, io_groupInfo.protectedSize, io_groupInfo.unprotectedSize);

        l_errl = SECUREBOOT::verifyContainer(iv_pHLLVaddr,
                                    extractLidIds(io_groupInfo.lidIds));
        if (l_errl)
        {
            UTIL_FT(ERR_MRK"HLLMgr::initMetaData - verifyContainer failed");
            SECUREBOOT::handleSecurebootFailure(l_errl);
            assert(false,"Bug! handleSecurebootFailure shouldn't return!");
        }
        l_errl = tpmExtendContainer(i_groupId, l_conHdr);
        if (l_errl)
        {
            UTIL_FT("HLLMgr::initMetaData failed to tpmExtend Group Name=%s", iv_curGroupIdStr);
            SECUREBOOT::handleSecurebootFailure(l_errl);
            assert(false,"Bug! handleSecurebootFailure shouldn't return!");
        }
    }

    } while(0);

    UTIL_FT(EXIT_MRK"HLLMgr::initMetaData");

    return l_errl;
}

errlHndl_t HLLMgr::managePhypLids(GroupInfo& io_groupInfo,
                                                 size_t& o_totalSize)
{
    // Handles decompression to PHYP mainstore payload base
    UTIL_FT(ENTER_MRK"HLLMgr::managePhypLids");
    errlHndl_t l_errl = nullptr;

    do {
    o_totalSize = 0;
    void * payloadBase_virt_addr = nullptr;
    uint64_t payload_size = TOC_TMP_SIZE;
    const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
    uint64_t payloadBase = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
    payloadBase = payloadBase * MEGABYTE;

    const uint64_t lmbSizeMb = (RUNTIME::getLMBSizeInMB() * MEGABYTE);
    const uint64_t lmbCapMb = VMM::BLOCK_MAP_CAP_MB;

    // Cap the memory block map size at the given max, as larger mappings can
    // cause hostboot to hang
    const uint64_t effLmbSizeMb = std::min(lmbSizeMb,lmbCapMb);
    const uint64_t mapSize = std::max(effLmbSizeMb, payload_size);

    UTIL_FT("HLLMgr::managePhypLids: lmbSizeMb = 0x%016llX, "
            "effLmbSizeMb = 0x%016llX, mapSize = 0x%016llX, "
            "payload_size = 0x%016llX",
            lmbSizeMb,effLmbSizeMb,mapSize,payload_size);

    payloadBase_virt_addr = mm_block_map(
                               reinterpret_cast<void*>(payloadBase),
                               mapSize);

    if (payloadBase_virt_addr == nullptr)
    {
        UTIL_FT(ERR_MRK"HLL::managePhypLids Fail from mm_block_map mapSize=0x%X payloadBase=0x%X",
                mapSize, payloadBase);
        /*@
         * @moduleid          Util::UTIL_HLL_MANAGE_PHYP
         * @reasoncode        Util::UTIL_MM_BLOCK_MAP_FAILED
         * @userdata1         Physical address being mapped
         * @userdata2         mapSize
         * @devdesc           Error calling mm_block_map
         * @custdesc          Firmware Error
         */
        l_errl = new ERRORLOG::ErrlEntry(
                       ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                       Util::UTIL_HLL_MANAGE_PHYP,
                       Util::UTIL_MM_BLOCK_MAP_FAILED,
                       payloadBase,
                       mapSize,
                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(UTIL_COMP_NAME);
        break;
    }

    auto payloadBase_virt_addr_ptr = reinterpret_cast<uint8_t*>(payloadBase_virt_addr);
    memset(payloadBase_virt_addr_ptr, 0, payload_size);
    uint64_t l_payloadBase_remaining_size = payload_size;

    // Only the HLL ordered list of phyp lids
    for (auto & lidInfo : io_groupInfo.lidIds)
    {
        if ((lidInfo.vAddr == 0) || (l_payloadBase_remaining_size == 0))
        {
            // If this problem surfaces, check the logs for what lids were previously compressed/decompressed for order
            UTIL_FT(ERR_MRK"HLLMgr::managePhypLids lidInfo.vAddr ZERO or l_payloadBase_remaining_size ZERO lidInfo.id=0x%X", lidInfo.id);
            /*@
             * @moduleid          Util::UTIL_HLL_MANAGE_PHYP
             * @reasoncode        Util::UTIL_HLL_PAYLOAD_BASE_SIZE
             * @userdata1         lidInfo.id
             * @userdata2         lidInfo.size
             * @devdesc           Unexpected conditions
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           Util::UTIL_HLL_MANAGE_PHYP,
                           Util::UTIL_HLL_PAYLOAD_BASE_SIZE,
                           lidInfo.id,
                           lidInfo.size,
                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(UTIL_COMP_NAME);
            break;
        }
        const uint8_t * i_buffer = reinterpret_cast<uint8_t *>(lidInfo.vAddr);
        const uint8_t HEADER_MAGIC[]= { 0xFD, '7', 'z', 'X', 'Z', 0x00 };
        bool l_XZ_compressed = (0 == memcmp(i_buffer, HEADER_MAGIC, sizeof(HEADER_MAGIC)));
        // uncompressedPayloadSize is the buffer size which the decompression will be expanded to

        uint64_t i_size = lidInfo.size;
        uint64_t io_size = l_payloadBase_remaining_size;
        uint8_t * o_buffer = payloadBase_virt_addr_ptr;

        // Only the PowerVM ordered list of lids come here
        if (l_XZ_compressed)
        {
            l_errl = decompressLid(i_buffer, o_buffer,
                            i_size, io_size);
            if (l_errl)
            {
                break;
            }
            UTIL_FT("HLL::managePhypLids lidInfo.id=0x%X ORIGINAL compressed=0x%X (%d) NEW uncompressed=0x%X (%d)",
                lidInfo.id, i_size, i_size, io_size, io_size);

        }
        else
        {
            UTIL_FT("HLL::managePhypLids lidInfo.id=0x%X ORIGINAL uncompressed=0x%X (%d) NO CHANGE",
                lidInfo.id, i_size, i_size);
            io_size = i_size; // common io_size to use for later handling
            // This path is NO XZ compresssion, so just copy to payloadBase MAINSTORE
            const uint32_t BLOCK_SIZE = 4096;
            for (uint32_t i = 0; i < i_size; i += BLOCK_SIZE)
            {
                memcpy(reinterpret_cast<void*>(o_buffer + i),
                        const_cast<uint8_t *>(i_buffer + i),
                        std::min( (static_cast<uint32_t>(i_size) - i), BLOCK_SIZE) );
            }
        }

        payloadBase_virt_addr_ptr += io_size;

        if (io_size >= l_payloadBase_remaining_size)
        {
            UTIL_FT("HLL::managePhypLids PROBLEM o_totalSize=%d l_payloadBase_remaining_size=%d io_size=%d", o_totalSize, l_payloadBase_remaining_size, io_size);
            assert(false, "HLL::managePhypLids PHYP PAYLOAD TOO LARGE");
        }
        else
        {
            l_payloadBase_remaining_size -= io_size;
        }
        o_totalSize += io_size; //new uncompressed size
    }   // for each lid
    UTIL_FT("HLL::managePhypLids o_totalSize=%d l_payloadBase_remaining_size=%d", o_totalSize, l_payloadBase_remaining_size);
    if (payloadBase_virt_addr != nullptr)
    {
        int l_mm_rc = mm_block_unmap(payloadBase_virt_addr);
        if(l_mm_rc != 0)
        {
            UTIL_FT(ERR_MRK"HLL::managePhypLids Fail from mm_block_unmap rc=%d payloadBase_virt_addr=0x%X",
                    l_mm_rc, payloadBase_virt_addr);
            /*@
             * @moduleid          Util::UTIL_HLL_MANAGE_PHYP
             * @reasoncode        Util::UTIL_MM_BLOCK_UNMAP_FAILED
             * @userdata1         Address being removed
             * @userdata2         rc from mm_block_unmap
             * @devdesc           Error calling mm_block_unmap
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           Util::UTIL_HLL_MANAGE_PHYP,
                           Util::UTIL_MM_BLOCK_UNMAP_FAILED,
                           reinterpret_cast<uint64_t>(payloadBase_virt_addr),
                           l_mm_rc,
                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_errl->collectTrace(UTIL_COMP_NAME);
            break;
        }
        payloadBase_virt_addr = nullptr;
    }

    } while(0);

    return l_errl;

}

errlHndl_t HLLMgr::loadLids(GroupInfo& io_groupInfo,
                                           size_t& o_totalSize)
{
    errlHndl_t l_errl = nullptr;

    // Force total size to zero
    o_totalSize = 0;
    // Pointer to mainstore memory temp space
    uint8_t* l_pLidVaddr = reinterpret_cast<uint8_t*>(iv_pVaddr);
    //  ^^ Can be EITHER BASE OR TMP
    // Remaining size to load lids into
    size_t l_remainSize = iv_maxSize;

    // Iterate through all Lids associated with a group
    // NOTE: iterate by reference to update lidInfo
    for (auto & lidInfo : io_groupInfo.lidIds)
    {
        // Get Lid from FSP/BMC
        UtilLidMgr l_lidMgr(lidInfo.id);
        // Get size of current lid to be loaded
        size_t l_lidSize = 0;
        l_errl = l_lidMgr.getLidSize(l_lidSize);
        if(l_errl)
        {
            UTIL_FT(ERR_MRK"HLLMgr::loadLids - Error getting size of lidId=0x%.8x",
                    lidInfo.id);
            break;
        }

        uint32_t l_reportedLidSize = 0;
        // Load lid into vaddr location. API will check if remaining size is
        // enough; throwing an error if not.
        l_errl = l_lidMgr.getLid(reinterpret_cast<void*>(l_pLidVaddr),
                                    l_remainSize,
                                    &l_reportedLidSize);
        if(l_errl)
        {
            UTIL_FT(ERR_MRK"HLLMgr::loadLids - Error getting lidId=0x%.8x",
                    lidInfo.id);
            break;
        }

        if(l_reportedLidSize)
        {
            l_lidSize = l_reportedLidSize;
        }

        // Special cases during build when the lid is built before knowing the final size, i.e. MLL (81E002FF)
        // In mixed V1 and V3 scopes (like release-fw1060) this may occur during HLL handling
        // We also exclude HLL_LIDID here since we are reading in the HLL_LIDID here and will run
        // verifyContainer on the HLL_LIDID size during the later security checking, all other lids need
        // to have their reported sizes match
        if ( ((lidInfo.size == 0) && (lidInfo.Unsigned)) || (lidInfo.id == Util::HLL_LIDID) )
        {
            // Update lid size
            UTIL_FT("HLLMgr::loadLids special handling lidInfo.id=0x%X l_lidSize=%d lidInfo.size=%d lidInfo.Unsigned=0x%X",
                lidInfo.id, l_lidSize, lidInfo.size, lidInfo.Unsigned);
            lidInfo.size = l_lidSize;
        }

        if (SECUREBOOT::enabled())
        {
            HashEntry hash = {0};
            SECUREBOOT::hashBlob(reinterpret_cast<void*>(l_pLidVaddr), l_reportedLidSize, hash.HashCalc);
            if (l_reportedLidSize != lidInfo.size)
            {
                // We are reading in the lids here, so the HLL_LIDID is validated
                // by the VerifyContainer with a secure header, so ignore its miscompare
                // The HLL_LIDID is the data we need in order to read and validate
                // reported sizes when lids are read, so we rely on the VerifyContainer
                // for the validation of the HLL_LIDID size itself.
                if (lidInfo.id != Util::HLL_LIDID)
                {
                    /*@
                    * @moduleid          Util::UTIL_HLL_LOADLIDS
                    * @reasoncode        Util::UTIL_HLL_SIZE_MISCOMPARE
                    * @userdata1[00:31]  lidInfo.size
                    * @userdata1[32:63]  l_reportedLidSize
                    * @userdata2[00:31]  lidInfo.id
                    * @devdesc           Size miscompare on hashBlob
                    * @custdesc          Firmware Error
                    */
                    l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                Util::UTIL_HLL_LOADLIDS,
                                Util::UTIL_HLL_SIZE_MISCOMPARE,
                                errl_util::SrcUserData(
                                    errl_util::bits{0, 31}, lidInfo.size,
                                    errl_util::bits{32, 63},l_reportedLidSize),
                                errl_util::SrcUserData(
                                    errl_util::bits{0, 31}, lidInfo.id),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    // Extra info to help direct problem source being PHYP HLL
                    l_errl->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE,
                                HWAS::SRCI_PRIORITY_HIGH);
                    l_errl->collectTrace(UTIL_COMP_NAME);
                    UTIL_FT(ERR_MRK"HLLMgr::loadLids - size miscompare on hashBlob validation lidInfo.id=0x%X lidInfo.size=%d l_reportedLidSize=%d",
                        lidInfo.id, lidInfo.size, l_reportedLidSize);
                    SECUREBOOT::handleSecurebootFailure(l_errl);
                    assert(false,"Bug! handleSecurebootFailure shouldn't return!");
                }
            }


            // @TODO JIRA:PFHB-802 Skipping V3 verification for now
            // (HLL is V3 based)
            UTIL_FT(INFO_MRK"HLLMgr::loadLids - Skipping Hash Verification on "
                "lidInfo.id=0x%X, lidInfo.size=%d l_reportedLidSize=%d, "
                "hash=0x%08X",
                lidInfo.id, lidInfo.size, l_reportedLidSize,
                sha512_to_u32(hash.HashCalc));
            //if (memcmp(hash.HashCalc, &lidInfo.hllHash, sizeof(HashEntry)) != 0)
            if (0)
            {
                /*@
                * @moduleid          Util::UTIL_HLL_LOADLIDS
                * @reasoncode        Util::UTIL_HLL_HASH_FAILURE
                * @userdata1[00:31]  lidInfo.id
                * @userdata1[32:63]  lidInfo.size
                * @devdesc           Secure hash failure on lid
                * @custdesc          Firmware Error
                */
                l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            Util::UTIL_HLL_LOADLIDS,
                            Util::UTIL_HLL_HASH_FAILURE,
                            errl_util::SrcUserData(
                                errl_util::bits{0, 31}, lidInfo.id,
                                errl_util::bits{32, 63},lidInfo.size),
                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_errl->addFFDC(UTIL_COMP_ID,
                            &lidInfo.hllHash,
                            sizeof(HashEntry),
                            0,      // version
                            ERRORLOG::ERRL_UDT_HASH, // parser ignores data
                            false); // merge
                l_errl->addFFDC(UTIL_COMP_ID,
                            hash.HashCalc,
                            sizeof(HashEntry),
                            0,      // version
                            ERRORLOG::ERRL_UDT_HASH, // parser ignores data
                            false); // merge
                // Extra info to help direct problem source being PHYP HLL
                l_errl->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE,
                            HWAS::SRCI_PRIORITY_HIGH);
                l_errl->collectTrace(UTIL_COMP_NAME);
                UTIL_FT(ERR_MRK"HLLMgr::loadLids - failed hashBlob validation");
                SECUREBOOT::handleSecurebootFailure(l_errl);
                assert(false,"Bug! handleSecurebootFailure shouldn't return!");
            }
            UTIL_FT("HLLMgr::loadLids lidInfo.id=0x%X passed HashCalc", lidInfo.id);
        }

        // Store current LID load virtual address
        lidInfo.vAddr = l_pLidVaddr;

        // Increment vaddr pointer
        l_pLidVaddr += l_lidSize;
        // Decrement size remaining in mainstore memory temp space
        // Above getLid should have caught any buffer overflow
        if (l_lidSize < l_remainSize)
        {
            l_remainSize -= l_lidSize;
        }

        // Increment total size
        o_totalSize += lidInfo.size;
    }

    UTIL_FT(EXIT_MRK"HLLMgr::loadLids Using total=%d of max=%d", o_totalSize, iv_maxSize);

    return l_errl;
}

} // end namespace HLL
