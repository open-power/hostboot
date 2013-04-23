/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatAttrOverrideSync.C $                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <mbox/mboxif.H>
#include <hwpf/plat/fapiPlatAttrOverrideSync.H>
#include <hwpf/plat/fapiPlatTrace.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributeTank.H>

namespace fapi
{

//******************************************************************************
// Global Variables
//******************************************************************************

// Set by a debug tool to directly apply an Attribute Override
TARGETING::AttributeTank::AttributeHeader g_attrOverrideHeader;
uint8_t g_attrOverride[AttrOverrideSync::MAX_DIRECT_OVERRIDE_ATTR_SIZE_BYTES];
uint8_t g_attrOverrideFapiTank = 0;

//******************************************************************************
// Apply a HWPF Attribute Override written directly into Hostboot memory from
// the Simics/VBU console. This function is called by a Simics/VBU debug tool
//******************************************************************************
void directOverride()
{
    // Apply the attribute override
    if (g_attrOverrideFapiTank)
    {
        FAPI_IMP(
            "directOverride: Applying direct attr override to FAPI tank (0x%08x:0x%08x:0x%04x:0x%02x)",
            g_attrOverrideHeader.iv_attrId, g_attrOverrideHeader.iv_targetType,
            g_attrOverrideHeader.iv_pos, g_attrOverrideHeader.iv_unitPos);

        theAttrOverrideSync().iv_overrideTank.setAttribute(
            g_attrOverrideHeader.iv_attrId,
            g_attrOverrideHeader.iv_targetType,
            g_attrOverrideHeader.iv_pos,
            g_attrOverrideHeader.iv_unitPos,
            g_attrOverrideHeader.iv_flags,
            g_attrOverrideHeader.iv_valSize,
            &g_attrOverride);
    }
    else
    {
        // Convert the FAPI targeting type to TARGETING
        TARGETING::TYPE l_targetType = TARGETING::TYPE_SYS;

        switch (g_attrOverrideHeader.iv_targetType)
        {
            case fapi::TARGET_TYPE_DIMM:
                l_targetType = TARGETING::TYPE_DIMM;
                break;
            case fapi::TARGET_TYPE_PROC_CHIP:
                l_targetType = TARGETING::TYPE_PROC;
                break;
            case fapi::TARGET_TYPE_MEMBUF_CHIP:
                l_targetType = TARGETING::TYPE_MEMBUF;
                break;
            case fapi::TARGET_TYPE_EX_CHIPLET:
                l_targetType = TARGETING::TYPE_EX;
                break;
            case fapi::TARGET_TYPE_MBA_CHIPLET:
                l_targetType = TARGETING::TYPE_MBA;
                break;
            case fapi::TARGET_TYPE_MCS_CHIPLET:
                l_targetType = TARGETING::TYPE_MCS;
                break;
            case fapi::TARGET_TYPE_XBUS_ENDPOINT:
                l_targetType = TARGETING::TYPE_XBUS;
                break;
            case fapi::TARGET_TYPE_ABUS_ENDPOINT:
                l_targetType = TARGETING::TYPE_ABUS;
                break;
        }

        FAPI_IMP(
            "directOverride: Applying direct attr override to TARG tank (0x%08x:0x%08x:0x%04x:0x%02x)",
            g_attrOverrideHeader.iv_attrId, l_targetType,
            g_attrOverrideHeader.iv_pos, g_attrOverrideHeader.iv_unitPos);

        TARGETING::Target::theTargOverrideAttrTank().setAttribute(
            g_attrOverrideHeader.iv_attrId,
            l_targetType,
            g_attrOverrideHeader.iv_pos,
            g_attrOverrideHeader.iv_unitPos,
            g_attrOverrideHeader.iv_flags,
            g_attrOverrideHeader.iv_valSize,
            &g_attrOverride);
    }
}

//******************************************************************************
AttrOverrideSync & theAttrOverrideSync()
{
    return Singleton<AttrOverrideSync>::instance();
}

//******************************************************************************
AttrOverrideSync::AttrOverrideSync() {}

//******************************************************************************
AttrOverrideSync::~AttrOverrideSync() {}

//******************************************************************************
void AttrOverrideSync::monitorForFspMessages()
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
            uint64_t l_tank = l_pMsg->data[0];
            TARGETING::AttributeTank::AttributeSerializedChunk l_chunk;
            l_chunk.iv_size = l_pMsg->data[1];
            l_chunk.iv_pAttributes = static_cast<uint8_t *>(l_pMsg->extra_data);

