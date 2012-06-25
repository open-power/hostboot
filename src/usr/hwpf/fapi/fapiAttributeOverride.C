/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/fapi/fapiAttributeOverride.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file fapiAttributeOverride.C
 *
 *  @brief Implements the AttributeOverrides and AttributeOverride classes.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/07/2012  Created
 */

#include <fapiAttributeOverride.H>
#include <fapiAttributeService.H>
#include <fapiPlatTrace.H>
#include <fapiReturnCode.H>
#include <fapiSystemConfig.H>

namespace fapi
{

//******************************************************************************
// Default Constructor
//******************************************************************************
AttributeOverrides::AttributeOverrides()
    : iv_overridesExist(false)
{
    FAPI_IMP("AttributeOverrides: Constructor");
}

//******************************************************************************
// Destructor
//******************************************************************************
AttributeOverrides::~AttributeOverrides()
{
    FAPI_IMP("AttributeOverrides: Destructor");
    for (OverridesItr_t l_itr = iv_overrides.begin(); l_itr
        != iv_overrides.end(); ++l_itr)
    {
        delete (*l_itr);
    }
}

//******************************************************************************
// clearOverrides
//******************************************************************************
void AttributeOverrides::clearOverrides()
{
    FAPI_IMP("AttributeOverrides: Clearing all overrides");
    platLock();
    
    iv_overridesExist = false;
    
    for (OverridesItr_t l_itr = iv_overrides.begin(); l_itr
        != iv_overrides.end(); ++l_itr)
    {
        delete (*l_itr);
    }

    iv_overrides.clear();
    
    platUnlock();
}

//******************************************************************************
// clearNonConstOverride
//******************************************************************************
void AttributeOverrides::clearNonConstOverride(
    const fapi::AttributeId i_attrId,
    const fapi::Target * const i_pTarget)
{
    // Do a quick check to see if any overrides exist. This is deliberately done
    // without a lock for performance. Overrides should not be changed while
    // HWPs are setting attributes, but even if they are there is no risk of
    // corruption.
    if (!iv_overridesExist)
    {
        return;
    }

    platLock();
    
    // Note that for an array attribute with an override, there will be multiple
    // AttributeOverride objects, one for each element
    OverridesItr_t l_itr = iv_overrides.begin();

    while (l_itr != iv_overrides.end())
    {
        if (((*l_itr)->iv_overrideType == ATTR_OVERRIDE_NON_CONST) &&
            overrideMatch(i_attrId, i_pTarget, *(*l_itr)))
        {
            delete (*l_itr);
            l_itr = iv_overrides.erase(l_itr);
        }
        else
        {
            ++l_itr;
        }
    }
    
    if (iv_overrides.empty())
    {
        iv_overridesExist = false;
    }
    
    platUnlock();
}

//******************************************************************************
// setOverride
//******************************************************************************
void AttributeOverrides::setOverride(const AttributeOverride & i_override)
{
    if (i_override.iv_overrideType == ATTR_OVERRIDE_CLEAR_ALL)
    {
        clearOverrides();
    }
    else
    {
        FAPI_IMP("Set Override. ID: 0x%x, Val: 0x%llx, Type: %d",
                 i_override.iv_attrId, i_override.iv_overrideVal,
                 i_override.iv_overrideType);
        FAPI_INF("Set Override. Target Type: 0x%x, Pos: 0x%x, UPos: 0x%x",
                 i_override.iv_targetType, i_override.iv_pos,
                 i_override.iv_unitPos);
        FAPI_INF("Set Override. Array Dims: %d.%d.%d.%d",
                 i_override.iv_arrayD1, i_override.iv_arrayD2,
                 i_override.iv_arrayD3, i_override.iv_arrayD4);
        
        AttributeOverride * l_pOverride = new AttributeOverride();
        *l_pOverride = i_override;

        platLock();
        iv_overridesExist = true;
        iv_overrides.push_back(l_pOverride);
        platUnlock();
    }
}

//******************************************************************************
// getOverride
//******************************************************************************
bool AttributeOverrides::getOverride(const fapi::AttributeId i_attrId,
                                     const fapi::Target * const i_pTarget,
                                     uint64_t & o_overrideVal,
                                     const uint8_t i_arrayD1,
                                     const uint8_t i_arrayD2,
                                     const uint8_t i_arrayD3,
                                     const uint8_t i_arrayD4)
{
    // Do a quick check to see if any overrides exist. This is deliberately done
    // without a lock for performance. Overrides should not be changed while
    // HWPs are getting attributes, but even if they are there is no risk of
    // corruption.
    if (!iv_overridesExist)
    {
        return false;
    }
    
    platLock();
    bool l_found = false;

    for (OverridesCItr_t l_itr = iv_overrides.begin(); l_itr
        != iv_overrides.end(); ++l_itr)
    {
        if (overrideMatch(i_attrId, i_pTarget, *(*l_itr)))
        {
            // Check the array dimensions
            if (((*l_itr)->iv_arrayD1 == i_arrayD1) &&
                ((*l_itr)->iv_arrayD2 == i_arrayD2) &&
                ((*l_itr)->iv_arrayD3 == i_arrayD3) &&
                ((*l_itr)->iv_arrayD4 == i_arrayD4))
            {
                l_found = true;
                o_overrideVal = (*l_itr)->iv_overrideVal;
                FAPI_IMP("Returning HWPF Attribute Override, 0x%x = 0x%llx",
                         i_attrId, o_overrideVal);
                break;
            }
        }
    }

    platUnlock();
    return l_found;
}

//******************************************************************************
// overridesExist
//******************************************************************************
bool AttributeOverrides::overridesExist()
{
    platLock();
    bool l_overridesExist = iv_overridesExist;
    platUnlock();
    return l_overridesExist;
}

//******************************************************************************
// overrideMatch
//******************************************************************************
bool AttributeOverrides::overrideMatch(
    const fapi::AttributeId i_attrId,
    const fapi::Target * const i_pTarget,
    const AttributeOverride & i_candidate)
{
    // Note that any errors querying a parent chip or a position attribute are
    // dropped and the function returns false (attribute is not a match)
    
    // Check the Attribute ID
    if (i_candidate.iv_attrId != static_cast<uint32_t>(i_attrId))
    {
        return false;
    }
    
    // Check the Target Type
    if (i_pTarget == NULL)
    {
        if (i_candidate.iv_targetType !=
            static_cast<uint32_t>(TARGET_TYPE_SYSTEM))
        {
            return false;
        }
    }
    else if (i_candidate.iv_targetType !=
        static_cast<uint32_t>(i_pTarget->getType()))
    {
        return false;
    }
    
    // Check the Target position if applicable and not the system Target
    if ((i_candidate.iv_pos != ATTR_POS_NA) &&
        (i_pTarget != NULL) &&
        (i_pTarget->getType() != TARGET_TYPE_SYSTEM))
    {
        ReturnCode l_rc;
        uint32_t l_pos = 0xffffffff;
        
        if (i_pTarget->isChiplet())
        {
            // Target is a chiplet, iv_pos is the parent chip position
            Target l_chip;
            
            l_rc = fapiGetParentChip(*i_pTarget, l_chip);
            
            if (l_rc)
            {
                FAPI_ERR("Error (0x%x) from fapiGetParentChip",
                         static_cast<uint32_t>(l_rc));
                return false;
            }
            
            l_rc = FAPI_ATTR_GET(ATTR_POS, &l_chip, l_pos);
            
            if (l_rc)
            {
                FAPI_ERR("Error (0x%x) getting parent chip position attr",
                         static_cast<uint32_t>(l_rc));
                return false;
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
                return false;
            }
        }
        
        if (i_candidate.iv_pos != l_pos)
        {
            return false;
        }
    }
    
    // Check the Unit Target position if applicable and a unit Target
    if ((i_candidate.iv_unitPos != ATTR_UNIT_POS_NA) &&
        (i_pTarget != NULL) &&
        (i_pTarget->isChiplet()))
    {
        ReturnCode l_rc;
        uint8_t l_unitPos = 0xff;
        
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, i_pTarget, l_unitPos);
        
        if (l_rc)
        {
            FAPI_ERR("Error (0x%x) getting chiplet position attr",
                     static_cast<uint32_t>(l_rc));
            return false;
        }
        
        if (i_candidate.iv_unitPos != l_unitPos)
        {
            return false;
        }
    }
    
    // Match
    return true;
}

}
