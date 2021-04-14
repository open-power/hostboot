/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/spnorrp.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#include "pnorrp.H"
#include "spnorrp.H"
#include <pnor/pnor_reasoncodes.H>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include <sys/msg.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sys/mm.h>
#include <errno.h>
#include <util/align.H>
#include "pnor_common.H"
#include <console/consoleif.H>
#include <secureboot/service.H>
#include <secureboot/containerheader.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/header.H>
#include <sys/task.h>
#include <arch/ppc.H>

extern trace_desc_t* g_trac_pnor;

// used to uniquely identify the secure PNOR RP message queue
const char* SPNORRP_MSG_Q = "spnorrpq";

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace PNOR
{
    //used by secure message queue for load/unload of secure PNOR sections
    enum secure_msg_type
    {
        MSG_LOAD_SECTION = 0x02,
        MSG_UNLOAD_SECTION = 0x03,
    };
};


using namespace PNOR;

/********************
 Helper Methods
 ********************/

/**
 * @brief  Static function wrapper to pass into task_create
 */
void* secure_wait_for_message( void* unused )
{
    // Mark task as an independent daemon so if it crashes, Hostboot will
    // terminate
    (void)task_detach();
    TRACUCOMP(g_trac_pnor, "wait_for_message> " );
    Singleton<SPnorRP>::instance().waitForMessage();
    return NULL;
}


/********************
 Private/Protected Methods
 ********************/

/**
 * @brief  Constructor
 */
SPnorRP::SPnorRP()
:
iv_msgQ(NULL)
,iv_startupRC(0)
{
    TRACDCOMP(g_trac_pnor, "SPnorRP::SPnorRP> " );
    // setup everything in a separate function
    initDaemon();

    TRACFCOMP(g_trac_pnor, "< SPnorRP::PnorRP : Startup Errors=%X ", iv_startupRC );
}

/**
 * @brief  Destructor
 */
SPnorRP::~SPnorRP()
{
    TRACDCOMP(g_trac_pnor, "SPnorRP::~SPnorRP> " );

    // delete the message queue we created
    if( iv_msgQ )
    {
        msg_q_destroy( iv_msgQ );
    }

    // clean up the load records
    for(std::map<SectionId, LoadRecord*>::iterator
        i = iv_loadedSections.begin();
        i != iv_loadedSections.end();
        ++i)
    {
        LoadRecord* l_rec = (*i).second;
        TRACFCOMP(g_trac_pnor,
            "Section 0x%X has %lu references.", (*i).first, l_rec->refCount);
        delete l_rec;
    }

    TRACDCOMP(g_trac_pnor, "< SPnorRP::~SPnorRP" );
}

SPnorRP* SPnorRP::setupVmm(const PNOR::SectionData_t * const i_TOC)
{
    errlHndl_t l_errhdl = nullptr;
    for(int i = 0; i < PNOR::NUM_SECTIONS; i++)
    {
        if(i_TOC[i].size == 0)
        {
            continue;
        }
        const auto temp_vaddr = reinterpret_cast<void*>(i_TOC[i].virtAddr +
                                                        VMM_VADDR_SPNOR_DELTA);

        const auto spnor_vaddr = reinterpret_cast<void*>(i_TOC[i].virtAddr +
                                                        (2*VMM_VADDR_SPNOR_DELTA));

        // create a Block for temp space
        l_errhdl = allocBlock(NULL,
                              temp_vaddr,
                              i_TOC[i].size );
        if( l_errhdl )
        {
            break;
        }

        // set permissions for temp space
        l_errhdl = setPermission(temp_vaddr,
                                 i_TOC[i].size,
                                 NO_ACCESS);
        if ( l_errhdl )
        {
            break;
        }

        // create a block for secure space
        l_errhdl = allocBlock(iv_msgQ,
                              spnor_vaddr,
                              i_TOC[i].size );
        if( l_errhdl )
        {
             break;
        }

        // set permissions for secure space
        l_errhdl = setPermission(spnor_vaddr,
                                 i_TOC[i].size,
                                 NO_ACCESS);
        if ( l_errhdl )
        {
            break;
        }
    }

    if( l_errhdl )
    {
        iv_startupRC = l_errhdl->reasonCode();
        errlCommit(l_errhdl,PNOR_COMP_ID);
    }
    return this;
}

/**
 * @brief  A wrapper for mm_alloc_block that encapsulates error log creation.
 */
errlHndl_t SPnorRP::allocBlock(msg_q_t i_mq, void* i_va, uint64_t i_size) const
{
    errlHndl_t l_errhdl = NULL;
    int rc = mm_alloc_block(i_mq, i_va, i_size );
    if( rc )
    {
        TRACFCOMP( g_trac_pnor,"SPnorRP::allocBlock> Error "
            "with mm_alloc_block at address 0x%.16llX : rc=%d", i_va, rc );
        /*@
         * @errortype
         * @severity     ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid     PNOR::MOD_SPNORRP_ALLOCATE_BLOCK
         * @reasoncode   PNOR::RC_EXTERNAL_ERROR
         * @userdata1    Requested Address
         * @userdata2    rc from mm_alloc_block
         * @devdesc      SPnorRP::initDaemon> Error from mm_alloc_block
         * @custdesc     A problem occurred while initializing secure PNOR
         */
        l_errhdl = new ERRORLOG::ErrlEntry(
                           ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                           PNOR::MOD_SPNORRP_ALLOCATE_BLOCK,
                           PNOR::RC_EXTERNAL_ERROR,
                           TO_UINT64(reinterpret_cast<uint64_t>(i_va)),
                           TO_UINT64(rc),
                           true); //Add HB SW Callout
        l_errhdl->collectTrace(PNOR_COMP_NAME);
        l_errhdl->collectTrace(SECURE_COMP_NAME);
    }
    return l_errhdl;
}

/**
 * @brief  A wrapper for mm_set_permission that adds error log creation.
 */
errlHndl_t SPnorRP::setPermission(void* i_va, uint64_t i_size,
                                              uint64_t i_accessType) const
{
    errlHndl_t l_errhdl = NULL;
    int rc = mm_set_permission(reinterpret_cast<void*>(i_va), i_size,
                                                              i_accessType);
    if ( rc )
    {
        TRACFCOMP( g_trac_pnor, "SPnorRP::setPermission> Error "
            "with mm_set_permission at address 0x%.16llX : rc=%d",i_va, rc );
        /*@
         * @errortype
         * @severity      ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid      PNOR::MOD_SPNORRP_SET_PERMISSION
         * @reasoncode    PNOR::RC_EXTERNAL_ERROR
         * @userdata1     Requested Address
         * @userdata2     rc from mm_set_permission
         * @devdesc       Could not set permissions of the
         *                given PNOR section
         * @custdesc      A problem occurred while initializing secure PNOR
         */
        l_errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                            PNOR::MOD_SPNORRP_SET_PERMISSION,
                            PNOR::RC_EXTERNAL_ERROR,
                            TO_UINT64(reinterpret_cast<uint64_t>(i_va)),
                            TO_UINT64(rc),
                            true); // Add HB SW Callout
        l_errhdl->collectTrace(PNOR_COMP_NAME);
        l_errhdl->collectTrace(SECURE_COMP_NAME);
    }
    return l_errhdl;
}

/**
 * @brief  A wrapper for mm_remove_pages that adds error log creation.
 */
