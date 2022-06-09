/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrrp.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
#include <targeting/targplatreasoncodes.H>
#include <targeting/attrrp.H>
#include <targeting/common/trace.H>
#include <targeting/common/attributeTank.H>
#include <targeting/targplatutil.H>
#include <initservice/initserviceif.H>
#include <util/align.H>
#include <util/utilrsvdmem.H>
#include <sys/misc.h>
#include <fapi2/plat_attr_override_sync.H>
#include <targeting/attrPlatOverride.H>
#include <secureboot/service.H>
#include <kernel/bltohbdatamgr.H>
#include <bootloader/bootloaderif.H>
#include <common_ringId.H>
#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>
#include <sbeio/sbeioif.H>
#include <util/crc32.H>
#include <pldm/requests/pldm_fileio_requests.H>
#include <util/utillidmgr.H>

using namespace INITSERVICE;
using namespace ERRORLOG;

#include "attrrp_common.C"

namespace TARGETING
{

    const char* ATTRRP_MSG_Q = "attrrpq";
    const char* ATTRRP_ATTR_SYNC_MSG_Q = "attrrpattrsyncq";

    void* AttrRP::getBaseAddress(const NODE_ID i_nodeIdUnused)
    {
        return reinterpret_cast<void*>(VMM_VADDR_ATTR_RP);
    }

    void* AttrRP::startMsgServiceTask(void* i_pInstance)
    {
        // Call msgServiceTask loop on instance.
        TARG_ASSERT(i_pInstance, "No instance passed to startMsgServiceTask");
        static_cast<AttrRP*>(i_pInstance)->msgServiceTask();
        return NULL;
    }

    void* AttrRP::startAttrSyncTask(void* i_pInstance)
    {
        TARG_ASSERT(i_pInstance, "No instance passed to startAttrSyncTask");
        static_cast<AttrRP*>(i_pInstance)->attrSyncTask();
        return nullptr;
    }

    void AttrRP::startup(errlHndl_t& io_taskRetErrl, bool i_isMpipl)
    {
        errlHndl_t l_errl = NULL;

        do
        {
            iv_isMpipl = i_isMpipl;
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

            // Now that the VMM blocks have been created we must set
            // the appropriate R/W permissions
            l_errl = this->editPagePermissions(ALL_SECTION_TYPES, DEFAULT_PERMISSIONS);
            if (l_errl)
            {
                break;
            }

            // Spawn daemon thread.
            task_create(&AttrRP::startMsgServiceTask, this);

            // Register attribute sync message queue so it can be discovered by
            // istep 21 in order to deregister it from shutdown event handling.
            auto rc = msg_q_register(iv_attrSyncMsgQ, ATTRRP_ATTR_SYNC_MSG_Q);
            assert(rc == 0, "Bug! Unable to register attribute sync message "
                "queue");

            // Spawn attribute sync thread
            task_create(&AttrRP::startAttrSyncTask, this);

            if(iv_isMpipl)
            {
                populateAttrsForMpipl();
            }



        } while (false);

        // If an error occurred, post to TaskArgs.
        if (l_errl)
        {
            l_errl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        }

        //  return any errlogs to _start()
        io_taskRetErrl = l_errl;
    }

    errlHndl_t AttrRP::notifyResourceReady(const RESOURCE i_resource)
    {
        return Singleton<AttrRP>::instance()._notifyResourceReady(i_resource);
    }

    errlHndl_t AttrRP::syncAllAttributesToSP()
    {
        return Singleton<AttrRP>::instance()._syncAllAttributesToSP();
    }

