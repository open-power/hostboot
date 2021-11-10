/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnorrp.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
/* [+] Google Inc.                                                        */
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
#include <stdlib.h>
#include <string.h>
#include "pnorrp.H"
#include "spnorrp.H"
#include <pnor/pnor_reasoncodes.H>
#include <initservice/taskargs.H>
#include <sys/msg.h>
#include <arch/ppc.H>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <limits.h>
#include <string.h>
#include <sys/mm.h>
#include <errno.h>
#include <initservice/initserviceif.H>
#include "ffs.h"   //Common header file with BuildingBlock.
#include "common/ffs_hb.H"//Hostboot definition of user data in ffs_entry struct
#include <pnor/ecc.H>
#include <kernel/console.H>
#include <endian.h>
#include <util/align.H>
#include <pnor/pnorif.H>
#include "pnor_common.H"
#include <hwas/common/hwasCallout.H>
#include <console/consoleif.H>

#ifdef CONFIG_SECUREBOOT
#include <secureboot/service.H>
#include <secureboot/containerheader.H>
#include <secureboot/settings.H>
#include <secureboot/header.H>
#include <secureboot/trustedbootif.H>
#endif

#ifdef CONFIG_FILE_XFER_VIA_PLDM
#include <pldm/pldm_errl.H>
#include <pnor/pnor_pldm_utils.H>
#endif

extern trace_desc_t* g_trac_pnor;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace PNOR;


/**
 * @brief   set up _start() task entry procedure for PNOR daemon
 */
TASK_ENTRY_MACRO( PnorRP::init );


/********************
 Public Methods
 ********************/

/**
 * @brief  Returns information about a given side of PNOR
 */
errlHndl_t PNOR::getSideInfo( PNOR::SideId i_side,
                              PNOR::SideInfo_t& o_info)
{
    return Singleton<PnorRP>::instance().getSideInfo(i_side,o_info);
}

/**
 * @brief  Return the size and address of a given section of PNOR data
 */
errlHndl_t PNOR::getSectionInfo( PNOR::SectionId i_section,
                                 PNOR::SectionInfo_t& o_info )
{
    return Singleton<PnorRP>::instance().getSectionInfo(i_section,o_info);
}

/**
 * @brief Returns whether a given section is available or not
 */
bool PNOR::isSectionAvailable(const PNOR::SectionId i_section)
{
    return Singleton<PnorRP>::instance().isSectionAvailable(i_section);
}

/**
 * @brief  Clear pnor section
 */
errlHndl_t PNOR::clearSection(PNOR::SectionId i_section)
{
    return Singleton<PnorRP>::instance().clearSection(i_section);
}

/**
 * @brief  Write the data for a given section into PNOR
 */
errlHndl_t PNOR::flush( PNOR::SectionId i_section)
{
    errlHndl_t l_err = NULL;
    do {
        PNOR::SectionInfo_t l_info;
        l_err = getSectionInfo(i_section, l_info);
        if (l_err)
        {
            TRACFCOMP(g_trac_pnor, "PNOR::flush: getSectionInfo errored,"
                    " secId: %d", (int)i_section);
            break;
        }
        uint8_t* l_vaddr = reinterpret_cast<uint8_t*>(l_info.vaddr);
        #ifdef CONFIG_SECUREBOOT
        if (l_info.secure)
        {
            // subtract 2 deltas to get the PNOR unsecured address
            l_vaddr = l_vaddr
               - VMM_VADDR_SPNOR_DELTA
               - VMM_VADDR_SPNOR_DELTA;
        }
        #endif
        int l_rc = mm_remove_pages (RELEASE, l_vaddr, l_info.size);
        if (l_rc)
        {
            TRACFCOMP(g_trac_pnor, "PNOR::flush: mm_remove_pages errored,"
                    " secId: %d, rc: %d", (int)i_section, l_rc);
            /*@
             *  @errortype
             *  @moduleid       PNOR::MOD_PNORRP_FLUSH
             *  @reasoncode     PNOR::RC_MM_REMOVE_PAGES_FAILED
             *  @userdata1      section Id
             *  @userdata2      RC
             *  @devdesc        mm_remove_pages failed
             *  @custdesc       Failed to remove pages
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PNOR::MOD_PNORRP_FLUSH,
                                        PNOR::RC_MM_REMOVE_PAGES_FAILED,
                                        i_section, l_rc, true);
            break;
        }
    } while (0);
    return l_err;
}

/**
 * @brief  check and fix correctable ECC for a given pnor section
 */
errlHndl_t PNOR::fixECC(PNOR::SectionId i_section)
{
    return Singleton<PnorRP>::instance().fixECC(i_section);
}

/**
 * @brief  Trace out which pages we loaded more than i_threshold times,
 *         then optionally clear the list.
 */
void PNOR::readAndClearCounter( uint32_t i_threshold,
                                bool i_clear )
{
    Singleton<PnorRP>::instance().readAndClearCounter(i_threshold,
                                                      i_clear);
}

#ifdef CONFIG_FILE_XFER_VIA_PLDM
const std::array<uint32_t, PNOR::NUM_SECTIONS>& PNOR::getLidIds()
{
    return Singleton<PnorRP>::instance().get_lid_ids();
}
#endif

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


/**
 * STATIC
 * @brief Static Initializer
 */
void PnorRP::init( errlHndl_t   &io_rtaskRetErrl )
{
    TRACUCOMP(g_trac_pnor, "PnorRP::init> " );
    uint64_t rc = 0;
    uint64_t rcs = 0; // spnorrp return code
    errlHndl_t  l_errl  =   NULL;

    if( Singleton<PnorRP>::instance().didStartupFail(rc)
#ifdef CONFIG_SECUREBOOT
#ifndef CONFIG_FILE_XFER_VIA_PLDM
        || Singleton<SPnorRP>::instance().didStartupFail(rcs)
#else
        || Singleton<SPnorRP>::instance().setupVmm(Singleton<PnorRP>::instance().iv_TOC)->didStartupFail(rcs)
#endif
#endif
      )
    {
        /*@
         *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
         *  @moduleid       PNOR::MOD_PNORRP_DIDSTARTUPFAIL
         *  @reasoncode     PNOR::RC_BAD_STARTUP_RC
         *  @userdata1      return code pnorrp
         *  @userdata2      return code spnorrp
         *
         *  @devdesc        PNOR startup task returned an error.
         * @custdesc    A problem occurred while accessing the boot flash.
         */
        l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                PNOR::MOD_PNORRP_DIDSTARTUPFAIL,
                                PNOR::RC_BAD_STARTUP_RC,
                                rc,
                                rcs,
                                true /*Add HB SW Callout*/ );

        l_errl->collectTrace(PNOR_COMP_NAME);
    }
    else
    {
        // Extend base image (HBB) when Hostboot first starts.  Since HBB is
        // never re-loaded, inhibit extending this image in runtime code.
        #ifndef __HOSTBOOT_RUNTIME
        #ifdef CONFIG_SECUREBOOT
        // Extend the base image to the TPM, regardless of how it was obtained
        l_errl = TRUSTEDBOOT::extendBaseImage();
        #endif
        #endif
    }

    io_rtaskRetErrl=l_errl;
}


/********************
 Helper Methods
 ********************/

/**
 * @brief  Static function wrapper to pass into task_create
 */
void* wait_for_message( void* unused )
{
    TRACUCOMP(g_trac_pnor, "wait_for_message> " );
    Singleton<PnorRP>::instance().waitForMessage();
    return NULL;
}

/********************
 Private/Protected Methods
 ********************/

/**
 * @brief  Constructor
 */
PnorRP::PnorRP()
:
iv_TOC_used(TOC_0)
,iv_msgQ(NULL)
,iv_startupRC(0)
,iv_shutdown_pending(false)
{
    TRACDCOMP(g_trac_pnor, "PnorRP::PnorRP> " );

    // setup everything in a separate function
    initDaemon();

    TRACFCOMP(g_trac_pnor, "< PnorRP::PnorRP : Startup Errors=%X ", iv_startupRC );
}

/**
 * @brief  Destructor
 */
PnorRP::~PnorRP()
{
    TRACDCOMP(g_trac_pnor, "PnorRP::~PnorRP> " );

    // delete the message queue we created
    if( iv_msgQ )
    {
        msg_q_destroy( iv_msgQ );
    }

    // should kill the task we spawned, but that isn't needed right now

    TRACDCOMP(g_trac_pnor, "< PnorRP::~PnorRP" );
}
#ifdef CONFIG_FILE_XFER_VIA_PLDM
errlHndl_t PnorRP::setupPnorVMM(void)
{
    errlHndl_t l_errhdl = nullptr;
    int rc = 0;
    int i = 0;
    bool alloc_fail = false;
    for(i = 0; i < PNOR::NUM_SECTIONS; i++)
    {
        if(iv_TOC[i].size == 0)
        {
            continue;
        }
        // create a Block, passing in the message queue
        rc = mm_alloc_block(iv_msgQ,
                            reinterpret_cast<void *>(iv_TOC[i].virtAddr),
                            iv_TOC[i].size );
        if( rc )
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::setupPnorVMM> Error from mm_alloc_block for address 0x%lx size 0x%x : rc=%d",
                       iv_TOC[i].virtAddr, iv_TOC[i].size, rc );
            alloc_fail = true;
            break;
        }

        //Register this memory range to be FLUSHed during a shutdown.
        INITSERVICE::registerBlock(reinterpret_cast<void *>(iv_TOC[i].virtAddr),
                                   iv_TOC[i].size,
                                   PNOR_PRIORITY);

        uint64_t access_type =
          (iv_TOC[i].misc & FFS_MISC_READ_ONLY) ? READ_ONLY : (WRITABLE | WRITE_TRACKED);

        rc = mm_set_permission(reinterpret_cast<void *>(iv_TOC[i].virtAddr),
                               iv_TOC[i].size,
                               access_type);

        if(rc)
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::setupPnorVMM> Error from mm_set_permission on address 0x%lx with access type 0x%lx : rc=%d",
                       iv_TOC[i].virtAddr, access_type, rc );
            break;
        }
    }

    if(rc)
    {
        /*@
        * @errortype
        * @moduleid     PNOR::MOD_PNORRP_SETUP_PNOR_VMM_PLDM
        * @reasoncode   PNOR::RC_EXTERNAL_ERROR
        * @userdata1      Requested Address
        * @userdata2[0:31]  rc from mm_alloc_block or mm_set_permission
        * @userdata2[32:63] 1 if rc if from mm_alloc_block, 0 if from mm_alloc_block
        * @devdesc      PnorRP::setupPnorVMM> Error from mm_alloc_block or mm_set_permission
        * @custdesc     A problem occurred while accessing the boot firmware.
        */
        l_errhdl = new ERRORLOG::ErrlEntry(
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                      PNOR::MOD_PNORRP_SETUP_PNOR_VMM_PLDM,
                      PNOR::RC_EXTERNAL_ERROR,
                      iv_TOC[i].virtAddr,
                      TWO_UINT32_TO_UINT64(TO_UINT32(rc),TO_UINT32(alloc_fail)),
                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errhdl->collectTrace(PNOR_COMP_NAME);
    }
    return l_errhdl;
}
#else
errlHndl_t PnorRP::setupPnorVMM()
{
    errlHndl_t l_errhdl = nullptr;

    do{
        // create a Block, passing in the message queue
        int rc = mm_alloc_block( iv_msgQ, (void*) BASE_VADDR, TOTAL_SIZE );
        if( rc )
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::setupPnorVMM> Error from mm_alloc_block : rc=%d", rc );
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORRP_SETUP_PNOR_VMM
             * @reasoncode   PNOR::RC_EXTERNAL_ERROR
             * @userdata1    Requested Address
             * @userdata2    rc from mm_alloc_block
             * @devdesc      PnorRP::setupPnorVMM> Error from mm_alloc_block
             * @custdesc     A problem occurred while accessing the boot flash.
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                           PNOR::MOD_PNORRP_SETUP_PNOR_VMM,
                           PNOR::RC_EXTERNAL_ERROR,
                           TO_UINT64(BASE_VADDR),
                           TO_UINT64(rc),
                           true /*Add HB SW Callout*/);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            break;
        }

        //Register this memory range to be FLUSHed during a shutdown.
        INITSERVICE::registerBlock(reinterpret_cast<void*>(BASE_VADDR),
                                   TOTAL_SIZE,PNOR_PRIORITY);
    }while(0);
    return l_errhdl;
}
#endif