            if (l_tank == TARGETING::AttributeTank::TANK_LAYER_FAPI)
            {
                FAPI_INF(
                    "monitorForFspMessages: MSG_SET_OVERRIDES FAPI (size %lld)",
                    l_pMsg->data[1]);
                iv_overrideTank.deserializeAttributes(l_chunk);
            }
            else
            {
                FAPI_INF(
                    "monitorForFspMessages: MSG_SET_OVERRIDES TARG (size %lld)",
                    l_pMsg->data[1]);
                TARGETING::Target::theTargOverrideAttrTank().
                    deserializeAttributes(l_chunk);
            }

            // Free the memory
            free(l_pMsg->extra_data);
            l_pMsg->extra_data = NULL;
            l_pMsg->data[0] = 0;
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
            iv_overrideTank.clearAllAttributes();
            TARGETING::Target::theTargOverrideAttrTank().clearAllAttributes();

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
errlHndl_t AttrOverrideSync::sendAttrsToFsp(
    const MAILBOX_MSG_TYPE i_msgType,
    const TARGETING::AttributeTank::TankLayer i_tankLayer,
    std::vector<TARGETING::AttributeTank::AttributeSerializedChunk> &
        io_attributes)
{
    errlHndl_t l_pErr = NULL;

    std::vector<TARGETING::AttributeTank::AttributeSerializedChunk>::iterator
        l_itr;

    // Send Attributes through the mailbox chunk by chunk.
    for (l_itr = io_attributes.begin(); l_itr != io_attributes.end(); ++l_itr)
    {
        msg_t * l_pMsg = msg_allocate();
        l_pMsg->type = i_msgType;
        l_pMsg->data[0] = i_tankLayer;
        l_pMsg->data[1] = (*l_itr).iv_size;
        l_pMsg->extra_data = (*l_itr).iv_pAttributes;

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
            l_pMsg = NULL;
            break;
        }

        // Mailbox freed the chunk data
        (*l_itr).iv_pAttributes = NULL;
        msg_free(l_pMsg);
        l_pMsg = NULL;
    }

    // Free any memory (only in error case will there be memory to free) and
    // clear the vector of Attribute Chunks
    for (l_itr = io_attributes.begin(); l_itr != io_attributes.end(); ++l_itr)
    {
        free((*l_itr).iv_pAttributes);
        (*l_itr).iv_pAttributes = NULL;
    }
    io_attributes.clear();

    return l_pErr;
}

