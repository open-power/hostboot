/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/spnorrp.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2017                        */
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
#include <config.h>
#include "pnor_common.H"
#include <console/consoleif.H>
#include <secureboot/service.H>
#include <secureboot/containerheader.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/header.H>

extern trace_desc_t* g_trac_pnor;

// used to uniquley identify the secure PNOR RP message queue
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
        delete l_rec;
    }

    TRACDCOMP(g_trac_pnor, "< SPnorRP::~SPnorRP" );
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

        // create a Block for temp space
        l_errhdl = allocBlock( NULL, reinterpret_cast<void*>(TEMP_VADDR),
                                                             PNOR_SIZE );
        if( l_errhdl )
        {
            break;
        }

        // set permissions for temp space
        l_errhdl = setPermission(reinterpret_cast<void*>(TEMP_VADDR),
                                    PNOR_SIZE, WRITABLE | ALLOCATE_FROM_ZERO);
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
uint64_t SPnorRP::verifySections(SectionId i_id, LoadRecord* o_rec)
{
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
#ifdef CONFIG_SECUREBOOT_BEST_EFFORT
            TRACFCOMP(g_trac_pnor,"PNOR::verifySections> called on unsecured section - Best effort policy skipping");
            break;
#else
            TRACFCOMP(g_trac_pnor,ERR_MRK"PNOR::verifySections> called on "
                "unsecured section");

            // TODO securebootp9 revisit this assert code and replace with error log
            // code if it is deemed that this assert could happen in the field
            assert(false,"PNOR::loadSection> section %i is not a secure section",
                                                                    i_id);
#endif
        }

        l_info.vaddr -= PAGESIZE; // back up a page to expose the secure header
        l_info.size += PAGESIZE; // add a page to size to account for the header

        // it's a coding error if l_info.vaddr is not in secure space
        assert(l_info.vaddr >= SBASE_VADDR, "Virtual address for section %s is"
            " not in secure space. Bad ptr=0x%X", l_info.name, l_info.vaddr);

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
                    "in temp space is 0x%.16llX, "
                    "section start address in unsecured space is 0x%.16llX, "
                    "l_info.size = 0x%.16llX, "
                    "payload size = 0x%.16llX, ",
                    l_tempAddr, l_unsecuredAddr, l_info.size,
                    l_info.secureProtectedPayloadSize);

        TRACDBIN(g_trac_pnor,"SPnorRP::verifySections unsecured mem now: ",
                             l_unsecuredAddr, 128);

        TRACDCOMP(g_trac_pnor,"SPnorRP::verifySections about to do memcpy");

        // copy from unsecured PNOR space to temp PNOR space
        memcpy(l_tempAddr, l_unsecuredAddr, l_info.secureProtectedPayloadSize
                                          + PAGESIZE); // plus header size

        SECUREBOOT::ContainerHeader l_conHdr(l_tempAddr);
        size_t l_totalContainerSize = l_conHdr.totalContainerSize();

        TRACFCOMP(g_trac_pnor, "SPnorRP::verifySections "
                "Total container size = 0x%.16llX", l_totalContainerSize);

        assert(l_totalContainerSize >= PAGESIZE +
               + l_info.secureProtectedPayloadSize,
               "For section %s, total container size (%d) was less than header "
               "size (4096) + payload text size (%d)",
               l_info.name,
               l_totalContainerSize,
               l_info.secureProtectedPayloadSize);

        assert(l_info.size >= l_totalContainerSize,
               "For section %s, logical section size (%d) was less than total "
               "container size (%d)",
               l_info.name,
               l_info.size,
               l_totalContainerSize);

        TRACDCOMP(g_trac_pnor,"SPnorRP::verifySections did memcpy");
        TRACDBIN(g_trac_pnor,"SPnorRP::verifySections temp mem now: ",
                             l_tempAddr, 128);

        // store secure space pointer in load record (Includes Header)
        o_rec->secAddr = reinterpret_cast<uint8_t*>(l_info.vaddr);

        TRACDCOMP(g_trac_pnor,"section start address in secure space is "
                              "0x%.16llX",o_rec->secAddr);

        // verify while in temp space
        if (SECUREBOOT::enabled())
        {
            l_errhdl = SECUREBOOT::verifyContainer(l_tempAddr);
            if (l_errhdl)
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"SPnorrRP::verifySections - section "
                      "with id 0x%08X failed verifyContainer", i_id);
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
        o_rec->textSize = l_conHdr.payloadTextSize();
        assert(o_rec->textSize == l_info.secureProtectedPayloadSize);
        // Size of data loaded into Secure PnorRP vaddr space (Includes Header)
        size_t l_protectedSizeWithHdr = PAGESIZE + o_rec->textSize;
        TRACFCOMP(g_trac_pnor, "SPnorRP::verifySections Total Protected size with Header = 0x%.16llX",
                  l_protectedSizeWithHdr);

        l_totalContainerSize = l_conHdr.totalContainerSize();
        // keep track of info size in load record (Includes Header)
        o_rec->infoSize = l_totalContainerSize;

        // pcr extension of PNOR hash
        l_errhdl = TRUSTEDBOOT::extendPnorSectionHash(l_conHdr,
                                        (l_tempAddr + PAGESIZE),
                                        i_id);
        if(l_errhdl)
        {
            TRACFCOMP(g_trac_pnor,"SPnorRP::verifySections extendPnorSectionHash failed");
            break;
        }

        // set permissions on the secured pages to writable
        l_errhdl = setPermission(o_rec->secAddr, l_protectedSizeWithHdr,
                                 WRITABLE);
        if(l_errhdl)
        {
            TRACFCOMP(g_trac_pnor,"SPnorRP::verifySections set permissions "
                                  "failed on text section");
            break;
        }

        // set permissions on the unsecured pages to write tracked so that any
        // unprotected payload pages with dirty writes can flow back to PNOR.
        uint64_t unprotectedPayloadSize = l_totalContainerSize
            - PAGESIZE - o_rec->textSize;
        if (unprotectedPayloadSize) // only write track a non-zero range
        {
            TRACDCOMP(g_trac_pnor,INFO_MRK " SPnorRP::verifySections "
                "creating unprotected area (%d bytes) for section %s",
                unprotectedPayloadSize,
                l_info.name);

            // Split the mod math out of the assert as the trace would not
            // display otherwise.
            bool l_onPageBoundary = !(o_rec->textSize % PAGESIZE);
            assert( l_onPageBoundary, "For section %s, payloadTextSize does "
                    "not fall on a page boundary and there is an unprotected "
                    "payload",
                    l_info.name);

            l_errhdl = setPermission(o_rec->secAddr + l_protectedSizeWithHdr,
                                       unprotectedPayloadSize,
                                       WRITABLE | WRITE_TRACKED);
            if(l_errhdl)
            {
                TRACFCOMP(g_trac_pnor,"SPnorRP::verifySections set permissions "
                                  "failed on data section");
                break;
            }

            // Register the write tracked memory range to be flushed on
            // shutdown.
            INITSERVICE::registerBlock(o_rec->secAddr + l_protectedSizeWithHdr,
                                        unprotectedPayloadSize, SPNOR_PRIORITY);
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
        uint32_t l_errPlid = l_errhdl->plid();
        iv_startupRC = l_errhdl->reasonCode();
        TRACFCOMP(g_trac_pnor,ERR_MRK"SPnorRP::verifySections there was an error");
        if (failedVerify)
        {
            SECUREBOOT::handleSecurebootFailure(l_errhdl,false);
        }
        else
        {
            errlCommit(l_errhdl,PNOR_COMP_ID);
            INITSERVICE::doShutdown(l_errPlid, true);
        }
    }

    return l_rc;
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
            // data[0] = virtual address requested
            // data[1] = address to place contents
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
                            "textSize=0x%.16llX secAddr0x%.16llX", user_addr,
                            eff_addr, message->type, l_rec.textSize,
                                                               l_rec.secAddr);

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
                        if (eff_addr < ( (l_rec.secAddr + PAGESIZE) +
                                          l_rec.textSize))
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
                            if (iv_loadedSections[l_id] == NULL)
                            {
                                LoadRecord* l_record = new LoadRecord;
                                uint64_t l_rc = verifySections(l_id, l_record);
                                if (l_rc)
                                {
                                    delete l_record;
                                    l_record = NULL;
                                    status_rc = -l_rc;
                                    break;
                                }
                                iv_loadedSections[l_id] = l_record;

                                // cache the record to use fields later as hints
                                l_rec = *l_record;
                            }
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
            }

            /*  Expected Response:
             *      data[0] = virtual address requested or
             *                section id (if load message)
             *      data[1] = rc (0 or negative errno value)
             *      extra_data = Specific reason code.
             */
            message->data[1] = status_rc;
            message->extra_data = 0;
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
 *  @brief Loads requested PNOR section to secure virtual address space
 */
