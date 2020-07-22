/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_attr_override_sync.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 *  @file plat_attr_override_sync.C
 *
 *  @brief Implements the functions for Attribute Override and Sync
 *
 */

//******************************************************************************
// Includes
//******************************************************************************
#include <sys/msg.h>
#include <limits.h>
#include <string.h>
#include <vector>
#include <sys/msg.h>
#include <sys/mm.h>
#include <errno.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <mbox/mboxif.H>
#include <plat_attr_override_sync.H>
#include <fapiPlatTrace.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributeTank.H>
#include <fapi2AttrSyncData.H>
#include <fapi2_attribute_service.H>
#include <util/utilmbox_scratch.H>
#include <fapi2/plat_utils.H>
#include <secureboot/service.H>

namespace fapi2
{

//******************************************************************************
// Global Variables
//******************************************************************************

#ifndef __HOSTBOOT_RUNTIME
// Set by a debug tool to directly apply an Attribute Override
TARGETING::AttributeTank::AttributeHeader g_attrOverrideHeader;
uint8_t g_attrOverride[AttrOverrideSync::MAX_DIRECT_OVERRIDE_ATTR_SIZE_BYTES];
uint8_t g_attrOverrideFapiTank = 0;
#endif

//******************************************************************************
// Apply a HWPF Attribute Override written directly into Hostboot memory from
// the Simics/VBU console. This function is called by a Simics/VBU debug tool
//******************************************************************************
void directOverride()
{
    if (!SECUREBOOT::allowAttrOverrides())
    {
        FAPI_INF("directOverride: skipping since "
                 "attribute overrides are not allowed");
        return;
    }

#ifndef __HOSTBOOT_RUNTIME
    // Apply the attribute override
    if (g_attrOverrideFapiTank)
    {
        FAPI_IMP("directOverride: Applying override to FAPI tank "
            "Id: 0x%08x, TargType: 0x%08x, Pos: 0x%04x, UPos: 0x%02x",
            g_attrOverrideHeader.iv_attrId, g_attrOverrideHeader.iv_targetType,
            g_attrOverrideHeader.iv_pos, g_attrOverrideHeader.iv_unitPos);
        FAPI_IMP("directOverride: Applying override to FAPI tank "
            "Node: 0x%02x, Flags: 0x%02x, Size: 0x%08x",
            g_attrOverrideHeader.iv_node, g_attrOverrideHeader.iv_flags,
            g_attrOverrideHeader.iv_valSize);

        theAttrOverrideSync().iv_overrideTank.setAttribute(
            g_attrOverrideHeader.iv_attrId,
            g_attrOverrideHeader.iv_targetType,
            g_attrOverrideHeader.iv_pos,
            g_attrOverrideHeader.iv_unitPos,
            g_attrOverrideHeader.iv_node,
            g_attrOverrideHeader.iv_flags,
            g_attrOverrideHeader.iv_valSize,
            &g_attrOverride);
    }
    else
    {
        const TargetType l_fapiTargetType
            = static_cast<TargetType>(g_attrOverrideHeader.iv_targetType);
        const TARGETING::TYPE l_targetType
            = convertFapi2TypeToTargeting(l_fapiTargetType);

        FAPI_IMP("directOverride: Applying override to TARG tank "
            "Id: 0x%08x, TargType: 0x%08x, Pos: 0x%04x, UPos: 0x%02x",
            g_attrOverrideHeader.iv_attrId, l_targetType,
            g_attrOverrideHeader.iv_pos, g_attrOverrideHeader.iv_unitPos);
        FAPI_IMP("directOverride: Applying override to TARG tank "
            "Node: 0x%02x, Flags: 0x%02x, Size: 0x%08x",
            g_attrOverrideHeader.iv_node, g_attrOverrideHeader.iv_flags,
            g_attrOverrideHeader.iv_valSize);

        TARGETING::Target::theTargOverrideAttrTank().setAttribute(
            g_attrOverrideHeader.iv_attrId,
            l_targetType,
            g_attrOverrideHeader.iv_pos,
            g_attrOverrideHeader.iv_unitPos,
            g_attrOverrideHeader.iv_node,
            g_attrOverrideHeader.iv_flags,
            g_attrOverrideHeader.iv_valSize,
            &g_attrOverride);
    }
#endif
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
#ifndef __HOSTBOOT_RUNTIME
    FAPI_IMP("monitorForFspMessages starting");

    // Register a message queue with the mailbox
    msg_q_t l_pMsgQ = msg_q_create();
    errlHndl_t l_pErr = MBOX::msgq_register(MBOX::HB_HWPF_ATTR_MSGQ, l_pMsgQ);

    // Find out if attributes override has been attempted
    TARGETING::Target* l_pSys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_pSys);
    // Assert that l_pSys is no longer nullptr
    assert(l_pSys != nullptr, "AttrOverrideSync::monitorForFspMessages() "
           "expected top level target, but got nullptr.");

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

