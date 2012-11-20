/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/fapi/fapiAttributeTank.C $                       */
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
 *  @file fapiAttributeTank.C
 *
 *  @brief Implements the AttributeTank and Attribute classes.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/07/2012  Created
 */
#include <stdlib.h>
#include <fapiAttributeTank.H>
#include <fapiAttributeService.H>
#include <fapiPlatTrace.H>
#include <fapiReturnCode.H>
#include <fapiSystemConfig.H>

namespace fapi
{

//******************************************************************************
AttributeTank::AttributeTank() :
    iv_pName("AttributeTank"), iv_attributesExist(false)
{
    FAPI_IMP("AttributeTank: Constructor");
}

//******************************************************************************
AttributeTank::~AttributeTank()
{
    FAPI_IMP("AttributeTank: Destructor");
}

//******************************************************************************
void AttributeTank::clearAllAttributes()
{
    platLock();
    FAPI_DBG("%s: Clearing all attributes", iv_pName);
    iv_attributesExist = false;
    iv_attributes.clear();
    platUnlock();
}

//******************************************************************************
void AttributeTank::clearNonConstAttribute(const fapi::AttributeId i_attrId,
                                           const fapi::Target * const i_pTarget)
{
    // Do a quick check to see if any attributes exist. This is deliberately
    // done without a lock for performance. The use-case for this function is
    // FAPI_ATTR_SET calling to clear any constant override, overrides should
    // not be changed while HWPs are setting attributes, but even if they are
    // there is no risk of corruption.
    if (!iv_attributesExist)
    {
        return;
    }
    
    uint32_t l_targetType = getTargetType(i_pTarget);
    uint16_t l_pos = getTargetPos(i_pTarget);
    uint8_t l_unitPos = getTargetUnitPos(i_pTarget);
    
    platLock();
    
    // Note that for an array attribute, there will be multiple Attribute
    // objects, one for each element
    AttributesItr_t l_itr = iv_attributes.begin();
    
    while (l_itr != iv_attributes.end())
    {
        if ( (!((*l_itr).iv_flags & ATTR_FLAG_CONST)) &&
             ((*l_itr).iv_attrId == static_cast<uint32_t>(i_attrId)) &&
             ((*l_itr).iv_targetType == l_targetType) &&
             ((*l_itr).iv_pos == l_pos) &&
             ((*l_itr).iv_unitPos == l_unitPos) )
        {
            FAPI_INF("%s: Clearing non-const attr 0x%x", iv_pName, i_attrId);
            l_itr = iv_attributes.erase(l_itr);
        }
        else
        {
            ++l_itr;
        }
    }
    
    if (iv_attributes.empty())
    {
        iv_attributesExist = false;
    }
    
    platUnlock();
}

//******************************************************************************
void AttributeTank::setAttribute(const fapi::AttributeId i_attrId,
                                 const fapi::Target * const i_pTarget,
                                 const uint64_t i_val,
                                 const uint8_t i_arrayD1,
                                 const uint8_t i_arrayD2,
                                 const uint8_t i_arrayD3,
                                 const uint8_t i_arrayD4)
{
    // Create an Attribute structure
    Attribute l_attr;
    
    l_attr.iv_val = i_val;
    l_attr.iv_attrId = i_attrId;
    l_attr.iv_targetType = getTargetType(i_pTarget);
    l_attr.iv_pos = getTargetPos(i_pTarget);
    l_attr.iv_unitPos = getTargetUnitPos(i_pTarget);
    l_attr.iv_flags = 0;
    l_attr.iv_arrayD1 = i_arrayD1;
    l_attr.iv_arrayD2 = i_arrayD2;
    l_attr.iv_arrayD3 = i_arrayD3;
    l_attr.iv_arrayD4 = i_arrayD4;
    
    // Set the attribute in the tank
    setAttribute(l_attr);
}

//******************************************************************************
void AttributeTank::setAttribute(const Attribute & i_attribute)
{
    platLock();
    
    // Search for an existing matching attribute
    bool l_found = false;
    AttributesItr_t l_itr = iv_attributes.begin();

    for (AttributesItr_t l_itr = iv_attributes.begin(); l_itr
        != iv_attributes.end(); ++l_itr)
    {
        if ( ((*l_itr).iv_attrId == i_attribute.iv_attrId) &&
             ((*l_itr).iv_targetType == i_attribute.iv_targetType) &&
             ((*l_itr).iv_pos == i_attribute.iv_pos) &&
             ((*l_itr).iv_unitPos == i_attribute.iv_unitPos) &&
             ((*l_itr).iv_arrayD1 == i_attribute.iv_arrayD1) &&
             ((*l_itr).iv_arrayD2 == i_attribute.iv_arrayD2) &&
             ((*l_itr).iv_arrayD3 == i_attribute.iv_arrayD3) &&
             ((*l_itr).iv_arrayD4 == i_attribute.iv_arrayD4) )
        {
            // Found existing attribute, update it unless the existing attribute
            // is const and the new attribute is non-const
            if (!( ((*l_itr).iv_flags & ATTR_FLAG_CONST) &&
                   (!(i_attribute.iv_flags & ATTR_FLAG_CONST)) ) )
            {
                FAPI_DBG("%s: Updating attr 0x%x", iv_pName,
                         i_attribute.iv_attrId);
                (*l_itr).iv_flags = i_attribute.iv_flags;
                (*l_itr).iv_val = i_attribute.iv_val;
            }
            l_found = true;
            break;
        }
    }
    
    if (!l_found)
    {
        // Add the attribute to the tank
        FAPI_DBG("%s: Setting attr 0x%x", iv_pName, i_attribute.iv_attrId);
        iv_attributesExist = true;
        iv_attributes.push_back(i_attribute);
    }
    
    platUnlock();
}

//******************************************************************************
bool AttributeTank::getAttribute(const fapi::AttributeId i_attrId,
                                 const fapi::Target * const i_pTarget,
                                 uint64_t & o_val,
                                 const uint8_t i_arrayD1,
                                 const uint8_t i_arrayD2,
                                 const uint8_t i_arrayD3,
                                 const uint8_t i_arrayD4) const
{
    // Do a quick check to see if any attributes exist. This is deliberately
    // done without a lock for performance. The use-case for this function is
    // FAPI_ATTR_GET calling to get an override, overrides should not be changed
    // while HWPs are getting attributes, but even if they are there is no risk
    // of corruption.
    if (!iv_attributesExist)
    {
        return false;
    }
    
    // Do not return any override for ATTR_POS or ATTR_CHIP_UNIT_POS because
    // this function calls getTargetPos and getTargetUnitPos which will query
    // ATTR_POS and ATTR_CHIP_UNIT_POS again resulting in an infinite loop
    if ((i_attrId == ATTR_POS) || (i_attrId == ATTR_CHIP_UNIT_POS))
    {
        return false;
    }
    
    bool l_found = false;
    uint32_t l_targetType = getTargetType(i_pTarget);
    uint16_t l_pos = getTargetPos(i_pTarget);
    uint8_t l_unitPos = getTargetUnitPos(i_pTarget);
    
    platLock();
    
    for (AttributesCItr_t l_itr = iv_attributes.begin(); l_itr
        != iv_attributes.end(); ++l_itr)
    {
        if ( ((*l_itr).iv_attrId == static_cast<uint32_t>(i_attrId)) &&
             ((*l_itr).iv_targetType == l_targetType) &&
             (((*l_itr).iv_pos == ATTR_POS_NA) || ((*l_itr).iv_pos == l_pos)) &&
             (((*l_itr).iv_unitPos == ATTR_UNIT_POS_NA) ||
              ((*l_itr).iv_unitPos == l_unitPos)) &&
             ((*l_itr).iv_arrayD1 == i_arrayD1) &&
             ((*l_itr).iv_arrayD2 == i_arrayD2) &&
             ((*l_itr).iv_arrayD3 == i_arrayD3) &&
             ((*l_itr).iv_arrayD4 == i_arrayD4) )
        {
            FAPI_INF("%s: Getting attr 0x%x:0x%llx", iv_pName, i_attrId,
                     (*l_itr).iv_val);
            l_found = true;
            o_val = (*l_itr).iv_val;
            break;
        }
    }

    platUnlock();
    return l_found;
}

//******************************************************************************
void AttributeTank::getAllAttributes(
    AllocType i_allocType,
    std::vector<AttributeChunk> & o_attributes) const
{
    platLock();
    
    FAPI_DBG("%s: Getting all attributes", iv_pName);
    
    if (iv_attributes.size())
    {
        AttributesCItr_t l_itr = iv_attributes.begin();
        size_t l_numAttrsRemaining = iv_attributes.size();
        
        while (l_numAttrsRemaining)
        {
            AttributeChunk l_chunk;
            l_chunk.iv_numAttributes = l_numAttrsRemaining;
            
            if (l_chunk.iv_numAttributes > AttributeChunk::MAX_ATTRS_PER_CHUNK)
            {
                l_chunk.iv_numAttributes = AttributeChunk::MAX_ATTRS_PER_CHUNK;
            }
            
            if (i_allocType == ALLOC_TYPE_MALLOC)
            {
                l_chunk.iv_pAttributes = static_cast<uint8_t *>
                    (malloc(sizeof(Attribute) * l_chunk.iv_numAttributes));
            }
            else
            {
                l_chunk.iv_pAttributes =
                    new uint8_t[sizeof(Attribute) * l_chunk.iv_numAttributes];
            }
            
            Attribute * l_pAttr = reinterpret_cast<Attribute *>
                (l_chunk.iv_pAttributes);
            
            for(size_t i = 0; i < l_chunk.iv_numAttributes; i++)
            {
                *l_pAttr++ = (*l_itr);
                l_itr++;
            }
            
            o_attributes.push_back(l_chunk);
            l_numAttrsRemaining -= l_chunk.iv_numAttributes;
        }
    }
    
    platUnlock();
}

//******************************************************************************
bool AttributeTank::attributesExist()
{
    platLock();
    bool l_attributesExist = iv_attributesExist;
    platUnlock();
    return l_attributesExist;
}

//******************************************************************************
uint32_t AttributeTank::getTargetType(const fapi::Target * const i_pTarget)
{
    if (i_pTarget == NULL)
    {
        return static_cast<uint32_t>(TARGET_TYPE_SYSTEM);
    }
    else
    {
       return static_cast<uint32_t>(i_pTarget->getType());
    }
}

//******************************************************************************
uint16_t AttributeTank::getTargetPos(const fapi::Target * const i_pTarget)
{
    // Note that any errors querying a parent chip or a position attribute are
    // ignored and the function returns ATTR_POS_NA
    uint16_t l_ret = ATTR_POS_NA;
    
    if (i_pTarget != NULL)
    {
        ReturnCode l_rc;
        uint32_t l_pos = 0xffffffff;
        
        if (i_pTarget->isChiplet())
        {
            // Target is a chiplet, o_pos is the parent chip position
            Target l_chip;
                
            l_rc = fapiGetParentChip(*i_pTarget, l_chip);
            
            if (l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetParentChip",
                         static_cast<uint32_t>(l_rc));
            }
            else
            {
                l_rc = FAPI_ATTR_GET(ATTR_POS, &l_chip, l_pos);
                
                if (l_rc)
                {
                    FAPI_ERR("Error (0x%x) getting parent chip position attr",
                             static_cast<uint32_t>(l_rc));
                }
                else
                {
                    l_ret = l_pos;
                }
            }
        }
        else
        {
            // Target is not a chiplet, iv_pos is the Target position
            l_rc = FAPI_ATTR_GET(ATTR_POS, i_pTarget, l_pos);
            
            if (l_rc)
            {
                FAPI_ERR("Error (0x%x) getting position attr",
                         static_cast<uint32_t>(l_rc));
            }
            else
            {
                l_ret = l_pos;
            }
        }
    }
    