errlHndl_t PNOR::loadSecureSection(const SectionId i_section)
{
    // Send message to secure provider to load the section
    errlHndl_t err = NULL;

    msg_q_t spnorQ = msg_q_resolve(SPNORRP_MSG_Q);

    assert(spnorQ != NULL);

    msg_t* msg = msg_allocate();

    assert(msg != NULL);

    msg->type = PNOR::MSG_LOAD_SECTION;
    msg->data[0] = static_cast<uint64_t>(i_section);
    int rc = msg_sendrecv(spnorQ, msg);

    TRACFCOMP(g_trac_pnor, "loadSecureSection i_section = %i (%s)",
              i_section,PNOR::SectionIdToString(i_section));

    // TODO securebootp9 - Need to be able to receive an error from the
    // message handler. Also, message handler should police whether the request
    // is for a secure section or not and throw an error accordingly.
    //if (0 == rc)
    //{
    //    err = reinterpret_cast<errlHndl_t>(msg->data[1]);
    //}
    //else remove the if clause below at some point
    if (rc != 0 || msg->data[1])
    {
        // Use rc if non-zero, msg data[1] otherwise.
        uint64_t l_rc = (rc) ? rc : msg->data[1];

        TRACFCOMP(g_trac_pnor,ERR_MRK"PNOR::loadSecureSection> Error from msg_sendrecv or msg->data[1] rc=0x%X",
                  l_rc );
        /* @errorlog
         * @severity          ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid          MOD_PNORRP_LOADSECURESECTION
         * @reasoncode        RC_EXTERNAL_ERROR
         * @userdata1         returncode from msg_sendrecv() or msg->data[1]
         * @userdata2[0:31]   SPNOR message type [LOAD | UNLOAD]
         * @userdata2[32:63]  Section ID
         * @devdesc           Could not load/unload section.
         * @custdesc          Security failure: unable to securely load
         *                    requested firmware.
         */
        err = new ERRORLOG::ErrlEntry(
                         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                         MOD_PNORRP_LOADSECURESECTION,
                         RC_EXTERNAL_ERROR,
                         l_rc,
                         TWO_UINT32_TO_UINT64(PNOR::MSG_LOAD_SECTION,
                                              i_section),
                         true /* Add HB Software Callout */);
        err->collectTrace(PNOR_COMP_NAME);
        err->collectTrace(SECURE_COMP_NAME);
    }
    msg_free(msg);
    return err;
}