            if (SECUREBOOT::allowAttrOverrides() == false)
            {
                FAPI_ERR("monitorForFspMessages: Ignoring Set Overrides "
                         "Message (0x%X) from FSP since attribute overrides "
                         "are not allowed",
                         l_pMsg->type);

                // Checking if OVERRIDES_ATTEMPTED_FLAG has not been set to 1.
                // If so, then this is the first time attributes override is
                // attempted in an FSP, while in secure mode; in this case, log
                // an error stating that attributes override was attempted.
                if (!l_pSys->
                        getAttr<TARGETING::ATTR_OVERRIDES_ATTEMPTED_FLAG>())
                {
                    /*@
                     * @errortype
                     * @reasoncode       RC_ATTR_OVERRIDE_DISALLOWED
                     * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
                     * @moduleid         MOD_FAPI2_MONITOR_FOR_FSP_MSGS
                     * @devdesc          Attribute overrides were rejected
                     *                   because system is in secure mode
                     * @custdesc         Action not allowed in secure mode
                     */
                    l_pErr = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            MOD_FAPI2_MONITOR_FOR_FSP_MSGS,
                            RC_ATTR_OVERRIDE_DISALLOWED);
                    l_pErr->collectTrace(SECURE_COMP_NAME);
                    SECUREBOOT::addSecureUserDetailsToErrlog(l_pErr);
                    errlCommit(l_pErr, HWPF_COMP_ID);
                    l_pSys->
                        setAttr<TARGETING::ATTR_OVERRIDES_ATTEMPTED_FLAG>(true);
                }
            }
            else if (l_chunk.iv_pAttributes == NULL)
            {
                FAPI_ERR("monitorForFspMessages: tank %d, size %d, NULL data pointer",
                         l_tank, l_chunk.iv_size);
            }
            else if (l_tank == TARGETING::AttributeTank::TANK_LAYER_FAPI)
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
            free(l_pMsg->extra_data);
            l_pMsg->extra_data = NULL;
            msg_free(l_pMsg);
        }
    }
#endif
}

//******************************************************************************
errlHndl_t AttrOverrideSync::sendAttrsToFsp(
    const MAILBOX_MSG_TYPE i_msgType,
    const TARGETING::AttributeTank::TankLayer i_tankLayer,
    std::vector<TARGETING::AttributeTank::AttributeSerializedChunk> &
        io_attributes)
{
    errlHndl_t l_pErr = nullptr;

#ifndef __HOSTBOOT_RUNTIME
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

            // If mailbox nullified the extra_data, that indicates it assumed
            // ownership of (and responsibility to free) the chunk data.
            if(l_pMsg->extra_data == nullptr)
            {
                (*l_itr).iv_pAttributes = nullptr;
            }
            msg_free(l_pMsg);
            l_pMsg = nullptr;
            break;
        }

        // On success, assume that mailbox freed the chunk data
        (*l_itr).iv_pAttributes = nullptr;
        msg_free(l_pMsg);
        l_pMsg = nullptr;
    }

    // Free any memory (only in error case will there be memory to free) and
    // clear the vector of Attribute Chunks
    for (l_itr = io_attributes.begin(); l_itr != io_attributes.end(); ++l_itr)
    {
        free((*l_itr).iv_pAttributes);
        (*l_itr).iv_pAttributes = nullptr;
    }
    io_attributes.clear();
#endif

    return l_pErr;
}