errlHndl_t SPnorRP::removePages(void* i_va, uint64_t i_size) const
{
    errlHndl_t l_errhdl = nullptr;
    int l_rc = mm_remove_pages (RELEASE,
            reinterpret_cast<void*>(i_va), i_size);
    if (l_rc)
    {
        TRACFCOMP(g_trac_pnor, "SPnorRP::removePages: mm_remove_pages errored,"
                " vaddr: 0x%llX, rc: %d, size:0x%llX", i_va, l_rc, i_size);
        /*@
         *  @errortype
         *  @moduleid         PNOR::MOD_SPNORRP_REMOVE_PAGES
         *  @reasoncode       PNOR::RC_EXTERNAL_ERROR
         *  @userdata1        virtual address
         *  @userdata2[00:31] rc from mm_remove_pages
         *  @userdata2[32:63] The size of memory attempted to remove
         *  @devdesc          mm_remove_pages failed
         *  @custdesc         A problem occurred in the security subsystem
         */
        l_errhdl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_SPNORRP_REMOVE_PAGES,
                                    PNOR::RC_EXTERNAL_ERROR,
                                    reinterpret_cast<uint64_t>(i_va),
                                    TWO_UINT32_TO_UINT64(
                                        TO_UINT32(l_rc),
                                        TO_UINT32(i_size)
                                    ),
                                    true); // Add HB SW Callout
        l_errhdl->collectTrace(PNOR_COMP_NAME);
        l_errhdl->collectTrace(SECURE_COMP_NAME);
    }
    return l_errhdl;
}


/**
 * @brief Initialize the daemon
 */
void SPnorRP::initDaemon()
{
    TRACFCOMP(g_trac_pnor, "SPnorRP::initDaemon> " );
    errlHndl_t l_errhdl = NULL;

    do
    {
        // create a message queue for secure space
        iv_msgQ = msg_q_create();

        // register it so that it can be discovered by loadSecureSection()
        int rc = msg_q_register(iv_msgQ, SPNORRP_MSG_Q);

        assert(rc == 0);

#ifndef CONFIG_FILE_XFER_VIA_PLDM
        // create a Block for temp space
        l_errhdl = allocBlock( NULL, reinterpret_cast<void*>(TEMP_VADDR),
                                                             PNOR_SIZE );
        if( l_errhdl )
        {
            break;
        }

        // set permissions for temp space
        l_errhdl = setPermission(reinterpret_cast<void*>(TEMP_VADDR),
                                                        PNOR_SIZE, NO_ACCESS);
        if ( l_errhdl )
        {
            break;
        }

        // create a block for secure space
        l_errhdl = allocBlock( iv_msgQ, reinterpret_cast<void*>(SBASE_VADDR),
                                                                PNOR_SIZE );
        if( l_errhdl )
        {
             break;
        }

        // set permissions for secure space
        l_errhdl = setPermission( reinterpret_cast<void*>(SBASE_VADDR),
                                                        PNOR_SIZE, NO_ACCESS);
        if ( l_errhdl )
        {
            break;
        }
#endif

        // start task to wait on the queue
        task_create( secure_wait_for_message, NULL );

    } while(0);

    if( l_errhdl )
    {
        iv_startupRC = l_errhdl->reasonCode();
        errlCommit(l_errhdl,PNOR_COMP_ID);
    }

    TRACUCOMP(g_trac_pnor, "< SPnorRP::initDaemon" );
}

/**
 * @brief  Load secure sections into temporary address space and verify them
 */
