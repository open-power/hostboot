/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwpf/fapi/fapiAttributeOverride.H $
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
 *  @file fapiAttributeOverride.H
 *
 *  @brief Defines the AttributeOverrides and AttributeOverride classes. A
 *         platform can choose to use an AttributeOverrides object to store
 *         Attribute Overrides.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/07/2012  Created
 */

#ifndef FAPIATTROVERRIDE_H_
#define FAPIATTROVERRIDE_H_

#include <stdint.h>
#include <list>
#include <fapiAttributeIds.H>
#include <fapiTarget.H>

namespace fapi
{

/**
 * @enum AttributeOverrideType
 *
 * Enumeration of the possible attribute override types
 */
enum AttributeOverrideType
{
    ATTR_OVERRIDE_CONST = 1,     // Not cleared by a FAPI_ATTR_SET
    ATTR_OVERRIDE_NON_CONST = 2, // Cleared by a FAPI_ATTR_SET
    ATTR_OVERRIDE_CLEAR_ALL = 3, // Clear all overrides
};

// Constants for various fields in AttributeOverrides
const uint16_t ATTR_POS_NA = 0xffff;   // iv_pos not applicable
const uint8_t ATTR_UNIT_POS_NA = 0xff; // iv_unitPos not applicable
const uint8_t ATTR_ARRAYD_NA = 0xff;   // iv_arayX not applicable

/**
 * @struct AttributeOverride
 *
 * This structure defines a single attribute override. In the case of an array
 * attribute, it is an override for a single element
 */
struct AttributeOverride
{
    uint64_t iv_overrideVal;  // Large enough to hold the biggest attribute size
    uint32_t iv_attrId;       // fapi::AttributeId enum value
    uint32_t iv_targetType;   // fapi::TargetType enum value
    uint16_t iv_pos;          // For chips/dimms the position
                              // For chiplets the parent chip position
    uint8_t  iv_unitPos;      // For chiplets the position
    uint8_t  iv_overrideType; // fapi::AttributeOverrideType enum value
    uint8_t  iv_arrayD1;      // Applies to element D1 in 1D or more array atts
    uint8_t  iv_arrayD2;      // Applies to element D2 in 2D or more array atts
    uint8_t  iv_arrayD3;      // Applies to element D3 in 3D or more array atts
    uint8_t  iv_arrayD4;      // Applies to element D4 in 4D array atts
};

/**
 * @class AttributeOverrides
 *
 * This class can be used to set and query attribute overrides
 */
class AttributeOverrides
{
public:
    /**
     * @brief Default constructor
     */
    AttributeOverrides();
    
    /**
     * @brief Destructor
     */
    ~AttributeOverrides();
    
    /**
     * @brief Clear all overrides
     */
    void clearOverrides();
    
    /**
     * @brief Clear any non-const override for a specified ID and Target
     * 
     * @param[in] i_attrId  Attribute ID
     * @param[in] i_pTarget Pointer to Target (NULL if system)
     */
    void clearNonConstOverride(const fapi::AttributeId i_attrId,
                               const fapi::Target * const i_pTarget);
    
    /**
     * @brief Set an override
     *
     * Note that no checking is done for duplicate overrides (an override on an
     * attribute that already has an override) for performance. If a duplicate
     * override is done then getOverride will return the first one.
     *
     * @param[in] i_override Reference to override structure, this is copied
     */
    void setOverride(const AttributeOverride & i_override);
    
    /**
     * @brief Get an override
     * 
     * Note that for array attributes, this must be called repeatedly, to query
     * an override for each element of the array
     * 
     * @param[in]  i_attrId      Attribute ID
     * @param[in]  i_pTarget     Pointer to Target (NULL if system)
     * @param[out] o_overrideVal Reference that is filled in with the override
     * @param[in]  i_arrayD1     Array dimension 1 if applicable
     * @param[in]  i_arrayD2     Array dimension 2 if applicable
     * @param[in]  i_arrayD3     Array dimension 3 if applicable
     * @param[in]  i_arrayD4     Array dimension 4 if applicable
     *
     * return true if override exists and was returned.
     */
    bool getOverride(const fapi::AttributeId i_attrId,
                     const fapi::Target * const i_pTarget,
                     uint64_t & o_overrideVal,
                     const uint8_t i_arrayD1 = ATTR_ARRAYD_NA,
                     const uint8_t i_arrayD2 = ATTR_ARRAYD_NA,
                     const uint8_t i_arrayD3 = ATTR_ARRAYD_NA,
                     const uint8_t i_arrayD4 = ATTR_ARRAYD_NA);
    
    /**
     * @brief Returns if any overrides exist
     * 
     * This is only expected to be called by unit test
     * 
     * return true if any overrides exist
     */
    bool overridesExist();

private:
    // Copy constructor and assignment operator disabled
    AttributeOverrides(const AttributeOverrides & i_right);
    AttributeOverrides & operator=(const AttributeOverrides & i_right);
    
    /**
     * @brief Returns if the specified override is for the specified
     *        attribute ID and Target
     * 
     * @param[in] i_attrId    Attribute ID
     * @param[in] i_pTarget   Pointer to Target (NULL if system)
     * @param[in] i_candidate Reference to AttributeOverride
     * 
     * @return true if the AttributeOverride matches
     */
    static bool overrideMatch(const fapi::AttributeId i_attrId,
                              const fapi::Target * const i_pTarget,
                              const AttributeOverride & i_candidate);
    
    /**
     * @brief Locks the AttributeOverrides object
     * 
     * Implemented by the platform
     */
    static void platLock();
    
    /**
     * @brief Unlocks the AttributeOverrides object
     * 
     * Implemented by the platform
     */
    static void platUnlock();
    
    // The attribute overrides
    bool iv_overridesExist;
    std::list<AttributeOverride *> iv_overrides;
    typedef std::list<AttributeOverride *>::iterator OverridesItr_t;
    typedef std::list<AttributeOverride *>::const_iterator OverridesCItr_t;
    
};

}

#endif // FAPIATTROVERRIDE_H_