/**
 * @brief Initialize the daemon
 */
void PnorRP::initDaemon()
{
    TRACUCOMP(g_trac_pnor, "PnorRP::initDaemon> " );
    errlHndl_t l_errhdl = nullptr;
    static_assert(TOTAL_SIZE <= VMM_VADDR_PNOR_RP_MAX_SIZE,
                  "Attempted to allocate too much VMM space for host fw data, check VMM_VADDR_PNOR_RP_MAX_SIZE and VMM_SIZE_RESERVED_PER_SECTION");

    do
    {
        // create a message queue
        iv_msgQ = msg_q_create();

        INITSERVICE::registerShutdownEvent( PNOR_COMP_ID,
                                            iv_msgQ,
                                            PNOR::MSG_SHUTDOWN,
                                            INITSERVICE::PNOR_RP_PRIORITY );

#ifdef CONFIG_FILE_XFER_VIA_PLDM
        l_errhdl = PLDM_PNOR::parse_ipl_lid_ids(iv_ipltime_lid_ids);
        if(l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, "An error occurred when while trying to get the ipl-time lid ids from the BMC.");
            break;
        }

        // Populate iv_TOC with the file table we got from PLDM
        l_errhdl = populateTOC(iv_TOC, iv_ipltime_lid_ids);
        if(l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, "PnorRP::initDaemon> populateTOC failed");
            break;
        }
#endif

        // Initialize the VMM memory pnorrp will use
        l_errhdl = setupPnorVMM();
        if(l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, "PnorRP::initDaemon> setupPnorVMM failed");
            break;
        }

#ifndef CONFIG_FILE_XFER_VIA_PLDM
        //Find and read the TOC in the PNOR to compute the sections and set
        //their correct permissions
        size_t l_sizeOfToc = 0;
        l_errhdl = findTOC(l_sizeOfToc);
        if( l_errhdl )
        {
            TRACFCOMP(g_trac_pnor, ERR_MRK"PnorRP::initDaemon: Failed to findTOC");
            errlCommit(l_errhdl, PNOR_COMP_ID);
            INITSERVICE::doShutdown(PNOR::RC_FINDTOC_FAILED);
        }

        l_errhdl = readTOC(l_sizeOfToc);
        if( l_errhdl )
        {
            TRACFCOMP(g_trac_pnor, ERR_MRK"PnorRP::initDaemon: Failed to readTOC");
            break;
        }

        l_errhdl =  setSideInfo (l_sizeOfToc);
        if(l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, "PnorRP::initDaemon> setSideInfo failed");
            break;
        }
#endif

        // start task to wait on the queue
        task_create( wait_for_message, NULL );
    } while(0);

    if( l_errhdl )
    {
        iv_startupRC = l_errhdl->reasonCode();
        errlCommit(l_errhdl,PNOR_COMP_ID);
    }


// Not supporting PNOR error in VPO
#ifndef CONFIG_VPO_COMPILE
    // call ErrlManager function - tell him that PNOR is ready!
    ERRORLOG::ErrlManager::errlResourceReady(ERRORLOG::PNOR);
#endif

    TRACUCOMP(g_trac_pnor, "< PnorRP::initDaemon" );
}

errlHndl_t PnorRP::getSideInfo( PNOR::SideId i_side,
                              PNOR::SideInfo_t& o_info)
{
    errlHndl_t l_err = NULL;
    do
    {
        //check to make sure side id is valid
        if (i_side != PNOR::INVALID_SIDE)
        {
            memcpy (&o_info, &iv_side[i_side], sizeof(SideInfo_t));
        }
        else
        {
            TRACFCOMP(g_trac_pnor, "Side:%d is currently not supported",
                    (int)i_side);
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORRP_GETSIDEINFO
             * @reasoncode   PNOR::RC_INVALID_PNOR_SIDE
             * @userdata1    Requested SIDE
             * @userdata2    0
             * @devdesc      PnorRP::getSideInfo> Side not supported
             * @custdesc     Processor NOR flash: Side not supported
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORRP_GETSIDEINFO,
                                            PNOR::RC_INVALID_PNOR_SIDE,
                                            TO_UINT64(i_side),
                                            0,true);
            break;
        }
    } while (0);
    return l_err;
}

/**
 *  @brief Returns whether a given section is available or not
 */
bool PnorRP::isSectionAvailable(const PNOR::SectionId i_section)
{
    bool available = false;
    uint64_t rc = 0;
    if(   (!didStartupFail(rc))
       && (i_section < PNOR::NUM_SECTIONS)
       && (!isInhibitedSection(i_section))
       && (iv_TOC[i_section].size != 0))
    {
        available = true;
    }
    return available;
}

/**
 * @brief  Return the size and address of a given section of PNOR data
 */
errlHndl_t PnorRP::getSectionInfo( PNOR::SectionId i_section,
                                   PNOR::SectionInfo_t& o_info )
{
    //TRACDCOMP(g_trac_pnor, "PnorRP::getSectionInfo> i_section=%d", i_section );
    errlHndl_t l_errhdl = NULL;
    PNOR::SectionId id = i_section;
    // Clear caller's hasHashTable since we only override when we find hash table
    o_info.hasHashTable = false;

    do
    {
        // Abort this operation if we had a startup failure
        uint64_t rc = 0;
        if( didStartupFail(rc) )
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::getSectionInfo> RP not properly initialized, failing : rc=%X", rc );
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORRP_GETSECTIONINFO
             * @reasoncode   PNOR::RC_STARTUP_FAIL
             * @userdata1    Requested Section
             * @userdata2    Startup RC
             * @devdesc      PnorRP::getSectionInfo> RP not properly initialized
             * @custdesc     Processor NOR flash:
             *               A problem occurred while accessing the boot flash.
             */
            l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               PNOR::MOD_PNORRP_GETSECTIONINFO,
                                               PNOR::RC_STARTUP_FAIL,
                                               TO_UINT64(i_section),
                                               rc,
                                               true /*Add HB SW Callout*/);
            l_errhdl->collectTrace(PNOR_COMP_NAME);

            // set the return section to our invalid data
            id = PNOR::INVALID_SECTION;
            break;
        }

        // inhibit any attempt to getSectionInfo on any attribute override
        // sections if secureboot is enabled
        bool l_inhibited = isInhibitedSection(id);

        // Zero-length means the section is invalid
        if( 0 == iv_TOC[id].size
            // attribute overrides inhibited by secure boot
            || l_inhibited
        )
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::getSectionInfo> Invalid Section Requested : i_section=%d (%s)", i_section, SectionIdToString(id));
            #ifdef CONFIG_SECUREBOOT
            if (l_inhibited)
            {
                TRACFCOMP( g_trac_pnor, "PnorRP::getSectionInfo> "
                "attribute overrides inhibited by secureboot");
            }
            #endif
            uint64_t size = iv_TOC[i_section].size;
            TRACFCOMP(g_trac_pnor, "o_info={ id=%d, size=%d , name=%s}",
                             iv_TOC[i_section].id, size, SectionIdToString(id) );
            /*@
             * @errortype
             * @moduleid         PNOR::MOD_PNORRP_GETSECTIONINFO
             * @reasoncode       PNOR::RC_INVALID_SECTION
             * @userdata1        Size of section
             * @userdata2[0:7]   TOC used
             * @userdata2[8:15]  Inhibited flag
             * @userdata2[16:23] Requested Section
             * @devdesc          PnorRP::getSectionInfo> Invalid Address for
             *                   read/write or prohibited by secureboot
             * @custdesc         A problem occurred while accessing the boot
             *                   flash.
             */
            l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               PNOR::MOD_PNORRP_GETSECTIONINFO,
                                               PNOR::RC_INVALID_SECTION,
                                               size,
                                               TO_UINT64(FOUR_UINT8_TO_UINT32(
                                                   iv_TOC_used,
                                                   l_inhibited,
                                                   i_section,
                                                   0)),
                                               true /*Add HB SW Callout*/);
            l_errhdl->collectTrace(PNOR_COMP_NAME);

            // set the return section to our invalid data
            id = PNOR::INVALID_SECTION;
            break;
        }