    errlHndl_t AttrRP::_syncAllAttributesToSP() const
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK
                  "AttrRP::_syncAllAttributesToSP");
        auto pError = _sendAttrSyncMsg(MSG_INVOKE_ATTR_SYNC, true);
        TRACFCOMP(g_trac_targeting, EXIT_MRK
                  "AttrRP::_syncAllAttributesToSP");
        return pError;
    }

    errlHndl_t AttrRP::sendAttrOverridesAndSyncs()
    {
        return Singleton<AttrRP>::instance()._sendAttrOverridesAndSyncs();
    }

    errlHndl_t AttrRP::_sendAttrOverridesAndSyncs() const
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK
                  "AttrRP::_sendAttrOverridesAndSyncs");
        auto pError = _sendAttrSyncMsg(MSG_ATTR_OVERRIDE_SYNC, true);
        TRACFCOMP(g_trac_targeting, EXIT_MRK
                  "AttrRP::_sendAttrOverridesAndSyncs");
        return pError;
    }

    errlHndl_t AttrRP::_notifyResourceReady(const RESOURCE i_resource) const
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK
                  "AttrRP::_notifyResourceReady: resource type = 0x%02X.",
                  i_resource);

        auto msgType = MSG_INVALID;
        const bool sync=false;

        switch (i_resource)
        {
            case MAILBOX:
                {
                    msgType = MSG_PRIME_ATTR_SYNC;
                }
                break;
            case SYNC_WINDOW_OPEN:
                {
                    msgType = MSG_ATTR_SYNC_WINDOW_OPEN;
                }
                break;
            default:
                {
                    TRACFCOMP(g_trac_targeting, ERR_MRK
                              "AttrRP::_notifyResourceReady: Bug! Unhandled "
                              "resource type = 0x%02X.",
                              i_resource);
                    assert(0);
                }
                break;
        }

        errlHndl_t pError = _sendAttrSyncMsg(msgType,sync);
        if(pError)
        {
            TRACFCOMP(g_trac_targeting, ERR_MRK
                      "AttrRP::_notifyResourceReady: Failed in call to "
                      "_sendAttrSyncMsg; msgType = 0x%08X, sync = %d.",
                      msgType,sync);
        }

        TRACFCOMP(g_trac_targeting, EXIT_MRK
                  "AttrRP::_notifyResourceReady");

        return pError;
    }

    errlHndl_t AttrRP::disableAttributeSyncToSP()
    {
        return Singleton<AttrRP>::instance()._disableAttributeSyncToSP();
    }

    errlHndl_t AttrRP::_disableAttributeSyncToSP() const
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK
                  "AttrRP::_disableAttributeSyncToSP");
        auto pError = _sendAttrSyncMsg(MSG_ATTR_DO_NOT_SYNC_ON_SHUTDOWN, true);
        TRACFCOMP(g_trac_targeting, EXIT_MRK
                  "AttrRP::_disableAttributeSyncToSP");
        return pError;
    }

    errlHndl_t AttrRP::_sendAttrSyncMsg(
        const ATTRRP_MSG_TYPE i_msgType,
        const bool            i_sync) const
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK
                  "AttrRP::_sendAttrSyncMsg: i_msgType = 0x%08X, i_sync = %d.",
                  i_msgType,
                  i_sync);

        errlHndl_t pError = nullptr;
        auto pMsg = msg_allocate();
        pMsg->type = i_msgType;
        int rc = 0;

        if(sync)
        {
            rc = msg_sendrecv(iv_attrSyncMsgQ,pMsg);
        }
        else
        {
            rc = msg_send(iv_attrSyncMsgQ,pMsg);
        }

        bool logError=false;
        uint32_t plid=0;
        int msgRc=0;

        if (rc)
        {
            TRACFCOMP(g_trac_targeting, ERR_MRK
                      "AttrRP::_sendAttrSyncMsg: Failed in %s. "
                      "Message type = 0x%08X, sync = %d, rc = %d.",
                      sync ? "msg_sendrecv" : "msg_send",
                      pMsg->type,sync,rc);
            logError=true;
        }
        else if(sync)
        {
            if(pMsg->data[1])
            {
                msgRc=static_cast<int>(pMsg->data[1]);
                TRACFCOMP(g_trac_targeting, ERR_MRK
                          "AttrRP::_sendAttrSyncMsg: Message (type = 0x%08X) "
                          "returned with rc = %d.",
                          pMsg->type,msgRc);
                logError=true;
            }

            if(pMsg->extra_data)
            {
                plid=static_cast<uint32_t>(
                    reinterpret_cast<uint64_t>(pMsg->extra_data));
                TRACFCOMP(g_trac_targeting, ERR_MRK
                          "AttrRP::_sendAttrSyncMsg: Message (type = 0x%08X) "
                          "returned with failure related to PLID = 0x%08X.",
                          pMsg->type,plid);
                logError=true;
            }
        }

        if(logError)
        {
            /*@
             *  @errortype
             *  @moduleid         TARG_SEND_ATTR_SYNC_MSG
             *  @reasoncode       TARG_RC_ATTR_MSG_FAIL
             *  @userdata1[00:31] Message type
             *  @userdata1[32:63] API return code (from msg_send or
             *      msg_sendrecv; 0=N/A)
             *  @userdata2[00:31] Message return code (0=N/A)
             *  @userdata2[32:63] Message error PLID (0=N/A)
             *  @devdesc          Failed to either send/(receive) the requested
             *      message to/from the attribute resource provider OR the
             *      provider failed executing the message request.
             *  @custdesc         Unexpected boot firmware error occurred
             */
            pError = new ErrlEntry(
                ERRL_SEV_UNRECOVERABLE,
                TARG_SEND_ATTR_SYNC_MSG,
                TARG_RC_ATTR_MSG_FAIL,
                TWO_UINT32_TO_UINT64(pMsg->type,rc),
                TWO_UINT32_TO_UINT64(msgRc,plid),
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            pError->collectTrace(TARG_COMP_NAME);
            if(plid)
            {
                pError->plid(plid);
            }
        }

        if(sync)
        {
            msg_free(pMsg);
            pMsg = nullptr;
        }

        TRACFCOMP(g_trac_targeting, EXIT_MRK
                  "AttrRP::_sendAttrSyncMsg: rc = %d, msgRc = %d, plid = "
                  "0x%08X.",
                  rc,msgRc,plid);

        return pError;
    }

    errlHndl_t AttrRP::_invokeAttrSync() const
    {
        errlHndl_t pError = nullptr;

        do
        {
            TRACFCOMP(g_trac_targeting, INFO_MRK "_invokeAttrSync: "
                "iv_attrSyncPrimed=%d iv_attrSyncWindowOpen=%d",
                iv_attrSyncPrimed, iv_attrSyncWindowOpen);
            // Check for sync primed
            if(!iv_attrSyncPrimed)
            {
                TRACFCOMP(g_trac_targeting, INFO_MRK "_invokeAttrSync: "
                        "Attribute sync not primed; suppressing "
                        "attribute sync.");
                break;
            }
            else if (!iv_attrSyncWindowOpen)
            {
                TRACFCOMP(g_trac_targeting, INFO_MRK "_invokeAttrSync: "
                        "Attribute sync window -NOT- OPEN; suppressing "
                        "attribute sync.");
                break;
            }
            // FSP
            else if (INITSERVICE::spBaseServicesEnabled())
            {
                TRACFCOMP(g_trac_targeting, INFO_MRK "_invokeAttrSync: "
                        "Calling attribute sync for FSP.");
                pError = _invokeFspSync();
            }
            // BMC
            else
            {
#ifdef CONFIG_DEVTREE
                TRACFCOMP(g_trac_targeting, INFO_MRK "_invokeAttrSync: "
                        "Calling devtree attribute sync for BMC.");
                (void)DEVTREE::devtreeSyncAttrs();

                // Update the persistent HBD partition with the current
                // state of RW attributes
                pError = updatePreservedAttrSection();
#endif
                break;
            }

        } while(0);

        return pError;
    }

    errlHndl_t AttrRP::_invokeFspSync() const
    {
        errlHndl_t pError = nullptr;

        do
        {
            // Ensure that SBE is not quiesced (in which case mailbox
            // related SBE FIFO traffic will not be serviced)
            TARGETING::Target* pMasterProc=nullptr;

            // Master processor is assumed to be functional since we're running
            // on it; if  no functional master is found, we'll error out.
            pError = TARGETING::
                targetService().queryMasterProcChipTargetHandle(pMasterProc);
            if(pError)
            {
                TRACFCOMP(g_trac_targeting, ERR_MRK "_invokeFspSync: "
                          "Failed to determine master processor target; "
                          "suppressing attribute sync.");
                break;
            }

            if(pMasterProc->getAttr<TARGETING::ATTR_ASSUME_SBE_QUIESCED>())
            {
                TRACFCOMP(g_trac_targeting, INFO_MRK "_invokeFspSync; SBE "
                          "is quiesced; suppressing attribute sync.");
                break;
            }

            pError = TARGETING::syncAllAttributesToFsp();
            if(pError)
            {
                TRACFCOMP(g_trac_targeting, ERR_MRK "_invokeFspSync: "
                          "Failed syncing attributes to FSP.");
                break;
            }

        } while(0);

        return pError;
    }

    void AttrRP::attrSyncTask()
    {
        // Crash Hostboot if this task dies
        (void)task_detach();

        errlHndl_t pError = nullptr;

        bool shutdown_requested = false;

        TRACFCOMP(g_trac_targeting, ENTER_MRK "AttrRP::attrSyncTask.");

        // Register to synchronize applicable attributes down to FSP when
        // a shutdown occurs.  NO_PRIORITY priority forces the attribute
        // synchronization to complete prior to the mailbox shutdown.
        // Intentionally ignores the return code that simply indicates if this
        // registration happened already.
        INITSERVICE::registerShutdownEvent(TARG_COMP_ID,
                                           iv_attrSyncMsgQ,
                                           MSG_SHUTDOWN_ATTR_SYNC,
                                           INITSERVICE::NO_PRIORITY);
        while(1)
        {
            int rc = 0;
            uint32_t plid = 0;

            auto pMsg = msg_wait(iv_attrSyncMsgQ);
            if (!pMsg)
            {
                continue;
            }

            TRACFCOMP(g_trac_targeting, INFO_MRK
                "AttrRP: attrSyncTask: "
                "Received message of type = 0x%08X.",
                pMsg->type);

            do {
            if (!shutdown_requested)
            {
                switch(pMsg->type)
                {
                    case MSG_PRIME_ATTR_SYNC:
                        {
                            iv_attrSyncPrimed=true;
                            TRACFCOMP(g_trac_targeting, INFO_MRK
                                "AttrRP: attrSyncTask: "
                                "Attribute provider primed to synchronize "
                                "attributes.");
                        }
                        break;
                    case MSG_INVOKE_ATTR_SYNC:
                        {
                            TRACFCOMP(g_trac_targeting, INFO_MRK
                                "AttrRP: attrSyncTask: "
                                "Invoking attribute sync.");

                            pError = _invokeAttrSync();
                        }
                        break;
                    case MSG_ATTR_OVERRIDE_SYNC:
                        {
                            TRACFCOMP(g_trac_targeting, INFO_MRK
                                "AttrRP: attrSyncTask: "
                                "Attr sync and override.");

                            fapi2::theAttrOverrideSync().
                                sendAttrOverridesAndSyncsToFsp();
                        }
                        break;
                    case MSG_SHUTDOWN_ATTR_SYNC:
                        {
                            TRACFCOMP(g_trac_targeting, INFO_MRK
                                "AttrRP: attrSyncTask: "
                                "Shutdown attribute sync.");

                            pError = _invokeAttrSync();
                            shutdown_requested = true;
                        }
                        break;
                    case MSG_ATTR_SYNC_WINDOW_OPEN:
                        {
                            iv_attrSyncWindowOpen=true;
                            TRACFCOMP(g_trac_targeting, INFO_MRK
                                "AttrRP: attrSyncTask: "
                                "Attribute Sync Window OPEN to synchronize "
                                "attributes.");
                        }
                        break;
                    case MSG_ATTR_DO_NOT_SYNC_ON_SHUTDOWN:
                        {
                            iv_attrSyncWindowOpen=false;
                            TRACFCOMP(g_trac_targeting, INFO_MRK
                                "AttrRP: attrSyncTask: "
                                "Disabling Attribute Sync on shutdown.");
                        }
                        break;
                    default:
                        {
                            TRACFCOMP(g_trac_targeting, ERR_MRK
                                "AttrRP: attrSyncTask: "
                                "Unhandled message type = 0x%08X.",
                                pMsg->type);
                            rc = -EINVAL;
                        }
                        break;
                }
            }
            else if (!msg_is_async(pMsg))
            {
                TRACFCOMP(g_trac_targeting, ERR_MRK
                       "AttrRP: attrSyncTask: "
                       "Service is down so message can not be handled");
                /*@
                 * @errortype
                 * @moduleid  TARG_ATTR_SYNC_TASK
                 * @reasoncode TARG_RC_ATTR_SYNC_SERVICE_DOWN
                 * @userdata1 Return code
                 * @userdata2 Message type
                 * @devdesc   Shutdown just occurred so the mailbox service
                 *       is down. Messages can not be handled at this time.
                 * @custdesc  Tolerated boot firmware error occurred
                 */
                pError = new ErrlEntry(
                    ERRL_SEV_INFORMATIONAL,
                    TARG_ATTR_SYNC_TASK,
                    TARG_RC_ATTR_SYNC_SERVICE_DOWN,
                    TO_UINT64(rc),
                    TO_UINT64(pMsg->type),
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            }
            } while (0);

            if (rc != 0)
            {
                /*@
                 * @errortype
                 * @moduleid   TARG_ATTR_SYNC_TASK
                 * @reasoncode TARG_RC_UNSUPPORTED_ATTR_SYNC_MSG
                 * @userdata1  Return code
                 * @userdata2  Message type
                 * @devdesc    Invalid message type requested through the
                 *     attribute resource provider's attribute synchronization
                 *     sync daemon.
                 * @custdesc   Unexpected boot firmware failure
                 */
                pError = new ErrlEntry(
                    ERRL_SEV_UNRECOVERABLE,
                    TARG_ATTR_SYNC_TASK,
                    TARG_RC_UNSUPPORTED_ATTR_SYNC_MSG,
                    TO_UINT64(rc),
                    TO_UINT64(pMsg->type),
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            }

            if(pError)
            {
                plid = pError->plid();
                errlCommit(pError, TARG_COMP_ID);
            }

            if(msg_is_async(pMsg))
            {
                // When caller sends an async message, the receiver must
                // deallocate the message
                (void)msg_free(pMsg);
                // Free doesn't nullify the caller's pointer automatically,
                pMsg=nullptr;
            }
            else
            {
                // Respond to request.
                pMsg->data[1] = static_cast<uint64_t>(rc);
                pMsg->extra_data = reinterpret_cast<void*>(
                    static_cast<uint64_t>(plid));
                rc = msg_respond(iv_attrSyncMsgQ, pMsg);
                if (rc)
                {
                    TRACFCOMP(g_trac_targeting,ERR_MRK
                        "AttrRP: attrSyncTask: "
                        "Bad rc = %d from msg_respond.", rc);
                }
            }
        }
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
            uint64_t vAddr = 0;
            void*    pAddr = nullptr;
            ssize_t  section = -1;
            uint64_t offset = 0;
            uint64_t size = 0;

            TRACDCOMP(g_trac_targeting, INFO_MRK "AttrRP: Message recv'd: "
                      "0x%08X",msg->type);

            // These messages are sent directly from the kernel and have
            // virtual/physical addresses for data 0 and 1 respectively.
            const std::array<uint32_t,2> kernelMessageTypes =
                {MSG_MM_RP_READ,
                 MSG_MM_RP_WRITE};

            do {

                if(   std::find(kernelMessageTypes.begin(),
                                kernelMessageTypes.end(),
                                msg->type)
                   != kernelMessageTypes.end())
                {
                    vAddr = msg->data[0];
                    pAddr = reinterpret_cast<void*>(msg->data[1]);

                    TRACDCOMP(g_trac_targeting,INFO_MRK
                        "AttrRP: message type = 0x%08X, vAddr = 0x%016llX, "
                        "pAddr = 0x%016llX.",
                        msg->type, vAddr, pAddr);

                    // Locate corresponding attribute section for message.
                    for (size_t i = 0; i < iv_sectionCount; ++i)
                    {
                        if ((vAddr >= iv_sections[i].vmmAddress) &&
                            (vAddr < iv_sections[i].vmmAddress +
                                                         iv_sections[i].size))
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
                        break; // go to error handler
                    }

                    // Determine PNOR offset and page size.
                    offset = vAddr - iv_sections[section].vmmAddress;
                    size = std::min(PAGE_SIZE,
                                         iv_sections[section].vmmAddress +
                                         iv_sections[section].size -
                                         vAddr);
                    // We could be requested to read/write less than a page
                    // if the virtual address requested is at the end of the
                    // section and the section size is not page aligned.
                    //
                    // Example: Section size is 6k and vAddr = vmmAddr + 4k,
                    //          we should only operate on 2k of content.


                }

                // Process request.

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
                        // if we are NOT in mpipl OR if this IS a r/w section
                        // on FSP system, do a memcpy from PNOR address into
                        // physical page.
                        if(!iv_isMpipl
                        #ifndef CONFIG_ENABLE_PERSISTENT_RW_ATTR
                           ||
                           (iv_sections[section].type == SECTION_TYPE_PNOR_RW))
                        #else
                            )
                        #endif
                        {
                            memcpy(pAddr,
                                reinterpret_cast<void*>(
                                        iv_sections[section].pnorAddress + offset),
                                size);
                        }
                        else
                        {
                            // Do memcpy from real memory into physical page.
                            memcpy(pAddr,
                                   reinterpret_cast<void*>(
                                   iv_sections[section].realMemAddress + offset),
                                   size);
                        }
                        break;

                    case MSG_MM_RP_WRITE:
                        #ifndef CONFIG_ENABLE_PERSISTENT_RW_ATTR
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
                        #else
                        // We should not be writing back into the RW partition,
                        // since it lives on the heap now.
                        assert(false, "AttrRP::msgServiceTask: attempt to write to RW partition");
                        #endif
                        break;
                    case MSG_MM_RP_RUNTIME_PREP:
                    {
                        // Only do this prep if the RW section needs to be
                        // flushed out to PNOR.
                        #ifndef CONFIG_ENABLE_PERSISTENT_RW_ATTR
                        // used for security purposes to pin all the attribute
                        // memory just prior to copying to reserve memory
                        uint64_t l_access =
                            msg->data[0] == MSG_MM_RP_RUNTIME_PREP_BEGIN?
                                WRITABLE:
                            msg->data[0] == MSG_MM_RP_RUNTIME_PREP_END?
                                WRITE_TRACKED: 0;
                        if (!l_access)
                        {
                            rc = -EINVAL;
                            break;
                        }

                        for (size_t i = 0; i < iv_sectionCount; ++i)
                        {
                            if ( iv_sections[i].type == SECTION_TYPE_PNOR_RW)
                            {
                                rc = mm_set_permission(reinterpret_cast<void*>(
                                       iv_sections[i].vmmAddress),
                                       iv_sections[i].size,
                                       l_access);
                            }
                        }
                        #endif
                        break;
                    }
                    default:
                        TRACFCOMP(g_trac_targeting,
                                  ERR_MRK "AttrRP: Unhandled command type %d.",
                                  msg->type);
                        rc = -EINVAL;
                        break;
                }

            } while (0);

            // Log an error log if the AttrRP was unable to handle a message
            // for any reason.
            if (rc != 0)
            {
                /*@
                 *   @errortype         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 *   @moduleid          TARG_MSG_SERVICE_TASK
                 *   @reasoncode        TARG_RC_ATTR_MSG_FAIL
                 *   @userdata1         Virtual Address
                 *   @userdata2         (Msg Type << 32) | Section #
                 *
                 *   @devdesc   The attribute resource provider was unable to
                 *              satisfy a message request from the VMM portion
                 *              of the kernel.  This was either due to an
                 *              address outside a valid range or a message
                 *              request that is invalid for the attribute
                 *              section containing the address.
                 *
                 *   @custdesc  Attribute Resource Provider failed to handle
                 *              request
                 */
                const bool hbSwError = true;
                errlHndl_t l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                                  TARG_MSG_SERVICE_TASK,
                                                  TARG_RC_ATTR_MSG_FAIL,
                                                  vAddr,
                                                  TWO_UINT32_TO_UINT64(
                                                        msg->type,
                                                        section),
                                                  hbSwError);
                errlCommit(l_errl,TARG_COMP_ID);
            }

            // Respond to request.
            msg->data[1] = rc;
            rc = msg_respond(iv_msgQ, msg);
            if (rc)
            {
                TRACFCOMP(g_trac_targeting,
                          ERR_MRK"AttrRP: Bad rc from msg_respond: %d", rc);
            }
        }
    }

    uint64_t AttrRP::getHbDataTocAddr()
    {
        // Setup physical TOC address
        uint64_t l_toc_addr = 0;
        const auto l_keys = g_BlToHbDataManager.getKeys();

        // Iterate over the number of key/addr structures until we find one
        // that matches
        for (uint8_t keyIndex = 0;
             keyIndex < g_BlToHbDataManager.getNumKeyAddrPair();
             ++keyIndex)
        {
            if(l_keys[keyIndex] == SBEIO::RSV_MEM_ATTR_ADDR)
            {
                const auto l_address = g_BlToHbDataManager.getAddresses();
                l_toc_addr = l_address[keyIndex];
                break;
            }
        }

        if(!l_toc_addr)
        {
            // Setup physical TOC address to hardcoded value
            l_toc_addr = cpu_spr_value(CPU_SPR_HRMOR) +
                VMM_HB_DATA_TOC_START_OFFSET;
        }

        // return the vaddr found from the mapping
        return l_toc_addr;
    }

    uint64_t AttrRP::getHbDataRelocPayloadAddr()
    {
        uint64_t payload_addr = 0;
        const auto l_keys = g_BlToHbDataManager.getKeys();

        // Iterate over the number of key/addr structures until we find one
        // that matches
        for(size_t keyIndex = 0;
            keyIndex < g_BlToHbDataManager.getNumKeyAddrPair();
            ++keyIndex)
        {
            if(l_keys[keyIndex] == SBEIO::RELOC_PAYLOAD_ADDR)
            {
                const auto l_address = g_BlToHbDataManager.getAddresses();
                payload_addr = l_address[keyIndex];
                break;
            }
        }

        // return relocated payload physical address
        return payload_addr;
    }

    errlHndl_t AttrRP::getReservedMemoryRegion(uint64_t& o_phys_attr_data_addr,
                                               uint64_t& o_attr_data_size)
    {
        errlHndl_t l_errl = nullptr;
        Util::hbrtTableOfContents_t * l_toc_ptr = nullptr;
        do
        {
        // Setup physical TOC address
        o_phys_attr_data_addr = 0;
        o_attr_data_size = 0;
        uint64_t l_toc_addr = TARGETING::AttrRP::getHbDataTocAddr();

        // Map the TOC to find the ATTR label address and size
        l_toc_ptr =
            reinterpret_cast<Util::hbrtTableOfContents_t *>(
            mm_block_map(reinterpret_cast<void*>(l_toc_addr),
            sizeof(Util::hbrtTableOfContents_t)));

        if (l_toc_ptr != nullptr)
        {
            // read the TOC and look for ATTR data section
            uint64_t l_attr_data_addr = Util::hb_find_rsvd_mem_label(
                Util::HBRT_MEM_LABEL_ATTR,
                l_toc_ptr,
                o_attr_data_size);

            // make sure we're not calculating a negative offset
            if (reinterpret_cast<uint64_t>(l_toc_ptr) > l_attr_data_addr)
            {
                TRACFCOMP(g_trac_targeting,
                    "getReservedMemoryRegion: hb_find_rsvd_mem_label found region "
                    "below the table of contents region");
                /*@
                 *  @errortype      ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 *  @moduleid       TARG_PARSE_ATTR_SECT_HEADER
                 *  @reasoncode     TARG_RC_RSVD_MEM_LABEL_FAIL
                 *  @userdata1      attribute region address
                 *  @userdata2      toc region
                 *
                 *  @devdesc   Attribute region found was below the table of
                 *             contents region
                 *  @custdesc  Error occurred during system boot
                 */
                l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                       TARG_PARSE_ATTR_SECT_HEADER,
                                       TARG_RC_RSVD_MEM_LABEL_FAIL,
                                       l_attr_data_addr,
                                       reinterpret_cast<uint64_t>(l_toc_ptr),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }

            // calculate the offset from the start of the TOC
            uint64_t l_attr_offset = l_attr_data_addr -
                reinterpret_cast<uint64_t>(l_toc_ptr);

            // setup where the ATTR data can be found
            o_phys_attr_data_addr = l_toc_addr + l_attr_offset;
        }
        else
        {
            TRACFCOMP(g_trac_targeting,
                      "Failed mapping Table of Contents section %p",
                      reinterpret_cast<void*>(l_toc_ptr));
            /*@
             *  @errortype      ERRORLOG::ERRL_SEV_UNRECOVERABLE
             *  @moduleid       TARG_PARSE_ATTR_SECT_HEADER
             *  @reasoncode     TARG_RC_TOC_MAPPING_FAIL
             *  @userdata1      Table of Contents pointer
             *
             *  @devdesc        Mapping TOC section failed
             *  @custdesc       Error occurred during system boot
             */
            l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                   TARG_PARSE_ATTR_SECT_HEADER,
                                   TARG_RC_TOC_MAPPING_FAIL,
                                   reinterpret_cast<uint64_t>(l_toc_ptr),
                                   0,
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        } while(0);

        if (l_toc_ptr != nullptr)
        {
            // clear the mapped memory for the TOC
            int rc = mm_block_unmap(
                reinterpret_cast<void*>(l_toc_ptr));
            if (rc != 0)
            {
                TRACFCOMP(g_trac_targeting,
                    "getReservedMemoryRegion fail to unmap virt addr %p, "
                    "rc = %d",
                    reinterpret_cast<void*>(l_toc_ptr), rc);
               /*@
                *  @errortype      ERRORLOG::ERRL_SEV_UNRECOVERABLE
                *  @moduleid       TARG_PARSE_ATTR_SECT_HEADER
                *  @reasoncode     TARG_RC_MM_BLOCK_UNMAP_FAIL
                *  @userdata1      return code
                *  @userdata2      Unmap virtual address
                *
                *  @devdesc   While attempting to unmap a virtual
                *             addr for our targeting information the
                *             kernel returned an error
                *  @custdesc  An internal firmware error occurred
                */
                auto l_unmap_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                                 TARG_PARSE_ATTR_SECT_HEADER,
                                                 TARG_RC_MM_BLOCK_FAIL,
                                                 rc,
                                                 reinterpret_cast<uint64_t>(l_toc_ptr),
                                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                if (l_errl)
                {
                    l_unmap_err->plid(l_errl->plid());
                    errlCommit(l_unmap_err, IPC_COMP_ID);
                }
                else
                {
                    l_errl = l_unmap_err;
                    l_unmap_err = nullptr;
                }
            }
        }

        return l_errl;
    }

    errlHndl_t AttrRP::parseAttrSectHeader()
    {
        errlHndl_t l_errl = nullptr;
        bool hasHBD_HPT = false;

        do
        {
            #ifdef CONFIG_SECUREBOOT
            // Securely load HB_DATA section
            l_errl = PNOR::loadSecureSection(PNOR::HB_DATA);
            if (l_errl)
            {
                break;
            }
            #endif

            // Locate attribute section in PNOR.
            PNOR::SectionInfo_t l_pnorSectionInfo;
            TargetingHeader* l_header = nullptr;
            l_errl = PNOR::getSectionInfo(PNOR::HB_DATA,
                                          l_pnorSectionInfo);
            if(l_errl)
            {
                break;
            }

            if (l_pnorSectionInfo.hasHashTable)
            {
                hasHBD_HPT = true;
            }
            TRACFCOMP(g_trac_targeting, INFO_MRK "parseAttrSectHeader: HBD hasHashTable=%d", hasHBD_HPT);

            if(!iv_isMpipl)
            {
                // Find attribute section header.
                l_header =
                reinterpret_cast<TargetingHeader*>(l_pnorSectionInfo.vaddr);
            }
            else
            {
                TRACFCOMP(g_trac_targeting,
                           "Reading attributes from memory, NOT PNOR");
                //Create a block map of the address space we used to store
                //attribute information on the initial IPL
                //Account HRMOR (non 0 base addr)
                uint64_t l_phys_attr_data_addr = 0;
                uint64_t l_attr_data_size = 0;
                l_errl = getReservedMemoryRegion(l_phys_attr_data_addr, l_attr_data_size);
                if (l_errl)
                {
                    break;
                }

                // Now just map the ATTR data section
                l_header = reinterpret_cast<TargetingHeader*>(
                    mm_block_map(
                        reinterpret_cast<void*>(l_phys_attr_data_addr),
                        l_attr_data_size));
            }


            // Validate eye catch.
            if (l_header->eyeCatcher != PNOR_TARG_EYE_CATCHER)
            {
                TRACFCOMP(g_trac_targeting,
                          "ATTR_DATA section in pnor header mismatch found"
                          " header: %d expected header: %d",
                          l_header->eyeCatcher,
                          PNOR_TARG_EYE_CATCHER);
                /*@
                 *   @errortype         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 *   @moduleid          TARG_PARSE_ATTR_SECT_HEADER
                 *   @reasoncode        TARG_RC_BAD_EYECATCH
                 *   @userdata1         Observed Header Eyecatch Value
                 *   @userdata2         Expected Eyecatch Value
                 *
                 *   @devdesc   The eyecatch value observed in PNOR does not
                 *              match the expected value of
                 *              PNOR_TARG_EYE_CATCHER and therefore the
                 *              contents of the Attribute PNOR section are
                 *              unable to be parsed.
                 *   @custdesc  A problem occurred during the IPL of the
                 *              system.
                 *              The eyecatch value observed in memory does not
                 *              match the expected value and therefore the
                 *              contents of the attribute sections are unable
                 *              to be parsed.
                */
                l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                       TARG_PARSE_ATTR_SECT_HEADER,
                                       TARG_RC_BAD_EYECATCH,
                                       l_header->eyeCatcher,
                                       PNOR_TARG_EYE_CATCHER);
                break;
            }

            // Allocate section structures based on section count in header.
            iv_sectionCount = l_header->numSections;
            iv_sections = new AttrRP_Section[iv_sectionCount];

            TargetingSection* l_section = nullptr;
            if(!iv_isMpipl)
            {
                // Find start to first section:
                //          (PNOR addr + size of header + offset in header).
                l_section =
                        reinterpret_cast<TargetingSection*>(
                                l_pnorSectionInfo.vaddr + sizeof(TargetingHeader) +
                                l_header->offsetToSections
                        );
            }
            else
            {
                // Find start to first section:
                // (header address + size of header + offset in header)
                l_section =
                    reinterpret_cast<TargetingSection*>(
                        reinterpret_cast<uint64_t>(l_header) +
                        sizeof(TargetingHeader) + l_header->offsetToSections
                        );

            }

            //Keep a running offset of how far into our real memory section we are
            uint64_t l_realMemOffset = 0;

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


                iv_sections[i].pnorAddress =
                    l_pnorSectionInfo.vaddr + l_section->sectionOffset;

                #ifdef CONFIG_SECUREBOOT
                // RW targeting section is part of the unprotected payload
                // so use the normal PNOR virtual address space unless HBD
                // has hash page table, in which case pull from the secure
                // provider that validates each page.
                if(   l_pnorSectionInfo.secure
                   && iv_sections[i].type == SECTION_TYPE_PNOR_RW)
                {
                    // if the HBD is HPT enabled means we have the HBD_RW partition
                    // HBD will always package the protected and unprotected HBD data
                    // which is needed for the ultimate LID, this is a packaging statement
                    //
                    // if HBD -NOT- HPT enabled we need to use
                    // the normal PNOR virtual address space
                    if (!hasHBD_HPT)
                    {
                        iv_sections[i].pnorAddress -=
                            (VMM_VADDR_SPNOR_DELTA + VMM_VADDR_SPNOR_DELTA);
                    }
                }
                #endif

                if(iv_isMpipl)
                {
                    //For MPIPL we are reading from real memory,
                    //not pnor flash. Set the real memory address
                    iv_sections[i].realMemAddress =
                        reinterpret_cast<uint64_t>(l_header) + l_realMemOffset;
                }
                iv_sections[i].size = l_section->sectionSize;

                //Increment our offset variable by the size of this section
                l_realMemOffset += iv_sections[i].size;

                TRACFCOMP(g_trac_targeting, INFO_MRK
                          "Decoded Attribute Section: Type %d, VMM 0x%lx PNOR 0x%lx Real 0x%lx Size 0x%lx",
                          iv_sections[i].type,
                          iv_sections[i].vmmAddress,
                          iv_sections[i].pnorAddress,
                          iv_sections[i].realMemAddress,
                          iv_sections[i].size);

            }

        } while (false);

        return l_errl;

    }

    errlHndl_t AttrRP::editPagePermissions(uint8_t i_type, uint32_t i_permission)
    {
        errlHndl_t l_errl = NULL;
        int rc;
        uint32_t l_perm = i_permission;
        do
        {
            // Create VMM block for each section, assign permissions.
            for (size_t i = 0; i < iv_sectionCount; ++i)
            {
                if(i_permission == DEFAULT_PERMISSIONS)
                {
                    switch(iv_sections[i].type)
                    {
                        case SECTION_TYPE_PNOR_RO:
                        case SECTION_TYPE_HB_METADATA:
                            l_perm = READ_ONLY;
                            break;

                        case SECTION_TYPE_PNOR_RW:
                            l_perm = WRITABLE;
                            #ifndef CONFIG_ENABLE_PERSISTENT_RW_ATTR
                            // Mark the RW section write-tracked for FSP
                            // systems. On BMC, the RW section behaves
                            // just like the PNOR_INIT section.
                            l_perm |= WRITE_TRACKED;
                            #endif
                        case SECTION_TYPE_HEAP_PNOR_INIT:
                            l_perm = WRITABLE;
                            break;

                        case SECTION_TYPE_HEAP_ZERO_INIT:
                        case SECTION_TYPE_HB_HEAP_ZERO_INIT:
                            l_perm = WRITABLE | ALLOCATE_FROM_ZERO;
                            break;

                        default:

                            /*@
                            *   @errortype  ERRORLOG::ERRL_SEV_UNRECOVERABLE
                            *   @moduleid   TARG_EDIT_PAGE_PERMISSIONS
                            *   @reasoncode TARG_RC_UNHANDLED_ATTR_SEC_TYPE
                            *   @userdata1  Section type
                            *
                            *   @devdesc    Found unhandled attribute section type
                            *   @custdesc   FW error, unexpected Attribute section type
                            */
                            const bool hbSwError = true;
                            l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                                TARG_EDIT_PAGE_PERMISSIONS,
                                                TARG_RC_UNHANDLED_ATTR_SEC_TYPE,
                                                iv_sections[i].type,
                                                0, hbSwError);
                            break;
                    }
                    if(l_errl)
                    {
                        break;
                    }
                }
                if( i_type == ALL_SECTION_TYPES || i_type == iv_sections[i].type)
                {
                    rc = mm_set_permission(reinterpret_cast<void*>(
                                    iv_sections[i].vmmAddress),
                                    iv_sections[i].size,
                                    l_perm);
                }

                if (rc)
                {
                    /*@
                        *   @errortype         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                        *   @moduleid          TARG_EDIT_PAGE_PERMISSIONS
                        *   @reasoncode        TARG_RC_MM_PERM_FAIL
                        *   @userdata1         vAddress attempting to allocate.
                        *   @userdata2         (kernel-rc << 32) | (Permissions)
                        *
                        *   @devdesc   While attempting to set permissions on
                        *              a virtual memory block for an attribute
                        *              section, the kernel returned an error.
                        *
                        *   @custdesc  Kernel failed to set permissions on
                        *              virtual memory block
                        */
                    const bool hbSwError = true;
                    l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                            TARG_EDIT_PAGE_PERMISSIONS,
                                            TARG_RC_MM_PERM_FAIL,
                                            iv_sections[i].vmmAddress,
                                            TWO_UINT32_TO_UINT64(rc, l_perm),
                                            hbSwError);
                    break;
                }
            }
        } while(0);
        return l_errl;
    }

    errlHndl_t AttrRP::createVmmSections()
    {
        errlHndl_t l_errl = NULL;

        do
        {
            // Allocate message queue for VMM requests.
            iv_msgQ = msg_q_create();

            // register it so it can be discovered by istep 21 and thus allow
            // secure runtime preparation of persistent r/w attributes
            int rc = msg_q_register(iv_msgQ, ATTRRP_MSG_Q);

            assert(rc == 0, "Bug! Unable to register message queue");

            // Create VMM block for each section, assign permissions.
            for (size_t i = 0; i < iv_sectionCount; ++i)
            {
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
                     *   @errortype         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                     *   @moduleid          TARG_CREATE_VMM_SECTIONS
                     *   @reasoncode        TARG_RC_MM_BLOCK_FAIL
                     *   @userdata1         vAddress attempting to allocate.
                     *   @userdata2         RC from kernel.
                     *
                     *   @devdesc   While attempting to allocate a virtual
                     *              memory block for an attribute section, the
                     *              kernel returned an error.
                     *   @custdesc  Kernel failed to block memory
                     */
                    const bool hbSwError = true;
                    l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                           TARG_CREATE_VMM_SECTIONS,
                                           TARG_RC_MM_BLOCK_FAIL,
                                           iv_sections[i].vmmAddress,
                                           rc, hbSwError);
                    break;
                }

#ifndef CONFIG_ENABLE_PERSISTENT_RW_ATTR
                // Only register the RW block if the RW section lives in PNOR
                // and needs to be flushed back into PNOR
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
#endif
            } // End iteration through each section

            if(l_errl)
            {
                break;
            }

        } while (false);

        return l_errl;
    }

    void AttrRP::populateAttrsForMpipl()
    {
        do
        {
            TRACFCOMP(g_trac_targeting, "AttrRP::populateAttrsForMpipl: "
                      "In MPIPL, extending cache to be real memory" );
            mm_extend(MM_EXTEND_REAL_MEMORY);

            // Copy RW, Heap Zero Init sections because we are not
            // running the isteps that set these attrs during MPIPL
            for (size_t i = 0; i < iv_sectionCount; ++i)
            {
                // The volatile sections in MPIPL need to be copied because
                // on the MPIPL flow we will not run the HWPs that set these attrs
                // the RW section of the attribute data must be copied
                // into the vmmAddress in order to make future r/w come
                // from the pnor address, not real memory
                if(((iv_sections[i].type == SECTION_TYPE_HEAP_ZERO_INIT) ||
                    (iv_sections[i].type == SECTION_TYPE_HB_HEAP_ZERO_INIT)
#ifndef CONFIG_ENABLE_PERSISTENT_RW_ATTR
                    /* Copy RW section only in FSP case; on BMC, we use
                       in-memory copy of RW data */
                    || (iv_sections[i].type == SECTION_TYPE_PNOR_RW)
#endif
                    )
                    && iv_isMpipl)
                {
                    memcpy(reinterpret_cast<void*>(iv_sections[i].vmmAddress),
                        reinterpret_cast<void*>(iv_sections[i].realMemAddress),
                        (iv_sections[i].size));
                }

            }
        }while(0);
    }

    void* AttrRP::save(uint64_t& io_addr)
    {
        // Call save on singleton instance.
        return Singleton<AttrRP>::instance()._save(io_addr);
    }

    errlHndl_t AttrRP::save( uint8_t* i_dest, size_t& io_size )
    {
        // Call save on singleton instance.
        return Singleton<AttrRP>::instance()._save(i_dest,io_size);
    }

    uint64_t  AttrRP::maxSize( )
    {
        // Find total size of the sections.
        uint64_t l_size = 0;
        for( size_t i = 0;
             i < Singleton<AttrRP>::instance().iv_sectionCount;
             ++i)
        {
            l_size += ALIGN_PAGE(Singleton<AttrRP>::
                          instance().iv_sections[i].size);
        }

        return(l_size);

    } // end maxSize


    errlHndl_t AttrRP::saveOverrides( uint8_t* i_dest, size_t& io_size )
    {
        // Call save on singleton instance.
        return Singleton<AttrRP>::instance()._saveOverrides(i_dest,io_size);
    }


    void* AttrRP::_save(uint64_t& io_addr)
    {
        TRACDCOMP(g_trac_targeting, "AttrRP::save: top @ 0x%lx", io_addr);

        void* region = reinterpret_cast<void*>(io_addr);
        uint8_t* pointer = reinterpret_cast<uint8_t*>(region);

        if (TARGETING::is_no_load())
        {
            // Find total size of the sections.
            uint64_t l_size = maxSize();

            io_addr = ALIGN_PAGE_DOWN(io_addr);
            // Determine bottom of the address region.
            io_addr = io_addr - l_size;
            // Align to 64KB for No Payload
            io_addr = ALIGN_DOWN_X(io_addr,64*KILOBYTE);
            // Map in region.
            region = mm_block_map(reinterpret_cast<void*>(io_addr),l_size);
            pointer = reinterpret_cast<uint8_t*>(region);
        }

        // Copy content.
        for (size_t i = 0; i < iv_sectionCount; ++i)
        {
            memcpy(pointer,
                   reinterpret_cast<void*>(iv_sections[i].vmmAddress),
                   iv_sections[i].size);

            pointer = &pointer[ALIGN_PAGE(iv_sections[i].size)];
        }

        TRACFCOMP(g_trac_targeting, "AttrRP::save: bottom @ 0x%lx", io_addr);
        return region;
    }

    errlHndl_t AttrRP::_save( uint8_t* i_dest, size_t& io_size )
    {
        TRACFCOMP( g_trac_targeting, ENTER_MRK"AttrRP::_save: i_dest=%p, io_size=%ld", i_dest, io_size );
        errlHndl_t l_err = nullptr;
        uint8_t* pointer = i_dest;
        uint64_t l_totalSize = 0;
        uint64_t l_maxSize = io_size;
        uint64_t l_filledSize = 0;

        // Copy content.
        for (size_t i = 0; i < iv_sectionCount; ++i)
        {
            l_totalSize += iv_sections[i].size;
            if (l_totalSize <= l_maxSize)
            {
                l_filledSize = l_totalSize;
                memcpy(pointer,
                       reinterpret_cast<void*>(iv_sections[i].vmmAddress),
                       iv_sections[i].size);

                pointer = &pointer[ALIGN_PAGE(iv_sections[i].size)];
            }
            else
            {
                // Need a larger buffer
                TRACFCOMP( g_trac_targeting, ERR_MRK"AttrRP::_save - max size %d exceeded, missing section %d, size %d",
                    io_size,i, iv_sections[i].size);
            }
        }

        if (l_totalSize > io_size)
        {
            // Need to increase size of the buffer
             /*@
                 *   @errortype
                 *   @moduleid          TARG_MOD_SAVE_ATTR_TANK
                 *   @reasoncode        TARG_SPACE_OVERRUN
                 *   @userdata1         Maximum Available size
                 *   @userdata2         Required size
                 *
                 *   @devdesc   Size of attribute data exceeds available
                 *              buffer space
                 *
                 *   @custdesc  Internal firmware error applying
                 *              custom configuration settings
                 */
                l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                      TARG_MOD_SAVE_ATTR_TANK,
                                      TARG_SPACE_OVERRUN,
                                      io_size,
                                      l_totalSize,
                                      true /*SW Error */);
        }

        io_size = l_filledSize;

        TRACFCOMP(g_trac_targeting, EXIT_MRK"AttrRP::_save: i_dest=%p, io_size=%ld, size needed=%ld", i_dest, io_size, l_totalSize );
        return l_err;
    }



    errlHndl_t AttrRP::_saveOverrides( uint8_t* i_dest, size_t& io_size )
    {
        TRACFCOMP( g_trac_targeting, ENTER_MRK"AttrRP::_saveOverrides: i_dest=%p, io_size=%d", i_dest, io_size );
        errlHndl_t l_err = nullptr;

        do
        {
            size_t l_maxSize = io_size;
            io_size = 0;

            if (!SECUREBOOT::allowAttrOverrides())
            {
                TRACFCOMP( g_trac_targeting, "AttrRP::_saveOverrides: skipping "
                           "since Attribute Overrides are not allowed.");
            }

            // Save the fapi and temp overrides
            //   Note: no need to look at PERM because those were added to
            //         the base targeting model

            size_t l_tankSize = l_maxSize;
            uint8_t* l_dest = i_dest;

            // FAPI
            l_err = saveOverrideTank( l_dest,
                       l_tankSize,
                       &fapi2::theAttrOverrideSync().iv_overrideTank,
                       AttributeTank::TANK_LAYER_FAPI );
            if( l_err )
            {
                break;
            }
            l_maxSize -= l_tankSize;
            io_size += l_tankSize;

            // TARGETING
            l_tankSize = l_maxSize;
            l_dest = i_dest + io_size;
            l_err = saveOverrideTank( l_dest,
                                      l_tankSize,
                                      &Target::theTargOverrideAttrTank(),
                                      AttributeTank::TANK_LAYER_TARG );
            if( l_err )
            {
                break;
            }
            l_maxSize -= l_tankSize;
            io_size += l_tankSize;
        } while(0);

        TRACFCOMP( g_trac_targeting, EXIT_MRK"AttrRP::_saveOverrides: io_size=%d, l_err=%.8X", io_size, ERRL_GETRC_SAFE(l_err) );
        return l_err;
    }

    errlHndl_t AttrRP::saveOverrideTank( uint8_t* i_dest,
                                         size_t& io_size,
                                         AttributeTank* i_tank,
                                         AttributeTank::TankLayer i_layer )
    {
        TRACFCOMP( g_trac_targeting, ENTER_MRK"AttrRP::saveOverrideTank: i_dest=%p, io_size=%d, i_layer=%d", i_dest, io_size, i_layer );
        errlHndl_t l_err = nullptr;
        size_t l_maxSize = io_size;
        io_size = 0;

        // List of chunks we're going to save away
        std::vector<AttributeTank::AttributeSerializedChunk> l_chunks;
        i_tank->serializeAttributes(
                       TARGETING::AttributeTank::ALLOC_TYPE_MALLOC,
                       PAGESIZE, l_chunks );

        // Copy each chunk until we run out of space
        for( auto l_chunk : l_chunks )
        {
            // total size of data plus header for this chunk
            uint32_t l_chunkSize = l_chunk.iv_size;
            l_chunkSize += sizeof(AttrOverrideSection);
            // don't want to double-count the data payload...
            l_chunkSize -= sizeof(AttrOverrideSection::iv_chunk);

            // look for overflow, but only create 1 error
            if( (l_err == nullptr)
                && (io_size + l_chunkSize > l_maxSize) )
            {
                TRACFCOMP( g_trac_targeting, ERR_MRK"Size of chunk is too big" );
                /*@
                 *   @errortype
                 *   @moduleid          TARG_MOD_SAVE_OVERRIDE_TANK
                 *   @reasoncode        TARG_SPACE_OVERRUN
                 *   @userdata1[00:31]  Maximum Available size
                 *   @userdata1[32:63]  Required size
                 *   @userdata2[00:31]  Chunk Size
                 *   @userdata2[32:63]  Previous Size
                 *
                 *   @devdesc   Size of override data exceeds available
                 *              buffer space
                 *
                 *   @custdesc  Internal firmware error applying
                 *              custom configuration settings
                 */
                l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                      TARG_CREATE_VMM_SECTIONS,
                                      TARG_RC_MM_PERM_FAIL,
                                      TWO_UINT32_TO_UINT64(l_maxSize,
                                            io_size + l_chunkSize),
                                      TWO_UINT32_TO_UINT64(l_chunkSize,
                                                           io_size),
                                      true /*SW Error */);
                //deliberately not breaking out here so that we can
                // compute the required size and free the memory in
                // one place
            }

            if( l_err == nullptr )
            {
                // fill in the header
                AttrOverrideSection* l_header =
                  reinterpret_cast<AttrOverrideSection*>(i_dest+io_size);
                l_header->iv_layer = i_layer;
                l_header->iv_size = l_chunk.iv_size;

                // add the data
                memcpy( l_header->iv_chunk,
                        l_chunk.iv_pAttributes,
                        l_chunk.iv_size );
            }

            io_size += l_chunkSize;

            // freeing data that was allocated by serializeAttributes()
            free( l_chunk.iv_pAttributes );
            l_chunk.iv_pAttributes = NULL;
        }

        // add a terminator at the end since the size might get lost
        //  but only if we found some overrides
        if( (io_size > 0)
            && (io_size + sizeof(AttributeTank::TankLayer) < l_maxSize) )
        {
            AttrOverrideSection* l_term =
              reinterpret_cast<AttrOverrideSection*>(i_dest+io_size);
            l_term->iv_layer = AttributeTank::TANK_LAYER_TERM;
            io_size += sizeof(AttributeTank::TankLayer);
        }

        TRACFCOMP( g_trac_targeting, ENTER_MRK"AttrRP::saveOverrideTank: io_size=%d", io_size );
        return l_err;
    }

    errlHndl_t AttrRP::mergeAttributes()
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK"AttrRP::mergeAttributes");
        errlHndl_t l_errl = nullptr;
