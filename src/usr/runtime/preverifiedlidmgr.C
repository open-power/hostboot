/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/preverifiedlidmgr.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
#include <runtime/preverifiedlidmgr.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <utility>
#include <runtime/populate_hbruntime.H>
#include <util/align.H>
#include <util/utillidmgr.H>
#include <util/utillidpnor.H>
#include <initservice/initserviceif.H>
#include <util/singleton.H>
#include <stdio.h>
#include <arch/ppc.H>
#include <targeting/common/target.H>
#include <targeting/common/attributes.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <secureboot/containerheader.H>
#include <runtime/common/runtime_utils.H>
#include <runtime/runtime_reasoncodes.H>
#include <util/utilmclmgr.H>

extern trace_desc_t *g_trac_runtime;

// Set static variables
TARGETING::PAYLOAD_KIND PreVerifiedLidMgr::cv_payloadKind = TARGETING::PAYLOAD_KIND_NONE;
std::map<uint64_t,bool> PreVerifiedLidMgr::cv_lidsLoaded {};
PreVerifiedLidMgr::ResvMemInfo* PreVerifiedLidMgr::cv_pResvMemInfo = nullptr;
PreVerifiedLidMgr::ResvMemInfo PreVerifiedLidMgr::cv_resvMemInfo {};
PreVerifiedLidMgr::ResvMemInfo PreVerifiedLidMgr::cv_phypResvMemInfo {};
mutex_t PreVerifiedLidMgr::cv_mutex = MUTEX_INITIALIZER;
mutex_t PreVerifiedLidMgr::cv_loadImageMutex = MUTEX_INITIALIZER;
bool PreVerifiedLidMgr::cv_addFakeHdrs = false;
PNOR::SectionId PreVerifiedLidMgr::cv_curPnorSecId = PNOR::INVALID_SECTION;

/********************
 Public Methods
 ********************/

void PreVerifiedLidMgr::initLock(const uint64_t i_prevAddr,
                                 const uint64_t i_prevSize,
                                 const size_t i_rangeId)
{
    Singleton<PreVerifiedLidMgr>::instance()._initLock(i_prevAddr,
                                                       i_prevSize,
                                                       i_rangeId);
}

void PreVerifiedLidMgr::unlock()
{
    Singleton<PreVerifiedLidMgr>::instance()._unlock();
}


errlHndl_t PreVerifiedLidMgr::loadFromPnor(const PNOR::SectionId i_sec,
                                           const uint64_t i_addr,
                                           const size_t i_size)
{
    return Singleton<PreVerifiedLidMgr>::instance()._loadFromPnor(i_sec,
                                                                  i_addr,
                                                                  i_size);
}

errlHndl_t PreVerifiedLidMgr::loadFromMCL(
    const uint32_t  i_lidId,
    const uint64_t  i_addr,
    const size_t    i_size,
    const bool      i_isPhypComp,
    const bool      i_firstLid,
          uint64_t& o_resvMemAddr)
{
    return Singleton<PreVerifiedLidMgr>::instance().
        _loadFromMCL(
            i_lidId,
            i_addr,
            i_size,
            i_isPhypComp,
            i_firstLid,
            o_resvMemAddr);
}

/********************
 Private Implementations of Static Public Methods
 ********************/

void PreVerifiedLidMgr::_initLock(const uint64_t i_prevAddr,
                                  const uint64_t i_prevSize,
                                  const size_t i_rangeId)
{
    mutex_lock(&cv_mutex);

    cv_payloadKind = TARGETING::PAYLOAD_KIND_NONE;

    // Default Reserved Memory Information
    cv_resvMemInfo.rangeId = i_rangeId;
    cv_resvMemInfo.curAddr = ALIGN_PAGE(i_prevAddr);
    cv_resvMemInfo.prevSize = ALIGN_PAGE(i_prevSize);

    // PHYP Reserved Memory Information
    cv_phypResvMemInfo.rangeId = i_rangeId;
    // PHYP lids loaded at HRMOR
    // Get Target Service, and the system target.
    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    assert(l_sys!=nullptr,"Top Level Target is nullptr");
    cv_phypResvMemInfo.curAddr = (l_sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>()
                                 * MEGABYTE);

    // PHYP should be placed starting exactly at HRMOR, so make prevSize 0
    cv_phypResvMemInfo.prevSize = 0;

    // Refer to default reserved memory
    cv_pResvMemInfo = &cv_resvMemInfo;

    // Set variables based on payload Kind
    // Note: For PHYP we build up starting at the end of the
    //       previously allocated HOMER/OCC areas, for OPAL we build
    //       downwards from the top of memory where the HOMER/OCC
    //       areas were placed

    // Set default next physical address to simply increment in order
    getNextAddress = getNextPhypAddress;

    if(TARGETING::is_phyp_load())
    {
        cv_payloadKind = TARGETING::PAYLOAD_KIND_PHYP;
    }
    else if(TARGETING::is_sapphire_load())
    {
        cv_payloadKind = TARGETING::PAYLOAD_KIND_SAPPHIRE;
        getNextAddress = getNextOpalAddress;
    }
}