//******************************************************************************
void AttrOverrideSync::sendAttrOverridesAndSyncsToFsp()
{
    const uint32_t MAILBOX_CHUNK_SIZE = 4096;

    if (MBOX::mailbox_enabled())
    {
        errlHndl_t l_pErr = NULL;

        // Clear all current FSP Attribute Overrides
        msg_t * l_pMsg = msg_allocate();
        l_pMsg->type = MSG_CLEAR_ALL_OVERRIDES;
        l_pMsg->data[0] = 0;
        l_pMsg->data[1] = 0;
        l_pMsg->extra_data = NULL;

        // Send the message
        l_pErr = MBOX::send(MBOX::FSP_HWPF_ATTR_MSGQ, l_pMsg);

        if (l_pErr)
        {
            FAPI_ERR(
                "sendAttrOverridesAndSyncsToFsp: Error clearing overrides");
            errlCommit(l_pErr, HWPF_COMP_ID);
            msg_free(l_pMsg);
            l_pMsg = NULL;
        }
        else
        {
            l_pMsg = NULL;

            // Send Hostboot Attribute Overrides to the FSP
            for (uint32_t i = TARGETING::AttributeTank::TANK_LAYER_FAPI;
                 i <= TARGETING::AttributeTank::TANK_LAYER_TARG; i++)
            {
                std::vector<TARGETING::AttributeTank::AttributeSerializedChunk>
                    l_attributes;

                if (i == TARGETING::AttributeTank::TANK_LAYER_FAPI)
                {
                    iv_overrideTank.serializeAttributes(
                        TARGETING::AttributeTank::ALLOC_TYPE_MALLOC,
                        MAILBOX_CHUNK_SIZE, l_attributes);
                }
                else
                {
                    TARGETING::Target::theTargOverrideAttrTank().
                        serializeAttributes(
                            TARGETING::AttributeTank::ALLOC_TYPE_MALLOC,
                            MAILBOX_CHUNK_SIZE, l_attributes);
                }

                if (l_attributes.size())
                {
                    l_pErr = sendAttrsToFsp(MSG_SET_OVERRIDES,
                        static_cast<TARGETING::AttributeTank::TankLayer>(i),
                        l_attributes);

                    if (l_pErr)
                    {
                        FAPI_ERR(
                            "sendAttrOverridesAndSyncsToFsp: Error sending overrides (%d)",
                            i);
                        errlCommit(l_pErr, HWPF_COMP_ID);
                        break;
                    }
                }
            }

            // Send Hostboot Attributes to Sync to the FSP
            for (uint32_t i = TARGETING::AttributeTank::TANK_LAYER_FAPI;
                 i <= TARGETING::AttributeTank::TANK_LAYER_TARG; i++)
            {
                std::vector<TARGETING::AttributeTank::AttributeSerializedChunk>
                    l_attributes;

                if (i == TARGETING::AttributeTank::TANK_LAYER_FAPI)
                {
                    iv_syncTank.serializeAttributes(
                        TARGETING::AttributeTank::ALLOC_TYPE_MALLOC,
                        MAILBOX_CHUNK_SIZE, l_attributes);
                }
                else
                {
                    TARGETING::Target::theTargSyncAttrTank().
                        serializeAttributes(
                            TARGETING::AttributeTank::ALLOC_TYPE_MALLOC,
                            MAILBOX_CHUNK_SIZE, l_attributes);
                }

                if (l_attributes.size())
                {
                    l_pErr = sendAttrsToFsp(MSG_SET_SYNC_ATTS,
                        static_cast<TARGETING::AttributeTank::TankLayer>(i),
                        l_attributes);

                    if (l_pErr)
                    {
                        FAPI_ERR(
                            "sendAttrOverridesAndSyncsToFsp: Error sending syncs (%d)",
                            i);
                        errlCommit(l_pErr, HWPF_COMP_ID);
                        break;
                    }
                    else
                    {
                        // Clear Sync tank
                        if (i == TARGETING::AttributeTank::TANK_LAYER_FAPI)
                        {
                            iv_syncTank.clearAllAttributes();
                        }
                        else
                        {
                            TARGETING::Target::theTargSyncAttrTank().
                                clearAllAttributes();
                        }
                    }
                }
            }
        }
    }
}

//******************************************************************************
void AttrOverrideSync::getAttrOverridesFromFsp()
{
    FAPI_IMP("Requesting Attribute Overrides from the FSP");

    errlHndl_t l_pErr = NULL;

    msg_t * l_pMsg = msg_allocate();
    l_pMsg->type = MSG_GET_OVERRIDES;
    l_pMsg->data[0] = 0;
    l_pMsg->data[1] = 0;
    l_pMsg->extra_data = NULL;

    // Send the message and wait for a response, the response message is not
    // read, it just ensures that the code waits until the FSP is done sending
    // attribute overrides
    l_pErr = MBOX::sendrecv(MBOX::FSP_HWPF_ATTR_MSGQ, l_pMsg);

    if (l_pErr)
    {
        FAPI_ERR("getAttrOverridesFromFsp: Error sending to FSP");
        errlCommit(l_pErr, HWPF_COMP_ID);
    }

    msg_free(l_pMsg);
    l_pMsg = NULL;
}

//******************************************************************************
bool AttrOverrideSync::getAttrOverride(const fapi::AttributeId i_attrId,
                                       const fapi::Target * const i_pTarget,
                                       void * o_pVal) const
{
    // Very fast check to see if there are any overrides at all
    if (!(iv_overrideTank.attributesExist()))
    {
        return false;
    }

    // Check to see if there are any overrides for this attr ID
    if (!(iv_overrideTank.attributeExists(i_attrId)))
    {
        return false;
    }

    // Do the work of figuring out the target's type/position and find out
    // if there is an override for this target
    uint32_t l_targetType = getTargetType(i_pTarget);
    uint16_t l_pos = getTargetPos(i_pTarget);
    uint8_t l_unitPos = getTargetUnitPos(i_pTarget);

    bool l_override = iv_overrideTank.getAttribute(i_attrId, l_targetType,
        l_pos, l_unitPos, o_pVal);

    if (l_override)
    {
        FAPI_INF("getAttrOverride: Returning Override for 0x%08x", i_attrId);
    }
    
    return l_override;
}