#ifdef CONFIG_ENABLE_PERSISTENT_RW_ATTR
        PNOR::SectionInfo_t l_hbdSectionInfo;

        do {

        if(UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
        {
            // No need to re-merge attributes in MPIPL. It would have been done
            // during the normal boot.
            TRACFCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: Skipping merge in MPIPL");
            break;
        }

        #ifdef CONFIG_SECUREBOOT
        l_errl = PNOR::loadSecureSection(PNOR::HB_DATA);
        if(l_errl)
        {
            break;
        }
        #endif

        l_errl = PNOR::getSectionInfo(PNOR::HB_DATA,
                                      l_hbdSectionInfo);
        if(l_errl)
        {
            TRACFCOMP(g_trac_targeting, ERR_MRK"AttrRP::mergeAttributes: could not get HBD section info");
            break;
        }

        // The existence of HBD_RW is driven by the HPT enabled bit of HBD,
        // so check that bit to make sure we actually need to perform the merge
        // (HBD_RW exists).
        if(l_hbdSectionInfo.hasHashTable)
        {
            PNOR::SectionInfo_t l_hbd_rwSectionInfo;
            l_errl = PNOR::getSectionInfo(PNOR::HB_DATA_RW,
                                          l_hbd_rwSectionInfo);
            if(l_errl)
            {
                TRACFCOMP(g_trac_targeting, ERR_MRK"AttrRP::mergeAttributes: could not get HBD_RW section info");
                break;
            }
            void* l_hbdPtr = reinterpret_cast<void*>(l_hbdSectionInfo.vaddr);
            rw_attr_section_t* l_hbdRwPtr = reinterpret_cast<rw_attr_section_t*>(l_hbd_rwSectionInfo.vaddr);

            // The map of attributes that have been persisted so far (old
            // attributes)
            huid_rw_attrs_map l_persistedRwAttrMap;
            l_errl = parseRWAttributeData(l_hbdRwPtr,
                                          l_persistedRwAttrMap);
            if(l_errl)
            {
                break;
            }

            section_metadata_mem_layout_t* l_attrMetadataPtr = nullptr;
            l_errl = getAttrMetadataPtr(l_hbdPtr, l_attrMetadataPtr);
            if(l_errl)
            {
                break;
            }

            // The map of new attributes from the current HBD
            attr_metadata_map l_newRwAttrMetadataMap;
            l_errl = parseAttrMetadataSection(l_attrMetadataPtr, l_newRwAttrMetadataMap);
            if(l_errl)
            {
                break;
            }

            // Grab all the targets to check their attributes
            TargetRangeFilter l_allTargets(targetService().begin(),
                                           targetService().end(),
                                           nullptr);

            for(; l_allTargets; ++l_allTargets)
            {
                const auto l_targetHuid = l_allTargets->getAttr<ATTR_HUID>();
                if(l_persistedRwAttrMap.find(l_targetHuid) == l_persistedRwAttrMap.end())
                {
                    // Target is not in RW data; continue to the next target
                    TRACFCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: HUID 0x%x is not found in persistent section; keeping the attribute value",
                              l_targetHuid);
                    continue;
                }

                TRACDCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: Target HUID 0x%x",
                          l_targetHuid);

                // Get all new (non-persisted) attributes and filter out only
                // the attributes with read-write persistency
                ATTRIBUTE_ID* l_attrIdArr = nullptr;
                AbstractPointer<void>* l_attrAddressesArr = nullptr;
                const uint32_t l_attrCnt = targetService().getTargetAttributes(*l_allTargets,
                                                                         &TARG_GET_SINGLETON(theAttrRP),
                                                                         l_attrIdArr,
                                                                         l_attrAddressesArr);
                TRACDCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: Found %d attributes for the target",
                          l_attrCnt);
                // Iterate the non-persistent RW attributes and compare their
                // values and metadata to the attributes we have preserved so
                // far
                for(uint32_t l_attrNum = 0; l_attrNum < l_attrCnt; ++l_attrNum)
                {
                    ATTRIBUTE_ID* l_attrId = l_attrIdArr + l_attrNum;
                    if(l_newRwAttrMetadataMap[*l_attrId].attrPersistency != SECTION_TYPE_PNOR_RW)
                    {
                        continue;
                    }

                    TRACDCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: Attribute 0x%x is RW",
                              *l_attrId);
                    // Get the attribute data out of the persistent attr
                    // section
                    if(l_persistedRwAttrMap[l_targetHuid].find(*l_attrId) == l_persistedRwAttrMap[l_targetHuid].end())
                    {
                        TRACFCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: HUID 0x%x  attr ID 0x%x is not found in the persistent section; keeping the new attribute value",
                                  l_targetHuid, *l_attrId)
                        continue;
                    }
                    TRACDCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: found attribute ID 0x%x HUID 0x%x in persistent data",
                              *l_attrId, l_targetHuid);
                    TRACDCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: attr size in persistent: %d",
                              l_persistedRwAttrMap[l_targetHuid][*l_attrId].metadata.attrSize);
                    TRACDBIN(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: value in persistent data", l_persistedRwAttrMap[l_targetHuid][*l_attrId].value.data(), l_persistedRwAttrMap[l_targetHuid][*l_attrId].metadata.attrSize);
                    if(l_persistedRwAttrMap[l_targetHuid][*l_attrId].metadata.attrSize ==
                       l_newRwAttrMetadataMap[*l_attrId].attrSize)
                    {
                        // Everything matched up to this point. Now
                        // compare the attr values.
                        void* l_attrAddr = nullptr;
                        l_allTargets->_getAttrPtr(*l_attrId,
                                                  &TARG_GET_SINGLETON(theAttrRP),
                                                  l_attrIdArr,
                                                  l_attrAddressesArr,
                                                  l_attrAddr);
                        if(l_attrAddr)
                        {
                            if(memcmp(l_attrAddr,
                                      l_persistedRwAttrMap[l_targetHuid][*l_attrId].value.data(),
                                      l_persistedRwAttrMap[l_targetHuid][*l_attrId].metadata.attrSize))
                            {
                                TRACFCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: HUID 0x%x  attr ID 0x%x values don't match. Keeping the persisted value",
                                          l_targetHuid, *l_attrId);
                                TRACFBIN(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: Incoming value",
                                         l_attrAddr,
                                         l_persistedRwAttrMap[l_targetHuid][*l_attrId].metadata.attrSize);
                                TRACFBIN(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: Persisted value",
                                         l_persistedRwAttrMap[l_targetHuid][*l_attrId].value.data(),
                                         l_persistedRwAttrMap[l_targetHuid][*l_attrId].metadata.attrSize);
                                memcpy(l_attrAddr,
                                       l_persistedRwAttrMap[l_targetHuid][*l_attrId].value.data(),
                                       l_persistedRwAttrMap[l_targetHuid][*l_attrId].metadata.attrSize);
                            }
                        }
                        else // attr value is nullptr
                        {
                            TRACFCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: HUID 0x%x  attr ID 0x%x not found",
                                      l_targetHuid, *l_attrId);
                        }
                    }
                    else // attr size is different
                    {
                        TRACFCOMP(g_trac_targeting, INFO_MRK"AttrRP::mergeAttributes: HUID 0x%x  attr ID 0x%x's size has changed. Old size: %d; new size: %d. Keeping the new value/size",
                                  l_targetHuid, *l_attrId, l_persistedRwAttrMap[l_targetHuid][*l_attrId].metadata.attrSize, l_newRwAttrMetadataMap[*l_attrId].attrSize);
                    }
                } // for each attribute
            } // for each target
        }
        else
        {
            TRACFCOMP(g_trac_targeting,INFO_MRK"AttrRP::mergeAttributes: HBD_RW doesn't exist");
        }
        } while(0);

        // Update the persistent partition even if there is an error
        if(l_hbdSectionInfo.hasHashTable)
        {
            errlHndl_t l_updateError = updatePreservedAttrSection();
            if(l_updateError)
            {
                TRACFCOMP(g_trac_targeting, ERR_MRK"AttrRP::mergeAttributes: could not update HBD_RW partition");
                if(l_errl)
                {
                    l_updateError->plid(l_errl->plid());
                    errlCommit(l_updateError, TARG_COMP_ID);
                }
                else
                {
                    l_errl = l_updateError;
                    l_updateError = nullptr;
                }
            }
        }

