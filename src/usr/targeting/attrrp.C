/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrrp.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file targeting/attrrp.C
 *
 *  @brief Attribute resource provider implementation which establishes and
 *      initializes virtual memory ranges for attributes as needed, and works
 *      with other resource providers (such as the PNOR resource provider) to
 *      retrieve attribute data which it connot directly provide.
 */

#include <util/singleton.H>
#include <pnortargeting.H>
#include <pnor/pnorif.H>
#include <sys/mm.h>
#include <errno.h>
#include <string.h>
#include <algorithm>
#include <vmmconst.h>
#include <targeting/adapters/assertadapter.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/attrrp.H>
#include <targeting/common/trace.H>
#include <initservice/initserviceif.H>
#include <util/align.H>

using namespace INITSERVICE;
using namespace ERRORLOG;

#include "attrrp_common.C"

namespace TARGETING
{
    void AttrRP::init(errlHndl_t &io_taskRetErrl)
    {
        // Call startup on singleton instance.
        Singleton<AttrRP>::instance().startup(io_taskRetErrl);
    }

    void* AttrRP::getBaseAddress(const NODE_ID i_nodeIdUnused)
    {
        return reinterpret_cast<void*>(VMM_VADDR_ATTR_RP);
    }

    void* AttrRP::startMsgServiceTask(void* i_pInstance)
    {
        // Call msgServiceTask loop on instance.
        TARG_ASSERT(i_pInstance);
        static_cast<AttrRP*>(i_pInstance)->msgServiceTask();
        return NULL;
    }

    void AttrRP::startup(errlHndl_t& io_taskRetErrl)
    {
        errlHndl_t l_errl = NULL;

        do
        {
            // Parse PNOR headers.
            l_errl = this->parseAttrSectHeader();
            if (l_errl)
            {
                break;
            }

            // Create corresponding VMM blocks for each section.
            l_errl = this->createVmmSections();
            if (l_errl)
            {
                break;
            }

            // Spawn daemon thread.
            task_create(&AttrRP::startMsgServiceTask, this);

        } while (false);

        // If an error occured, post to TaskArgs.
        if (l_errl)
        {
            l_errl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        }

        //  return any errlogs to _start()
        io_taskRetErrl = l_errl;
    }