#ifdef CONFIG_FILE_XFER_VIA_PLDM
        if(iv_ipltime_lid_ids[i_section] == PLDM_PNOR::INVALID_LID)
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::getSectionInfo> Requested a section we have no lid mapping for : i_section=%d (%s)", i_section, SectionIdToString(id));
            /*@
             * @errortype
             * @moduleid         PNOR::MOD_PNORRP_GETSECTIONINFO
             * @reasoncode       PNOR::RC_NO_LID_MAPPING
             * @userdata1        Requested Section
             * @userdata2        Unused
             * @devdesc          No lid mapping found for requested section
             * @custdesc         A problem occurred while accessing the boot
             *                   flash.
             */
            l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               PNOR::MOD_PNORRP_GETSECTIONINFO,
                                               PNOR::RC_NO_LID_MAPPING,
                                               i_section,
                                               0,
                                               ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
            PLDM::addBmcErrorCallouts(l_errhdl);
            // set the return section to our invalid data
            id = PNOR::INVALID_SECTION;
            break;
        }
#endif

        if (PNOR::INVALID_SECTION != id)
        {
            TRACDCOMP( g_trac_pnor, "PnorRP::getSectionInfo: i_section=%d, id=%d", i_section, iv_TOC[i_section].id );

            // copy my data into the external format
            o_info.id = iv_TOC[id].id;
            o_info.name = SectionIdToString(id);
            o_info.sizeActual = iv_TOC[id].size;

#ifdef CONFIG_SECUREBOOT
            o_info.secure = iv_TOC[id].secure;
            o_info.size = iv_TOC[id].size;
            o_info.secureProtectedPayloadSize = 0; // for non secure sections
                                                   // the protected payload size
                                                   // defaults to zero
            // If a secure section and has a secure header handle secure
            // sections in SPnorRP's address space
            if (o_info.secure)
            {
                uint8_t* l_vaddr = reinterpret_cast<uint8_t*>(iv_TOC[id].virtAddr);
                // By adding VMM_VADDR_SPNOR_DELTA twice we can translate a pnor
                // address into a secure pnor address, since pnor, temp, and spnor
                // spaces are equidistant.
                // See comments in SPnorRP::verifySections() method in spnorrp.C
                // and the definition of VMM_VADDR_SPNOR_DELTA in vmmconst.h
                // for specifics.
                o_info.vaddr = reinterpret_cast<uint64_t>(l_vaddr)
                                                           + VMM_VADDR_SPNOR_DELTA
                                                           + VMM_VADDR_SPNOR_DELTA;

                // Get size of the secured payload for the secure section
                // Note: the payloadSize we get back is untrusted because
                // we are parsing the header in pnor (non secure space).
                size_t payloadTextSize = 0;
                // Do an existence check on the container to see if it's non-empty
                // and has valid beginning bytes. For optional Secure PNOR sections.

                SECUREBOOT::ContainerHeader l_conHdr;
                l_errhdl = l_conHdr.setHeader(l_vaddr);
                if (l_errhdl)
                {
                    TRACFCOMP(g_trac_pnor, ERR_MRK"PnorRP::getSectionInfo: setheader failed");
                    break;
                }
                payloadTextSize = l_conHdr.payloadTextSize();
                if ( payloadTextSize <= 0)
                {
                    TRACFCOMP(g_trac_pnor, ERR_MRK"PnorRP::getSectionInfo: non-zero protected payload text size expected for section %s",
                              o_info.name);

                    /*@
                     * @errortype
                     * @moduleid         PNOR::MOD_PNORRP_GETSECTIONINFO
                     * @reasoncode       PNOR::RC_SECTION_SIZE_IS_ZERO
                     * @userdata1        PNOR section
                     * @userdata2        Section's secure flag
                     * @devdesc          Protected Payload Size is 0
                     * @custdesc         Platform security problem detected
                     */
                    l_errhdl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PNOR::MOD_PNORRP_GETSECTIONINFO,
                                        PNOR::RC_SECTION_SIZE_IS_ZERO,
                                        i_section,
                                        o_info.secure,
                                        true /*Add HB SW Callout*/);
                    l_errhdl->collectTrace(PNOR_COMP_NAME);
                    l_errhdl->collectTrace(SECURE_COMP_NAME);
                    // set the return section to our invalid data
                    id = PNOR::INVALID_SECTION;
                    break;
                }

                // skip secure header for secure sections at this point in time
                o_info.vaddr += PAGESIZE;
                // now that we've skipped the header we also need to adjust the
                // size of the section to reflect that.
                // Note: For unsecured sections, the header skip and size decrement
                // was done previously in pnor_common.C
                o_info.size -= PAGESIZE;

                // Need to change size to accommodate for hash table
                if (l_conHdr.sb_flags()->sw_hash)
                {
                    o_info.vaddr += payloadTextSize;
                    // Hash page table needs to use containerSize as the base
                    // and subtract off header and hash table size
                    o_info.size = l_conHdr.totalContainerSize() - PAGE_SIZE -
                                  payloadTextSize;
                    o_info.hasHashTable = true;
                }

                // cache the value in SectionInfo struct so that we can
                // parse the container header less often
                o_info.secureProtectedPayloadSize = payloadTextSize;
            }
            else
#endif
            {
                o_info.size = iv_TOC[id].size;
                o_info.vaddr = iv_TOC[id].virtAddr;
            }

            o_info.flashAddr = iv_TOC[id].flashAddr;
            o_info.eccProtected = ((iv_TOC[id].integrity & FFS_INTEG_ECC_PROTECT)
                                    != 0) ? true : false;
            o_info.sha512Version = ((iv_TOC[id].version & FFS_VERS_SHA512)
                                     != 0) ? true : false;
            o_info.sha512perEC = ((iv_TOC[id].version & FFS_VERS_SHA512_PER_EC)
                                   != 0) ? true : false;
            o_info.readOnly = ((iv_TOC[id].misc & FFS_MISC_READ_ONLY)
                                   != 0) ? true : false;
            o_info.reprovision = ((iv_TOC[id].misc & FFS_MISC_REPROVISION)
                                   != 0) ? true : false;
            o_info.Volatile = ((iv_TOC[id].misc & FFS_MISC_VOLATILE)
                                   != 0) ? true : false;
            o_info.clearOnEccErr = ((iv_TOC[id].misc & FFS_MISC_CLR_ECC_ERR)
                                   != 0) ? true : false;
        }

    } while(0);

    return l_errhdl;
}

/*
 * @brief Finds the toc locations based on hostboot base address
 */