    return l_ret;
}

//******************************************************************************
uint8_t AttributeTank::getTargetUnitPos(const fapi::Target * const i_pTarget)
{
    // Note that any errors querying a position attribute are ignored and the
    // function returns ATTR_UNIT_POS_NA
    uint8_t l_ret = ATTR_UNIT_POS_NA;
    
    if (i_pTarget != NULL)
    {
        if (i_pTarget->isChiplet())
        {
            uint8_t l_unitPos = 0xff;
            
            ReturnCode l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, i_pTarget,
                                            l_unitPos);
            
            if (l_rc)
            {
                FAPI_ERR("Error (0x%x) getting chiplet position attr",
                         static_cast<uint32_t>(l_rc));
            }
            else
            {
                l_ret = l_unitPos;
            }
        }
    }
    
    return l_ret;
}
//******************************************************************************
OverrideAttributeTank::OverrideAttributeTank()
{
    iv_pName = "OverrideAttributeTank";
    FAPI_IMP("OverrideAttributeTank: Constructor");
}

//******************************************************************************
SyncAttributeTank::SyncAttributeTank()
{
    iv_pName = "SyncAttributeTank";
    FAPI_IMP("SyncAttributeTank: Constructor");
}

//******************************************************************************
void SyncAttributeTank::setAttribute(const fapi::AttributeId i_attrId,
                                     const fapi::Target * const i_pTarget,
                                     const uint64_t i_val,
                                     const uint8_t i_arrayD1,
                                     const uint8_t i_arrayD2,
                                     const uint8_t i_arrayD3,
                                     const uint8_t i_arrayD4)
{
    if (platSyncEnabled())
    {
        AttributeTank::setAttribute(i_attrId, i_pTarget, i_val, i_arrayD1,
                                    i_arrayD2, i_arrayD3, i_arrayD4);
    }
}

}
