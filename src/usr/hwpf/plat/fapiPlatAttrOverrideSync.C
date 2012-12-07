/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatAttrOverrideSync.C $                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
 *  @file fapiPlatAttrOverrideSync.C
 *
 *  @brief Implements the functions for Attribute Override and Sync
 *
 */

//******************************************************************************
// Includes
//******************************************************************************
#include <limits.h>
#include <sys/msg.h>
#include <string.h>
#include <vector>
#include <sys/msg.h>
#include <util/singleton.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <mbox/mboxif.H>
#include <hwpf/fapi/fapiAttributeTank.H>
#include <hwpf/plat/fapiPlatAttrOverrideSync.H>
#include <hwpf/plat/fapiPlatTrace.H>

namespace fapi
{

//******************************************************************************
// Global Variables
//******************************************************************************

// Attribute set directly by debug tool in standalone Hostboot mode to apply
// an Attribute Override
fapi::Attribute g_attrOverride;

namespace attrOverrideSync
{

/**
 * @brief Attribute Override/Sync Mailbox Message Type Constants
 *        These must be kept in sync with FSP firmware
 */
enum MAILBOX_MSG_TYPE
{
    MSG_SET_OVERRIDES       = MBOX::FIRST_UNSECURE_MSG + 0x10, // FSP<->Hostboot
    MSG_CLEAR_ALL_OVERRIDES = MBOX::FIRST_UNSECURE_MSG + 0x11, // FSP<->Hostboot
    MSG_SET_SYNC_ATTS       = MBOX::FIRST_UNSECURE_MSG + 0x12, // FSP<--Hostboot
};

//******************************************************************************
// Apply a HWPF Attribute Override written directly into Hostboot memory from
// the Simics/VBU console. This function is called by a Simics/VBU debug tool
//******************************************************************************
void directOverride()
{
    // Apply the attribute override
    Singleton<fapi::OverrideAttributeTank>::instance().
        setAttribute(g_attrOverride);
}

//******************************************************************************
void monitorForFspMessages()
{
    FAPI_IMP("monitorForFspMessages starting");
    
    // Register a message queue with the mailbox
    msg_q_t l_pMsgQ = msg_q_create();
    errlHndl_t l_pErr = MBOX::msgq_register(MBOX::HB_HWPF_ATTR_MSGQ, l_pMsgQ);
    
    if (l_pErr)
    {
        // In the unlikely event that registering fails, the code will commit an
        // error and then wait forever for a message to appear on the queue
        FAPI_ERR("monitorForFspMessages: Error registering msgq with mailbox");
        errlCommit(l_pErr, HWPF_COMP_ID);
    }
    
    while (1)
    {
        msg_t * l_pMsg = msg_wait(l_pMsgQ);
        
        if (l_pMsg->type == MSG_SET_OVERRIDES)
        {
            // FSP is setting attribute override(s).
            FAPI_INF("monitorForFspMessages: MSG_SET_OVERRIDES");
            uint64_t l_size = l_pMsg->data[1];
            Attribute * l_pAttribute =
                reinterpret_cast<Attribute *>(l_pMsg->extra_data);
            
            while (l_size > sizeof(fapi::Attribute))
            {
                Singleton<fapi::OverrideAttributeTank>::instance().
                    setAttribute(*l_pAttribute);
                l_pAttribute++;
                l_size -= sizeof(fapi::Attribute);
            }
            
            // Free the memory
            free(l_pMsg->extra_data);
            l_pMsg->extra_data = NULL;
            l_pMsg->data[1] = 0;
            
            if (msg_is_async(l_pMsg))
            {
                msg_free(l_pMsg);
            }
            else
            {
                // Send the message back as a response
                msg_respond(l_pMsgQ, l_pMsg);
            }
        }
        else if (l_pMsg->type == MSG_CLEAR_ALL_OVERRIDES)
        {
            // FSP is clearing all attribute overrides.
            FAPI_INF("monitorForFspMessages: MSG_CLEAR_ALL_OVERRIDES");
            Singleton<fapi::OverrideAttributeTank>::instance().
                clearAllAttributes();
            
            if (msg_is_async(l_pMsg))
            {
                msg_free(l_pMsg);
            }
            else
            {
                // Send the message back as a response
                msg_respond(l_pMsgQ, l_pMsg);
            }
        }
        else
        {
            FAPI_ERR("monitorForFspMessages: Unrecognized message 0x%x",
                     l_pMsg->type);
        }
    }
}

//******************************************************************************
// Utility function called by sendAttrOverridesAndSyncsToFsp
//******************************************************************************
errlHndl_t sendAttrsToFsp(const MAILBOX_MSG_TYPE i_msgType,
                          std::vector<AttributeChunk> & i_attributes)
{
    errlHndl_t l_pErr = NULL;
    
    // Send Attributes through the mailbox chunk by chunk.
    for (size_t i = 0; i < i_attributes.size(); i++)
    {
        msg_t * l_pMsg = msg_allocate();
        l_pMsg->type = i_msgType;
        l_pMsg->data[0] = 0;
        l_pMsg->data[1] = i_attributes[i].iv_numAttributes * sizeof(Attribute);
        l_pMsg->extra_data = i_attributes[i].iv_pAttributes;
        
        // Send the message and wait for a response, the response message is not
        // read, it just ensures that the code waits until the FSP is done
        // Note: A possible performance boost could be to send only the last
        //       message synchronously to avoid the small delay between each
        //       message
        l_pErr = MBOX::sendrecv(MBOX::FSP_HWPF_ATTR_MSGQ, l_pMsg);
        
        if (l_pErr)
        {
            FAPI_ERR("sendAttrsToFsp: Error sending to FSP");
            msg_free(l_pMsg);
            break;
        }
        
        // Mailbox freed the chunk data
        i_attributes[i].iv_pAttributes = NULL;
        msg_free(l_pMsg);
    }
    
    // Free any memory (only in error case will there be memory to free) and
    // clear the vector of Attribute Chunks
    for (size_t i = 0; i < i_attributes.size(); i++)
    {
        free(i_attributes[i].iv_pAttributes);
        i_attributes[i].iv_pAttributes = NULL;
    }
    i_attributes.clear();
    
    return l_pErr;
}

//******************************************************************************
void sendAttrOverridesAndSyncsToFsp()
{
    if (MBOX::mailbox_enabled())
    {
        // Clear all current FSP Attribute Overrides
        msg_t * l_pMsg = msg_allocate();
        l_pMsg->type = MSG_CLEAR_ALL_OVERRIDES;
        l_pMsg->data[0] = 0;
        l_pMsg->data[1] = 0;
        l_pMsg->extra_data = NULL;

        // Send the message
        errlHndl_t l_pErr = MBOX::send(MBOX::FSP_HWPF_ATTR_MSGQ, l_pMsg);
 
        if (l_pErr)
        {
            FAPI_ERR("SendAttrOverridesToFsp: Error clearing FSP overrides");
            errlCommit(l_pErr, HWPF_COMP_ID);
            msg_free(l_pMsg);
            l_pMsg = NULL;
        }
        else
        {
            l_pMsg = NULL;

            // Send Hostboot Attribute Overrides to the FSP
            std::vector<AttributeChunk> l_attributes;

            Singleton<fapi::OverrideAttributeTank>::instance().
                getAllAttributes(AttributeTank::ALLOC_TYPE_MALLOC,
                                 l_attributes);

            if (l_attributes.size())
            {
                l_pErr = sendAttrsToFsp(MSG_SET_OVERRIDES, l_attributes);

                if (l_pErr)
                {
                    FAPI_ERR("SendAttrOverridesToFsp: Error sending overrides to FSP");
                    errlCommit(l_pErr, HWPF_COMP_ID);
                }
            }

            if (l_pErr == NULL)
            {
                // Send Hostboot Attributes to Sync to the FSP
                std::vector<AttributeChunk> l_attributes;
                
                Singleton<fapi::SyncAttributeTank>::instance().
                    getAllAttributes(AttributeTank::ALLOC_TYPE_MALLOC,
                                     l_attributes);

                if (l_attributes.size())
                {
                    l_pErr = sendAttrsToFsp(MSG_SET_SYNC_ATTS, l_attributes);

                    if (l_pErr)
                    {
                        FAPI_ERR("SendAttrOverridesToFsp: Error sending syncs to FSP");
                        errlCommit(l_pErr, HWPF_COMP_ID);
                    }
                    else
                    {
                        // Clear Hostboot Attributes to Sync
                        Singleton<fapi::SyncAttributeTank>::instance().
                            clearAllAttributes();
                    }
                }
            }
        }
    }
}

//******************************************************************************
AttributeTank & theOverrideAttrTank()
{
    return Singleton<fapi::OverrideAttributeTank>::instance();
}

//******************************************************************************
AttributeTank & theSyncAttrTank()
{
    return Singleton<fapi::SyncAttributeTank>::instance();
}

//******************************************************************************
// This is used as a singleton and contains the lock used to serialize access
// to the OverrideAttributeTank
//******************************************************************************
class OverrideAttributeTankLock
{
public:
    OverrideAttributeTankLock()
    {
        mutex_init(&iv_mutex);
    }

