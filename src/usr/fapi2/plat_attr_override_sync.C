/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_attr_override_sync.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#include <plat_utils.H>

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
#ifndef __HOSTBOOT_RUNTIME
    uint32_t l_targetType = TARGETING::TYPE_NA;
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
        // Convert the FAPI targeting type to TARGETING

        switch (g_attrOverrideHeader.iv_targetType)
        {
            case fapi2::TARGET_TYPE_SYSTEM:
                l_targetType = TARGETING::TYPE_SYS;
                break;
            case fapi2::TARGET_TYPE_DIMM:
                l_targetType = TARGETING::TYPE_DIMM;
                break;
            case fapi2::TARGET_TYPE_PROC_CHIP:
                l_targetType = TARGETING::TYPE_PROC;
                break;
            case fapi2::TARGET_TYPE_MEMBUF_CHIP:
                l_targetType = TARGETING::TYPE_MEMBUF;
                break;
            case fapi2::TARGET_TYPE_EX_CHIPLET:
                l_targetType = TARGETING::TYPE_EX;
                break;
            case fapi2::TARGET_TYPE_MBA_CHIPLET:
                l_targetType = TARGETING::TYPE_MBA;
                break;
            case fapi2::TARGET_TYPE_MCS_CHIPLET:
                l_targetType = TARGETING::TYPE_MCS;
                break;
            case fapi2::TARGET_TYPE_XBUS_ENDPOINT:
                l_targetType = TARGETING::TYPE_XBUS;
                break;
            case fapi2::TARGET_TYPE_ABUS_ENDPOINT:
                l_targetType = TARGETING::TYPE_ABUS;
                break;
            case fapi2::TARGET_TYPE_L4:
                l_targetType = TARGETING::TYPE_L4;
                break;
            case fapi2::TARGET_TYPE_CORE:
                l_targetType = TARGETING::TYPE_CORE;
                break;
            case fapi2::TARGET_TYPE_EQ:
                l_targetType = TARGETING::TYPE_EQ;
                break;
            case fapi2::TARGET_TYPE_MCA:
                l_targetType = TARGETING::TYPE_MCA;
                break;
            case fapi2::TARGET_TYPE_MCBIST:
                l_targetType = TARGETING::TYPE_MCBIST;
                break;
            case fapi2::TARGET_TYPE_CAPP:
                l_targetType = TARGETING::TYPE_CAPP;
                break;
            case fapi2::TARGET_TYPE_DMI:
                l_targetType = TARGETING::TYPE_DMI;
                break;
            case fapi2::TARGET_TYPE_OBUS:
                l_targetType = TARGETING::TYPE_OBUS;
                break;
            case fapi2::TARGET_TYPE_OBUS_BRICK:
                l_targetType = TARGETING::TYPE_OBUS_BRICK;
                break;
            case fapi2::TARGET_TYPE_SBE:
                l_targetType = TARGETING::TYPE_SBE;
                break;
            case fapi2::TARGET_TYPE_PPE:
                l_targetType = TARGETING::TYPE_PPE;
                break;
            case fapi2::TARGET_TYPE_PERV:
                l_targetType = TARGETING::TYPE_PERV;
                break;
            case fapi2::TARGET_TYPE_PEC:
                l_targetType = TARGETING::TYPE_PEC;
                break;
            case fapi2::TARGET_TYPE_PHB:
                l_targetType = TARGETING::TYPE_PHB;
                break;
            default:
                l_targetType = TARGETING::TYPE_NA;
        }

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

            if (l_chunk.iv_pAttributes == NULL)
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
    errlHndl_t l_pErr = NULL;

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

    //Let the tool know we are finished syncing with magic address
    Util::writeDebugCommRegs(Util::MSG_TYPE_ATTRDUMP,
                             0xFFFFCAFE, 0);

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

    // Do the work of figuring out the target's type/position/node and find out
    // if there is an override for this target
    uint32_t l_targetType = getTargetType(i_pTarget);

    // Get the Target pointer
    TARGETING::Target * l_pTarget =
        reinterpret_cast<TARGETING::Target*>(i_pTarget->get());
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
        TARGETING::Target * l_pTarget =
            reinterpret_cast<TARGETING::Target*>(i_pTarget->get());
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
void AttrOverrideSync::triggerAttrSync()
{
    uint8_t * l_buf = NULL;

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

        //skip if not functional
        if(l_pTarget->getAttr<TARGETING::ATTR_HWAS_STATE>().functional
           != true)
        {
            continue;
        }

        TARGETING::EntityPath phys_path_ptr =
          l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>();
        FAPI_INF("triggerAttrSync: HUID 0x%X, fapi type[%x] [%s]",
                 TARGETING::get_huid(l_pTarget), l_fType,
                 phys_path_ptr.toString());

        //Need a generic fapi target to use later
        fapi2::Target<TARGET_TYPE_ALL> l_fapiTarget( l_pTarget);

        //Determine the target location info
        uint16_t l_pos = 0;
        uint8_t l_unitPos = 0;
        uint8_t l_node = 0;
        l_pTarget->getAttrTankTargetPosData(l_pos, l_unitPos, l_node);

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
                         l_bytes);
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
                iv_syncTank.setAttribute(l_attrs[i].iv_attrId, l_fType,
                                         l_pos, l_unitPos, l_node, 0,
                                         l_bytes, l_buf);
            }
            else
            {
                delete l_pErr; //Debug tool, ignore errors
            }
        }
    }

    free(l_buf);

    //Now push the data to the debug tool
    sendFapiAttrSyncs();
}