#endif // CONFIG_ENABLE_PERSISTENT_RW_ATTR
        TRACFCOMP(g_trac_targeting, EXIT_MRK"AttrRP::mergeAttributes");
        return l_errl;
    }

    errlHndl_t AttrRP::updatePreservedAttrSection()
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK"AttrRP::updatePreservedAttrSection");
        errlHndl_t l_errl = nullptr;

#ifdef CONFIG_ENABLE_PERSISTENT_RW_ATTR

        do {

        if(UTIL::assertGetToplevelTarget()->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
        {
            // No need to update preserved section during MPIPL.
            TRACFCOMP(g_trac_targeting, INFO_MRK"AttrRP::updatePreservedAttrSection: Skipping update in MPIPL");
            break;
        }

        #ifdef CONFIG_SECUREBOOT
        l_errl = PNOR::loadSecureSection(PNOR::HB_DATA);
        if(l_errl)
        {
            break;
        }
        #endif

        PNOR::SectionInfo_t l_hbdSectionInfo;
        l_errl = PNOR::getSectionInfo(PNOR::HB_DATA,
                                      l_hbdSectionInfo);
        if(l_errl)
        {
            TRACFCOMP(g_trac_targeting, ERR_MRK"AttrRP::updatePreservedAttrSection: could not get HBD section info");
            break;
        }

        if(l_hbdSectionInfo.hasHashTable)
        {
            void* l_hbdPtr = reinterpret_cast<void*>(l_hbdSectionInfo.vaddr);

            PNOR::SectionInfo_t l_hbd_rwSectionInfo;
            l_errl = PNOR::getSectionInfo(PNOR::HB_DATA_RW,
                                          l_hbd_rwSectionInfo);
            if(l_errl)
            {
                TRACFCOMP(g_trac_targeting, ERR_MRK"AttrRP::updatePreservedAttrSection: could not get HBD_RW section info");
                break;
            }

            rw_attr_section_t* l_hbdRwPtr = reinterpret_cast<rw_attr_section_t*>(l_hbd_rwSectionInfo.vaddr);

            section_metadata_mem_layout_t* l_attrMetadataPtr = nullptr;
            l_errl = getAttrMetadataPtr(l_hbdPtr, l_attrMetadataPtr);
            if(l_errl)
            {
                break;
            }

            attr_metadata_map l_rwAttrMetadataMap;
            l_errl = parseAttrMetadataSection(l_attrMetadataPtr, l_rwAttrMetadataMap);
            if(l_errl)
            {
                break;
            }

            TargetRangeFilter l_allTargets(targetService().begin(),
                                           targetService().end(),
                                           nullptr);

            uint32_t l_rwAttrCnt = 0;
            uint32_t l_rwDataSize = sizeof(l_hbdRwPtr->version) +
                                    sizeof(l_hbdRwPtr->dataSize) +
                                    sizeof(l_hbdRwPtr->numAttributes);
            rw_attr_memory_layout_t* l_preservedAttrPtr = l_hbdRwPtr->attrArray;
            // Iterate over all targets and write the RW attributes into the
            // persistent HBD_RW partition
            for(; l_allTargets; ++l_allTargets)
            {
                ATTRIBUTE_ID* l_attrIdArr = nullptr;
                AbstractPointer<void>* l_attrAddressesArr = nullptr;
                uint32_t l_attrCnt = targetService().getTargetAttributes(*l_allTargets,
                                                                         &TARG_GET_SINGLETON(theAttrRP),
                                                                         l_attrIdArr,
                                                                         l_attrAddressesArr);

                for(uint32_t l_attrNum = 0; l_attrNum < l_attrCnt; ++l_attrNum)
                {
                    ATTRIBUTE_ID* l_attrId = l_attrIdArr + l_attrNum;
                    if(l_rwAttrMetadataMap[*l_attrId].attrPersistency == SECTION_TYPE_PNOR_RW)
                    {
                        // Save the RW attribute info
                        l_rwAttrCnt++;
                        l_preservedAttrPtr->attrHash = *l_attrId;
                        l_preservedAttrPtr->huid = l_allTargets->getAttr<ATTR_HUID>();
                        l_preservedAttrPtr->attrData.metadata.attrSize =
                            l_rwAttrMetadataMap[*l_attrId].attrSize;
                        l_preservedAttrPtr->attrData.metadata.attrPersistency =
                            l_rwAttrMetadataMap[*l_attrId].attrPersistency;

                        void* l_attrValue = nullptr;
                        l_allTargets->_getAttrPtr(*l_attrId,
                                                  &TARG_GET_SINGLETON(theAttrRP),
                                                  l_attrIdArr,
                                                  l_attrAddressesArr,
                                                  l_attrValue);
                        if(l_attrValue)
                        {
                            memcpy(l_preservedAttrPtr->attrData.value,
                                   l_attrValue,
                                   l_rwAttrMetadataMap[*l_attrId].attrSize);
                        }
                        // Move to the next RW attribute pointer
                        uint32_t l_currAttrSize = sizeof(rw_attr_memory_layout_t) +
                                                  l_rwAttrMetadataMap[*l_attrId].attrSize;
                        l_preservedAttrPtr = reinterpret_cast<rw_attr_memory_layout_t*>(
                            reinterpret_cast<uint8_t*>(l_preservedAttrPtr) +
                            l_currAttrSize);
                        l_rwDataSize += l_currAttrSize;
                    }
                } // for all attributes
            } // for all targets

            const uint64_t END_OF_DATA_MARKER = 0x454e4444415441; // ENDDATA
            // Copy in the end of data marker
            memcpy(l_preservedAttrPtr, &END_OF_DATA_MARKER, sizeof(END_OF_DATA_MARKER));

            // Write the version, the hash, and the number of RW attributes
            l_hbdRwPtr->version = CURRENT_HBD_PERSISTENT_VERSION;
            l_hbdRwPtr->numAttributes = l_rwAttrCnt;
            l_hbdRwPtr->dataSize = l_rwDataSize;
            uint8_t* l_rwDataPtr = reinterpret_cast<uint8_t*>(&(l_hbdRwPtr->version));
            l_hbdRwPtr->dataHash = Util::crc32_calc(l_rwDataPtr, l_hbdRwPtr->dataSize);

            // Make sure the data is written out to PNOR
            l_errl = PNOR::flush(PNOR::HB_DATA_RW);
            if(l_errl)
            {
                break;
            }
        }
        } while(0);

#endif

        TRACFCOMP(g_trac_targeting, EXIT_MRK"AttrRP::updatePreservedAttrSection");
        return l_errl;
    }
};