/**
 *  @brief Flushes any applicable pending writes and unloads requested PNOR
 *         section from secure virtual address space
 */
errlHndl_t PNOR::unloadSecureSection(const SectionId i_section)
{
    // @TODO RTC 156118
    // Replace with call to secure provider to unload the section
    errlHndl_t pError=NULL;
    return pError;
}

void SPnorRP::processLabOverride(
    const sb_flags_t& i_flags) const
{
    TARGETING::Target* pSys = nullptr;
    TARGETING::targetService().getTopLevelTarget(pSys);
    assert(pSys != nullptr,"System target was nullptr.");
    // ATTR_HB_SECURITY_MODE attribute values are inverted with respect to the
    // lab override flag for the same logical meaning
    TARGETING::ATTR_HB_SECURITY_MODE_type securityMode =
        !(i_flags.hw_lab_override);
    pSys->setAttr<TARGETING::ATTR_HB_SECURITY_MODE>(securityMode);
    TRACFCOMP(g_trac_pnor,INFO_MRK "Set lab security override policy to %s.",
        securityMode ? "*NO* override" : "override if requested");
}

errlHndl_t SPnorRP::processFwKeyIndicators(
    const SECUREBOOT::ContainerHeader& i_header,
    const PNOR::SectionId              i_sectionId) const
{
    errlHndl_t pError = nullptr;

    if(i_sectionId == PNOR::SBE_IPL)
    {
        auto const * const headerFlags = i_header.sb_flags();
        processLabOverride(*headerFlags);
    }

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

    // Check if measured and build time hashes of HBB sw signatures match.
    // Query the HBB header
    const void* l_pHbbHeader = NULL;
    SECUREBOOT::baseHeader().getHeader(l_pHbbHeader);
    // Fatal code bug if either address is NULL
    assert(l_pHbbHeader!=NULL,"ERORR: Cached header address is NULL");
    // Build a container header object from the raw header
    SECUREBOOT::ContainerHeader l_hbbContainerHeader(l_pHbbHeader);

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
    }

    return l_errl;
}

errlHndl_t SPnorRP::keyTransitionCheck(const uint8_t *i_vaddr) const
{
    errlHndl_t l_errl = NULL;
    assert(i_vaddr != NULL);

    do {
    // Check if the header flags have the key transition bit set
    SECUREBOOT::ContainerHeader l_outerConHdr(i_vaddr);
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
    SECUREBOOT::ContainerHeader l_nestedConHdr(l_nestedVaddr);
    l_errl = SECUREBOOT::verifyContainer(l_nestedVaddr,
                                         l_nestedConHdr.hwKeyHash());
    if (l_errl)
    {
        TRACFCOMP( g_trac_pnor, ERR_MRK"SPnorRP::keyTransitionCheck() - failed verifyContainer");
        break;
    }
    }while(0);

    return l_errl;
}