void PreVerifiedLidMgr::_unlock()
{
    mutex_unlock(&cv_mutex);
}

errlHndl_t PreVerifiedLidMgr::_loadFromPnor(const PNOR::SectionId i_sec,
                                            const uint64_t i_addr,
                                            const size_t i_size)
{
    mutex_lock(&cv_loadImageMutex);

    TRACFCOMP(g_trac_runtime, ENTER_MRK"PreVerifiedLidMgr::_loadFromPnor - sec %s",
              PNOR::SectionIdToString(i_sec));

#ifdef CONFIG_SECUREBOOT
    // If SB compiled in, only add fake secure header if the section is never
    // signed. e.g. RINGOVD section
    // Otherwise always add fake secure header when SB compiled out
    if (!1 /* FIXME RTC:257489 RUNTIME::isPreVerifiedSectionSecure(i_sec)*/)
    {
#endif
        // Check if Header is mising
        if (!PNOR::cmpSecurebootMagicNumber(
                reinterpret_cast<uint8_t*>(i_addr)))
        {
            TRACFCOMP(g_trac_runtime, "PreVerifiedLidMgr::_loadFromPnor adding fake header to %s",
                      PNOR::SectionIdToString(i_sec));
            // Add fake headers to pnor loads
            cv_addFakeHdrs = true;
            cv_curPnorSecId = i_sec;
        }
#ifdef CONFIG_SECUREBOOT
    }
#endif

    errlHndl_t l_errl = nullptr;

    do {

    // Translate Pnor Section Id to Lid
    auto l_lids = Util::getPnorSecLidIds(i_sec);
    TRACDCOMP( g_trac_runtime, "PreVerifiedLidMgr::_loadFromPnor - getPnorSecLidIds lid = 0x%X, containerLid = 0x%X",
               l_lids.lid, l_lids.containerLid);
    if(l_lids.lid == Util::INVALID_LIDID)
    {
        TRACFCOMP( g_trac_runtime, ERR_MRK "PreVerifiedLidMgr::_loadFromPnor - Pnor Section = %s not associated with any Lids",
                   PNOR::SectionIdToString(i_sec));

        /*@
         * @errortype
         * @severity      ERRL_SEV_UNRECOVERABLE
         * @moduleid      RUNTIME::MOD_PREVERLIDMGR_LOAD_FROM_PNOR
         * @reasoncode    RUNTIME::RC_INVALID_LID
         * @userdata1     PNOR section
         * @userdata2     Lid id mapped from PNOR section
         * @devdesc       Trying to load invalid lid
         * @custdesc      Platform security problem detected
         */
        l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            RUNTIME::MOD_PREVERLIDMGR_LOAD_FROM_PNOR,
            RUNTIME::RC_INVALID_LID,
            i_sec,
            l_lids.lid,
            true);
        l_errl->collectTrace(RUNTIME_COMP_NAME);
        break;
    }

    // Only load if not previously done.
    if( isLidLoaded(l_lids.containerLid) && isLidLoaded(l_lids.lid) )
    {
        TRACFCOMP( g_trac_runtime, "PreVerifiedLidMgr::_loadFromPnor - sec %s already loaded",
                PNOR::SectionIdToString(i_sec));
        break;
    }

    // Get next available HB reserved memory address
    cv_pResvMemInfo->curAddr = getNextAddress(i_size);

    bool l_loadImage = false;
    if(cv_payloadKind == TARGETING::PAYLOAD_KIND_PHYP)
    {
        l_loadImage = true;
        // Verified Lid - Header Only
        if ( (l_lids.containerLid != Util::INVALID_LIDID) &&
             !isLidLoaded(l_lids.containerLid))
        {
            char l_containerLidStr [Util::lidIdStrLength] {};
            snprintf (l_containerLidStr, Util::lidIdStrLength, "%08X",
                    l_lids.containerLid);
            l_errl = RUNTIME::setNextHbRsvMemEntry(HDAT::RHB_TYPE_VERIFIED_LIDS,
                                                   cv_pResvMemInfo->rangeId,
                                                   cv_pResvMemInfo->curAddr,
                                                   PAGE_SIZE,
                                                   l_containerLidStr);
            if(l_errl)
            {
                TRACFCOMP( g_trac_runtime, ERR_MRK"PreVerifiedLidMgr::_loadFromPnor - setNextHbRsvMemEntry Lid header failed");
                break;
            }
        }

        // Verified Lid - Content Only
        if ( (l_lids.lid != Util::INVALID_LIDID) &&
             !isLidLoaded(l_lids.lid))
        {
            // Ensure there is content besides the header and that the size is
            // valid
            if(i_size <= PAGE_SIZE)
            {
                TRACFCOMP( g_trac_runtime, ERR_MRK "PreVerifiedLidMgr::_loadFromPnor - PNOR Section %s size 0x%X is not greater than the header size 0x%X, thus missing actual content to pre-verify",
                           PNOR::SectionIdToString(i_sec), i_size, PAGE_SIZE);

                /*@
                 * @errortype
                 * @severity      ERRL_SEV_UNRECOVERABLE
                 * @moduleid      RUNTIME::MOD_PREVERLIDMGR_LOAD_FROM_PNOR
                 * @reasoncode    RUNTIME::RC_PREVER_INVALID_SIZE
                 * @userdata1     PNOR section
                 * @userdata2     Size of section including header
                 * @devdesc       No content after Section header or size was parsed from secure header incorrectly.
                 * @custdesc      Platform security problem detected
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    RUNTIME::MOD_PREVERLIDMGR_LOAD_FROM_PNOR,
                    RUNTIME::RC_PREVER_INVALID_SIZE,
                    i_sec,
                    i_size,
                    true);
                l_errl->collectTrace(RUNTIME_COMP_NAME);
                break;
            }

            char l_lidStr[Util::lidIdStrLength] {};
            snprintf (l_lidStr, Util::lidIdStrLength, "%08X",l_lids.lid);
            l_errl = RUNTIME::setNextHbRsvMemEntry(HDAT::RHB_TYPE_VERIFIED_LIDS,
                                                   cv_pResvMemInfo->rangeId,
                                                   cv_pResvMemInfo->curAddr+PAGE_SIZE,
                                                   i_size-PAGE_SIZE,
                                                   l_lidStr);
            if(l_errl)
            {
                TRACFCOMP( g_trac_runtime, ERR_MRK"PreVerifiedLidMgr::_loadFromPnor - setNextHbRsvMemEntry Lid content failed");
                break;
            }
        }
    }
    else if(cv_payloadKind == TARGETING::PAYLOAD_KIND_SAPPHIRE)
    {
        l_loadImage = true;
        // Verified PNOR - Header + Content
        l_errl = RUNTIME::setNextHbRsvMemEntry(HDAT::RHB_TYPE_VERIFIED_PNOR,
                                               cv_pResvMemInfo->rangeId,
                                               cv_pResvMemInfo->curAddr,
                                               getAlignedSize(i_size),
                                               PNOR::SectionIdToString(i_sec),
                                               HDAT::RHB_READ_ONLY);
        if(l_errl)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK"PreVerifiedLidMgr::_loadFromPnor - setNextHbRsvMemEntry PNOR content failed");
            break;
        }
    }

    if (l_loadImage)
    {
        // Load image into HB reserved memory
        l_errl = loadImage(i_addr, i_size);
        if(l_errl)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK"PreVerifiedLidMgr::_loadFromPnor - setNextHbRsvMemEntry PNOR content failed");
            break;
        }
    }

    // Indicate the full PNOR section has been loaded.
    // Include both the header and content lids
    cv_lidsLoaded.insert(std::make_pair(l_lids.containerLid, true));
    cv_lidsLoaded.insert(std::make_pair(l_lids.lid, true));

    } while(0);

    // Force fake header bool to be false and clear cur PNOR section id
    cv_addFakeHdrs = false;
    cv_curPnorSecId = PNOR::INVALID_SECTION;

    TRACFCOMP( g_trac_runtime, EXIT_MRK"PreVerifiedLidMgr::_loadFromPnor");

    mutex_unlock(&cv_loadImageMutex);

    return l_errl;
}

errlHndl_t PreVerifiedLidMgr::_loadFromMCL(
    const uint32_t  i_lidId,
    const uint64_t  i_addr,
    const size_t    i_size,
    const bool      i_isPhypComp,
    const bool      i_firstLid,
          uint64_t& o_resvMemAddr)
{
    mutex_lock(&cv_loadImageMutex);

    TRACFCOMP(g_trac_runtime, ENTER_MRK"PreVerifiedLidMgr::_loadFromMCL lid = 0x%X",
              i_lidId);

    // Force fake header bool to be false in MCL path
    cv_addFakeHdrs = false;

    errlHndl_t l_errl = nullptr;

    // Switch to Different Memory Info for PHYP component
    // Exception: put the PHyp signature LID in the normal reserved memory area
    if (i_isPhypComp && !i_firstLid)
    {
        cv_pResvMemInfo = &cv_phypResvMemInfo;
    }

    do {

    // Only load if not previously done.
    if( isLidLoaded(i_lidId) )
    {
        TRACFCOMP( g_trac_runtime, "PreVerifiedLidMgr::_loadFromMCL - lid 0x%08X already loaded",
                   i_lidId);
        continue;
    }

    // Get next available HB reserved memory address
    cv_pResvMemInfo->curAddr = getNextAddress(i_size);

    // Return the address the lid was loaded to the caller
    o_resvMemAddr = cv_pResvMemInfo->curAddr;

    if(cv_payloadKind == TARGETING::PAYLOAD_KIND_PHYP)
    {
        // Verified Lid
        char l_lidStr[Util::lidIdStrLength] {};
        snprintf (l_lidStr, Util::lidIdStrLength, "%08X",i_lidId);
        l_errl = RUNTIME::setNextHbRsvMemEntry(HDAT::RHB_TYPE_VERIFIED_LIDS,
                                               cv_pResvMemInfo->rangeId,
                                               cv_pResvMemInfo->curAddr,
                                               i_size,
                                               l_lidStr,
                                               HDAT::RHB_READ_WRITE,
                                               // Memory limit everything that
                                               // is not a PHYP component
                                               !(i_isPhypComp));
        if(l_errl)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK"PreVerifiedLidMgr::_loadFromMCL - setNextHbRsvMemEntry Lid content failed");
            break;
        }

        // Phyp component has already been loaded and verified before MCL mgr
        // Simply update HB reserved prev size in Phyp component case
        // Special case: If it's the PHyp signature LID, handle below
        if (i_isPhypComp && !i_firstLid)
        {
            // align previous size to page size to ensure starting addresses
            // are page aligned.
            cv_pResvMemInfo->prevSize = ALIGN_PAGE(i_size);
        }
        else
        {
            // Load image into HB reserved memory
            // Special case: If it's the PHyp signature LID, pull the
            // data from the cached PHyp header, instead of the
            // scratch area
            uint64_t addr = (i_isPhypComp && i_firstLid) ?
                reinterpret_cast<uint64_t>(
                    const_cast<uint8_t*>(
                        ::MCL::MasterContainerLidMgr::getPhypHeader()))
                : i_addr;
            l_errl = loadImage(addr, i_size);
            if(l_errl)
            {
                TRACFCOMP( g_trac_runtime, ERR_MRK"PreVerifiedLidMgr::_loadFromMCL - Load Image failed");
                break;
            }
        }

        // Indicate the lid has been loaded
        cv_lidsLoaded.insert(std::make_pair(i_lidId, true));
    }

    } while (0);

    // Force switch back to default reserved memory info
    cv_pResvMemInfo = &cv_resvMemInfo;

    TRACFCOMP(g_trac_runtime, EXIT_MRK"PreVerifiedLidMgr::_loadFromMCL");

    mutex_unlock(&cv_loadImageMutex);

    return l_errl;
}

/********************
 Private/Protected Methods
 ********************/

PreVerifiedLidMgr& PreVerifiedLidMgr::getInstance()
{
    return Singleton<PreVerifiedLidMgr>::instance();
}

uint64_t PreVerifiedLidMgr::getAlignedSize(const size_t i_imgSize)
{
    return ALIGN_X(i_imgSize, HBRT_RSVD_MEM_OPAL_ALIGN);
}

uint64_t PreVerifiedLidMgr::getNextPhypAddress(const size_t i_prevSize)
{
    return cv_pResvMemInfo->curAddr + cv_pResvMemInfo->prevSize;
}

uint64_t PreVerifiedLidMgr::getNextOpalAddress(const size_t i_curSize)
{
    return cv_pResvMemInfo->curAddr - getAlignedSize(i_curSize);
}

bool PreVerifiedLidMgr::isLidLoaded(uint32_t i_lidId)
{
    bool l_loaded = false;

    if (cv_lidsLoaded.count(i_lidId) > 0)
    {
        l_loaded = true;
    }

    return l_loaded;
}

errlHndl_t PreVerifiedLidMgr::loadImage(const uint64_t i_imgAddr,
                                        const size_t i_imgSize)
{
    TRACDCOMP( g_trac_runtime, ENTER_MRK"PreVerifiedLidMgr::loadImage addr = 0x%X, size = 0x%X",
               i_imgAddr, i_imgSize);

    errlHndl_t l_errl = nullptr;

    do {

    uint64_t l_tmpVaddr = 0;
    size_t l_alignedSize = ALIGN_PAGE(i_imgSize);

    // Load the Verified image into HB resv memory
    l_errl = RUNTIME::mapPhysAddr(cv_pResvMemInfo->curAddr, l_alignedSize, l_tmpVaddr);
    if(l_errl)
    {
        TRACFCOMP( g_trac_runtime, ERR_MRK"PreVerifiedLidMgr::loadImage - mapPhysAddr failed");
        break;
    }

    TRACDCOMP(g_trac_runtime, "PreVerifiedLidMgr::loadImage - curAddr 0x%X, size 0x%X, vaddr 0x%X",
              cv_pResvMemInfo->curAddr, i_imgSize, l_tmpVaddr);

    // Inject a fake header when loading from PNOR and secureboot is compiled
    // out.
    if(cv_addFakeHdrs)
    {
        TRACFCOMP(g_trac_runtime, "PreVerifiedLidMgr::loadImage inject fake header before image without one");
        SECUREBOOT::ContainerHeader l_fakeHdr;
        l_errl = l_fakeHdr.setFakeHeader(i_imgSize,
                                      PNOR::SectionIdToString(cv_curPnorSecId));
        if(l_errl)
        {
            break;
        }
        // Inject Fake header into reserved memory
        memcpy(reinterpret_cast<void*>(l_tmpVaddr),
               l_fakeHdr.fakeHeader(),
               PAGE_SIZE);

        if(i_imgSize <= PAGE_SIZE)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "PreVerifiedLidMgr::loadImage - Image size 0x%X is not greater than the header size 0x%X, thus no space to inject fake header",
                       i_imgSize, PAGE_SIZE);

            /*@
             * @errortype
             * @severity      ERRL_SEV_UNRECOVERABLE
             * @moduleid      RUNTIME::MOD_PREVERLIDMGR_LOAD_IMAGE
             * @reasoncode    RUNTIME::RC_PREVER_INVALID_SIZE
             * @userdata1     Size of section including space for header
             * @userdata2     Size of header
             * @devdesc       No space left for fake header injection
             * @custdesc      Platform security problem detected
             */
            l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                RUNTIME::MOD_PREVERLIDMGR_LOAD_IMAGE,
                RUNTIME::RC_PREVER_INVALID_SIZE,
                i_imgSize,
                PAGE_SIZE,
                true);
            l_errl->collectTrace(RUNTIME_COMP_NAME);
            break;
        }
        // Include rest of image after header
        // NOTE: Do not use aligned size for memcpy
        memcpy(reinterpret_cast<void*>(l_tmpVaddr+PAGE_SIZE),
               reinterpret_cast<void*>(i_imgAddr),
               i_imgSize-PAGE_SIZE);
    }
    else
    {
        TRACDCOMP(g_trac_runtime, "PreVerifiedLidMgr::loadImage default load");
        // NOTE: Do not use aligned size for memcpy
        memcpy(reinterpret_cast<void*>(l_tmpVaddr),
               reinterpret_cast<void*>(i_imgAddr),
               i_imgSize);
    }

    l_errl = RUNTIME::unmapVirtAddr(l_tmpVaddr);
    if(l_errl)
    {
        TRACFCOMP( g_trac_runtime, ERR_MRK"PreVerifiedLidMgr::loadImage - unmapVirtAddr failed");
        break;
    }

    if(cv_payloadKind == TARGETING::PAYLOAD_KIND_SAPPHIRE)
    {
        // Update previous size using aligned size for OPAL alignment even if
        // that means there is some wasted space.
        cv_pResvMemInfo->prevSize = getAlignedSize(i_imgSize);
    }
    else
    {
        // align previous size to page size to ensure starting addresses are
        // page aligned.
        cv_pResvMemInfo->prevSize = l_alignedSize;
    }

    } while(0);

    TRACDCOMP( g_trac_runtime, EXIT_MRK"PreVerifiedLidMgr::loadImage");

    return l_errl;
}

uint64_t PreVerifiedLidMgr::getNextResMemAddr(const size_t i_size)
{
    return Singleton<PreVerifiedLidMgr>::instance().getNextAddress(i_size);
}