errlHndl_t PnorRP::findTOC(size_t & o_tocSize)
{
    TRACDCOMP(g_trac_pnor, ENTER_MRK"PnorRP::findTOC...");
    errlHndl_t l_err             = NULL;
    uint8_t *realTocBuffer  = nullptr;
    do {
        const uint32_t l_shiftAmount = 32;
        uint64_t l_chip         = 0;
        uint64_t l_fatalError   = 0;
        bool l_foundTOC         = false;
        uint64_t l_toc          = PNOR::PNOR_SIZE - 1;
        ffs_hdr* l_ffs_hdr      = 0;
        uint64_t l_hbbAddr      = 0;
        uint8_t l_tmpTocBuffer [PAGESIZE];

        //get the HBB Address we booted from
        l_err =  PNOR::mmioToPhysicalOffset(l_hbbAddr);
        if (l_err)
        {
            TRACFCOMP(g_trac_pnor, "PnorRP::findTOC> mmioToPhysicalOffset failed");
            break;
        }

        //if we booted from a lower address, then we need to increment
        //sides as we find tocs, otherwise decrement.
        bool l_inc = (ALIGN_DOWN_X(l_hbbAddr, l_shiftAmount*MEGABYTE) == 0);
        uint64_t l_tempHBB = l_hbbAddr;

        //while TOC not found and we are within the flash size
        while((!l_foundTOC) && (l_tempHBB > 0) && (l_tempHBB < PNOR_SIZE))
        {
            //Align HBB down -- looking at 0x0 or 0x2000000
            l_toc = ALIGN_DOWN_X(l_tempHBB, l_shiftAmount*MEGABYTE);
            l_err = readFromDevice(l_toc, l_chip, false, l_tmpTocBuffer,
                    l_fatalError);
            if(l_err)
            {
                TRACFCOMP(g_trac_pnor,"findTOC: readFromDevice failed "
                        "searching for primaryTOC");
                break;
            }

            l_ffs_hdr  = (ffs_hdr*)l_tmpTocBuffer;
            l_foundTOC = ((l_ffs_hdr->magic == FFS_MAGIC) &&
                        (PNOR::pnor_ffs_checksum(l_ffs_hdr,FFS_HDR_SIZE) == 0));

            printk("Addr [%lx], magic[%x] checksum[%d]\n",
                   l_toc,l_ffs_hdr->magic, PNOR::pnor_ffs_checksum(l_ffs_hdr,FFS_HDR_SIZE));
            if (!l_foundTOC)
            {
                //If TOC not found at 0x0 or 0x2000000
                //Align HBB down + 8000 -- looking at 0x8000 or 0x2008000
                l_toc += TOC_SIZE;
                l_err = readFromDevice(l_toc, l_chip, false, l_tmpTocBuffer,
                    l_fatalError);
                if(l_err)
                {
                    TRACFCOMP(g_trac_pnor,"findTOC: readFromDevice failed "
                            "searching for backupTOC for A-B-D arrangement");
                    break;
                }

                l_ffs_hdr  = (ffs_hdr*)l_tmpTocBuffer;
                l_foundTOC =
                    ((l_ffs_hdr->magic == FFS_MAGIC) &&
                     (PNOR::pnor_ffs_checksum(l_ffs_hdr, FFS_HDR_SIZE) == 0));
                printk("Addr [%lx], magic[%x] checksum[%d]\n",
                       l_toc,l_ffs_hdr->magic, PNOR::pnor_ffs_checksum(l_ffs_hdr,FFS_HDR_SIZE));
            }

            if (!l_foundTOC)
            {
                //If toc not found at 0x8000 or 0x2008000
                //Align HBB up (l_shiftAmount) - 8000
                // -- looking at 0x1FF8000 or 0x3FF8000
                l_toc = ALIGN_X(l_tempHBB, l_shiftAmount*MEGABYTE);
                l_toc -= TOC_SIZE;
                l_err = readFromDevice(l_toc, l_chip, false, l_tmpTocBuffer,
                    l_fatalError);
                if(l_err)
                {
                    TRACFCOMP(g_trac_pnor,"findTOC: readFromDevice failed"
                            "searching for backupTOC for A-D-B arrangement");
                    break;
                }

                l_ffs_hdr  = (ffs_hdr*)l_tmpTocBuffer;
                l_foundTOC =
                    ((l_ffs_hdr->magic == FFS_MAGIC) &&
                     (PNOR::pnor_ffs_checksum(l_ffs_hdr, FFS_HDR_SIZE) == 0));
                printk("Addr [%lx], magic[%x] checksum[%d]\n",
                       l_toc,l_ffs_hdr->magic, PNOR::pnor_ffs_checksum(l_ffs_hdr,FFS_HDR_SIZE));
            }

            //Setup for next time -- look for the other side
            l_tempHBB = (l_inc) ? (l_tempHBB + l_shiftAmount*MEGABYTE) :
                                  (l_tempHBB - l_shiftAmount*MEGABYTE);
        }

        if(l_err)
        {
            break;
        }

        //found at least one TOC
        if(l_foundTOC)
        {
            TRACDCOMP(g_trac_pnor, "findTOC> found at least one toc at 0x%X", l_toc);

            //TOC might be greater than one page (4k), so need to check hdr if we need
            //to increase the size of the buffer
            o_tocSize = l_ffs_hdr->block_size * l_ffs_hdr->size;
            realTocBuffer = new uint8_t[o_tocSize];
            TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
            l_err = DeviceFW::deviceRead(pnor_target, realTocBuffer, o_tocSize,
                                         DEVICE_PNOR_ADDRESS(0,l_toc));
            if (l_err)
            {
                TRACFCOMP(g_trac_pnor,"findTOC:failed trying to copy TOC from the device into a buffer");
                break;
            }

            l_ffs_hdr = (ffs_hdr*)realTocBuffer;

            //look for BACKUP_PART and read it
            uint64_t l_backupTOC = INVALID_OFFSET;
            PNOR::findPhysicalOffset(l_ffs_hdr,"BACKUP_PART",l_backupTOC);

            //figure out if the toc found belongs to the side we booted from
            //or if it belongs to the other side
            uint64_t l_foundHBB;
            PNOR::findPhysicalOffset(l_ffs_hdr, "HBB", l_foundHBB);
            bool l_isActiveTOC = (l_foundHBB == l_hbbAddr);
            l_isActiveTOC = 1; //@FIXME RTC 138268 needs multiple sides support
            printk("forced to true - l_isActiveTOC=%d\n",
                l_isActiveTOC); //@FIXME RTC 138268

#ifdef CONFIG_PNOR_TWO_SIDE_SUPPORT
            uint64_t l_otherPrimaryTOC = INVALID_OFFSET;
            uint64_t l_otherBackupTOC  = INVALID_OFFSET;
            uint8_t l_otherPrimaryTOCBuff [PAGESIZE];
            uint8_t l_otherBackupTOCBuff  [PAGESIZE];
            uint8_t l_backupTOCBuffer     [PAGESIZE];

            //look for OTHER_SIDE
            PNOR::findPhysicalOffset(l_ffs_hdr, "OTHER_SIDE",l_otherPrimaryTOC);

            //reading to look for OTHER_SIDE's backup
            bool l_foundOtherBackup  = false;
            bool l_foundOtherPrimary = false;

            if (l_otherPrimaryTOC != INVALID_OFFSET)
            {
                l_err = readFromDevice(l_otherPrimaryTOC,l_chip,
                            false, l_otherPrimaryTOCBuff,l_fatalError);
                l_ffs_hdr = (ffs_hdr*)l_otherPrimaryTOCBuff;
                if(l_err)
                {
                    TRACFCOMP(g_trac_pnor, "findTOC: readFromDevice failed"
                            " while looking for other side's primary TOC");
                    errlCommit(l_err, PNOR_COMP_ID);
                }
                else if ((l_ffs_hdr->magic == FFS_MAGIC) &&
                        (PNOR::pnor_ffs_checksum(l_ffs_hdr, FFS_HDR_SIZE)==0))
                {
                        //if otherPrimaryTOC is valid,
                        //then we can find it's backup
                        PNOR::findPhysicalOffset(l_ffs_hdr, "BACKUP_PART",
                              l_otherBackupTOC);
                        l_foundOtherPrimary = true;
                }
            }
            if ((!l_foundOtherPrimary) && (l_backupTOC != INVALID_OFFSET))
            {
                //if otherPrimaryTOC is not valid, find the other backup
                //through BACKUP_PART's OTHER_SIDE
                l_err = readFromDevice (l_backupTOC, l_chip, false,
                        l_backupTOCBuffer, l_fatalError);
                l_ffs_hdr = (ffs_hdr*)l_backupTOCBuffer;
                if (l_err)
                {
                    TRACFCOMP(g_trac_pnor, "findTOC: readFromDevice failed"
                            " while reading for backup TOC");
                    errlCommit(l_err, PNOR_COMP_ID);
                }
                else if ((l_ffs_hdr->magic == FFS_MAGIC)
                      && (PNOR::pnor_ffs_checksum(l_ffs_hdr,FFS_HDR_SIZE)==0))
                {
                    PNOR::findPhysicalOffset(l_ffs_hdr,"OTHER_SIDE",
                                    l_otherBackupTOC);
                    l_foundOtherBackup = true;
                }
            }

            //figure out if other side's toc belongs to the side we booted from
            if(l_foundOtherPrimary)
            {
                PNOR::findPhysicalOffset((ffs_hdr*)l_otherPrimaryTOCBuff, "HBB",
                    l_foundHBB);
            }
            else if (l_foundOtherBackup)
            {
                l_err = readFromDevice (l_otherBackupTOC, l_chip, false,
                        l_otherBackupTOCBuff, l_fatalError);
                l_ffs_hdr = (ffs_hdr*)l_backupTOCBuffer;
                if (l_err)
                {
                    TRACFCOMP(g_trac_pnor, "findTOC: readFromDevice failed"
                            " while reading other side's backup TOC");
                    errlCommit(l_err, PNOR_COMP_ID);
                }
                else if ((l_ffs_hdr->magic == FFS_MAGIC) &&
                        (PNOR::pnor_ffs_checksum(l_ffs_hdr,FFS_HDR_SIZE)==0))
                {
                    PNOR::findPhysicalOffset(l_ffs_hdr,"HBB",
                                    l_foundHBB);
                }
            }
            bool l_isOtherActiveTOC = (l_foundHBB == l_hbbAddr);

            if (l_isActiveTOC)
            {
                iv_TocOffset[WORKING].first    = l_toc;
                iv_TocOffset[WORKING].second   = l_backupTOC;
                iv_TocOffset[ALTERNATE].first  = l_otherPrimaryTOC;
                iv_TocOffset[ALTERNATE].second = l_otherBackupTOC;
            }
            else if (l_isOtherActiveTOC)
            {
                iv_TocOffset[WORKING].first    = l_otherPrimaryTOC;
                iv_TocOffset[WORKING].second   = l_otherBackupTOC;
                iv_TocOffset[ALTERNATE].first  = l_toc;
                iv_TocOffset[ALTERNATE].second = l_backupTOC;
            }
            else
            {
                TRACFCOMP(g_trac_pnor,"findTOC>No valid TOC found, looked"
                       "at following addresses PrimaryTOC:0x%08X, BackupTOC:"
                       "0x%08X", l_toc, l_backupTOC);
                INITSERVICE::doShutdown(PNOR::RC_PARTITION_TABLE_CORRUPTED);
            }
            TRACFCOMP(g_trac_pnor,"findTOC>activePrimary:0x%X,activeBackup:0x%X"
                  "altPrimary:0x%X, altBackup:0x%X",iv_TocOffset[WORKING].first,
                  iv_TocOffset[WORKING].second, iv_TocOffset[ALTERNATE].first,
                  iv_TocOffset[ALTERNATE].second);
#else
            if (l_isActiveTOC)
            {
                iv_TocOffset[WORKING].first  = l_toc;
                iv_TocOffset[WORKING].second = l_backupTOC;
                TRACFCOMP(g_trac_pnor, "findTOC> activePrimary:0x%X, "
                        "activeBackup:0x%X", iv_TocOffset[WORKING].first,
                        iv_TocOffset[WORKING].second);
            }
            else
            {
                TRACFCOMP(g_trac_pnor,"findTOC>No valid TOC found, looked"
                       "at following addresses PrimaryTOC:0x%08X, BackupTOC:"
                       "0x%08X", l_toc, l_backupTOC);
                INITSERVICE::doShutdown(PNOR::RC_PARTITION_TABLE_CORRUPTED);
            }

#endif
        }
        else
        {
            printk("no valid toc - l_foundTOC=%d, l_toc=%lX, l_tmpTocBuffer=%p\n",
                   l_foundTOC, l_toc, l_tmpTocBuffer);
            sync();
            //no valid TOC found
            TRACFCOMP(g_trac_pnor, "No valid TOC found");
            if (l_err)
            {
                errlCommit(l_err, PNOR_COMP_ID);
            }
            INITSERVICE::doShutdown(PNOR::RC_PARTITION_TABLE_NOT_FOUND);
        }
    } while (0);

    if(realTocBuffer != nullptr)
    {
        delete[] realTocBuffer;
    }

    TRACDCOMP(g_trac_pnor, EXIT_MRK"findTOC");
    return l_err;
}