uint64_t SPnorRP::verifySections(SectionId i_id,
                                 bool i_loadedPreviously,
                                 LoadRecord* io_rec,
                                 uint32_t& o_plid)
{
    o_plid=0;
    SectionInfo_t l_info;
    errlHndl_t l_errhdl = NULL;
    bool failedVerify = false;
    uint64_t l_rc = 0;

    do {
        l_errhdl = getSectionInfo(i_id, l_info);

        if (l_errhdl)
        {
            TRACFCOMP(g_trac_pnor,
                "< SPnorrRP::verifySections - getSectionInfo failed");

            break;
        }

        TRACDCOMP(g_trac_pnor,"SPnorRP::verifySections getSectionInfo"
                " succeeded for sec = %s", l_info.name);

        if (!l_info.secure)
        {
            TRACFCOMP(g_trac_pnor,ERR_MRK"PNOR::verifySections> called on "
                    "unsecured section");

            /*@
             * @errortype
             * @severity     ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid     PNOR::MOD_SPNORRP_VERIFYSECTIONS
             * @reasoncode   PNOR::RC_UNSIGNED_PNOR_SECTION
             * @userdata1    PNOR section requested to verify
             * @userdata2    0
             * @devdesc      Cannot verify unsigned PNOR section
             * @custdesc     Security failure: unable to securely load
             *               requested firmware.
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                                   ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                   PNOR::MOD_SPNORRP_VERIFYSECTIONS,
                                   PNOR::RC_UNSIGNED_PNOR_SECTION,
                                   TO_UINT64(i_id),
                                   0,
                                   true /*Add HB SW Callout*/);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            l_errhdl->collectTrace(SECURE_COMP_NAME);
            break;
        }
        else
        {
            TRACFCOMP(g_trac_pnor,"PNOR::verifySections> called on secure section %s",
                      PNOR::SectionIdToString(i_id));
        }

        // If hash table exists, need to adjust sizes
        if (l_info.hasHashTable)
        {
            TRACFCOMP(g_trac_pnor, "PNOR::verifySections> hasHashTable FOUND l_info.name=%s", l_info.name);
            io_rec->hasHashTable = true;
            l_info.vaddr -= l_info.secureProtectedPayloadSize;
            l_info.size += l_info.secureProtectedPayloadSize;
            io_rec->hashTableVaddr = l_info.vaddr;
        }

        l_info.vaddr -= PAGESIZE; // back up a page to expose the secure header
        l_info.size += PAGESIZE; // add a page to size to account for the header

        // it's a coding error if l_info.vaddr is not in secure space
        if (l_info.vaddr < SBASE_VADDR)
        {
            TRACFCOMP(g_trac_pnor,ERR_MRK"SPnorRP::verifySections Virtual address for section %s is not in secure space. Virtual address=0x%llX",
                      l_info.name, l_info.vaddr);
            /*@
             * @errortype
             * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid        PNOR::MOD_SPNORRP_VERIFYSECTIONS
             * @reasoncode      PNOR::RC_SECURE_VADDR_MISMATCH
             * @userdata1       PNOR section
             * @userdata2       PNOR section virtual address
             * @devdesc         Virtual address of PNOR section is not in Secure Space
             * @custdesc        Platform Security Error
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            PNOR::MOD_SPNORRP_VERIFYSECTIONS,
                            PNOR::RC_SECURE_VADDR_MISMATCH,
                            TO_UINT64(i_id),
                            l_info.vaddr,
                            true);
            SECUREBOOT::addSecureUserDetailsToErrlog(l_errhdl);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            l_errhdl->collectTrace(SECURE_COMP_NAME);
            break;
        }


        // Note: A pointer to virtual memory in one PNOR space can be converted
        // to a pointer to any of the other two PNOR spaces and visa versa.
        // These are unsecured space, temp space, and secured space. They are
        // evenly separated by VMM_VADDR_SPNOR_DELTA and in the above order.
        // l_info.vaddr points to secure space, so we subtract a delta value
        // from it to calculate its corresponding address in temp space.
        uint8_t* l_tempAddr = reinterpret_cast<uint8_t*>(l_info.vaddr)
                                                       - VMM_VADDR_SPNOR_DELTA;

        // calcluate unsecured address from temp address
        uint8_t* l_unsecuredAddr = l_tempAddr - VMM_VADDR_SPNOR_DELTA;

        TRACFCOMP(g_trac_pnor,"SPnorRP::verifySections section start address "
                    "in temp space l_tempAddr=0x%.16llX, "
                    "section start address in unsecured space l_unsecureAddr=0x%.16llX, "
                    "l_info.size = 0x%.16llX, "
                    "l_info.secureProtectedPayloadSize = 0x%.16llX, ",
                    l_tempAddr, l_unsecuredAddr, l_info.size,
                    l_info.secureProtectedPayloadSize);

        TRACDBIN(g_trac_pnor,"SPnorRP::verifySections unsecured mem now: ",
                             l_unsecuredAddr, 128);

        TRACDCOMP( g_trac_pnor,
                    "SPnorRP::verifySections Doing setPermission for address "
                              "0x%llX of length 0x%llX",
                       l_tempAddr,
                       l_info.secureProtectedPayloadSize + PAGESIZE);

        l_errhdl = setPermission(l_tempAddr,
                                 l_info.secureProtectedPayloadSize + PAGESIZE,
                                 WRITABLE | ALLOCATE_FROM_ZERO);

        if (l_errhdl)
        {
            TRACFCOMP( g_trac_pnor,
                       ERR_MRK"SPnorRP::verifySections "
                              "setPermission failed for address "
                              "0x%llX of length 0x%llX",
                       l_tempAddr,
                       l_info.secureProtectedPayloadSize + PAGESIZE);
            break;
        }


        TRACDCOMP(g_trac_pnor,"SPnorRP::verifySections about to do memcpy");

        // copy from unsecured PNOR space to temp PNOR space
        memcpy(l_tempAddr, l_unsecuredAddr, l_info.secureProtectedPayloadSize
                                          + PAGESIZE); // plus header size

        SECUREBOOT::ContainerHeader l_conHdr;
        l_errhdl = l_conHdr.setHeader(l_tempAddr);
        if (l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorRP::verifySections> setheader failed");
            break;
        }

        size_t l_totalContainerSize = l_conHdr.totalContainerSize();
        auto l_prefixHdrFlags = l_conHdr.prefixHeaderFlags();

        TRACFCOMP(g_trac_pnor, "SPnorRP::verifySections> Prefix hdr flags:0x%X, "
                  "secure_version:0x%X", l_prefixHdrFlags, l_conHdr.secureVersion());

        TRACFCOMP(g_trac_pnor, "SPnorRP::verifySections "
                "Total container size = 0x%.16llX", l_totalContainerSize);

        if (l_totalContainerSize <
            (PAGESIZE + l_info.secureProtectedPayloadSize))
        {
            TRACFCOMP(g_trac_pnor,ERR_MRK"SPnorRP::verifySections For section %s, total container size (%d) was less than header "
                      "size (4096) + payload text size (%d)",
                      l_info.name,
                      l_totalContainerSize,
                      l_info.secureProtectedPayloadSize)
            /*@
             * @errortype
             * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid        PNOR::MOD_SPNORRP_VERIFYSECTIONS
             * @reasoncode      PNOR::RC_SECURE_TOTAL_SIZE_INVAL
             * @userdata1       PNOR section
             * @userdata2       Protected Payload Size plus Header Size
             * @devdesc         Total Container Size smaller than Protected Payload and Header size
             * @custdesc        Failure in security subsystem
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            PNOR::MOD_SPNORRP_VERIFYSECTIONS,
                            PNOR::RC_SECURE_TOTAL_SIZE_INVAL,
                            TO_UINT64(i_id),
                            PAGESIZE + l_info.secureProtectedPayloadSize,
                            true);
            SECUREBOOT::addSecureUserDetailsToErrlog(l_errhdl);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            l_errhdl->collectTrace(SECURE_COMP_NAME);
            break;
        }

        if (l_info.size < l_totalContainerSize)
        {
            TRACFCOMP(g_trac_pnor,ERR_MRK"SPnorRP::verifySections For section %s, logical section size (%d) was less than total container size (%d)",
                      l_info.name,
                      l_info.size,
                      l_totalContainerSize);
            /*@
             * @errortype
             * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid        PNOR::MOD_SPNORRP_VERIFYSECTIONS
             * @reasoncode      PNOR::RC_SECURE_SIZE_MISMATCH
             * @userdata1       PNOR section
             * @userdata2       Total Container Size
             * @devdesc         PNOR section size smaller than total container size
             * @custdesc        Failure in security subsystem
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            PNOR::MOD_SPNORRP_VERIFYSECTIONS,
                            PNOR::RC_SECURE_SIZE_MISMATCH,
                            TO_UINT64(i_id),
                            l_totalContainerSize,
                            true);
            SECUREBOOT::addSecureUserDetailsToErrlog(l_errhdl);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            l_errhdl->collectTrace(SECURE_COMP_NAME);
            break;
        }

        TRACDCOMP(g_trac_pnor,"SPnorRP::verifySections did memcpy");
        TRACDBIN(g_trac_pnor,"SPnorRP::verifySections temp mem now: ",
                             l_tempAddr, 128);

        // store secure space pointer in load record (Includes Header)
        io_rec->secAddr = reinterpret_cast<uint8_t*>(l_info.vaddr);

        TRACDCOMP(g_trac_pnor,"section start address in secure space is "
                              "0x%.16llX",io_rec->secAddr);

        // verify while in temp space
        if (SECUREBOOT::enabled())
        {
            l_errhdl = SECUREBOOT::verifyContainer(l_tempAddr, {i_id});
            if (l_errhdl)
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorrRP::verifySections - section "
                      "with id 0x%08X failed verifyContainer", i_id);
                failedVerify = true;
                break;
            }

            auto const * const pPnorString = PNOR::SectionIdToString(i_id);
            l_errhdl = SECUREBOOT::verifyComponentId(l_conHdr,pPnorString);
            if(l_errhdl)
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorrRP::verifySections: "
                    "Failed in call to SECUREBOOT::verifyComponentId");
                failedVerify = true;
                break;
            }

            l_errhdl = miscSectionVerification(l_tempAddr, i_id);
            if (l_errhdl)
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorrRP::verifySections  - section "
                     " with id 0x%08X failed miscSectionVerification", i_id);
                failedVerify = true;
                break;
            }
        }

        l_errhdl = processFwKeyIndicators(l_conHdr,i_id);
        if(l_errhdl)
        {
            TRACFCOMP(g_trac_pnor, ERR_MRK "SPnorrRP::verifySections: Failed "
                "in call to processFwKeyIndicators().  PNOR section = %s.",
                PNOR::SectionIdToString(i_id));
            break;
        }

        // verification succeeded

        // parse container header now that it is verified
        // store the payload text size in the section load record
        // Note: the text size we get back is now trusted
        io_rec->textSize = l_conHdr.payloadTextSize();
        if (io_rec->textSize != l_info.secureProtectedPayloadSize)
        {
            TRACFCOMP(g_trac_pnor,ERR_MRK"SPnorRP::verifySections For section %s, verified protected size (%d) does not equal unverified size parsed by pnorrp (%d)",
                      l_info.name,
                      io_rec->textSize ,
                      l_info.secureProtectedPayloadSize);
            /*@
             * @errortype
             * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid        PNOR::MOD_SPNORRP_VERIFYSECTIONS
             * @reasoncode      PNOR::RC_SECURE_PRO_SIZE_MISMATCH
             * @userdata1       PNOR section
             * @userdata2       Protected Payload Size
             * @devdesc         Verified Protected Payload size does not match what was parsed by PnorRp
             * @custdesc        Failure in security subsystem
             */
            l_errhdl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            PNOR::MOD_SPNORRP_VERIFYSECTIONS,
                            PNOR::RC_SECURE_PRO_SIZE_MISMATCH,
                            TO_UINT64(i_id),
                            l_info.secureProtectedPayloadSize,
                            true);
            SECUREBOOT::addSecureUserDetailsToErrlog(l_errhdl);
            l_errhdl->collectTrace(PNOR_COMP_NAME);
            l_errhdl->collectTrace(SECURE_COMP_NAME);
            break;
        }

        // Size of data loaded into Secure PnorRP vaddr space (Includes Header)
        size_t l_protectedSizeWithHdr = PAGESIZE + io_rec->textSize;
        TRACFCOMP(g_trac_pnor, "SPnorRP::verifySections Total Protected size with Header = 0x%.16llX",
                  l_protectedSizeWithHdr);

        l_totalContainerSize = l_conHdr.totalContainerSize();
        // keep track of info size in load record (Includes Header)
        io_rec->infoSize = l_totalContainerSize;

        // if not loaded previously or...
        if (!i_loadedPreviously ||
        // loading after a prior unload and...
            (i_loadedPreviously &&
            // the protected payload measurement doesn't match the old one
            memcmp(&io_rec->payloadTextHash[0],
                   l_conHdr.payloadTextHash(),
                   SHA512_DIGEST_LENGTH)!=0
            )
           )
        {
            // pcr extension of PNOR hash
            l_errhdl = TRUSTEDBOOT::extendPnorSectionHash(l_conHdr,
                                        (l_tempAddr + PAGESIZE),
                                        i_id);
            if(l_errhdl)
            {
                TRACFCOMP(g_trac_pnor,"SPnorRP::verifySections extendPnorSectionHash failed");
                break;
            }
            // save off the payload text hash
            memcpy(&io_rec->payloadTextHash[0],
                   l_conHdr.payloadTextHash(),
                   SHA512_DIGEST_LENGTH);
        }

        // set permissions to be writable
        // in the case of HPT this is the header + HPT
        // in the case of no HPT this is the header + text region
        l_errhdl = setPermission(io_rec->secAddr, l_protectedSizeWithHdr,
                                 WRITABLE);
        if (l_errhdl)
        {
            if (l_info.hasHashTable)
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorRP::verifySections set permissions "
                          "failed on header + hash page table");
            }
            else
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorRP::verifySections set permissions "
                          "failed on header + text section");
            }
            break;
        }

        // set permissions on the unsecured pages to write tracked so that any
        // unprotected payload pages with dirty writes can flow back to PNOR.
        uint64_t unprotectedPayloadSize = l_totalContainerSize
            - PAGESIZE - io_rec->textSize;
        if (unprotectedPayloadSize) // only write track a non-zero range
        {
            TRACDCOMP(g_trac_pnor,INFO_MRK " SPnorRP::verifySections "
                "creating unprotected area (%d bytes) for section %s",
                unprotectedPayloadSize,
                l_info.name);

            if ((io_rec->textSize % PAGESIZE))
            {
                TRACFCOMP(g_trac_pnor,ERR_MRK"SPnorRP::verifySections For section %s, payloadTextSize does not fall on a page boundary and there is an unprotected payload",
                          l_info.name);
                /*@
                 * @errortype
                 * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid        PNOR::MOD_SPNORRP_VERIFYSECTIONS
                 * @reasoncode      PNOR::RC_NOT_PAGE_ALIGNED
                 * @userdata1       PNOR section
                 * @userdata2       Protected Payload Size
                 * @devdesc         Protected Payload Size not Page aligned
                 * @custdesc        Failure in security subsystem
                 */
                l_errhdl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                PNOR::MOD_SPNORRP_VERIFYSECTIONS,
                                PNOR::RC_NOT_PAGE_ALIGNED,
                                TO_UINT64(i_id),
                                io_rec->textSize,
                                true);
                SECUREBOOT::addSecureUserDetailsToErrlog(l_errhdl);
                l_errhdl->collectTrace(PNOR_COMP_NAME);
                l_errhdl->collectTrace(SECURE_COMP_NAME);
                break;
            }

            if (l_info.hasHashTable)
            {
                l_errhdl = setPermission(io_rec->secAddr + l_protectedSizeWithHdr,
                                         unprotectedPayloadSize,
                                         READ_ONLY);
            }
            else
            {
                l_errhdl = setPermission(io_rec->secAddr + l_protectedSizeWithHdr,
                                         unprotectedPayloadSize,
                                         WRITABLE | WRITE_TRACKED);
            }
            if(l_errhdl)
            {
                TRACFCOMP(g_trac_pnor,"SPnorRP::verifySections set permissions "
                                  "failed on data section");
                break;
            }

            // Register the write tracked memory range to be flushed on
            // shutdown.
            if (!l_info.hasHashTable)
            {
                INITSERVICE::registerBlock(io_rec->secAddr + l_protectedSizeWithHdr,
                                           unprotectedPayloadSize, SPNOR_PRIORITY);
            }
        }
        else
        {
            TRACFCOMP(g_trac_pnor,INFO_MRK " SPnorRP::verifySections not "
                "creating unprotected area for section %s",
                l_info.name);
        }
        TRACDCOMP(g_trac_pnor,"SPnorRP::verifySections set permissions "
                              "and register block complete");
    } while(0);

    if( l_errhdl )
    {
        l_rc = EACCES;
        uint32_t l_errEid = l_errhdl->eid();
        iv_startupRC = l_errhdl->reasonCode();
        TRACFCOMP(g_trac_pnor,ERR_MRK"SPnorRP::verifySections there was an error");
        o_plid=l_errhdl->plid();
        if (failedVerify)
        {
            SECUREBOOT::handleSecurebootFailure(l_errhdl, false, true);
        }
        else
        {
            errlCommit(l_errhdl,PNOR_COMP_ID);
            INITSERVICE::doShutdown(l_errEid, true);
        }
    }

    return l_rc;
}