//******************************************************************************
void AttrOverrideSync::clearAttrOverrides()
{
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
#ifndef __HOSTBOOT_RUNTIME
    errlHndl_t err = NULL;
    int64_t rc = 0;

    do
    {
        // Create a memory block to serve as Debug Comm channel
        // NOTE: using mm_alloc_block since this code is running before we
        // have mainstore and we must have contiguous blocks of memory for
        // Cronus putmempba
        rc = mm_alloc_block( NULL,
                             reinterpret_cast<void*>
                             (VMM_VADDR_DEBUG_COMM),
                             VMM_DEBUG_COMM_SIZE);
        if(rc == -EALREADY)
        {
            //-EALREADY inidciates the block is already mapped -- ignore
            rc = 0;
        }

        if( rc )
        {
            // This is a debug interface, just emit trace and exit
            FAPI_ERR("dynSetAttrOverrides() - "
                     "Error from mm_alloc_block : rc=%d", rc );
            break;
        }

        rc = mm_set_permission(reinterpret_cast<void*>
                               (VMM_VADDR_DEBUG_COMM),
                               VMM_DEBUG_COMM_SIZE,
                               WRITABLE | ALLOCATE_FROM_ZERO);
        if( rc )
        {
            // This is a debug interface, just emit trace and exit
            FAPI_ERR("dynSetAttrOverrides() - "
                     "Error from mm_set_permission : rc=%d", rc );
            break;
        }

        //Now masquerade this at the ATTR_TMP PNOR section so the underlying
        //ATTR override and bin file can be used as is
        PNOR::SectionInfo_t l_sectionInfo;
        l_sectionInfo.id = PNOR::ATTR_TMP;
        l_sectionInfo.name = "ATTR_TMP";
        l_sectionInfo.vaddr = VMM_VADDR_DEBUG_COMM;
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
        memset (reinterpret_cast<void*>(VMM_VADDR_DEBUG_COMM), 0xFF,
                VMM_DEBUG_COMM_SIZE);
        uint64_t l_addr =
          mm_virt_to_phys(reinterpret_cast<void*>(VMM_VADDR_DEBUG_COMM));
        FAPI_INF("virt[%llx] phys[%llx]", VMM_VADDR_DEBUG_COMM, l_addr);
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

    // Attempt to clean up after ourselves.  Ignore errors on cleanup
    // path in debug interface
    //release all pages in page block
    rc = mm_remove_pages(RELEASE, reinterpret_cast<void*>(VMM_VADDR_DEBUG_COMM),
                         VMM_DEBUG_COMM_SIZE);
    rc = mm_set_permission(reinterpret_cast<void*>(VMM_VADDR_DEBUG_COMM),
                           VMM_DEBUG_COMM_SIZE, NO_ACCESS | ALLOCATE_FROM_ZERO);
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