//******************************************************************************
bool AttrOverrideSync::getAttrOverrideFunc(const fapi::AttributeId i_attrId,
                                           const fapi::Target * const i_pTarget,
                                           void * o_pVal)
{
    return Singleton<AttrOverrideSync>::instance().getAttrOverride(i_attrId,
        i_pTarget, o_pVal);
}


//******************************************************************************
void AttrOverrideSync::setAttrActions(const fapi::AttributeId i_attrId,
                                      const fapi::Target * const i_pTarget,
                                      const uint32_t i_size,
                                      const void * i_pVal)
{
    // Figure out if effort should be expended figuring out the target's type/
    // position in order to clear any non-const attribute overrides and/or to
    // store the attribute for syncing to Cronus

    bool l_clearAnyNonConstOverride = false;

    // Very fast check to see if there are any overrides at all for this Attr ID
    if (iv_overrideTank.attributesExist())
    {
        // Fast check to see if there are any overrides for this attr ID
        if (iv_overrideTank.attributeExists(i_attrId))
        {
            l_clearAnyNonConstOverride = true;
        }
    }

    bool l_syncAttribute = TARGETING::AttributeTank::syncEnabled();

    if (l_clearAnyNonConstOverride || l_syncAttribute)
    {
        uint32_t l_targetType = getTargetType(i_pTarget);
        uint16_t l_pos = getTargetPos(i_pTarget);
        uint8_t l_unitPos = getTargetUnitPos(i_pTarget);

        if (l_clearAnyNonConstOverride)
        {
            // Clear any non const override for this attribute because the
            // attribute is being written
            iv_overrideTank.clearNonConstAttribute(i_attrId, l_targetType,
                l_pos, l_unitPos);
        }

        if (l_syncAttribute)
        {
            // Write the attribute to the SyncAttributeTank to sync to Cronus
            iv_syncTank.setAttribute(i_attrId, l_targetType, l_pos, l_unitPos,
                0, i_size, i_pVal);
        }
    }
}

//******************************************************************************
void AttrOverrideSync::setAttrActionsFunc(const fapi::AttributeId i_attrId,
                                          const fapi::Target * const i_pTarget,
                                          const uint32_t i_size,
                                          const void * i_pVal)
{
    Singleton<AttrOverrideSync>::instance().setAttrActions(i_attrId, i_pTarget,
        i_size, i_pVal);
}


//******************************************************************************
uint32_t AttrOverrideSync::getTargetType(const fapi::Target * const i_pTarget)
{
    uint32_t l_targetType = fapi::TARGET_TYPE_SYSTEM;

    if (i_pTarget != NULL)
    {
        l_targetType = i_pTarget->getType();
    }

    return l_targetType;
}

//******************************************************************************
uint16_t AttrOverrideSync::getTargetPos(const fapi::Target * const i_pTarget)
{
    // Note that an error querying a parent chip is ignored and the function
    // returns ATTR_POS_NA
    uint16_t l_pos = TARGETING::AttributeTank::ATTR_POS_NA;

    if (i_pTarget != NULL)
    {
        // Get the Target pointer
        TARGETING::Target * l_pTarget =
            reinterpret_cast<TARGETING::Target*>(i_pTarget->get());

        if (l_pTarget->getAttr<TARGETING::ATTR_CLASS>() ==
            TARGETING::CLASS_UNIT)
        {
            // Target is a chiplet. The position is the parent chip position
            const TARGETING::Target * l_pChip = getParentChip(l_pTarget);

            if (l_pChip == NULL)
            {
                FAPI_ERR("getParentChip failed to return parent");
            }
            else
            {
                l_pos = l_pChip->getAttr<TARGETING::ATTR_POSITION>();
            }
        }
        else
        {
            // Target is not a chiplet
            l_pos = l_pTarget->getAttr<TARGETING::ATTR_POSITION>();
        }
    }

    return l_pos;
}

//******************************************************************************
uint8_t AttrOverrideSync::getTargetUnitPos(const fapi::Target * const i_pTarget)
{
    uint8_t l_unitPos = TARGETING::AttributeTank::ATTR_UNIT_POS_NA;

    if (i_pTarget != NULL)
    {
        // Get the Target pointer
        TARGETING::Target * l_pTarget =
            reinterpret_cast<TARGETING::Target*>(i_pTarget->get());

        if (l_pTarget->getAttr<TARGETING::ATTR_CLASS>() ==
            TARGETING::CLASS_UNIT)
        {
            l_unitPos = l_pTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();
        }
    }

    return l_unitPos;
}

} // End fapi namespace