//******************************************************************************
void AttrOverrideSync::sendAttrOverridesAndSyncsToFsp()
{

#ifndef __HOSTBOOT_RUNTIME
    const uint32_t MAILBOX_CHUNK_SIZE = 4096;

    if (MBOX::mailbox_enabled())
    {
        errlHndl_t l_pErr = NULL;

        // Non-const overrides may have been cleared by being written to.
        // Therefore, clear the FSP Attribute Overrides for this node and
        // send the current set of overrides to the FSP for this node

        // Clear all current FSP Attribute Overrides for this node
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

                // Note that NODE_FILTER_NOT_ALL_NODES retrieves all overrides
                // that are not for all nodes - i.e. overrides for this node.
                // The FSP already has all overrides for all nodes.
                if (i == TARGETING::AttributeTank::TANK_LAYER_FAPI)
                {
                    iv_overrideTank.serializeAttributes(
                        TARGETING::AttributeTank::ALLOC_TYPE_MALLOC,
                        MAILBOX_CHUNK_SIZE, l_attributes,
                        TARGETING::AttributeTank::NODE_FILTER_NOT_ALL_NODES);
                }
                else
                {
                    TARGETING::Target::theTargOverrideAttrTank().
                        serializeAttributes(
                            TARGETING::AttributeTank::ALLOC_TYPE_MALLOC,
                            MAILBOX_CHUNK_SIZE, l_attributes,
                            TARGETING::AttributeTank::
                                NODE_FILTER_NOT_ALL_NODES);
                }

                if (l_attributes.size())
                {
                    l_pErr = sendAttrsToFsp(MSG_SET_OVERRIDES,
                        static_cast<TARGETING::AttributeTank::TankLayer>(i),
                        l_attributes);

                    if (l_pErr)
                    {
                        FAPI_ERR("sendAttrOverridesAndSyncsToFsp: Error sending overrides (%d)", i);
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
                        FAPI_ERR("sendAttrOverridesAndSyncsToFsp: Error sending syncs (%d)", i);
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
#endif
}

//******************************************************************************
void AttrOverrideSync::sendFapiAttrSyncs()
{

#ifndef __HOSTBOOT_RUNTIME
    const uint32_t MAILBOX_CHUNK_SIZE = 4096;

    // Send Hostboot Attributes to Sync to the debug channel
    std::vector<TARGETING::AttributeTank::AttributeSerializedChunk>
      l_attributes;

    iv_syncTank.serializeAttributes(
                                    TARGETING::AttributeTank::ALLOC_TYPE_MALLOC,
                                    MAILBOX_CHUNK_SIZE, l_attributes);

    // Send Attributes through the mailbox chunk by chunk.
    std::vector<TARGETING::AttributeTank::AttributeSerializedChunk>::iterator
        l_itr;
    for (l_itr = l_attributes.begin(); l_itr != l_attributes.end(); ++l_itr)
    {
        // Send the message and wait for tool to recieve
        // address to go to zero (means that Cronus/debug framework has
        // consumed
        uint64_t l_addr = reinterpret_cast<uint64_t>((*l_itr).iv_pAttributes);
        Util::writeDebugCommRegs(Util::MSG_TYPE_ATTRDUMP,
                                 l_addr,
                                 (*l_itr).iv_size);

        // Freed the chunk data
        free((*l_itr).iv_pAttributes);
        (*l_itr).iv_pAttributes = NULL;

    }

    // Clear Sync tank
    l_attributes.clear();
    iv_syncTank.clearAllAttributes();

#endif
}

//******************************************************************************
void AttrOverrideSync::getAttrOverridesFromFsp()
{
#ifndef __HOSTBOOT_RUNTIME
    FAPI_IMP("Requesting Attribute Overrides from the FSP");
    errlHndl_t l_pErr = NULL;

    if (!SECUREBOOT::allowAttrOverrides())
    {
        FAPI_INF("AttrOverrideSync::getAttrOverridesFromFsp: skipping "
                 "since attribute overrides are not allowed");
        return;
    }

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
#endif
}

//******************************************************************************
bool AttrOverrideSync::getAttrOverride(const AttributeId i_attrId,
                                const Target<TARGET_TYPE_ALL>* const i_pTarget,
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

    // This check after previous two for performance reasons
    if (!SECUREBOOT::allowAttrOverrides())
    {
        FAPI_INF("AttrOverrideSync::getAttrOverride: skipping "
                 "since attribute overrides are not allowed");
        return false;
    }

    // Do the work of figuring out the target's type/position/node and find out
    // if there is an override for this target
    uint32_t l_targetType = getTargetType(i_pTarget);

    // Get the Target pointer
    TARGETING::Target * l_pTarget = i_pTarget->get();
    uint16_t l_pos = 0;
    uint8_t l_unitPos = 0;
    uint8_t l_node = 0;
    l_pTarget->getAttrTankTargetPosData(l_pos, l_unitPos, l_node);

    FAPI_INF("getAttrOverride: Checking for override for ID: 0x%08x, "
             "TargType: 0x%08x, Pos/Upos/Node: 0x%08x",
             i_attrId, l_targetType,
             (static_cast<uint32_t>(l_pos) << 16) +
             (static_cast<uint32_t>(l_unitPos) << 8) + l_node);

    bool l_override = iv_overrideTank.getAttribute(i_attrId, l_targetType,
        l_pos, l_unitPos, l_node, o_pVal);

    if (l_override)
    {
        FAPI_INF("getAttrOverride: Returning Override for ID: 0x%08x",
                 i_attrId);
    }

    return l_override;
}

//******************************************************************************
bool AttrOverrideSync::getAttrOverrideFunc(const AttributeId i_attrId,
                             const Target<TARGET_TYPE_ALL>& i_pTarget,
                             void * o_pVal)
{

    return Singleton<AttrOverrideSync>::instance().getAttrOverride(i_attrId,
        &i_pTarget, o_pVal);
}

//******************************************************************************
void AttrOverrideSync::setAttrActions(const AttributeId i_attrId,
                                      const Target<TARGET_TYPE_ALL>* i_pTarget,
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

        // Get the Target pointer
        TARGETING::Target * l_pTarget = i_pTarget->get();
        uint16_t l_pos = 0;
        uint8_t l_unitPos = 0;
        uint8_t l_node = 0;
        l_pTarget->getAttrTankTargetPosData(l_pos, l_unitPos, l_node);

        if (l_clearAnyNonConstOverride)
        {
            // Clear any non const override for this attribute because the
            // attribute is being written
            iv_overrideTank.clearNonConstAttribute(i_attrId, l_targetType,
                l_pos, l_unitPos, l_node);
        }

        if (l_syncAttribute)
        {
            // Write the attribute to the SyncAttributeTank to sync to Cronus
            iv_syncTank.setAttribute(i_attrId, l_targetType, l_pos, l_unitPos,
                l_node, 0, i_size, i_pVal);
        }
    }
}

//******************************************************************************
void AttrOverrideSync::triggerAttrSync(fapi2::TargetType i_type,
                                       uint32_t i_fapiPos, uint32_t i_attrHash)
{
    uint8_t * l_buf = NULL;
    uint64_t l_totalBytes = 0;

    uint32_t l_targetCount = 0;
    iv_syncTank.clearAllAttributes();

    //Walk through all HB targets and see if there is a matching FAPI target
    //If so then get the list of ATTR for FAPI target and add to sync list
    for (TARGETING::TargetIterator target = TARGETING::targetService().begin();
         target != TARGETING::targetService().end();
         ++target)
    {
        // Get the Target pointer
        TARGETING::Target * l_pTarget = *target;

        //Get FAPI target
        TARGETING::TYPE l_type = l_pTarget->getAttr<TARGETING::ATTR_TYPE>();
        fapi2::TargetType l_fType = convertTargetingTypeToFapi2(l_type);

        if(l_fType == fapi2::TARGET_TYPE_NONE)
        {
            continue; //not a FAPI2 target -- skip to next target
        }

        //Check to see if looking for a specific type/fapi_pos
        if(i_type != fapi2::TARGET_TYPE_NONE)
        {
            if (i_type != l_fType) // types don't match, skip
            {
                continue;
            }

            //Now look for specific pos (if set)
            if((i_fapiPos != TARGETING::FAPI_POS_NA) && // specific pos
               (i_fapiPos != l_pTarget->getAttr<TARGETING::ATTR_FAPI_POS>()))
            {
                continue;
            }
        }

        //skip if not functional
        if(l_pTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional
           != true)
        {
            continue;
        }

        TARGETING::EntityPath phys_path_ptr =
          l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();
        uint32_t l_fTypeBitPos = 0x0; //default to TARGET_TYPE_NONE
        for(uint32_t i=0; i < 64 /*bits per dword*/; i++)
        {
            if (l_fType & (0x0000000000000001ULL << i))
            {
               l_fTypeBitPos = i;
               break;
            }
        }
        //Need a generic fapi target to use later
        fapi2::Target<TARGET_TYPE_ALL> l_fapiTarget( l_pTarget);

        //Determine the target location info
        uint16_t l_pos = 0;
        uint8_t l_unitPos = 0;
        uint8_t l_node = 0;
        l_pTarget->getAttrTankTargetPosData(l_pos, l_unitPos, l_node);

        char * l_physString = phys_path_ptr.toString();
        FAPI_INF("triggerAttrSync: HUID 0x%X, type num[%d] fapi type[%llx] [%s], [n%d:p%d:c%d]",
                 TARGETING::get_huid(l_pTarget), l_fTypeBitPos, l_fType,
                 l_physString, l_node, l_pos, l_unitPos);
        free (l_physString);

        //Loop on all fapi ATTR under this target type
        size_t l_elems = 0;
        const AttributeSyncInfo * l_attrs =
                            get_fapi_target_attr_array(l_fType, l_elems);

        //If NULL, nothing there to sync
        if(!l_attrs)
        {
            continue;
        }

        for(size_t i = 0; i < l_elems; i++)
        {
            //#@TODO RTC: 182602 -- Need to scrub through attributes for dimm target
            //For now, just skipping over BAD_DQ_BITMAP as it does not have a valid
            //lookup for cumulus
            //Look for specific ATTR
            if(((i_attrHash!= 0x0) &&  //looking for specific ATTR
               (i_attrHash != l_attrs[i].iv_attrId)) ||
               (l_attrs[i].iv_attrId == fapi2::ATTR_BAD_DQ_BITMAP))
            {
                continue;
            }

            // Write the attribute to the SyncAttributeTank to sync to Cronus
            size_t l_bytes =
              l_attrs[i].iv_attrElemSizeBytes * l_attrs[i].iv_dims[0] *
              l_attrs[i].iv_dims[1] * l_attrs[i].iv_dims[2] *
              l_attrs[i].iv_dims[3];

            //Get the data -- limit this to ATTR less than 1K in size
            //otherwise can cause memory fragmentation in cache contained HB.
            //Specifically this is to weed out the WOF_TABLE_DATA (128K)
            if(l_bytes > KILOBYTE)
            {
                FAPI_INF("triggerAttrSync: ATTR %x bigger [%x] than 1K... skipping",
                         l_attrs[i].iv_attrId, l_bytes);
                continue;
            }

            l_buf = reinterpret_cast<uint8_t *>(realloc(l_buf, l_bytes));
            ReturnCode l_rc =
              rawAccessAttr(
                        static_cast<fapi2::AttributeId>(l_attrs[i].iv_attrId),
                        l_fapiTarget, &l_buf[0]);

            // Write the attribute to the SyncAttributeTank to sync to Cronus
            errlHndl_t l_pErr = fapi2::rcToErrl(l_rc);
            if(!l_pErr)
            {
                iv_syncTank.setAttribute(l_attrs[i].iv_attrId, l_fTypeBitPos,
                                         l_pos, l_unitPos, l_node, 0,
                                         l_bytes, l_buf);
            }
            else
            {
                delete l_pErr; //Debug tool, ignore errors
            }

            l_targetCount++;
            l_totalBytes += l_bytes;
        }

        // Done with this target, release l_buf
        free(l_buf);
        l_buf = NULL;

        // Push the target attributes to debug tool
        sendFapiAttrSyncs();
    }

#ifndef __HOSTBOOT_RUNTIME
    //Let the tool know we are finished syncing with magic address
    Util::writeDebugCommRegs(Util::MSG_TYPE_ATTRDUMP,
                             0xFFFFCAFE, 0);
#endif

    FAPI_INF("triggerAttrSync - Finished sending all target attributes. "
             "Total targets %d, Total bytes %d", l_targetCount, l_totalBytes);
}

//******************************************************************************
void AttrOverrideSync::clearAttrOverrides()
{
    if (!SECUREBOOT::allowAttrOverrides())
    {
        FAPI_INF("AttrOverrideSync::clearAttrOverrides: skipping clear calls"
                 "since attribute overrides are not allowed");
        return;
    }
#ifndef __HOSTBOOT_RUNTIME
    // Debug Channel is clearing all attribute overrides.
    FAPI_INF("Debug Channel CLEAR_ALL_OVERRIDES");
    iv_overrideTank.clearAllAttributes();
    TARGETING::Target::theTargOverrideAttrTank().clearAllAttributes();
#endif
}

//******************************************************************************
void AttrOverrideSync::dynSetAttrOverrides()
{
    if (!SECUREBOOT::allowAttrOverrides())
    {
        FAPI_INF("AttrOverrideSync::dynSetAttrOverrides: skipping since "
                "attribute overrides are not allowed");
        return;
    }

#ifndef __HOSTBOOT_RUNTIME
    errlHndl_t err = nullptr;
    void * l_vaddr = nullptr;

    do
    {
        // Allocate a contiguous block of memory -- can just use malloc for
        // this because Cronus will use putmempba to load
        l_vaddr = malloc(VMM_DEBUG_COMM_SIZE);


        //Now masquerade this at the ATTR_TMP PNOR section so the underlying
        //ATTR override and bin file can be used as is
        PNOR::SectionInfo_t l_sectionInfo;
        l_sectionInfo.id = PNOR::ATTR_TMP;
        l_sectionInfo.name = "ATTR_TMP";
        l_sectionInfo.vaddr = reinterpret_cast<uint64_t>(l_vaddr);
        l_sectionInfo.flashAddr = 0xFFFFFFFF; //Not used
        l_sectionInfo.size = VMM_DEBUG_COMM_SIZE;
        l_sectionInfo.eccProtected = false;
        l_sectionInfo.sha512Version = false;
        l_sectionInfo.sha512perEC = false;
        l_sectionInfo.readOnly = true;
        l_sectionInfo.reprovision = false;
        l_sectionInfo.secure = false;


        //Send debug message to tool to update memory
        //Must clear data to actually alloction phys pages
        memset (l_vaddr, 0xFF, VMM_DEBUG_COMM_SIZE);
        uint64_t l_addr = mm_virt_to_phys(l_vaddr);
        FAPI_INF("virt[%p] phys[%llx]", l_vaddr, l_addr);
        Util::writeDebugCommRegs(Util::MSG_TYPE_ATTROVERRIDE,
                                 l_addr,
                                 VMM_DEBUG_COMM_SIZE);


        FAPI_INF("init: processing dynamic overrides");
        err = TARGETING::getAttrOverrides(l_sectionInfo, NULL);
        if (err)
        {
            FAPI_ERR("Failed getAttrOverrides from dyanmic set");
            errlCommit(err, HWPF_COMP_ID);
            break;
        }
    }while(0);

    // Attempt to clean up after ourselves
    free(l_vaddr);
    l_vaddr = nullptr;
#endif
}

//******************************************************************************
void AttrOverrideSync::dynAttrGet()
{
#ifndef __HOSTBOOT_RUNTIME
    void * l_vaddr = nullptr;

    do
    {
        // Create a memory block to serve as Debug Comm channel
        // Allocate a contiguous block of memory -- can just use malloc for
        // this because Cronus will use putmempba to load
        l_vaddr = malloc(VMM_DEBUG_COMM_SIZE);

        //Send debug message to tool to update memory
        //Must clear data to actually alloction phys pages
        memset (l_vaddr, 0xFF, VMM_DEBUG_COMM_SIZE);
        uint64_t l_addr = mm_virt_to_phys(l_vaddr);
        FAPI_INF("virt[%p] phys[%llx]", l_vaddr, l_addr);
        Util::writeDebugCommRegs(Util::MSG_TYPE_ATTRGET,
                                 l_addr,
                                 VMM_DEBUG_COMM_SIZE);

        uint32_t * l_targInfo =
          reinterpret_cast<uint32_t*>(l_vaddr);

        FAPI_INF("init: processing dynamic ATTR get");
        triggerAttrSync(static_cast<fapi2::TargetType>(
                          l_targInfo[Util::DEBUG_ATTRGET_FAPI_TYPE]),
                        l_targInfo[Util::DEBUG_ATTRGET_FAPI_POS],
                        l_targInfo[Util::DEBUG_ATTRGET_HASH]);
    }while(0);

    // Attempt to clean up after ourselves.
    free(l_vaddr);
    l_vaddr = nullptr;
#endif
}


//******************************************************************************
void AttrOverrideSync::setAttrActionsFunc(const AttributeId i_attrId,
                                      const Target<TARGET_TYPE_ALL>& i_pTarget,
                                          const uint32_t i_size,
                                          const void * i_pVal)
{
    Singleton<AttrOverrideSync>::instance().setAttrActions(i_attrId, &i_pTarget,
        i_size, i_pVal);
}


//******************************************************************************
uint32_t AttrOverrideSync::getTargetType(
                                      const Target<TARGET_TYPE_ALL>* i_pTarget)
{
    uint32_t l_targetType = fapi2::TARGET_TYPE_SYSTEM;

    if (i_pTarget != NULL)
    {
        l_targetType = i_pTarget->getType();
    }

    return l_targetType;
}

} // End fapi namespace