int64_t getHashPageTableIndex(const int64_t i_vaddr)
{
    return (i_vaddr / static_cast<int64_t>(PAGE_SIZE)) + 1;
}


PAGE_TABLE_ENTRY_t* getHashPageTableEntry(const int64_t i_vaddr,
                                          const uint64_t i_hash_vaddr)
{
    int64_t l_index = getHashPageTableIndex(i_vaddr);
    int64_t l_offset = l_index * HASH_PAGE_TABLE_ENTRY_SIZE;

    // l_offset is the offset for the start of the hash page table
    // i_hash_vaddr is the vaddr for the start of the hash in SECURE
    // subtract off DELTA of 3GB to get into TEMP space
    return reinterpret_cast<PAGE_TABLE_ENTRY_t*>(l_offset + i_hash_vaddr -
                                                 VMM_VADDR_SPNOR_DELTA);
}

errlHndl_t verify_page(const int64_t i_offset_vaddr, const uint64_t i_hash_vaddr,
                       const uint64_t i_hash_size)
{
    errlHndl_t l_errl = nullptr;

    // Get current hash page table entry in TEMP space
    PAGE_TABLE_ENTRY_t* l_pageTableEntry =
        getHashPageTableEntry(i_offset_vaddr, i_hash_vaddr);

    // Get previous hash page table entry in TEMP space
    PAGE_TABLE_ENTRY_t* l_prevPageTableEntry =
        getHashPageTableEntry(i_offset_vaddr - PAGE_SIZE, i_hash_vaddr);

    // Concatenate previous hash with current page data
    std::vector< std::pair<void*,size_t> > l_blobs;
    l_blobs.push_back(std::make_pair<void*,size_t>(l_prevPageTableEntry,
                                                   HASH_PAGE_TABLE_ENTRY_SIZE));

    // To get to PNOR space, we have the address of the hash in SECURE space and
    // we add hash table size to get passed the hash page table. Then we add
    // i_offset_vaddr, the offset of the requested vaddr, to end up at the
    // requested vaddr in SECURE space. Finally we subtract off 2 DELTAS of
    // 3GB each to get to the requested vaddr in PNOR space
    l_blobs.push_back(std::make_pair<void*,size_t>(
                                        reinterpret_cast<void*>(i_offset_vaddr +
                                            i_hash_vaddr + i_hash_size -
                                            2 * VMM_VADDR_SPNOR_DELTA),
                                            PAGE_SIZE));
    SHA512_t l_curPageHash = {0};
    SECUREBOOT::hashConcatBlobs(l_blobs, l_curPageHash);

    // Compare existing hash page table entry with the derived one.
    if (memcmp(l_pageTableEntry,l_curPageHash,HASH_PAGE_TABLE_ENTRY_SIZE) != 0)
    {
        TRACFCOMP(g_trac_pnor, "ERROR:>PNOR::verify_page secureboot verify fail on vaddr 0x%016llX",
                        i_hash_vaddr + i_hash_size + i_offset_vaddr);
        /*@
         * @severity        ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        MOD_SPNORRP_VERIFY_PAGE
         * @reasoncode      RC_VERIFY_PAGE_FAILED
         * @userdata1       Kernel RC
         * @userdata2       Virtual address accessed
         *
         * @devdesc         Secureboot page verify failure
         * @custdesc        Corrupted flash image or firmware error during system boot
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                         MOD_SPNORRP_VERIFY_PAGE,
                                         RC_VERIFY_PAGE_FAILED,
                                         TO_UINT64(EACCES),
                                         i_offset_vaddr,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(PNOR_COMP_NAME);
        l_errl->collectTrace(SECURE_COMP_NAME);
    }
    return l_errl;
}



/**
 * @brief  Message receiver for secure space
 */
void SPnorRP::waitForMessage()
{
    TRACDCOMP(g_trac_pnor, "SPnorRP::waitForMessage>" );

    errlHndl_t l_errhdl = NULL;
    msg_t* message = NULL;
    uint8_t* user_addr = NULL;
    uint8_t* eff_addr = NULL;
    int rc = 0;
    uint64_t status_rc = 0;
    LoadRecord l_rec;
    l_rec.secAddr = NULL;
    l_rec.textSize = 0;
    l_rec.infoSize = 0;

    while(1)
    {
        status_rc = 0;
        TRACUCOMP(g_trac_pnor, "SPnorRP::waitForMessage> waiting for message" );
        message = msg_wait( iv_msgQ );
        if( message )
        {
            uint32_t plid=0;

            // data[0] = virtual address requested
            // data[1] = address to place contents
            uint64_t requested_vaddr = message->data[0];
            eff_addr = reinterpret_cast<uint8_t*>(message->data[0]);
            user_addr = reinterpret_cast<uint8_t*>(message->data[1]);

            switch(message->type)
            {
                case( MSG_MM_RP_READ ):
                    {
                        uint64_t delta = VMM_VADDR_SPNOR_DELTA;

                        // check and see if our cached section information
                        // is obsolete and if so, change it
                        // NOTE: secAddr points to Secure Header
                        if ( (eff_addr < l_rec.secAddr) ||
                             (eff_addr >= (l_rec.secAddr + l_rec.infoSize))
                           )
                        {
                            bool l_found = false;
                            // recalculate addresses
                            for(std::map<SectionId, LoadRecord*>::const_iterator
                                i = iv_loadedSections.begin();
                                i != iv_loadedSections.end();
                                ++i)
                            {
                                LoadRecord* l_record = (*i).second;
                                if ( (eff_addr >= l_record->secAddr) &&
                                     (eff_addr < (l_record->secAddr +
                                                l_record->infoSize))
                                   )
                                {
                                    l_rec = *l_record;
                                    l_found = true;
                                    break;
                                }
                            }
                            if (!l_found)
                            {
                                TRACFCOMP( g_trac_pnor,
                                    "SPnorRP::waitforMessage - address %p "
                                    "out of bounds", eff_addr);
                                // not much we can do here unfortunately
                                // if we get here it is a coding mistake
                                status_rc = -EFAULT;
                                break;
                            }

                        }

                        TRACDCOMP( g_trac_pnor, "SPnorRP::waitForMessage got a"
                            " request to read from secure space - "
                            "message : user_addr=%p, eff_addr=%p, msgtype=%d, "
                            "textSize=0x%.16llX secAddr=0x%.16llX", user_addr,
                            eff_addr, message->type, l_rec.textSize,
                                                               l_rec.secAddr);

                        // If record has an associated hash page table, then we
                        // want to verify the page with the hash table in temp
                        if (SECUREBOOT::enabled() && l_rec.hasHashTable)
                        {
                            // Pass in the offset of just the data
                            int64_t offset_vaddr = requested_vaddr -
                                l_rec.hashTableVaddr - l_rec.textSize;

                            // There is no hash table entry when we try to
                            // verify the header
                            if (offset_vaddr >= 0) {
                                l_errhdl = verify_page(offset_vaddr,
                                                       l_rec.hashTableVaddr,
                                                       l_rec.textSize);
                            }

                            if (l_errhdl)
                            {
                                SECUREBOOT::handleSecurebootFailure(l_errhdl, false, true);
                                status_rc = -EFAULT;
                                break;
                            }
                        }

                        // determine the source of the data depending on
                        // whether it is part of the secure payload.
                        // by the way, this if could be removed to make this
                        // purely arithmetic
                        // NOTE: secAddr points to Secure Header
                        if (eff_addr >= ( (l_rec.secAddr + PAGESIZE) +
                                           l_rec.textSize))
                        {
                            delta += VMM_VADDR_SPNOR_DELTA;
                        }
                        TRACDCOMP( g_trac_pnor, "SPnorRP::waitForMessage "
                            "source address: %p", eff_addr - delta);

                        // depending on the value of delta, memcpy from either
                        // temp space or unsecured pnor space over to secure
                        // pnor space
                        memcpy(user_addr, eff_addr - delta, PAGESIZE);
                        // if the page came from temp space then free up
                        // the temp page now that we're done with it
                        // NOTE: secAddr points to Secure Header
                        if (!l_rec.hasHashTable && (eff_addr < ( (l_rec.secAddr + PAGESIZE) +
                                                    l_rec.textSize)))
                        {
                            mm_remove_pages(RELEASE, eff_addr - delta,
                                            PAGESIZE);
                        }
                    }
                    break;

                case( MSG_MM_RP_WRITE ):
                    {
                        TRACDCOMP( g_trac_pnor, "SPnorRP::waitForMessage "
                            "writing to an unsecured area of section.");

                        // calculate unsecured address (in PnorRP) by
                        // subtracting two deltas from secure address
                        uint8_t* dest = eff_addr - VMM_VADDR_SPNOR_DELTA
                                                  - VMM_VADDR_SPNOR_DELTA;
                        memcpy(dest, user_addr, PAGESIZE);
                    }
                    break;

                case( PNOR::MSG_LOAD_SECTION ):
                    {
                        SectionId l_id =
                                    static_cast<SectionId>(message->data[0]);
                        do
                        {
                            LoadRecord* l_record = nullptr;
                            bool l_loadedPreviously = false;
                            uint64_t l_rc = 0;

                            // if there is already a Load Record
                            auto l_item = iv_loadedSections.find(l_id);
                            if (l_item != iv_loadedSections.end())
                            {
                                l_loadedPreviously = true;
                                l_record = iv_loadedSections[l_id];
                            }
                            else
                            {
                                TRACDCOMP(g_trac_pnor,"Loading %s for the first time", PNOR::SectionIdToString(l_id));
                                l_record = new LoadRecord;
                            }

                            TRACDCOMP(g_trac_pnor, "SPnorRP::waitForMessage> MSG_LOAD_SECTION refCount is %i",l_record->refCount);
                            if (l_record->refCount == 0)
                            {
                                TRACDCOMP(g_trac_pnor,"Loading %s fresh", PNOR::SectionIdToString(l_id));
                                uint32_t loadPlid=0;
                                l_rc = verifySections(l_id,
                                                      l_loadedPreviously,
                                                      l_record,
                                                      loadPlid);
                                if (l_rc)
                                {
                                    if(!l_loadedPreviously)
                                    {
                                        delete l_record;
                                        l_record = nullptr;
                                    }
                                    status_rc = -l_rc;

                                    // Tunnel the PLID of the verify error to
                                    // the caller
                                    plid=loadPlid;

                                    break;
                                }
                            }

                            if (!l_loadedPreviously)
                            {
                                iv_loadedSections[l_id] = l_record;
                            }

                            // increment refcount
                            l_record->refCount++;

                            // cache the record to use fields later as hints
                            l_rec = *l_record;
                        } while (0);
                    }
                    break;
                case( PNOR::MSG_UNLOAD_SECTION ):
                    {
                        SectionId l_id =
                                      static_cast<SectionId>(message->data[0]);

                        do {
                            // Disallow unload of HBB, HBI and Targeting
                            if (l_id == HB_BASE_CODE ||
                                l_id == HB_EXT_CODE  ||
                                l_id == HB_DATA)
                            {
                                TRACFCOMP( g_trac_pnor, ERR_MRK"SPnorRP::waitForMessage> Secure unload of HBB, HBI, and targeting is not allowed secId=%d", l_id);
                                /*@
                                 * @errortype
                                 * @moduleid   PNOR::MOD_SPNORRP_WAITFORMESSAGE
                                 * @reasoncode PNOR::RC_SECURE_UNLOAD_DISALLOWED
                                 * @userdata1  Section Id
                                 * @devdesc    Secure unload of sections that
                                 *             critical to hostboot operation
                                 *             are not allowed.
                                 * @custdesc   A problem occurred within the
                                 *             security subsystem.
                                 */
                                l_errhdl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_SPNORRP_WAITFORMESSAGE,
                                    PNOR::RC_SECURE_UNLOAD_DISALLOWED,
                                    TO_UINT64(l_id),
                                    0,
                                    true /*Add HB SW Callout*/);
                                status_rc = -EFAULT;
                                break;

                            }

                            // if we don't find a record
                            // or refcount is zero then throw an error since
                            // this is not currently a loaded section
                            auto l_item = iv_loadedSections.find(l_id);
                            if (l_item == iv_loadedSections.end() ||
                                l_item->second->refCount == 0 )
                            {
                                TRACFCOMP( g_trac_pnor, ERR_MRK"SPnorRP::waitForMessage> Attempting to unload a section that is not a loaded section. refCount=%i",l_item->second->refCount);
                                /*@
                                 * @errortype
                                 * @moduleid   PNOR::MOD_SPNORRP_WAITFORMESSAGE
                                 * @reasoncode PNOR::RC_NOT_A_LOADED_SECTION
                                 * @userdata1  Section attempted to unload
                                 * @devdesc    Not a loaded section
                                 * @custdesc   A problem occurred within the
                                 *             security subsystem.
                                 */
                                l_errhdl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_SPNORRP_WAITFORMESSAGE,
                                    PNOR::RC_NOT_A_LOADED_SECTION,
                                    TO_UINT64(l_id),
                                    0,
                                    true /*Add HB SW Callout*/);
                                status_rc = -EFAULT;
                                break;
                            }

                            auto l_rec = l_item->second;

                            TRACDCOMP(g_trac_pnor, "SPnorRP::waitForMessage> MSG_UNLOAD_SECTION refCount is %i",l_rec->refCount);

                            size_t l_sizeWithHdr = PAGESIZE + l_rec->textSize;

                            // if the section has an unsecured portion
                            if (l_sizeWithHdr != l_rec->infoSize && !l_rec->hasHashTable)
                            {
                                TRACFCOMP( g_trac_pnor, ERR_MRK"SPnorRP::waitForMessage> Attempting to unload an unsupported section: 0x%X textsize+hdr: 0x%llX infosize: 0x%llX (the two sizes must be equal)", l_id, l_sizeWithHdr, l_rec->infoSize);
                                /*@
                                 * @errortype
                                 * @moduleid   PNOR::MOD_SPNORRP_WAITFORMESSAGE
                                 * @reasoncode PNOR::RC_NOT_A_SUPPORTED_SECTION
                                 * @userdata1  Section attempted to unload
                                 * @devdesc    Not a supported section
                                 * @custdesc   A problem occurred within the
                                 *             security subsystem.
                                 */
                                l_errhdl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_SPNORRP_WAITFORMESSAGE,
                                    PNOR::RC_NOT_A_SUPPORTED_SECTION,
                                    TO_UINT64(l_id),
                                    0,
                                    true /*Add HB SW Callout*/);
                                status_rc = -EFAULT;
                                break;
                            }

                            if (l_rec->refCount > 1)
                            {
                                l_rec->refCount--;
                                 // normal operation, no error
                                 // no need to do anything if refcount is
                                 // 2 or more
                                break;
                            }
                            TRACDCOMP(g_trac_pnor,"Completely unloading %s", PNOR::SectionIdToString(l_id));

                            if (l_rec->hasHashTable)
                            {
                                // remove unprotected pages
                                l_errhdl = removePages(l_rec->secAddr + PAGE_SIZE + l_rec->textSize,
                                                       l_rec->infoSize - PAGE_SIZE - l_rec->textSize);
                                if (l_errhdl)
                                {
                                    TRACFCOMP(g_trac_pnor,
                                        ERR_MRK"SPnorRP::waitForMessage> "
                                        "removePages failed for address "
                                        "0x%11X of length 0x%11X",
                                        l_rec->secAddr + PAGE_SIZE + l_rec->textSize,
                                        l_rec->infoSize - PAGE_SIZE - l_rec->textSize);
                                    status_rc = -EFAULT;
                                    break;
                                }

                                l_errhdl = setPermission(l_rec->secAddr + PAGE_SIZE + l_rec->textSize,
                                                         l_rec->infoSize - PAGE_SIZE - l_rec->textSize,
                                                         NO_ACCESS);
                                if (l_errhdl)
                                {
                                    TRACFCOMP(g_trac_pnor,
                                        ERR_MRK"SPnorRP::waitForMessage> "
                                        "setPermission failed for address "
                                        "0x%11X of length 0x%11X",
                                        l_rec->secAddr + PAGE_SIZE + l_rec->textSize,
                                        l_rec->infoSize - PAGE_SIZE - l_rec->textSize);

                                    status_rc = -EFAULT;
                                    break;
                                }
                            }

                            l_errhdl = removePages(l_rec->secAddr,
                                                   l_sizeWithHdr);
                            if (l_errhdl)
                            {
                                TRACFCOMP( g_trac_pnor,
                                    ERR_MRK"SPnorRP::waitForMessage> "
                                    "removePages failed for address "
                                    "0x%llX of length 0x%llX", l_rec->secAddr,
                                                                l_sizeWithHdr);
                                status_rc = -EFAULT;
                                break;
                            }

                            l_errhdl = setPermission(l_rec->secAddr,
                                                     l_sizeWithHdr,
                                                     NO_ACCESS);
                            if (l_errhdl)
                            {
                                TRACFCOMP( g_trac_pnor,
                                    ERR_MRK"SPnorRP::waitForMessage> "
                                    "setPermission failed for address "
                                    "0x%llX of length 0x%llX", l_rec->secAddr,
                                                               l_sizeWithHdr);

                                status_rc = -EFAULT;
                                break;
                            }

                            // clear out temp space
                            uint8_t* l_tempAddr = l_rec->secAddr -
                                                    VMM_VADDR_SPNOR_DELTA;

                            l_errhdl = removePages(l_tempAddr,
                                                   l_sizeWithHdr);
                            if (l_errhdl)
                            {
                                TRACFCOMP(g_trac_pnor,
                                    ERR_MRK"SPnorRP::waitForMessage> "
                                    "removePages failed for address "
                                    "0x%llX of length 0x%llX", l_tempAddr,
                                                               l_sizeWithHdr);
                                status_rc = -EFAULT;
                                break;
                            }

                            TRACDCOMP( g_trac_pnor,
                                    "SPnorRP::waitForMessage> "
                                    "Doing setPermission NO_ACCESS for address "
                                    "0x%llX of length 0x%llX", l_tempAddr,
                                                               l_sizeWithHdr);

                            l_errhdl = setPermission(l_tempAddr,
                                                     l_sizeWithHdr,
                                                     NO_ACCESS);
                            if (l_errhdl)
                            {
                                TRACFCOMP(g_trac_pnor,
                                    ERR_MRK"SPnorRP::waitForMessage> "
                                    "setPermission failed for address "
                                    "0x%llX of length 0x%llX", l_tempAddr,
                                                               l_sizeWithHdr);
                                status_rc = -EFAULT;
                                break;
                            }

                            l_rec->secAddr = nullptr;
                            l_rec->textSize = 0;
                            l_rec->infoSize = 0;
                            l_rec->refCount = 0;
                        } while (0);
                    }
                    break;
                default:
                    TRACFCOMP( g_trac_pnor, ERR_MRK"SPnorRP::waitForMessage> "
                    "Unrecognized message type : user_addr=%p, eff_addr=%p,"
                    " msgtype=%d", user_addr, eff_addr, message->type );
                    /*@
                     * @errortype
                     * @severity     ERRL_SEV_CRITICAL_SYS_TERM
                     * @moduleid     PNOR::MOD_SPNORRP_WAITFORMESSAGE
                     * @reasoncode   PNOR::RC_INVALID_MESSAGE_TYPE
                     * @userdata1    Message type
                     * @userdata2    Requested Virtual Address
                     * @devdesc      PnorRP::waitForMessage> Unrecognized
                     *               message type
                     * @custdesc     A problem occurred while accessing
                     *               the boot flash.
                     */
                    l_errhdl = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                           PNOR::MOD_SPNORRP_WAITFORMESSAGE,
                                           PNOR::RC_INVALID_MESSAGE_TYPE,
                                           TO_UINT64(message->type),
                                           reinterpret_cast<uint64_t>(eff_addr),
                                           true /*Add HB SW Callout*/);
                    l_errhdl->collectTrace(PNOR_COMP_NAME);
                    l_errhdl->collectTrace(SECURE_COMP_NAME);
                    status_rc = -EINVAL; /* Invalid argument */
            }

            assert(msg_is_async(message) == false);

            if( l_errhdl )
            {
                errlCommit(l_errhdl,PNOR_COMP_ID);
                TRACFCOMP(g_trac_pnor,
                    ERR_MRK"SPnorRP::waitForMessage> status_rc=%d, ", status_rc );
            }

            /*  Expected Response:
             *      data[0] = virtual address requested or
             *                section id (if load message)
             *      data[1] = rc (0 or negative errno value)
             *      extra_data = Specific reason code.
             */
            message->data[1] = status_rc;
            message->extra_data = reinterpret_cast<void*>(plid);
            rc = msg_respond( iv_msgQ, message );
            if( rc )
            {
                TRACFCOMP(g_trac_pnor,
                          "SPnorRP::waitForMessage> Error from msg_respond, "
                          "giving up : rc=%d", rc );
                break;
            }
        }
        assert(message != NULL);
    }

    TRACDCOMP(g_trac_pnor, "< SPnorRP::waitForMessage" );
}