/**
 * @brief Read the TOC and store section information
 */
errlHndl_t PnorRP::readTOC(size_t i_tocSize)
{
    TRACUCOMP(g_trac_pnor, "PnorRP::readTOC>" );
    errlHndl_t l_errhdl = nullptr;
    errlHndl_t l_primary_errhdl = nullptr;
    errlHndl_t l_secondary_errhdl = nullptr;
    TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

    uint8_t* toc0Buffer = new uint8_t[i_tocSize];
    uint8_t* toc1Buffer = new uint8_t[i_tocSize];

    PNOR::SectionData_t l_secondary_TOC[PNOR::NUM_SECTIONS+1];

    do {
        //Initialize toc buffers to invalid value
        //If these buffers are not read from device,
        //then parseTOC will see invalid data
        memset(toc0Buffer, 0xFF, i_tocSize);
        memset(toc1Buffer, 0xFF, i_tocSize);
        //If the first toc is at a valid offset try to read and parse it
        if (iv_TocOffset[WORKING].first != INVALID_OFFSET)
        {
            l_errhdl = DeviceFW::deviceRead(pnor_target, toc0Buffer, i_tocSize,
                                            DEVICE_PNOR_ADDRESS(0,iv_TocOffset[WORKING].first));
            if (l_errhdl)
            {
                TRACFCOMP(g_trac_pnor,"readTOC:readFromDevice failed for TOC0");
                break;
            }
            l_primary_errhdl = PNOR::parseTOC(toc0Buffer, iv_TOC);

            //For now assume TOC_0 worked and we are using it
            iv_TOC_used = TOC_0;
        }
        //If the second toc is at a valid offset try to read and parse it
        if (iv_TocOffset[WORKING].second != INVALID_OFFSET)
        {
            l_errhdl = DeviceFW::deviceRead(pnor_target, toc1Buffer, i_tocSize,
                                            DEVICE_PNOR_ADDRESS(0,iv_TocOffset[WORKING].second));
            if (l_errhdl)
            {
                TRACFCOMP(g_trac_pnor,"readTOC:readFromDevice failed for TOC1");
                break;
            }

            l_secondary_errhdl = PNOR::parseTOC(toc1Buffer, l_secondary_TOC);
        }

        //if at least one of them is good, only report errors as informational
        if((l_primary_errhdl != nullptr) && (l_secondary_errhdl == nullptr))
        {
            //Found an error in primary TOC, report it

                //@TODO RTC:144079 Try to fix PNOR for detected TOC failures
                //Set the error severity to INFORMATIONAL
                l_primary_errhdl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                //commit error logs for corrupted TOC
                errlCommit(l_primary_errhdl, PNOR_COMP_ID);

                //use the secondary TOC if first is bad
                iv_TOC_used = TOC_1;
                memcpy(iv_TOC, l_secondary_TOC, (sizeof(l_secondary_TOC)));
        }
        //If we found an error in the secondary TOC
        else if((l_secondary_errhdl != nullptr) && (l_primary_errhdl == nullptr))
        {
            //@TODO RTC:144079 Try to fix PNOR for detected TOC failures
            //Set the error severity to INFORMATIONAL
            l_secondary_errhdl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            //commit error logs for corrupted TOC
            errlCommit(l_secondary_errhdl, PNOR_COMP_ID);
        }
        //In the case that both TOCs failing, have errors shut down the system
        else if(l_primary_errhdl != nullptr && l_secondary_errhdl != nullptr)
        {
            //commit both error logs for each corrupted TOC
            l_primary_errhdl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            errlCommit(l_primary_errhdl, PNOR_COMP_ID);
            l_secondary_errhdl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            errlCommit(l_secondary_errhdl, PNOR_COMP_ID);
            TRACFCOMP(g_trac_pnor, "readTOC: parseTOC failed");
            //With invalid pnor we cannot do anything, time to shut down
            INITSERVICE::doShutdown(PNOR::RC_PARTITION_TABLE_INVALID);
        }

        //Set the virtual addresses for the different sections of pnor
        //so the resource provider has it ready for later use
        l_errhdl = setVirtAddrs();

        if (l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, "readTOC: Failed to set virtual addresses in TOC");
            INITSERVICE::doShutdown(PNOR::RC_PNOR_SET_VADDR_FAILED);
        }
    } while (0);

    if(toc0Buffer != nullptr)
    {
        delete[] toc0Buffer;
    }

    if(toc1Buffer != nullptr)
    {
        delete[] toc1Buffer;
    }
    TRACUCOMP(g_trac_pnor, "< PnorRP::readTOC" );
    return l_errhdl;
}

errlHndl_t PnorRP::setSideInfo (size_t i_tocSize)
{
    uint8_t* l_tocBuffer  = new uint8_t [i_tocSize];
    ffs_hdr* l_ffs_hdr    = 0;
    errlHndl_t l_err      = NULL;
    TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
    for (SideId i = FIRST_SIDE; i < NUM_SIDES; i = (SideId)(i+1))
    {
        //id
        iv_side[i].id = (SideId)i;

        //get a valid TOC
        uint64_t l_primaryTOC = iv_TocOffset[i].first;
        uint64_t l_backupTOC  = iv_TocOffset[i].second;

        uint64_t l_validTOC = (l_primaryTOC != INVALID_OFFSET) ? l_primaryTOC :
                              ((l_backupTOC != INVALID_OFFSET) ? l_backupTOC  :
                                INVALID_OFFSET);
        if(l_validTOC == INVALID_OFFSET)
        {
            if (i == WORKING)
            {
                TRACFCOMP(g_trac_pnor, "setSideInfo: No valid TOC found for"
                        "working side");
                INITSERVICE::doShutdown(PNOR::RC_INVALID_WORKING_TOC);
            }
            else
            {
                TRACFCOMP(g_trac_pnor,"setSideInfo: No valid TOC found for"
                        " side: %d", i);
                /*@
                 * @errortype
                 * @moduleid         PNOR::MOD_PNORRP_SETSIDEINFO
                 * @reasoncode       PNOR::RC_INVALID_TOC
                 * @userdata1        Side Id
                 * @userdata2[00:31] primary toc
                 * @userdata2[32:63] backup toc
                 * @devdesc          PnorRP::setSideInfo> No valid TOCs found
                 * @custdesc         No valid Table of Contents (TOC) found
                 *                   for Processor NOR flash
                 */
                l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            PNOR::MOD_PNORRP_SETSIDEINFO,
                            PNOR::RC_INVALID_TOC,
                            i,TWO_UINT32_TO_UINT64(l_primaryTOC,l_backupTOC),
                            true);
                l_err->addPartCallout(
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        HWAS::PNOR_PART_TYPE,
                        HWAS::SRCI_PRIORITY_LOW,
                        HWAS::NO_DECONFIG,
                        HWAS::GARD_NULL);
                break;
            }
        }

        iv_side[i].primaryTOC = l_primaryTOC;
        iv_side[i].backupTOC  = l_backupTOC;


        l_err = DeviceFW::deviceRead(pnor_target, l_tocBuffer, i_tocSize,
                                        DEVICE_PNOR_ADDRESS(0,l_validTOC));
        if(l_err)
        {
            TRACFCOMP(g_trac_pnor, "setSideInfo: readFromDevice failed"
                    " while reading a valid TOC");
            break;
        }
        l_ffs_hdr = (ffs_hdr*)l_tocBuffer;

        //isGolden
        //Entry 0 is the "part" partition
        //Need to read from the ffs hdr instead of the TOC because
        //TOC has no knowledge of other side
        ffs_entry* cur_entry = (&l_ffs_hdr->entries[0]);
        ffs_hb_user_t* ffsUserData = (ffs_hb_user_t*)&(cur_entry->user);
        iv_side[i].isGolden = (ffsUserData->miscFlags & FFS_MISC_GOLDEN);

        //isGuardPresent
        uint64_t l_secOffset = INVALID_OFFSET;
        findPhysicalOffset (l_ffs_hdr, "GUARD", l_secOffset);
        iv_side[i].isGuardPresent = (l_secOffset != INVALID_OFFSET);

        //isOtherSide
        iv_side[i].hasOtherSide = false;
#ifdef CONFIG_PNOR_TWO_SIDE_SUPPORT
        iv_side[i].hasOtherSide =
            ((iv_TocOffset[(i+1)%NUM_SIDES].first != INVALID_OFFSET) ||
            (iv_TocOffset[(i+1)%NUM_SIDES].second != INVALID_OFFSET));
#endif

        //hbbAddress
        l_secOffset = INVALID_OFFSET;
        findPhysicalOffset (l_ffs_hdr, "HBB", l_secOffset);
        iv_side[i].hbbAddress = l_secOffset;

        //mmioOffset
        uint64_t l_mmioOffset;
        physicalToMmioOffset(l_secOffset, l_mmioOffset);
        iv_side[i].hbbMmioOffset = l_mmioOffset;

        //char side
        iv_side[i].side =(ALIGN_DOWN_X(l_secOffset,32*MEGABYTE) == 0) ? 'A':'B';

        TRACFCOMP(g_trac_pnor, "setSideInfo: sideId:%d, isGolden:%d, "
              "isGuardPresent:%d, hasOtherSide:%d, primaryTOC: 0x%x, backupTOC"
              ":0x%X, HBB:0x%X, MMIO:0x%X",i, iv_side[i].isGolden,
              iv_side[i].isGuardPresent,iv_side[i].hasOtherSide,
              iv_side[i].primaryTOC, iv_side[i].backupTOC,
              iv_side[i].hbbAddress, iv_side[i].hbbMmioOffset);
    }
    return l_err;
}
/**
 * @brief  Message receiver
 */