    void AttrRP::msgServiceTask() const
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK "AttrRP::msgServiceTask");

        // Daemon loop.
        while(1)
        {
            int rc = 0;

            // Wait for message.
            msg_t* msg = msg_wait(iv_msgQ);
            if (!msg) continue;

            // Parse message data members.
            uint64_t vAddr = msg->data[0];
            void*    pAddr = reinterpret_cast<void*>(msg->data[1]);

            TRACFCOMP(g_trac_targeting, INFO_MRK "AttrRP: Message recv'd: "
                      "0x%x, 0x%lx 0x%p", msg->type, vAddr, pAddr);

            // Locate corresponding attribute section for message.
            ssize_t section = -1;
            for (size_t i = 0; i < iv_sectionCount; ++i)
            {
                if ((vAddr >= iv_sections[i].vmmAddress) &&
                    (vAddr < iv_sections[i].vmmAddress + iv_sections[i].size))
                {
                    section = i;
                    break;
                }
            }

            // Return EINVAL if no section was found.  Kernel bug?
            if (section == -1)
            {
                rc = -EINVAL;
                TRACFCOMP(g_trac_targeting,
                          ERR_MRK "AttrRP: Address given outside section "
                                  "ranges: %p",
                          vAddr);
            }
            else // Process request.
            {

                // Determine PNOR offset and page size.
                uint64_t offset = vAddr - iv_sections[section].vmmAddress;
                uint64_t size = std::min(PAGE_SIZE,
                                         iv_sections[section].vmmAddress +
                                         iv_sections[section].size -
                                         vAddr);
                    // We could be requested to read/write less than a page
                    // if the virtual address requested is at the end of the
                    // section and the section size is not page aligned.
                    //
                    // Example: Section size is 6k and vAddr = vmmAddr + 4k,
                    //          we should only operate on 2k of content.


                // Read / Write message behavior.
                switch(msg->type)
                {
                    case MSG_MM_RP_READ:
                        // HEAP_ZERO_INIT should never be requested for read
                        // because kernel should automatically get a zero page.
                        if ( (iv_sections[section].type ==
                              SECTION_TYPE_HEAP_ZERO_INIT) ||
                             (iv_sections[section].type ==
                              SECTION_TYPE_HB_HEAP_ZERO_INIT) )
                        {
                            TRACFCOMP(g_trac_targeting,
                                      ERR_MRK "AttrRP: Read request on "
                                              "HEAP_ZERO section.");
                            rc = -EINVAL;
                            break;
                        }
                        // Do memcpy from PNOR into physical page.
                        memcpy(pAddr,
                               reinterpret_cast<void*>(
                                    iv_sections[section].pnorAddress + offset),
                               size);
                        break;

                    case MSG_MM_RP_WRITE:
                        // Only PNOR_RW should ever be requested for write-back
                        // because others are not allowed to be pushed back to
                        // PNOR.
                        if (iv_sections[section].type !=
                            SECTION_TYPE_PNOR_RW)
                        {
                            TRACFCOMP(g_trac_targeting,
                                      ERR_MRK "AttrRP: Write request on "
                                              "non-PNOR_RW section.");
                            rc = -EINVAL;
                            break;
                        }
                        // Do memcpy from physical page into PNOR.
                        memcpy(reinterpret_cast<void*>(
                                    iv_sections[section].pnorAddress + offset),
                               pAddr,
                               size);
                        break;

                    default:
                        TRACFCOMP(g_trac_targeting,
                                  ERR_MRK "AttrRP: Unhandled command type %d.",
                                  msg->type);
                        rc = -EINVAL;
                        break;
                }
            }

            // Log an error log if the AttrRP was unable to handle a message
            // for any reason.
            if (rc != 0)
            {
                /*@
                 *   @errortype
                 *   @moduleid          TARG_MOD_ATTRRP
                 *   @reasoncode        TARG_RC_ATTR_MSG_FAIL
                 *   @userdata1         Virtual Address
                 *   @userdata2         (Msg Type << 32) | Section #
                 *
                 *   @devdesc   The Attribute Resource Provider was unable to
                 *              satisfy a message request from the VMM portion
                 *              of the kernel.  This was either due to an
                 *              address outside a valid range or a message
                 *              request that is invalid for the attribute
                 *              section containing the address.
                 */
                errlHndl_t l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                                  TARG_MOD_ATTRRP,
                                                  TARG_RC_ATTR_MSG_FAIL,
                                                  vAddr,
                                                  TWO_UINT32_TO_UINT64(
                                                        msg->type,
                                                        section)
                                                  );
                errlCommit(l_errl,TARG_COMP_ID);

            }

            // Respond to kernel request.
            msg->data[1] = rc;
            rc = msg_respond(iv_msgQ, msg);
            if (rc)
            {
                TRACFCOMP(g_trac_targeting,
                          ERR_MRK "AttrRP: Bad rc from msg_respond: %d", rc);
            }
        }
    }

    errlHndl_t AttrRP::parseAttrSectHeader()
    {
        errlHndl_t l_errl = NULL;

        do
        {
            // Locate attribute section in PNOR.
            PNOR::SectionInfo_t l_pnorSectionInfo;
            l_errl = PNOR::getSectionInfo(PNOR::HB_DATA,
                                          l_pnorSectionInfo);
            if (l_errl) break;

            // Find attribute section header.
            TargetingHeader* l_header =
                reinterpret_cast<TargetingHeader*>(l_pnorSectionInfo.vaddr);

            // Validate eye catch.
            if (l_header->eyeCatcher != PNOR_TARG_EYE_CATCHER)
            {
                /*@
                 *   @errortype
                 *   @moduleid          TARG_MOD_ATTRRP
                 *   @reasoncode        TARG_RC_BAD_EYECATCH
                 *   @userdata1         Observed Header Eyecatch Value
                 *   @userdata2         Expected Eyecatch Value
                 *
                 *   @devdesc   The eyecatch value observed in PNOR does not
                 *              match the expected value of
                 *              PNOR_TARG_EYE_CATCHER and therefore the
                 *              contents of the Attribute PNOR section are
                 *              unable to be parsed.
                 */
                l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                       TARG_MOD_ATTRRP,
                                       TARG_RC_BAD_EYECATCH,
                                       l_header->eyeCatcher,
                                       PNOR_TARG_EYE_CATCHER);
                break;
            }

            // Allocate section structures based on section count in header.
            iv_sectionCount = l_header->numSections;
            iv_sections = new AttrRP_Section[iv_sectionCount];

            // Find start to first section:
            //          (PNOR addr + size of header + offset in header).
            TargetingSection* l_section =
                    reinterpret_cast<TargetingSection*>(
                            l_pnorSectionInfo.vaddr + sizeof(TargetingHeader) +
                            l_header->offsetToSections
                    );

            // Parse each section.
            for (size_t i = 0; i < iv_sectionCount; i++, ++l_section)
            {
                iv_sections[i].type = l_section->sectionType;

                // Conversion cast for templated abstract pointer object only
                // works when casting to pointer of the templated type.  Since
                // cache is of a different type, we first cast to extract the
                // real pointer, then recast it into the cache
                iv_sections[i].vmmAddress =
                        static_cast<uint64_t>(
                            TARG_TO_PLAT_PTR(l_header->vmmBaseAddress)) +
                        l_header->vmmSectionOffset*i;
                iv_sections[i].pnorAddress = l_pnorSectionInfo.vaddr +
                                             l_section->sectionOffset;
                iv_sections[i].size = l_section->sectionSize;

                TRACFCOMP(g_trac_targeting,
                          "Decoded Attribute Section: %d, 0x%lx 0x%lx 0x%lx",
                          iv_sections[i].type,
                          iv_sections[i].vmmAddress,
                          iv_sections[i].pnorAddress,
                          iv_sections[i].size);

            }

        } while (false);

        return l_errl;

    }

    errlHndl_t AttrRP::createVmmSections()
    {
        errlHndl_t l_errl = NULL;

        do
        {
            // Allocate message queue for VMM requests.
            iv_msgQ = msg_q_create();

            // Create VMM block for each section, assign permissions.
            for (size_t i = 0; i < iv_sectionCount; ++i)
            {
                uint64_t l_perm = 0;
                switch(iv_sections[i].type)
                {
                    case SECTION_TYPE_PNOR_RO:
                        l_perm = READ_ONLY;
                        break;

                    case SECTION_TYPE_PNOR_RW:
                        l_perm = WRITABLE | WRITE_TRACKED;
                        break;

                    case SECTION_TYPE_HEAP_PNOR_INIT:
                        l_perm = WRITABLE;
                        break;

                    case SECTION_TYPE_HEAP_ZERO_INIT:
                    case SECTION_TYPE_HB_HEAP_ZERO_INIT:
                        l_perm = WRITABLE | ALLOCATE_FROM_ZERO;
                        break;

                    default:

                        /*@
                         *   @errortype
                         *   @moduleid   TARG_MOD_ATTRRP
                         *   @reasoncode TARG_RC_UNHANDLED_ATTR_SEC_TYPE
                         *   @userdata1  Section type
                         *
                         *   @devdesc    Found unhandled attribute section type
                         */
                    l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                           TARG_MOD_ATTRRP,
                                           TARG_RC_UNHANDLED_ATTR_SEC_TYPE,
                                           iv_sections[i].type);
                    break;
                }

                if(l_errl)
                {
                    break;
                }

                int rc = 0;
                msg_q_t l_msgQ = iv_msgQ;

                if ( (iv_sections[i].type == SECTION_TYPE_HEAP_ZERO_INIT) ||
                     (iv_sections[i].type == SECTION_TYPE_HB_HEAP_ZERO_INIT) )
                {
                    l_msgQ = NULL;
                }

                rc = mm_alloc_block(l_msgQ,
                                    reinterpret_cast<void*>(iv_sections[i].vmmAddress),
                                    iv_sections[i].size);

                if (rc)
                {
                    /*@
                     *   @errortype
                     *   @moduleid          TARG_MOD_ATTRRP
                     *   @reasoncode        TARG_RC_MM_BLOCK_FAIL
                     *   @userdata1         vAddress attempting to allocate.
                     *   @userdata2         RC from kernel.
                     *
                     *   @devdesc   While attempting to allocate a virtual
                     *              memory block for an attribute section, the
                     *              kernel returned an error.
                     */
                    l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                           TARG_MOD_ATTRRP,
                                           TARG_RC_MM_BLOCK_FAIL,
                                           iv_sections[i].vmmAddress,
                                           rc);
                    break;
                }

                if(iv_sections[i].type == SECTION_TYPE_PNOR_RW)
                {
                    /*
                     * Register this memory range to be FLUSHed during
                     * a shutdown.
                     */
                    INITSERVICE::registerBlock(
                        reinterpret_cast<void*>(iv_sections[i].vmmAddress),
                        iv_sections[i].size,ATTR_PRIORITY);
                }

                rc = mm_set_permission(reinterpret_cast<void*>(
                                                iv_sections[i].vmmAddress),
                                       iv_sections[i].size,
                                       l_perm);

                if (rc)
                {
                    /*@
                     *   @errortype
                     *   @moduleid          TARG_MOD_ATTRRP
                     *   @reasoncode        TARG_RC_MM_PERM_FAIL
                     *   @userdata1         vAddress attempting to allocate.
                     *   @userdata2         (kernel-rc << 32) | (Permissions)
                     *
                     *   @devdesc   While attempting to set permissions on
                     *              a virtual memory block for an attribute
                     *              section, the kernel returned an error.
                     */
                    l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                           TARG_MOD_ATTRRP,
                                           TARG_RC_MM_PERM_FAIL,
                                           iv_sections[i].vmmAddress,
                                           TWO_UINT32_TO_UINT64(rc, l_perm));
                    break;
                }

            } // End iteration through each section

            if(l_errl)
            {
                break;
            }

        } while (false);

        return l_errl;
    }

};