/**
 *  @brief Loads or unloads requested PNOR section to secure virtual address
 *         space
 */
errlHndl_t loadUnloadSecureSection(const SectionId i_section,
                                   secure_msg_type i_loadUnload)
{
    assert( i_loadUnload == PNOR::MSG_LOAD_SECTION ||
            i_loadUnload == PNOR::MSG_UNLOAD_SECTION, "Bug! You can only pass PNOR::MSG_LOAD_SECTION or PNOR::MSG_UNLOAD_SECTION into loadUnloadSecureSection()");

    // Send message to secure provider to load the section
    errlHndl_t err = NULL;

    msg_q_t spnorQ = msg_q_resolve(SPNORRP_MSG_Q);

    assert(spnorQ != NULL);

    msg_t* msg = msg_allocate();

    assert(msg != NULL);

    msg->type = i_loadUnload;
    msg->data[0] = static_cast<uint64_t>(i_section);
    int rc = msg_sendrecv(spnorQ, msg);

    // TODO securebootp9 - Need to be able to receive an error from the
    // message handler. Also, message handler should police whether the request
    // is for a secure section or not and throw an error accordingly.
    //if (0 == rc)
    //{
    //    err = reinterpret_cast<errlHndl_t>(msg->data[1]);
    //}
    //else remove the if clause below at some point
    TRACDCOMP(g_trac_pnor,"PNOR::loadUnloadSecureSection> rc=%d msg->data[1]=0x%X ", rc, msg->data[1] );

    if (rc != 0 || msg->data[1])
    {
        // Use rc if non-zero, msg data[1] otherwise.
        uint64_t l_rc = (rc) ? rc : msg->data[1];

        TRACFCOMP(g_trac_pnor,ERR_MRK"PNOR::loadUnloadSecureSection> Error from msg_sendrecv or msg->data[1] rc=%d",
                  l_rc );
        /*@
         * @errortype
         * @severity          ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid          MOD_PNORRP_LOADUNLOADSECURESECTION
         * @reasoncode        RC_EXTERNAL_ERROR
         * @userdata1         returncode from msg_sendrecv() or msg->data[1]
         * @userdata2[0:31]   SPNOR message type [LOAD | UNLOAD]
         * @userdata2[32:63]  Section ID
         * @devdesc           Secure Boot: Failed to securely load or unload
         *                    signed boot firmware.
         * @custdesc          Failure in security subsystem
         */
        err = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                         MOD_PNORRP_LOADUNLOADSECURESECTION,
                         RC_EXTERNAL_ERROR,
                         l_rc,
                         TWO_UINT32_TO_UINT64(i_loadUnload,
                                              i_section),
                         true /* Add HB Software Callout */);

        // On a failure of load secure section, link the load error to this
        // error by PLID, if available
        if(   (i_loadUnload == PNOR::MSG_LOAD_SECTION)
           && (rc==0)
           && (msg->data[1]!=0)
           && (msg->extra_data != nullptr))
        {
            // extra_data is 64 bits, PLID occupies lower 32 bits, so slice off
            // the upper bits
            const uint32_t plid=reinterpret_cast<uint64_t>(msg->extra_data);
            err->plid(plid);
        }

        err->collectTrace(PNOR_COMP_NAME);
        err->collectTrace(SECURE_COMP_NAME);
    }
    msg_free(msg);
    return err;
}