void PnorRP::waitForMessage()
{
    TRACDCOMP(g_trac_pnor, "PnorRP::waitForMessage>" );

    errlHndl_t l_errhdl = NULL;
    msg_t* message = NULL;
    uint8_t* user_addr = NULL;
    uint8_t* eff_addr = NULL;
    uint64_t dev_offset = 0;
    uint64_t chip_select = 0xF;
    bool needs_ecc = false;
    int rc = 0;
    uint64_t status_rc = 0;
    uint64_t fatal_error = 0;

    while(1)
    {
        status_rc = 0;
        TRACUCOMP(g_trac_pnor, "PnorRP::waitForMessage> waiting for message" );
        message = msg_wait( iv_msgQ );
        if( message )
        {
            // if its a shutdown message skip the address calculation
            if( message->type !=  PNOR::MSG_SHUTDOWN )
            {
                /*  data[0] = virtual address requested
                 *  data[1] = address to place contents
                 */
                eff_addr = (uint8_t*)message->data[0];
                user_addr = (uint8_t*)message->data[1];

                //figure out the real pnor offset
                l_errhdl =
                    computeDeviceAddr( eff_addr,
                            dev_offset, chip_select, needs_ecc );
            }

            if( l_errhdl )
            {
                status_rc = -EFAULT; /* Bad address */
            }
            else
            {
                switch(message->type)
                {
                    case( PNOR::MSG_SHUTDOWN ):
                        {
                            // we got a message saying there is a shutdown in
                            // progress, dont accept any new pnor writes
                            iv_shutdown_pending = true;
                            TRACFCOMP(g_trac_pnor,"PnorRP::Shutdown message recieved" );
                        }
                        break;

                    case( MSG_MM_RP_READ ):
                        l_errhdl = readFromDevice( dev_offset,
                                                   chip_select,
                                                   needs_ecc,
                                                   user_addr,
                                                   fatal_error );
                        if( l_errhdl || ( 0 != fatal_error ) )
                        {
                            status_rc = -EIO; /* I/O error */
                        }
                        iv_pageCounter[dev_offset]++;
                        break;

                    case( MSG_MM_RP_WRITE ):
                        if( !iv_shutdown_pending )
                        {
                            l_errhdl = writeToDevice( dev_offset,
                                                      chip_select,
                                                      needs_ecc,
                                                      user_addr );
                            if( l_errhdl )
                            {
                                status_rc = -EIO; /* I/O error */
                            }
                        }
                        else
                        {
                          TRACFCOMP(g_trac_pnor, "PnorRP::shutdown pending write dropped");
                        }
                        break;

                    default:
                        TRACFCOMP( g_trac_pnor, "PnorRP::waitForMessage> Unrecognized message type : user_addr=%p, eff_addr=%p, msgtype=%d", user_addr, eff_addr, message->type );
                        /*@
                         * @errortype
                         * @moduleid     PNOR::MOD_PNORRP_WAITFORMESSAGE
                         * @reasoncode   PNOR::RC_INVALID_MESSAGE_TYPE
                         * @userdata1    Message type
                         * @userdata2    Requested Virtual Address
                         * @devdesc      PnorRP::waitForMessage> Unrecognized
                         *               message type
                         * @custdesc     A problem occurred while accessing
                         *               the boot flash.
                         */
                        l_errhdl = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           PNOR::MOD_PNORRP_WAITFORMESSAGE,
                                           PNOR::RC_INVALID_MESSAGE_TYPE,
                                           TO_UINT64(message->type),
                                           (uint64_t)eff_addr,
                                           true /*Add HB SW Callout*/);
                        l_errhdl->collectTrace(PNOR_COMP_NAME);
                        status_rc = -EINVAL; /* Invalid argument */
                }
            }

            if( !l_errhdl && msg_is_async(message) )
            {
                TRACFCOMP( g_trac_pnor, "PnorRP::waitForMessage> Unsupported Asynchronous Message  : user_addr=%p, eff_addr=%p, msgtype=%d", user_addr, eff_addr, message->type );
                /*@
                 * @errortype
                 * @moduleid     PNOR::MOD_PNORRP_WAITFORMESSAGE
                 * @reasoncode   PNOR::RC_INVALID_ASYNC_MESSAGE
                 * @userdata1    Message type
                 * @userdata2    Requested Virtual Address
                 * @devdesc      PnorRP::waitForMessage> Unrecognized message
                 *               type
                 * @custdesc     A problem occurred while accessing the boot
                 *               flash.
                 */
                l_errhdl = new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         PNOR::MOD_PNORRP_WAITFORMESSAGE,
                                         PNOR::RC_INVALID_ASYNC_MESSAGE,
                                         TO_UINT64(message->type),
                                         (uint64_t)eff_addr,
                                         true /*Add HB SW Callout*/);
                l_errhdl->collectTrace(PNOR_COMP_NAME);
                status_rc = -EINVAL; /* Invalid argument */
            }

            if( l_errhdl )
            {
                errlCommit(l_errhdl,PNOR_COMP_ID);
            }


            /*  Expected Response:
             *      data[0] = virtual address requested
             *      data[1] = rc (0 or negative errno value)
             *      extra_data = Specific reason code.
             */
            message->data[1] = status_rc;
            message->extra_data = reinterpret_cast<void*>(fatal_error);
            rc = msg_respond( iv_msgQ, message );
            if( rc )
            {
                TRACFCOMP(g_trac_pnor, "PnorRP::waitForMessage> Error from msg_respond, giving up : rc=%d", rc );
                break;
            }
        }
    }


    TRACDCOMP(g_trac_pnor, "< PnorRP::waitForMessage" );
}


/**
 * @brief  Retrieve 1 page of data from the PNOR device
 */
