/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/attributeTank.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
 *  @file attributeTank.C
 *
 *  @brief Implements the AttributeTank and associated classes.
 */
#include <stdlib.h>
#include <string.h>
#include <targeting/common/attributeTank.H>
#include <targeting/common/trace.H>

namespace TARGETING
{

//******************************************************************************
AttributeTank::AttributeHeader::AttributeHeader() :
    iv_attrId(0), iv_targetType(0), iv_pos(0), iv_unitPos(0), iv_node(0),
    iv_flags(0), iv_valSize(0)
{

}

//******************************************************************************
AttributeTank::AttributeSerializedChunk::AttributeSerializedChunk() :
    iv_size(0), iv_pAttributes(NULL)
{

}

//******************************************************************************
AttributeTank::AttributeTank() :
    iv_attributesExist(false)
{
    TARG_MUTEX_INIT(iv_mutex);
}

//******************************************************************************
AttributeTank::~AttributeTank()
{
    for (AttributesItr_t l_itr = iv_attributes.begin();
         l_itr != iv_attributes.end(); ++l_itr)
    {
        delete (*l_itr);
        (*l_itr) = NULL;
    }

    TARG_MUTEX_DESTROY(iv_mutex);
}

//******************************************************************************
bool AttributeTank::syncEnabled()
{
    // TODO, RTC 42642. Check for CronusMode, probably using an attribute
    // but TBD. If CronusMode is not enabled then there should not be the
    // performance hit of adding written attributes to a SyncAttributeTank
    return false;
}

//******************************************************************************
void AttributeTank::clearAllAttributes(
    const NodeFilter i_nodeFilter,
    const uint8_t i_node)
{
    TARG_MUTEX_LOCK(iv_mutex);

    AttributesItr_t l_itr = iv_attributes.begin();

    while (l_itr != iv_attributes.end())
    {
        if (i_nodeFilter == NODE_FILTER_NOT_ALL_NODES)
        {
            // Only clear attributes that are not for all nodes
            if ((*l_itr)->iv_hdr.iv_node == ATTR_NODE_NA)
            {
                l_itr++;
                continue;
            }
        }
        else if (i_nodeFilter == NODE_FILTER_SPECIFIC_NODE_AND_ALL)
        {
            // Only clear attributes associated with i_node or all
            if ( ((*l_itr)->iv_hdr.iv_node != ATTR_NODE_NA) &&
                 ((*l_itr)->iv_hdr.iv_node != i_node) )
            {
                l_itr++;
                continue;
            }
        }
        else if (i_nodeFilter == NODE_FILTER_SPECIFIC_NODE)
        {
            // Only clear attributes associated with i_node
            if ((*l_itr)->iv_hdr.iv_node != i_node)
            {
                l_itr++;
                continue;
            }
        }

        delete (*l_itr);
        (*l_itr) = NULL;
        l_itr = iv_attributes.erase(l_itr);
    }

    if (iv_attributes.empty())
    {
        iv_attributesExist = false;
    }

    TARG_MUTEX_UNLOCK(iv_mutex);
}

//******************************************************************************
void AttributeTank::clearNonConstAttribute(const uint32_t i_attrId,
                                           const uint32_t i_targetType,
                                           const uint16_t i_pos,
                                           const uint8_t i_unitPos,
                                           const uint8_t i_node)
{
    TARG_MUTEX_LOCK(iv_mutex);

    for (AttributesItr_t l_itr = iv_attributes.begin();
         l_itr != iv_attributes.end(); ++l_itr)
    {
        if ( ((*l_itr)->iv_hdr.iv_attrId == i_attrId) &&
             ((*l_itr)->iv_hdr.iv_targetType == i_targetType) &&
             ((*l_itr)->iv_hdr.iv_pos == i_pos) &&
             ((*l_itr)->iv_hdr.iv_unitPos == i_unitPos) &&
             ((*l_itr)->iv_hdr.iv_node == i_node) )
        {
            if (!((*l_itr)->iv_hdr.iv_flags & ATTR_FLAG_CONST))
            {
                delete (*l_itr);
                (*l_itr) = NULL;
                iv_attributes.erase(l_itr);

                if (iv_attributes.empty())
                {
                    iv_attributesExist = false;
                }
            }

            break;
        }
    }

    TARG_MUTEX_UNLOCK(iv_mutex);
}

//******************************************************************************
void AttributeTank::setAttribute(const uint32_t i_attrId,
                                 const uint32_t i_targetType,
                                 const uint16_t i_pos,
                                 const uint8_t i_unitPos,
                                 const uint8_t i_node,
                                 const uint8_t i_flags,
                                 const uint32_t i_valSize,
                                 const void * i_pVal)
{
    TARG_MUTEX_LOCK(iv_mutex);

    // Search for an existing matching attribute
    bool l_found = false;

    for (AttributesItr_t l_itr = iv_attributes.begin();
         l_itr != iv_attributes.end(); ++l_itr)
    {
        if ( ((*l_itr)->iv_hdr.iv_attrId == i_attrId) &&
             ((*l_itr)->iv_hdr.iv_targetType == i_targetType) &&
             ((*l_itr)->iv_hdr.iv_pos == i_pos) &&
             ((*l_itr)->iv_hdr.iv_unitPos == i_unitPos) &&
             ((*l_itr)->iv_hdr.iv_node == i_node) &&
             ((*l_itr)->iv_hdr.iv_valSize == i_valSize) )
        {
            // Found existing attribute, update it unless the existing attribute
            // is const and the new attribute is non-const
            if (!( ((*l_itr)->iv_hdr.iv_flags & ATTR_FLAG_CONST) &&
                   (!(i_flags & ATTR_FLAG_CONST)) ) )
            {
                (*l_itr)->iv_hdr.iv_flags = i_flags;
                memcpy((*l_itr)->iv_pVal, i_pVal, i_valSize);
            }
            l_found = true;
            break;
        }
    }

    if (!l_found)
    {
        // Add a new attribute to the tank
        Attribute * l_pAttr = new Attribute();

        l_pAttr->iv_hdr.iv_attrId = i_attrId;
        l_pAttr->iv_hdr.iv_targetType = i_targetType;
        l_pAttr->iv_hdr.iv_pos = i_pos;
        l_pAttr->iv_hdr.iv_unitPos = i_unitPos;
        l_pAttr->iv_hdr.iv_node = i_node;
        l_pAttr->iv_hdr.iv_flags = i_flags;
        l_pAttr->iv_hdr.iv_valSize = i_valSize;
        l_pAttr->iv_pVal = new uint8_t[i_valSize];
        memcpy(l_pAttr->iv_pVal, i_pVal, i_valSize);

        iv_attributesExist = true;
        iv_attributes.push_back(l_pAttr);
    }

    TARG_MUTEX_UNLOCK(iv_mutex);
}

//******************************************************************************
bool AttributeTank::getAttribute(const uint32_t i_attrId,
                                 const uint32_t i_targetType,
                                 const uint16_t i_pos,
                                 const uint8_t i_unitPos,
                                 const uint8_t i_node,
                                 void * o_pVal) const
{
    TARG_MUTEX_LOCK(iv_mutex);

    bool l_found = false;

    for (AttributesCItr_t l_itr = iv_attributes.begin(); l_itr
         != iv_attributes.end(); ++l_itr)
    {
        // Allow match if attribute applies to all positions
        if ( ((*l_itr)->iv_hdr.iv_attrId == i_attrId) &&
             ((*l_itr)->iv_hdr.iv_targetType == i_targetType) &&
             (((*l_itr)->iv_hdr.iv_pos == ATTR_POS_NA) ||
              ((*l_itr)->iv_hdr.iv_pos == i_pos)) &&
             (((*l_itr)->iv_hdr.iv_unitPos == ATTR_UNIT_POS_NA) ||
              ((*l_itr)->iv_hdr.iv_unitPos == i_unitPos)) &&
             (((*l_itr)->iv_hdr.iv_node == ATTR_NODE_NA) ||
              ((*l_itr)->iv_hdr.iv_node == i_node)) )
        {
            l_found = true;
            memcpy(o_pVal, (*l_itr)->iv_pVal, (*l_itr)->iv_hdr.iv_valSize);
            break;
        }
    }

    TARG_MUTEX_UNLOCK(iv_mutex);
    return l_found;
}

//******************************************************************************
void AttributeTank::serializeAttributes(
    const AllocType i_allocType,
    const uint32_t i_chunkSize,
    std::vector<AttributeSerializedChunk> & o_attributes,
    const NodeFilter i_nodeFilter,
    const uint8_t i_node) const
{
    TARG_MUTEX_LOCK(iv_mutex);

    // Temporary buffer of the requested chunk size for storing attributes
    uint8_t * l_pBuffer = new uint8_t[i_chunkSize];
    uint32_t l_index = 0;

    AttributesCItr_t l_itr = iv_attributes.begin();

    while (l_itr != iv_attributes.end())
    {
        // Fill up the buffer with as many attributes as possible
        while (l_itr != iv_attributes.end())
        {
            if (i_nodeFilter == NODE_FILTER_NOT_ALL_NODES)
            {
                // Only want attributes that are not for all nodes
                if ((*l_itr)->iv_hdr.iv_node == ATTR_NODE_NA)
                {
                    l_itr++;
                    continue;
                }
            }
            else if (i_nodeFilter == NODE_FILTER_SPECIFIC_NODE_AND_ALL)
            {
                // Only want attributes associated with i_node or all
                if ( ((*l_itr)->iv_hdr.iv_node != ATTR_NODE_NA) &&
                     ((*l_itr)->iv_hdr.iv_node != i_node) )
                {
                    l_itr++;
                    continue;
                }
            }
            else if (i_nodeFilter == NODE_FILTER_SPECIFIC_NODE)
            {
                // Only want attributes associated with i_node
                if ((*l_itr)->iv_hdr.iv_node != i_node)
                {
                    l_itr++;
                    continue;
                }
            }

            if ((l_index + sizeof(AttributeHeader) +
                     (*l_itr)->iv_hdr.iv_valSize) > i_chunkSize)
            {
                // Attribute will not fit into the buffer
                if (l_index == 0)
                {
                    // Attribute will not fit in an empty buffer of the
                    // requested chunk size, this should not happen, if it does,
                    // just move to the next attribute
                    TRACFCOMP(g_trac_targeting,
                        "serializeAttributes: Error, attr too big to serialize (0x%x)",
                        (*l_itr)->iv_hdr.iv_valSize);
                    l_itr++;
                }
                else
                {
                    // Attribute will not fit in a partially filled buffer, the
                    // buffer is ready to send to the user
                    break;
                }
            }
            else
            {
                // Copy the attribute header to the buffer
                AttributeHeader * l_pHeader =
                    reinterpret_cast<AttributeHeader *>(l_pBuffer + l_index);
                *l_pHeader = (*l_itr)->iv_hdr;
                l_index += sizeof(AttributeHeader);

                // Copy the attribute value to the buffer
                memcpy((l_pBuffer + l_index), (*l_itr)->iv_pVal,
                       (*l_itr)->iv_hdr.iv_valSize);
                l_index += (*l_itr)->iv_hdr.iv_valSize;

                l_itr++;
            }
        }

        if (l_index)
        {
            // Create a chunk and add it to the caller's vector
            AttributeSerializedChunk l_chunk;

            if (i_allocType == ALLOC_TYPE_MALLOC)
            {
                l_chunk.iv_pAttributes =
                    static_cast<uint8_t *>(malloc(l_index));
            }
            else
            {
                l_chunk.iv_pAttributes = new uint8_t[l_index];
            }

            memcpy(l_chunk.iv_pAttributes, l_pBuffer, l_index);
            l_chunk.iv_size = l_index;
            o_attributes.push_back(l_chunk);

            // Reuse the buffer for the next attribute
            l_index = 0;
        }
    }

    delete [] l_pBuffer;

    TARG_MUTEX_UNLOCK(iv_mutex);
}

//******************************************************************************
bool AttributeTank::attributeExists(const uint32_t i_attrId) const
{
    // Note. The use-case is for the caller to call attributesExist() before
    // calling this function, i.e. the caller has already verified that
    // attributes exist in the tank. No need for this function to call
    // attributesExist() again.
    TARG_MUTEX_LOCK(iv_mutex);

    bool l_found = false;

    for (AttributesCItr_t l_itr = iv_attributes.begin(); l_itr
         != iv_attributes.end(); ++l_itr)
    {
        if ((*l_itr)->iv_hdr.iv_attrId == i_attrId)
        {
            l_found = true;
            break;
        }
    }

    TARG_MUTEX_UNLOCK(iv_mutex);
    return l_found;
}

//******************************************************************************
void AttributeTank::deserializeAttributes(
        const AttributeSerializedChunk & i_attributes)
{
    TARG_MUTEX_LOCK(iv_mutex);

    uint32_t l_index = 0;

    while (l_index < i_attributes.iv_size)
    {
        AttributeHeader * l_pAttrHdr =
            reinterpret_cast<AttributeHeader *>
                (i_attributes.iv_pAttributes + l_index);

        if (sizeof(AttributeHeader) > (i_attributes.iv_size - l_index))
        {
            // Remaining chunk smaller than attribute header, quit
            TRACFCOMP(g_trac_targeting,
                      "deserializeAttributes: Error, header too big for chunk (0x%x)",
                        (i_attributes.iv_size - l_index));
            break;
        }

        l_index += sizeof(AttributeHeader);

        if (l_pAttrHdr->iv_valSize > (i_attributes.iv_size - l_index))
        {
            // Remaining chunk smaller than attribute value, quit
            TRACFCOMP(g_trac_targeting,
                      "deserializeAttributes: Error, attr too big for chunk (0x%x:0x%x)",
                      l_pAttrHdr->iv_valSize, (i_attributes.iv_size - l_index));
            break;
        }

        // Create a new Attribute and add it to the tank
        Attribute * l_pAttr = new Attribute();
        l_pAttr->iv_hdr = *l_pAttrHdr;
        l_pAttr->iv_pVal = new uint8_t[l_pAttrHdr->iv_valSize];
        memcpy(l_pAttr->iv_pVal, (i_attributes.iv_pAttributes + l_index),
               l_pAttrHdr->iv_valSize);

        l_index += l_pAttrHdr->iv_valSize;
        iv_attributesExist = true;
        iv_attributes.push_back(l_pAttr);
    }

    TARG_MUTEX_UNLOCK(iv_mutex);
}

//******************************************************************************
AttributeTank::Attribute::Attribute() :
    iv_pVal(NULL)
{

}

//******************************************************************************
AttributeTank::Attribute::~Attribute()
{
    delete[] iv_pVal;
    iv_pVal = NULL;
}

}