/**
 *  @brief Loads requested PNOR section to secure virtual address space
 */
errlHndl_t PNOR::loadSecureSection(const SectionId i_section)
{
    TRACFCOMP(g_trac_pnor, "loadSecureSection i_section = %i (%s)",
              i_section,PNOR::SectionIdToString(i_section));

    return loadUnloadSecureSection(i_section, PNOR::MSG_LOAD_SECTION);
}

/**
 *  @brief Unloads requested PNOR section from secure virtual address space
 */
errlHndl_t PNOR::unloadSecureSection(const SectionId i_section)
{
    TRACFCOMP(g_trac_pnor, "unloadSecureSection i_section = %i (%s)",
              i_section,PNOR::SectionIdToString(i_section));

    return loadUnloadSecureSection(i_section, PNOR::MSG_UNLOAD_SECTION);
}

errlHndl_t SPnorRP::processFwKeyIndicators(
    const SECUREBOOT::ContainerHeader& i_header,
    const PNOR::SectionId              i_sectionId) const
{
    errlHndl_t pError = nullptr;

    do {

    // Place holder functiion for now

    } while(0);

    return pError;
}

errlHndl_t SPnorRP::miscSectionVerification(const uint8_t *i_vaddr,
                                            SectionId i_secId) const
{
    errlHndl_t l_errl = NULL;
    assert(i_vaddr != NULL);

    TRACFCOMP(g_trac_pnor, "SPnorRP::miscSectionVerification section=%d (%s)",
              i_secId,PNOR::SectionIdToString(i_secId));

    // Do any additional verification needed for a specific PNOR section
    switch (i_secId) {
        case HB_EXT_CODE:
            // Compare HBB and HBI versions. Pass the vaddr of HBI's hash page
            // table by skipping past the container header.
            l_errl = baseExtVersCheck((i_vaddr + PAGESIZE));
            break;
        case SBKT:
            // Ensure the nested container of the SBKT partition has a valid key
            // transition container and that the outer containers' key
            // transition bit is set
            l_errl = keyTransitionCheck((i_vaddr));
            break;
        default:
            break;
    }
    return l_errl;
}