    ~OverrideAttributeTankLock()
    {
        mutex_destroy(&iv_mutex);
    }
    mutex_t iv_mutex;
};

//******************************************************************************
// This is used as a singleton and contains the lock used to serialize access
// to the SyncAttributeTank
//******************************************************************************
class SyncAttributeTankLock
{
public:
    SyncAttributeTankLock()
    {
        mutex_init(&iv_mutex);
    }

    ~SyncAttributeTankLock()
    {
        mutex_destroy(&iv_mutex);
    }
    mutex_t iv_mutex;
};

} // End attrOverrideSync namespace

//******************************************************************************
// This is the Hostboot PLAT implementation of a FAPI function
//******************************************************************************
void OverrideAttributeTank::platLock() const
{
    mutex_lock(&(Singleton<fapi::attrOverrideSync::
        OverrideAttributeTankLock>::instance().iv_mutex));
}

//******************************************************************************
// This is the Hostboot PLAT implementation of a FAPI function
//******************************************************************************
void OverrideAttributeTank::platUnlock() const
{
    mutex_unlock(&(Singleton<fapi::attrOverrideSync::
        OverrideAttributeTankLock>::instance().iv_mutex));
}

//******************************************************************************
// This is the Hostboot PLAT implementation of a FAPI function
//******************************************************************************
void SyncAttributeTank::platLock() const
{
    mutex_lock(&(Singleton<fapi::attrOverrideSync::
        SyncAttributeTankLock>::instance().iv_mutex));
}

//******************************************************************************
// This is the Hostboot PLAT implementation of a FAPI function
//******************************************************************************
void SyncAttributeTank::platUnlock() const
{
    mutex_unlock(&(Singleton<fapi::attrOverrideSync::
        SyncAttributeTankLock>::instance().iv_mutex));
}

//******************************************************************************
// This is the Hostboot PLAT implementation of a FAPI function
//******************************************************************************
bool SyncAttributeTank::platSyncEnabled()
{
    // TODO, RTC 42642. Check for CronusMode, probably using a FAPI Attribute
    // but TBD. If CronusMode is not enabled then there should not be the
    // performance hit of adding written attributes to the SyncAttributeTank
    return false;
}

} // End fapi namespace