errlHndl_t PnorRP::readFromDevice( uint64_t i_offset,
                                   uint64_t i_chip,
                                   bool i_ecc,
                                   void* o_dest,
                                   uint64_t& o_fatalError )
{
    TRACUCOMP(g_trac_pnor, "PnorRP::readFromDevice> i_offset=0x%X, i_chip=%d", i_offset, i_chip );
    errlHndl_t l_errhdl = NULL;
    o_fatalError = 0;

    do
    {
        TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // assume a single page
        void* data_to_read = o_dest;
        size_t read_size = PAGESIZE;

        // if we need to handle ECC we need to read more than 1 page
        if( i_ecc )
        {
            data_to_read = iv_ecc_buffer;
            read_size = PAGESIZE_PLUS_ECC;
        }

        // get the data from the PNOR DD
        l_errhdl = DeviceFW::deviceRead(pnor_target,
                                        data_to_read,
                                        read_size,
                                        DEVICE_PNOR_ADDRESS(i_chip,i_offset) );
        if( l_errhdl )
        {
            TRACFCOMP(g_trac_pnor, "PnorRP::readFromDevice> Error from device : RC=%X", l_errhdl->reasonCode() );
            break;
        }

        // remove the ECC data
        if( i_ecc )
        {
            // remove the ECC and fix the original data if it is broken
            PNOR::ECC::eccStatus ecc_stat =
              PNOR::ECC::removeECC( reinterpret_cast<uint8_t*>(data_to_read),
                                    reinterpret_cast<uint8_t*>(o_dest),
                                    PAGESIZE );

            // create an error if we couldn't correct things
            if( ecc_stat == PNOR::ECC::UNCORRECTABLE )
            {
                PNOR::SectionId l_id = computeSectionPhys(i_offset);
                TRACFCOMP( g_trac_pnor, "PnorRP::readFromDevice> Uncorrectable ECC error : chip=%d,offset=0x%.X", i_chip, i_offset );
                CONSOLE::displayf(CONSOLE::DEFAULT,  NULL, "ECC error in PNOR flash in section offset 0x%.8X\n", i_offset );

                //Attempt to find the section and check if we can clear
                //it to recover
                if ((l_id != PNOR::INVALID_SECTION )
                    && ((iv_TOC[l_id].misc & FFS_MISC_CLR_ECC_ERR) != 0))
                {
                    CONSOLE::displayf(CONSOLE::DEFAULT,  nullptr, "Clearing section %s due to ECC error\n",
                                       SectionIdToString(l_id));
                    clearSection(l_id); //shutting down -- ignore and leak errl

                    CONSOLE::displayf(CONSOLE::DEFAULT,  nullptr, "Done\n");
                }

                // Need to shutdown here instead of creating an error log
                //  because the bad page could be critical to the regular
                //  error handling path and cause an infinite loop.
                // Also need to spawn a separate task to do the shutdown
                //  so that the regular PNOR task can service the writes
                //  that happen during shutdown.
                o_fatalError = PNOR::RC_ECC_UE;
                INITSERVICE::doShutdown( PNOR::RC_ECC_UE, true );
            }
            // found an error so we need to fix something
            else if( ecc_stat != PNOR::ECC::CLEAN )
            {
                TRACFCOMP( g_trac_pnor, "PnorRP::readFromDevice> Correctable ECC error : chip=%d, offset=0x%.X", i_chip, i_offset );

                // need to write good data back to PNOR
                l_errhdl = DeviceFW::deviceWrite(pnor_target,
                                       data_to_read,//corrected data
                                       read_size,
                                       DEVICE_PNOR_ADDRESS(i_chip,i_offset) );
                if( l_errhdl )
                {
                    TRACFCOMP(g_trac_pnor, "PnorRP::readFromDevice> Error writing corrected data back to device : RC=%X", l_errhdl->reasonCode() );
                    // we don't need to fail here since we can correct
                    //  it the next time we read it again, instead just
                    //  commit the log here
                    errlCommit(l_errhdl,PNOR_COMP_ID);
                }

                // keep some stats here in case we want them someday
                //no need for mutex since only ever 1 thread accessing this
                iv_stats[i_offset/PAGESIZE].numCEs++;
            }
        }
    } while(0);

    TRACUCOMP(g_trac_pnor, "< PnorRP::readFromDevice" );
    return l_errhdl;
}

/**
 * @brief  Write 1 page of data to the PNOR device
 */
errlHndl_t PnorRP::writeToDevice( uint64_t i_offset,
                                  uint64_t i_chip,
                                  bool i_ecc,
                                  void* i_src )
{
    TRACUCOMP(g_trac_pnor, "PnorRP::writeToDevice> i_offset=%X, i_chip=%d", i_offset, i_chip );
    errlHndl_t l_errhdl = NULL;

    do
    {
        TARGETING::Target* pnor_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // assume a single page to write
        void* data_to_write = i_src;
        size_t write_size = PAGESIZE;

        // apply ECC to data if needed
        if( i_ecc )
        {
            PNOR::ECC::injectECC( reinterpret_cast<uint8_t*>(i_src),
                                  PAGESIZE,
                                  reinterpret_cast<uint8_t*>(iv_ecc_buffer) );
            data_to_write = reinterpret_cast<void*>(iv_ecc_buffer);
            write_size = PAGESIZE_PLUS_ECC;
        }

        //no need for mutex since only ever a singleton object
        iv_stats[i_offset/PAGESIZE].numWrites++;

        // write the data out to the PNOR DD
        errlHndl_t l_errhdl = DeviceFW::deviceWrite( pnor_target,
                                       data_to_write,
                                       write_size,
                                       DEVICE_PNOR_ADDRESS(i_chip,i_offset) );
        if( l_errhdl )
        {
            TRACFCOMP(g_trac_pnor, "PnorRP::writeToDevice> Error from device : RC=%X", l_errhdl->reasonCode() );
            break;
        }
    } while(0);

    TRACUCOMP(g_trac_pnor, "< PnorRP::writeToDevice" );
    return l_errhdl;
}

/**
 * @brief  Convert a virtual address into the PNOR device address
 */
errlHndl_t PnorRP::computeDeviceAddr( void* i_vaddr,
                                      uint64_t& o_offset,
                                      uint64_t& o_chip,
                                      bool& o_ecc )
{
    errlHndl_t l_errhdl = NULL;
    o_offset = 0;
    o_chip = 99;
    uint64_t l_vaddr = (uint64_t)i_vaddr;

    do
    {
        // make sure this is one of our addresses
        if( !((l_vaddr >= BASE_VADDR)
              && (l_vaddr < LAST_VADDR)) )
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::computeDeviceAddr> Virtual Address outside known PNOR range : i_vaddr=%p", i_vaddr );
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORRP_WAITFORMESSAGE
             * @reasoncode   PNOR::RC_INVALID_ADDRESS
             * @userdata1    Virtual Address
             * @userdata2    Base PNOR Address
             * @devdesc      PnorRP::computeDeviceAddr> Virtual Address outside
             *               known PNOR range
             * @custdesc    A problem occurred while accessing the boot flash.
             */
            l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORRP_COMPUTEDEVICEADDR,
                                            PNOR::RC_INVALID_ADDRESS,
                                            l_vaddr,
                                            BASE_VADDR,
                                            true /*Add HB SW Callout*/);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            break;
        }

        // find the matching section
        PNOR::SectionId id = PNOR::INVALID_SECTION;
        l_errhdl = computeSection( l_vaddr, id );
        if( l_errhdl )
        {
            TRACFCOMP( g_trac_pnor, "PnorRP::computeDeviceAddr> Virtual address does not match any pnor sections : i_vaddr=%p", i_vaddr );
            break;
        }

        // pull out the information we need to return from our global copy
        o_chip = iv_TOC[id].chip;
        o_ecc = (bool)(iv_TOC[id].integrity & FFS_INTEG_ECC_PROTECT);
        o_offset = l_vaddr - iv_TOC[id].virtAddr; //offset into section

        // for ECC we need to figure out where the ECC-enhanced offset is
        //  before tacking on the offset to the section
        if( o_ecc )
        {
            o_offset = (o_offset * 9) / 8;
        }
        // add on the offset of the section itself
        o_offset += iv_TOC[id].flashAddr;
    } while(0);

    TRACUCOMP( g_trac_pnor, "< PnorRP::computeDeviceAddr: i_vaddr=%X, o_offset=0x%X, o_chip=%d", l_vaddr, o_offset, o_chip );
    return l_errhdl;
}

/**
 * @brief Static instance function
 */
PnorRP& PnorRP::getInstance()
{
    return Singleton<PnorRP>::instance();
}

/**
 * @brief  Figure out which section a VA belongs to
 */
errlHndl_t PnorRP::computeSection( uint64_t i_vaddr,
                                   PNOR::SectionId& o_id )
{
    errlHndl_t errhdl = NULL;

    o_id = PNOR::INVALID_SECTION;

    do {
        // loop through all sections to find a matching id
        for( PNOR::SectionId id = PNOR::FIRST_SECTION;
             id < PNOR::NUM_SECTIONS;
             id = (PNOR::SectionId) (id + 1) )
        {
            if( (i_vaddr >= iv_TOC[id].virtAddr)
                && (i_vaddr < (iv_TOC[id].virtAddr + iv_TOC[id].size)) )
            {
                o_id = iv_TOC[id].id;
                break;
            }
        }

    }while(0);

    if(o_id == PNOR::INVALID_SECTION)
    {
        TRACFCOMP( g_trac_pnor, "PnorRP::computeSection> Invalid virtual address : i_vaddr=%X", i_vaddr );
        /*@
         * @errortype
         * @moduleid     PNOR::MOD_PNORRP_COMPUTESECTION
         * @reasoncode   PNOR::RC_INVALID_ADDRESS
         * @userdata1    Requested Virtual Address
         * @userdata2    <unused>
         * @devdesc      PnorRP::computeSection> Invalid Address
         * @custdesc    A problem occurred while accessing the boot flash.
         */
        errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         PNOR::MOD_PNORRP_COMPUTESECTION,
                                         PNOR::RC_INVALID_ADDRESS,
                                         i_vaddr,
                                         0,
                                         true /*Add HB SW Callout*/);
        errhdl->collectTrace(PNOR_COMP_NAME);
        return errhdl;
    }

    return errhdl;
}

/**
 * @brief  Figure out which section a PA belongs to
 */
PNOR::SectionId  PnorRP::computeSectionPhys( uint64_t i_offset)
{
    PNOR::SectionId o_id = PNOR::INVALID_SECTION;

    // loop through all sections to find a matching id
    for( PNOR::SectionId id = PNOR::FIRST_SECTION;
         id < PNOR::NUM_SECTIONS;
         id = static_cast<PNOR::SectionId>(id + 1) )
    {
        //Need to take ECC into account for the size
        uint32_t l_size = iv_TOC[id].size;
        if ((iv_TOC[id].integrity & FFS_INTEG_ECC_PROTECT) != 0) //ECC
        {
             l_size = (l_size / 8) * 9;
        }

        if( (i_offset >= iv_TOC[id].flashAddr)
            && (i_offset < (iv_TOC[id].flashAddr + l_size)) )
        {
            o_id = iv_TOC[id].id;
            break;
        }
    }

    return o_id;
}

