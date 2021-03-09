/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/attributeTank.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
 *  @file attributeTank.C
 *
 *  @brief Implements the AttributeTank and associated classes.
 */
#include <stdlib.h>
#include <string.h>
#include <targeting/common/attributeTank.H>
#include <targeting/common/trace.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/predicates/predicateattrtanktargetpos.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/targetservice.H>
#include <targeting/targplatutil.H>
#include <targeting/common/targreasoncodes.H>



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
        // Get a copy of the Attribute's node for quick access
        uint8_t l_node = (*l_itr)->getHeader().iv_node;
        if (i_nodeFilter == NODE_FILTER_NOT_ALL_NODES)
        {
            // Only clear attributes that are not for all nodes
            if (l_node == ATTR_NODE_NA)
            {
                l_itr++;
                continue;
            }
        }
        else if (i_nodeFilter == NODE_FILTER_SPECIFIC_NODE_AND_ALL)
        {
            // Only clear attributes associated with i_node or all
            if ( (l_node != ATTR_NODE_NA) &&
                 (l_node != i_node) )
            {
                l_itr++;
                continue;
            }
        }
        else if (i_nodeFilter == NODE_FILTER_SPECIFIC_NODE)
        {
            // Only clear attributes associated with i_node
            if (l_node != i_node)
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
        // Get a (constant) reference to the Attribute Header
        // for easy access to data members
        const AttributeHeader &l_attributeHeader = (*l_itr)->getHeader();

        // Find attribute that satisfies search criteria
        if ( (l_attributeHeader.iv_attrId == i_attrId) &&
             (l_attributeHeader.iv_targetType == i_targetType) &&
             (l_attributeHeader.iv_pos == i_pos) &&
             (l_attributeHeader.iv_unitPos == i_unitPos) &&
             (l_attributeHeader.iv_node == i_node) )
        {
            if (!(l_attributeHeader.iv_flags & ATTR_FLAG_CONST))
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
        // Get a reference to the Attribute Header
        // for easy access to data members
        const AttributeHeader &l_attributeHeader = (*l_itr)->getHeader();

        // Find attribute that satisfies search criteria
        if ( (l_attributeHeader.iv_attrId == i_attrId) &&
             (l_attributeHeader.iv_targetType == i_targetType) &&
             (l_attributeHeader.iv_pos == i_pos) &&
             (l_attributeHeader.iv_unitPos == i_unitPos) &&
             (l_attributeHeader.iv_node == i_node) &&
             (l_attributeHeader.iv_valSize == i_valSize) )
        {
            // Found existing attribute, update it unless the existing attribute
            // is const and the new attribute is non-const
            if (!( (l_attributeHeader.iv_flags & ATTR_FLAG_CONST) &&
                   (!(i_flags & ATTR_FLAG_CONST)) ) )
            {
                (*l_itr)->setFlags(i_flags);
                (*l_itr)->setValue(i_pVal, i_valSize);
            }
            l_found = true;
            break;
        }
    }

    if (!l_found)
    {
        // Add a new attribute to the tank
        Attribute * l_pAttr = new Attribute();

        l_pAttr->setId(i_attrId);
        l_pAttr->setTargetType(i_targetType);
        l_pAttr->setPosition(i_pos);
        l_pAttr->setUnitPosition(i_unitPos);
        l_pAttr->setNode(i_node);
        l_pAttr->setFlags(i_flags);
        l_pAttr->setValue(i_pVal, i_valSize);

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
        // Get a (constant) reference to the Attribute Header
        // for easy access to data members
        const AttributeHeader &l_attributeHeader = (*l_itr)->getHeader();

        // Find attribute that satisfies search criteria
        if ( (l_attributeHeader.iv_attrId == i_attrId) &&
             (l_attributeHeader.iv_targetType == i_targetType) &&
             ((l_attributeHeader.iv_pos == ATTR_POS_NA) ||
              (l_attributeHeader.iv_pos == i_pos)) &&
             ((l_attributeHeader.iv_unitPos == ATTR_UNIT_POS_NA) ||
              (l_attributeHeader.iv_unitPos == i_unitPos)) &&
             ((l_attributeHeader.iv_node == ATTR_NODE_NA) ||
              (l_attributeHeader.iv_node == i_node)) )
        {
            l_found = true;
            (*l_itr)->cloneValue(o_pVal, l_attributeHeader.iv_valSize);
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
            // Get a (constant) reference to the Attribute Header
            // for easy access to data members
            const AttributeHeader &l_attributeHeader =
                                                 (*l_itr)->getHeader();

            // Get a copy of the node for quick access
            uint8_t l_node = l_attributeHeader.iv_node;

            if (i_nodeFilter == NODE_FILTER_NOT_ALL_NODES)
            {
                // Only want attributes that are not for all nodes
                if (l_node == ATTR_NODE_NA)
                {
                    l_itr++;
                    continue;
                }
            }
            else if (i_nodeFilter == NODE_FILTER_SPECIFIC_NODE_AND_ALL)
            {
                // Only want attributes associated with i_node or all
                if ( (l_node != ATTR_NODE_NA) &&
                     (l_node != i_node) )
                {
                    l_itr++;
                    continue;
                }
            }
            else if (i_nodeFilter == NODE_FILTER_SPECIFIC_NODE)
            {
                // Only want attributes associated with i_node
                if (l_node != i_node)
                {
                    l_itr++;
                    continue;
                }
            }

            if ((l_index + (*l_itr)->getSize()) > i_chunkSize)
            {
                // Attribute will not fit into the buffer
                if (l_index == 0)
                {
                    // Attribute will not fit in an empty buffer of the
                    // requested chunk size, this should not happen, if it does,
                    // just move to the next attribute
                    TRACFCOMP(g_trac_targeting,
                        "serializeAttributes: Error, attr too big to serialize "
                        "(0x%x)",
                        l_attributeHeader.iv_valSize);
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
                l_index += (*l_itr)->serialize(l_pBuffer + l_index,
                                               (*l_itr)->getSize());
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
        if ((*l_itr)->getHeader().iv_attrId == i_attrId)
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
        const AttributeSerializedChunk & i_attributes,
        bool i_echoAttributes )
{
    TARG_MUTEX_LOCK(iv_mutex);

    uint32_t l_index = 0;

    // Get a handle to the serialized Attributes
    uint8_t* l_serializedData =
                        reinterpret_cast<uint8_t*>(i_attributes.iv_pAttributes);

    // Iterate thru the Attributes
    while (l_index < i_attributes.iv_size)
    {
        // Create a new Attribute
        Attribute * l_pAttribute = new Attribute();

        // Deserialize the data, if possible
        uint32_t l_deserializedDataSize = l_pAttribute->deserialize(
                                l_serializedData + l_index,
                                i_attributes.iv_size - l_index);

        if (!l_deserializedDataSize)
        {
            // Unable to deserialize data, delete Attribute
            delete l_pAttribute;
            l_pAttribute = NULL;

            // Remaining chunk smaller than attribute header, quit
            TRACFCOMP(g_trac_targeting,
                      "deserializeAttributes: Error, attribute too big for "
                      "chunk (0x%x)",
                      (i_attributes.iv_size - l_index));
            break;
        }

        // Was able to deserialize data, add Attribute to the tank
        iv_attributesExist = true;
        iv_attributes.push_back(l_pAttribute);

        // Increment the index after deserializing an attribute
        l_index += l_deserializedDataSize;

        if ( i_echoAttributes == true ) // attributes should be echo'd
        {
            // extract individual fields from attribute
            uint32_t attrId(l_pAttribute->getHeader().iv_attrId);
            uint32_t targetType(l_pAttribute->getHeader().iv_targetType);
            uint16_t pos(l_pAttribute->getHeader().iv_pos);
            uint8_t unitPos(l_pAttribute->getHeader().iv_unitPos);

            uint8_t node(l_pAttribute->getHeader().iv_node);
            uint8_t flags(l_pAttribute->getHeader().iv_flags);

            uint32_t valueLen(l_pAttribute->getHeader().iv_valSize);

            TRACFCOMP(g_trac_targeting,
                      "deserializeAttributes: Attribute Hdr: "
                      "ID = %.8X  Target Type = %.8X  Positon = %.4X  "
                      "Unit Position = %.2X  node = %.1X  flags = %.1X  "
                      "Parm Length = %.8X\n",
                      attrId, targetType, pos, unitPos, node, flags, valueLen);

            TRACFBIN(g_trac_targeting,
                      "deserializeAttributes: Parm Value: ",
                      l_pAttribute->getValue(), valueLen);
        } // end echo attributes
    }

    TARG_MUTEX_UNLOCK(iv_mutex);
}

//******************************************************************************
void AttributeTank::deserializeAttributes(
        const AttributeSerializedChunk & i_attributes)
{
    // deserialize without echo
    deserializeAttributes( i_attributes,
                           false );
}

//******************************************************************************
errlHndl_t AttributeTank::writePermAttributes()
{
    errlHndl_t l_err = NULL;

    for(AttributesCItr_t l_attrIter = iv_attributes.begin();
        l_attrIter != iv_attributes.end(); ++l_attrIter)
    {
        // Get a (constant) reference to the Attribute Header
        // for easy access to data members
        const AttributeHeader &l_attrHdr = (*l_attrIter)->getHeader();

        PredicatePostfixExpr l_permAttrOverrides;

        // Predicate to match target type
        PredicateCTM l_targetTypeFilter
                (CLASS_NA, static_cast<TYPE>(l_attrHdr.iv_targetType));

        // Predicate to match attribute tank target position
        PredicateAttrTankTargetPos l_targetPosFilter(l_attrHdr.iv_pos,
                                                     l_attrHdr.iv_unitPos,
                                                     l_attrHdr.iv_node);

        l_permAttrOverrides.push(&l_targetTypeFilter)
            .push(&l_targetPosFilter).And();

        // Apply the filter through all targets
        TargetRangeFilter l_permTargetList( targetService().begin(),
                                            targetService().end(),
                                            &l_permAttrOverrides);

        // Write permanent attributes to target
        for ( ; l_permTargetList; ++l_permTargetList)
        {
            bool l_success = (*l_permTargetList)->_trySetAttr(
                                static_cast<ATTRIBUTE_ID>(l_attrHdr.iv_attrId),
                                l_attrHdr.iv_valSize,
                                (*l_attrIter)->getValue() );

            if (l_success)
            {
                TRACFCOMP(g_trac_targeting, "writePermAttributes: Successful "
                    "permanent override of Attr ID:0x%X Value:0x%llX applied "
                    "to target 0x%X",
                    l_attrHdr.iv_attrId,
                    *reinterpret_cast<const uint64_t *>
                                                    ((*l_attrIter)->getValue()),
                    (*l_permTargetList)->getAttr<ATTR_HUID>() );
            }
            else
            {
                uint8_t * l_pAttrData(NULL);
                bool l_found = (*l_permTargetList)->_tryGetAttr(
                                static_cast<ATTRIBUTE_ID>(l_attrHdr.iv_attrId),
                                l_attrHdr.iv_valSize,
                                l_pAttrData);

                if (l_found)
                {
                    TRACFCOMP(g_trac_targeting, "writePermAttributes: Value "
                        "NOT applied to target, override failed for Attr "
                        "ID:0x%X Value:0x%llX on target 0x%X - current value "
                        "0x%llX",
                        l_attrHdr.iv_attrId,
                        *reinterpret_cast<const uint64_t *>
                                                    ((*l_attrIter)->getValue()),
                        (*l_permTargetList)->getAttr<ATTR_HUID>(),
                        *reinterpret_cast<uint64_t *>(l_pAttrData) );
                    /*@
                     * @errortype
                     * @moduleid     TARG_WRITE_PERM_ATTR
                     * @reasoncode   TARG_RC_WRITE_PERM_ATTR_FAIL
                     * @userdata1    Target specified
                     * @userdata2    Attribute specified
                     * @devdesc      Failure applying given attribute override
                     *               on given target
                     * @custdesc     Error occurred during system boot                               */
                    UTIL::createTracingError(
                       TARG_WRITE_PERM_ATTR,
                       TARG_RC_WRITE_PERM_ATTR_FAIL,
                       (*l_permTargetList)->getAttr<ATTR_HUID>(),
                       l_attrHdr.iv_attrId,
                       0,0,
                       l_err);
                    break;
                }
                else
                {
                    TRACFCOMP(g_trac_targeting, "writePermAttributes: Target "
                        "does not have attribute, override NOT applied for "
                        "Attr ID:0x%X on target 0x%X",
                        l_attrHdr.iv_attrId,
                        (*l_permTargetList)->getAttr<ATTR_HUID>() );
                    /*@
                     * @errortype
                     * @moduleid     TARG_WRITE_PERM_ATTR
                     * @reasoncode   TARG_RC_WRITE_PERM_ATTR_TARGET_FAIL
                     * @userdata1    Target specified
                     * @userdata2    Attribute specified
                     * @devdesc      Given target does not have given attribute
                     *               to apply override
                     * @custdesc     Error occurred during system boot
                     */
                    UTIL::createTracingError(
                       TARG_WRITE_PERM_ATTR,
                       TARG_RC_WRITE_PERM_ATTR_TARGET_FAIL,
                       (*l_permTargetList)->getAttr<ATTR_HUID>(),
                       l_attrHdr.iv_attrId,
                       0,0,
                       l_err);
                    break;
                }
            }
        }
        if (l_err)
        {
            break;
        }
    }
    return l_err;
}

//******************************************************************************
size_t AttributeTank::size() const
{
    return iv_attributes.size();
}

//******************************************************************************
void AttributeTank::getAllAttributes( std::list<Attribute *>& o_attributes ) const
{
    o_attributes = iv_attributes;
}

//******************************************************************************
const char* AttributeTank::layerToString( TankLayer i_layer )
{
    switch(i_layer)
    {
        case(AttributeTank::TANK_LAYER_FAPI): return "FAPI";
        case(AttributeTank::TANK_LAYER_TARG): return "TARG";
        case(AttributeTank::TANK_LAYER_PERM): return "PERM";
        default: return "UNKNOWN";
    }
}

}