errlHndl_t SPnorRP::baseExtVersCheck(const uint8_t *i_vaddr) const
{
    errlHndl_t l_errl = NULL;
    assert(i_vaddr != NULL);

    do {
    // Check if measured and build time hashes of HBB sw signatures match.
    // Query the HBB header
    const void* l_pHbbHeader = NULL;
    SECUREBOOT::baseHeader().getHeader(l_pHbbHeader);
    // Fatal code bug if either address is NULL
    assert(l_pHbbHeader!=NULL,"ERORR: Cached header address is NULL");
    // Build a container header object from the raw header
    SECUREBOOT::ContainerHeader l_hbbContainerHeader;
    l_errl = l_hbbContainerHeader.setHeader(l_pHbbHeader);
    if (l_errl)
    {
        TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorRP::baseExtVersCheck> setheader failed");
        break;
    }

    // Calculate hash of HBB's sw signatures
    SHA512_t l_hashSwSigs = {0};
    SECUREBOOT::hashBlob(l_hbbContainerHeader.sw_sigs(),
                         l_hbbContainerHeader.totalSwKeysSize(),
                         l_hashSwSigs);

    // Get build time hash of HBB's sw signatures. The hash of HBB's sw
    // signatures are stored in the first entry (SALT) of HBI's hash page
    // table. The first entry of HBI's hash pagle starts immediately after the
    // header so we can simply cast the vaddr to get our first entry (SALT)
    // Note: It is expected that i_vaddr points to the start of HBI's hash
    //       page table.
    const PAGE_TABLE_ENTRY_t* l_hashPageTableSaltEntry =
                           reinterpret_cast<const PAGE_TABLE_ENTRY_t*>(i_vaddr);

    // Throw an error if the hashes do not match to the truncated length
    // of a hash page table entry.
    if ( memcmp(l_hashSwSigs, l_hashPageTableSaltEntry,
                HASH_PAGE_TABLE_ENTRY_SIZE) != 0 )
    {
        TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorRP::baseExtVersCheck Hostboot Base and Extended image mismatch");
        TRACFBIN(g_trac_pnor,"SPnorRP::baseExtVersCheck Measured sw key hash",
                            l_hashSwSigs, HASH_PAGE_TABLE_ENTRY_SIZE);
        TRACFBIN(g_trac_pnor,"SPnorRP::baseExtVersCheck HBI's hash page table salt entry",
                        l_hashPageTableSaltEntry, HASH_PAGE_TABLE_ENTRY_SIZE);

        // Memcpy needed for measured hash to avoid gcc error: dereferencing
        // type-punned pointer will break strict-aliasing rules
        uint64_t l_measuredHash = 0;
        memcpy(&l_measuredHash, l_hashSwSigs, sizeof(l_measuredHash));
        /*@ errorlog
         * @severity        ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        MOD_SPNORRP_BASE_EXT_VER_CHK
         * @reasoncode      RC_BASE_EXT_MISMATCH
         * @userdata1       First 8 bytes of hash of measured SW signatures
         * @userdata2       First 8 bytes of hash of stored SW signatures in
         *                  hash page table
         * @devdesc         Hostboot Base and Extend code do not match versions.
         * @custdesc        Firmware level mismatch.
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
            MOD_SPNORRP_BASE_EXT_VER_CHK,
            RC_BASE_EXT_MISMATCH,
            l_measuredHash,
            TO_UINT64(*reinterpret_cast<const uint64_t*>(l_hashPageTableSaltEntry)));
        l_errl->collectTrace(PNOR_COMP_NAME);
        l_errl->collectTrace(SECURE_COMP_NAME);
        break;
    }

    } while(0);

    return l_errl;
}

errlHndl_t SPnorRP::keyTransitionCheck(const uint8_t *i_vaddr) const
{
    errlHndl_t l_errl = NULL;
    assert(i_vaddr != NULL);

    do {
    // Check if the header flags have the key transition bit set
    SECUREBOOT::ContainerHeader l_outerConHdr;
    l_errl = l_outerConHdr.setHeader(i_vaddr);
    if (l_errl)
    {
        TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorRP::keyTransitionCheck> outer setheader failed");
        break;
    }
    if (!l_outerConHdr.sb_flags()->hw_key_transition)
    {
        TRACFCOMP( g_trac_pnor, ERR_MRK"SPnorRP::keyTransitionCheck() - Key transition flag not set");
        /*@
         * @errortype
         * @severity        ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        MOD_SPNORRP_KEY_TRAN_CHK
         * @reasoncode      RC_KEY_TRAN_FLAG_UNSET
         * @userdata1       0
         * @userdata2       0
         * @devdesc         Key transition flag not set in outer SBKT container containing new hw keys
         * @custdesc        Secureboot key transition failure
         */
         l_errl = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                           MOD_SPNORRP_KEY_TRAN_CHK,
                                           RC_KEY_TRAN_FLAG_UNSET,
                                           0,
                                           0,
                                           true /*Add HB Software Callout*/ );
        l_errl->collectTrace(PNOR_COMP_NAME);
        l_errl->collectTrace(SECURE_COMP_NAME);
        break;
    }

    // Validate nested container is properly signed using new hw keys
    uint8_t * l_nestedVaddr = const_cast<uint8_t*>(i_vaddr) + PAGESIZE;
    SECUREBOOT::ContainerHeader l_nestedConHdr;
    l_errl = l_nestedConHdr.setHeader(l_nestedVaddr);
    if (l_errl)
    {
        TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorRP::keyTransitionCheck> nested setheader failed");
        break;
    }

    l_errl = SECUREBOOT::verifyContainer(l_nestedVaddr,
                                         {PNOR::SBKT},
                                         l_nestedConHdr.hwKeyHash());
    if (l_errl)
    {
        TRACFCOMP( g_trac_pnor, ERR_MRK"SPnorRP::keyTransitionCheck() - failed verifyContainer");
        break;
    }

    }while(0);

    return l_errl;
}