errlHndl_t PnorRP::clearSection(PNOR::SectionId i_section)
{
    TRACDCOMP(g_trac_pnor, "PnorRP::clearSection Section id = %d", i_section);
    errlHndl_t l_errl = NULL;
    const uint64_t CLEAR_BYTE = 0xFF;
    uint8_t* l_buf = new uint8_t[PAGESIZE];
    uint8_t* l_eccBuf = NULL;

    do
    {
        // Flush pages of pnor section we are trying to clear
        l_errl = flush(i_section);
        if (l_errl)
        {
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorRP::clearSection: flush() failed on section",
                        i_section);
            break;
        }

        // Get PNOR section info
        uint64_t l_address = iv_TOC[i_section].flashAddr;
        uint64_t l_chipSelect = iv_TOC[i_section].chip;
        uint32_t l_size = iv_TOC[i_section].size;
        bool l_ecc = iv_TOC[i_section].integrity & FFS_INTEG_ECC_PROTECT;

        // Number of pages needed to cycle proper ECC
        // Meaning every 9th page will copy the l_eccBuf at offset 0
        const uint64_t l_eccCycleNum = 9;

        // Boundaries for properly splitting up an ECC page for 4K writes.
        // Subtract 1 from l_eccCycleNum because we start writing with offset 0
        // and add this value 8 times to complete a cycle.
        const uint64_t l_sizeOfOverlapSection = (PAGESIZE_PLUS_ECC - PAGESIZE) /
                                                (l_eccCycleNum - 1);

        // Create clear section buffer
        memset(l_buf, CLEAR_BYTE, PAGESIZE);

        // apply ECC to data if needed
        if(l_ecc)
        {
            l_eccBuf = new uint8_t[PAGESIZE_PLUS_ECC];
            PNOR::ECC::injectECC( reinterpret_cast<uint8_t*>(l_buf),
                                  PAGESIZE,
                                  reinterpret_cast<uint8_t*>(l_eccBuf) );
            l_size = (l_size*9)/8;
        }

        // Write clear section page to PNOR
        for (uint64_t i = 0; i < l_size; i+=PAGESIZE)
        {
            if(l_ecc)
            {
                // Take (current page) mod (l_eccCycleNum) to get cycle position
                uint8_t l_bufPos = ( (i/PAGESIZE) % l_eccCycleNum );
                uint64_t l_bufOffset = l_sizeOfOverlapSection * l_bufPos;
                memcpy(l_buf, (l_eccBuf + l_bufOffset), PAGESIZE);
            }

            // Set ecc parameter to false to avoid double writes will only write
            // 4k at a time, even if the section is ecc protected.
            l_errl = writeToDevice((l_address + i), l_chipSelect,
                                   false, l_buf);
            if (l_errl)
            {
                TRACFCOMP( g_trac_pnor, ERR_MRK"PnorRP::clearSection: writeToDevice fail: eid=0x%X, rc=0x%X",
                           l_errl->eid(), l_errl->reasonCode());
                break;
            }
        }
        if (l_errl)
        {
            break;
        }
    } while(0);

    // Free allocated memory
    if(l_eccBuf)
    {
        delete[] l_eccBuf;
    }
    delete [] l_buf;

    return l_errl;
}

/**
 * @brief check and fix correctable ECC errors for a given section
 */
errlHndl_t PnorRP::fixECC (PNOR::SectionId i_section)
{
    errlHndl_t l_err  = NULL;
    uint8_t* l_buffer = new uint8_t [PAGESIZE] ();
    do {
        TRACFCOMP(g_trac_pnor, ENTER_MRK"PnorRP::fixECC");

        //get info from the TOC
        uint8_t* l_virtAddr = reinterpret_cast<uint8_t*>
                                (iv_TOC[i_section].virtAddr);
        uint32_t l_size    = iv_TOC[i_section].size;
        bool l_ecc         = iv_TOC[i_section].integrity&FFS_INTEG_ECC_PROTECT;

        if (!l_ecc)
        {
            TRACFCOMP(g_trac_pnor, "PnorRP::fixECC: section is not"
                    " ecc protected");
            /*@
             *  @errortype      ERRL_SEV_INFORMATIONAL
             *  @moduleid       PNOR::MOD_PNORRP_FIXECC
             *  @reasoncode     PNOR::RC_NON_ECC_PROTECTED_SECTION
             *  @userdata1      Section ID
             *  @userdata2      0
             *
             *  @devdesc        Non ECC protected section is passed to fixECC
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    PNOR::MOD_PNORRP_FIXECC,
                                    PNOR::RC_NON_ECC_PROTECTED_SECTION,
                                    i_section,
                                    0,true);
            break;
        }

        uint32_t l_numOfPages = (l_size)/PAGESIZE;

        //loop over number of pages in a section
        for (uint32_t i = 0; i < l_numOfPages; i++)
        {
            TRACDCOMP(g_trac_pnor, "PnorRP::fixECC: memcpy virtAddr:0x%X",
                      l_virtAddr);
            memcpy(l_buffer, l_virtAddr, PAGESIZE);
            l_virtAddr += PAGESIZE;
        }
    } while (0);

    delete [] l_buffer;
    TRACDCOMP(g_trac_pnor, EXIT_MRK"PnorRP::fixECC");
    return l_err;
}

uint64_t PnorRP::getTocOffset(TOCS i_toc) const
{
    // Can use a ternary operator because there are only 2 TOCs per side
    return (i_toc == TOC_0) ? iv_TocOffset[WORKING].first :
                              iv_TocOffset[WORKING].second;
}

void PnorRP::readAndClearCounter( uint32_t i_threshold,
                                  bool i_clear )
{
    TRACFCOMP(g_trac_pnor,"PnorRP::readAndClearCounter>  (Flash offset)=(Number of reads)");
    for( auto const& page : iv_pageCounter )
    {
        if( page.second > i_threshold )
        {
            TRACFCOMP(g_trac_pnor,"%.8X=%d", page.first, page.second);
        }
    }
    if( i_clear )
    {
        iv_pageCounter.clear();
    }
}

errlHndl_t PnorRP::setVirtAddrs(void)
{
    errlHndl_t l_errhdl = NULL;
    //Start out with the "next v addr" being the base of pnor
    //(this will increment in the loop below)
    uint64_t l_next_vAddr = BASE_VADDR;

    //Loop through each section in the TOC Buffer
    for(uint32_t i=0; i<PNOR::NUM_SECTIONS; i++)
    {

        if(iv_TOC[i].flashAddr == INVALID_FLASH_OFFSET)
        {
            //all flashAddrs are initialized to INVALID_FLASH_OFFSET
            //if the section's flashAddr does not get set, it doesnt exist
            // in this TOC
            continue;
        }
        //Set virtAddr for the current section
        iv_TOC[i].virtAddr = l_next_vAddr;
        l_next_vAddr += iv_TOC[i].size;

          // Handle section permissions
        if (iv_TOC[i].misc & FFS_MISC_READ_ONLY)
        {
            // Partitions marked with readOnly flag should be
            // READ_ONLY and not WRITABLE.
            int rc = mm_set_permission(
                                    (void*)iv_TOC[i].virtAddr,
                                    iv_TOC[i].size,
                                    READ_ONLY);
            if (rc)
            {
                TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC: Failed to set block permissions to READ_ONLY for section %s.",
                          SectionIdToString(i));
                /*@
                * @errortype
                * @moduleid PNOR::MOD_PNORRP_READTOC
                * @reasoncode PNOR::RC_READ_ONLY_PERM_FAIL
                * @userdata1 PNOR section id
                * @userdata2 PNOR section vaddr
                * @devdesc Could not set permissions of the
                *          given PNOR section to READ_ONLY
                * @custdesc A problem occurred while reading
                *           Processor NOR flash partition table
                */
                l_errhdl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                PNOR::MOD_PNORRP_READTOC,
                                PNOR::RC_READ_ONLY_PERM_FAIL,
                                i,
                                iv_TOC[i].virtAddr,
                                true /*Add HB SW Callout*/);
                l_errhdl->collectTrace(PNOR_COMP_NAME);
                break;
            }
        }
        else
        {
            // Need to set permissions to R/W
            int rc = mm_set_permission(
                                (void*)iv_TOC[i].virtAddr,
                                iv_TOC[i].size,
                                WRITABLE | WRITE_TRACKED);
            if (rc)
            {
                TRACFCOMP(g_trac_pnor, "E>PnorRP::readTOC: Failed to set block permissions to WRITABLE/WRITE_TRACKED for section %s.",
                          SectionIdToString(i));
                /*@
                * @errortype
                * @moduleid PNOR::MOD_PNORRP_READTOC
                * @reasoncode PNOR::RC_WRITE_TRACKED_PERM_FAIL
                * @userdata1 PNOR section id
                * @userdata2 PNOR section vaddr
                * @devdesc Could not set permissions of the
                *          given PNOR section to
                *          WRITABLE/WRITE_TRACKED
                * @custdesc A problem occurred while reading
                *           Processor NOR flash partition table
                */
                l_errhdl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                PNOR::MOD_PNORRP_READTOC,
                                PNOR::RC_WRITE_TRACKED_PERM_FAIL,
                                i,
                                iv_TOC[i].virtAddr,
                                true /*Add HB SW Callout*/);
                l_errhdl->collectTrace(PNOR_COMP_NAME);
                break;
            }
        }
    }

    return l_errhdl;
}
