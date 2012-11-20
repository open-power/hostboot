/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/fapi/fapiAttributeTank.H $               */
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
 *  @file fapiAttributeTank.H
 *
 *  @brief Defines the AttributeTank and Attribute classes. A platform can
 *         choose to use these classes to store attributes for Attribute
 *         Overriding and Synchronization
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/07/2012  Created
 *                          mjjones     10/15/2012  Moved to general AttributeTank.
 */

#ifndef FAPIATTRTANK_H_
#define FAPIATTRTANK_H_

#include <stdint.h>
#include <list>
#include <vector>
#include <fapiAttributeIds.H>

namespace fapi
{

class Target; // Forward Reference

/**
 * @enum AttributeFlags
 *
 * Enumeration of the possible attribute flags. This is a bitmap
 */
enum AttributeFlags
{
    ATTR_FLAG_CONST = 1,     // Not cleared by clearNonConstAttribute
                             // Use-case is a constant Attribute Override
};

// Constants for various fields in Attribute
const uint16_t ATTR_POS_NA = 0xffff;      // iv_pos not applicable
const uint8_t  ATTR_UNIT_POS_NA = 0xff;   // iv_unitPos not applicable
const uint8_t  ATTR_ARRAYD_NA = 0xff;     // iv_arrayDX not applicable

/**
 * @struct Attribute
 *
 * This structure defines a single attribute value. In the case of an array
 * attribute, it is the value of one specific element
 */
struct Attribute
{
    uint64_t iv_val;        // Value of attribute.
    uint32_t iv_attrId;     // fapi::AttributeId enum value
    uint32_t iv_targetType; // fapi::TargetType enum value
    uint16_t iv_pos;        // For chips/dimms the position
                            // For chiplets the parent chip position
    uint8_t  iv_unitPos;    // For chiplets the position
    uint8_t  iv_flags;      // fapi::AttributeFlags enum value
    uint8_t  iv_arrayD1;    // Applies to element D1 in 1D or more array atts
    uint8_t  iv_arrayD2;    // Applies to element D2 in 2D or more array atts
    uint8_t  iv_arrayD3;    // Applies to element D3 in 3D or more array atts
    uint8_t  iv_arrayD4;    // Applies to element D4 in 4D array atts
};

/**
 * @struct AttributeChunk
 *
 * This structure defines a chunk of memory containing Attributes. The max chunk
 * size is chosen to be reasonable to send over a mailbox type interface
 * between subsystems
 */
struct AttributeChunk
{
    static const size_t MAX_CHUNK_SIZE_BYTES = 4096;
    static const size_t MAX_ATTRS_PER_CHUNK =
        MAX_CHUNK_SIZE_BYTES / sizeof(Attribute);
    size_t iv_numAttributes;  // Number of Attributes in chunk
    uint8_t * iv_pAttributes; // Pointer to chunk of memory
};

/**
 * @class AttributeTank
 *
 * This class can be used to store Attributes
 */
class AttributeTank
{
public:
    /**
     * @brief Allocation types
     */
    enum AllocType
    {
        ALLOC_TYPE_MALLOC = 1,
        ALLOC_TYPE_NEW = 2,
    };
    
    /**
     * @brief Default constructor
     */
    AttributeTank();
    
    /**
     * @brief Destructor
     */
    virtual ~AttributeTank();
    
    /**
     * @brief Clear all attributes
     */
    virtual void clearAllAttributes();
    
    /**
     * @brief Clear any non-const attribute for a specified ID and Target
     * 
     * Note that for array attributes, this clears all values of the array
     * 
     * This is called on an OverrideAttributeTank to clear a non-const
     * Attribute Override during FAPI_ATTR_SET
     * 
     * @param[in] i_attrId  Attribute ID
     * @param[in] i_pTarget Pointer to Target (NULL if system)
     */
    virtual void clearNonConstAttribute(const fapi::AttributeId i_attrId,
                                        const fapi::Target * const i_pTarget);
    
    /**
     * @brief Set an Attribute
     * 
     * Note that for array attributes, this must be called repeatedly, to set
     * the attribute value for each element of the array
     * 
     * If the attribute already exists then it is replaced with the new one
     * 
     * This is called on a SyncAttributeTank to save an Attribute for syncing
     * during FAPI_ATTR_SET
     * 
     * @param[in] i_attrId  Attribute ID
     * @param[in] i_pTarget Pointer to Target (NULL if system)
     * @param[in] i_val     Value
     * @param[in] i_arrayD1 Array dimension 1 if applicable
     * @param[in] i_arrayD2 Array dimension 2 if applicable
     * @param[in] i_arrayD3 Array dimension 3 if applicable
     * @param[in] i_arrayD4 Array dimension 4 if applicable
     */
    virtual void setAttribute(const fapi::AttributeId i_attrId,
                              const fapi::Target * const i_pTarget,
                              const uint64_t i_val,
                              const uint8_t i_arrayD1 = ATTR_ARRAYD_NA,
                              const uint8_t i_arrayD2 = ATTR_ARRAYD_NA,
                              const uint8_t i_arrayD3 = ATTR_ARRAYD_NA,
                              const uint8_t i_arrayD4 = ATTR_ARRAYD_NA);
    
    /**
     * @brief Set an attribute
     *
     * Note that for array attributes, this must be called repeatedly, to set
     * the attribute value for each element of the array
     * 
     * If the attribute already exists then it is replaced with the new one
     * 
     * @param[in] i_attribute Reference to Attribute structure, this is copied
     */
    virtual void setAttribute(const Attribute & i_attribute);
    
    /**
     * @brief Get a copy of an Attribute
     * 
     * Note that for array attributes, this must be called repeatedly, to query
     * the attribute value for each element of the array
     * 
     * This is called on an OverrideAttributeTank to query/get an Attribute
     * Override during FAPI_ATTR_GET
     * 
     * @param[in]  i_attrId  Attribute ID
     * @param[in]  i_pTarget Pointer to Target (NULL if system)
     * @param[out] o_val     Reference that is filled in with the attr value
     * @param[in]  i_arrayD1 Array dimension 1 if applicable
     * @param[in]  i_arrayD2 Array dimension 2 if applicable
     * @param[in]  i_arrayD3 Array dimension 3 if applicable
     * @param[in]  i_arrayD4 Array dimension 4 if applicable
     *
     * return true if attribute exists and a copy was returned.
     */
    virtual bool getAttribute(const fapi::AttributeId i_attrId,
                              const fapi::Target * const i_pTarget,
                              uint64_t & o_val,
                              const uint8_t i_arrayD1 = ATTR_ARRAYD_NA,
                              const uint8_t i_arrayD2 = ATTR_ARRAYD_NA,
                              const uint8_t i_arrayD3 = ATTR_ARRAYD_NA,
                              const uint8_t i_arrayD4 = ATTR_ARRAYD_NA) const;
    
    /**
     * @brief Get a copy of all Attributes into newly allocated memory chunks
     * 
     * The use case is for getting the attributes to send across the FSP/
     * Hostboot mailbox. Mailbox frees the data memory using free on Hostboot
     * and delete[] on FSP.
     * 
     * @param[in]  i_allocType  Which allocation is used to allocated memory
     * @param[out] o_attributes Reference to vector that AttributeChunk structs
     *                          are added to. The caller must free (if MALLOC)
     *                          or delete[] (if NEW) each chunk's memory
     */
    virtual void getAllAttributes(
        AllocType i_allocType,
        std::vector<AttributeChunk> & o_attributes) const;
    
    /**
     * @brief Returns if any attributes exist in the tank
     * 
     * This is only expected to be called by unit test
     * 
     * return true if any attributes exist
     */
    virtual bool attributesExist();

protected:
    // The name of the Tank used in traces, a derived class can set
    const char * iv_pName;
    
private:
    // Copy constructor and assignment operator disabled
    AttributeTank(const AttributeTank & i_right);
    AttributeTank & operator=(const AttributeTank & i_right);
    
    /**
     * @brief Returns the Attribute::iv_targetType of the specified Target
     * 
     * @param[in] i_pTarget Pointer to Target
     * 
     * @return uint32_t target-type
     */
    static uint32_t getTargetType(const fapi::Target * const i_pTarget);
    
    /**
     * @brief Returns the Attribute::iv_pos of the specified Target
     * 
     * @param[in] i_pTarget Pointer to Target
     * 
     * @return uint16_t position
     */
    static uint16_t getTargetPos(const fapi::Target * const i_pTarget);
    
    /**
     * @brief Returns the Attribute::iv_unitPos of the specified Target
     * 
     * @param[in] i_pTarget Pointer to Target
     * 
     * @return uint8_t unit-position
     */
    static uint8_t getTargetUnitPos(const fapi::Target * const i_pTarget);
    
    /**
     * @brief Locks the AttributeTank object
     * 
     * Pure virtual function that must be overridden by a concrete derived class
     * and implemented by the platform
     */
    virtual void platLock() const = 0 ;
    
    /**
     * @brief Unlocks the AttributeTank object
     * 
     * Pure virtual function that must be overridden by a concrete derived class
     * and implemented by the platform
     */
    virtual void platUnlock() const = 0;
    
    // The attributes
    // Note: A possible performance boost could be to store the elements in a
    //       map, the key could be a sub-structure.
    bool iv_attributesExist;
    std::list<Attribute> iv_attributes;
    typedef std::list<Attribute>::iterator AttributesItr_t;
    typedef std::list<Attribute>::const_iterator AttributesCItr_t;
    
};

/**
 * @class OverrideAttributeTank
 *
 * This class can be used to store a set of attribute overrides. It is provided
 * to allow a platform to create a singleton Tank for holding overrides
 */
class OverrideAttributeTank : public AttributeTank
{
public:
    OverrideAttributeTank();
    
private:
    // Copy constructor and assignment operator disabled
    OverrideAttributeTank(const OverrideAttributeTank & i_right);
    OverrideAttributeTank & operator=(const OverrideAttributeTank & i_right);
    
    /**
     * @brief Locks the OverrideAttributeTank object
     * 
     * Must be implemented by the platform
     */
    virtual void platLock() const;
    
    /**
     * @brief Unlocks the AttributeTank object
     * 
     * Must be implemented by the platform
     */
    virtual void platUnlock() const;
};

/**
 * @class SyncAttributeTank
 *
 * This class can be used to store a set of attributes to sync. It is provided
 * to allow a platform to create a singleton Tank for holding attributes to sync
 */
class SyncAttributeTank : public AttributeTank
{
public:
    SyncAttributeTank();
    
    /**
     * @brief Set an Attribute
     * 
     * This overrides the AttributeTank function, it checks if the platform
     * has enabled synchronization before saving the attribute in the tank
     * 
     * @param[in] i_attrId  Attribute ID
     * @param[in] i_pTarget Pointer to Target (NULL if system)
     * @param[in] i_val     Value
     * @param[in] i_arrayD1 Array dimension 1 if applicable
     * @param[in] i_arrayD2 Array dimension 2 if applicable
     * @param[in] i_arrayD3 Array dimension 3 if applicable
     * @param[in] i_arrayD4 Array dimension 4 if applicable
     */
    virtual void setAttribute(const fapi::AttributeId i_attrId,
                              const fapi::Target * const i_pTarget,
                              const uint64_t i_val,
                              const uint8_t i_arrayD1 = ATTR_ARRAYD_NA,
                              const uint8_t i_arrayD2 = ATTR_ARRAYD_NA,
                              const uint8_t i_arrayD3 = ATTR_ARRAYD_NA,
                              const uint8_t i_arrayD4 = ATTR_ARRAYD_NA);

    /**
     * @brief Set an attribute
     *
     * This overrides the AttributeTank function, it simply calls the base class
     * function (needed because the other version of setAttribute was
     * overridden)
     *
     * @param[in] i_attribute Reference to Attribute structure, this is copied
     */
    virtual void setAttribute(const Attribute & i_attribute)
    {
        AttributeTank::setAttribute(i_attribute);
    }
    
private:
    // Copy constructor and assignment operator disabled
    SyncAttributeTank(const SyncAttributeTank & i_right);
    SyncAttributeTank & operator=(const SyncAttributeTank & i_right);
    
    /**
     * @brief Checks if the platform has enabled synchronization
     * 
     * Must be implemented by the platform
     */
    static bool platSyncEnabled();
    
    /**
     * @brief Locks the OverrideAttributeTank object
     * 
     * Must be implemented by the platform
     */
    virtual void platLock() const;
    
    /**
     * @brief Unlocks the AttributeTank object
     * 
     * Must be implemented by the platform
     */
    virtual void platUnlock() const;
};

/**
 * @brief This template function gets a 1D array attribute from an AttributeTank
 *
 * @param[in]  i_attrId  Attribute ID
 * @param[in]  i_pTarget Pointer to Target the attribute is for (NULL if system)
 * @param[in]  i_tank    Reference to AttributeTank
 * @param[out] o_1dArray Reference to 1D array where attribute will be copied to
 * @return bool True if override was returned
 */
template <typename T, uint8_t SZ1>
bool getAttributeT(const fapi::AttributeId i_attrId,
                   const fapi::Target * const i_pTarget,
                   fapi::AttributeTank & i_tank,
                   T(&o_1dArray)[SZ1])
{
    uint64_t l_val = 0;

    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        if (!(i_tank.getAttribute(i_attrId, i_pTarget, l_val, d1)))
        {
            // For array attributes, all elements must be overridden
            return false;
        }
        else
        {
            // Standard conversion converts uint64_t to attribute type
            o_1dArray[d1] = l_val;
        }
    }

    return true;
}

/**
 * @brief This template function gets a 2D array attribute from an AttributeTank
 *
 * @param[in]  i_attrId  Attribute ID
 * @param[in]  i_pTarget Pointer to Target the attribute is for (NULL if system)
 * @param[in]  i_tank    Reference to AttributeTank
 * @param[out] o_2dArray Reference to 2D array where attribute will be copied to
 * @return bool True if override was returned
 */
template <typename T, uint8_t SZ1, uint8_t SZ2>
bool getAttributeT(const fapi::AttributeId i_attrId,
                   const fapi::Target * const i_pTarget,
                   fapi::AttributeTank & i_tank,
                   T(&o_2dArray)[SZ1][SZ2])
{
    uint64_t l_val = 0;

    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        for (uint8_t d2 = 0; d2 < SZ2; d2++)
        {
            if (!(i_tank.getAttribute(i_attrId, i_pTarget, l_val, d1, d2)))
            {
                // For array attributes, all elements must be overridden
                return false;
            }
            else
            {
                // Standard conversion converts uint64_t to attribute type
                o_2dArray[d1][d2] = l_val;
            }
        }
    }

    return true;
}

/**
 * @brief This template function gets a 3D array attribute from an AttributeTank
 *
 * @param[in]  i_attrId  Attribute ID
 * @param[in]  i_pTarget Pointer to Target the attribute is for (NULL if system)
 * @param[in]  i_tank    Reference to AttributeTank
 * @param[out] o_3dArray Reference to 3D array where attribute will be copied to
 * @return bool True if override was returned
 */
template <typename T, uint8_t SZ1, uint8_t SZ2, uint8_t SZ3>
bool getAttributeT(const fapi::AttributeId i_attrId,
                   const fapi::Target * const i_pTarget,
                   fapi::AttributeTank & i_tank,
                   T(&o_3dArray)[SZ1][SZ2][SZ3])
{
    uint64_t l_val = 0;

    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        for (uint8_t d2 = 0; d2 < SZ2; d2++)
        {
            for (uint8_t d3 = 0; d3 < SZ3; d3++)
            {
                if (!(i_tank.getAttribute(i_attrId, i_pTarget, l_val, d1, d2,
                                          d3)))
                {
                    // For array attributes, all elements must be overridden
                    return false;
                }
                else
                {
                    // Standard conversion converts uint64_t to attribute type
                    o_3dArray[d1][d2][d3] = l_val;
                }
            }
        }
    }

    return true;
}

/**
 * @brief This template function gets a 4D array attribute from an AttributeTank
 *
 * @param[in]  i_attrId  Attribute ID
 * @param[in]  i_pTarget Pointer to Target the attribute is for (NULL if system)
 * @param[in]  i_tank    Reference to AttributeTank
 * @param[out] o_4dArray Reference to 4D array where attribute will be copied to
 * @return bool True if override was returned
 */
template <typename T, uint8_t SZ1, uint8_t SZ2, uint8_t SZ3, uint8_t SZ4>
bool getAttributeT(const fapi::AttributeId i_attrId,
                   const fapi::Target * const i_pTarget,
                   fapi::AttributeTank & i_tank,
                   T(&o_4dArray)[SZ1][SZ2][SZ3][SZ4])
{
    uint64_t l_val = 0;

    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        for (uint8_t d2 = 0; d2 < SZ2; d2++)
        {
            for (uint8_t d3 = 0; d3 < SZ3; d3++)
            {
                for (uint8_t d4 = 0; d4 < SZ4; d4++)
                {
                    if (!(i_tank.getAttribute(i_attrId, i_pTarget, l_val, d1, d2,
                                              d3, d4)))
                    {
                        // For array attributes, all elements must be overridden
                        return false;
                    }
                    else
                    {
                        // Standard conversion converts uint64_t to attribute
                        // type
                        o_4dArray[d1][d2][d3][d4] = l_val;
                    }
                }
            }
        }
    }

    return true;
}

/**
 * @brief This template function gets a non-array attribute from an
 *        AttributeTank
 *
 * @param[in]  i_attrId  Attribute ID
 * @param[in]  i_pTarget Pointer to Target the attribute is for (NULL if system)
 * @param[in]  i_tank    Reference to AttributeTank
 * @param[out] o_val     Reference to variable where attribute will be copied to
 * @return bool True if override was returned
 */
template <typename T>
bool getAttributeT(const fapi::AttributeId i_attrId,
                   const fapi::Target * const i_pTarget,
                   fapi::AttributeTank & i_tank,
                   T & o_val)
{
    uint64_t l_val = 0;

    if (!(i_tank.getAttribute(i_attrId, i_pTarget, l_val)))
    {
        return false;
    }

    o_val = static_cast<T>(l_val);
    return true;
}

/**
 * @brief This template function sets a 1D array attribute into an AttributeTank
 *
 * @param[in] i_attrId  Attribute ID
 * @param[in] i_pTarget Pointer to Target the attribute is for (NULL if system)
 * @param[in] i_tank    Reference to AttributeTank
 * @param[in] i_1dArray Reference to 1D array containing attribute
 */
template <typename T, uint8_t SZ1>
void setAttributeT(const fapi::AttributeId i_attrId,
                   const fapi::Target * const i_pTarget,
                   fapi::AttributeTank & i_tank,
                   const T(&i_1dArray)[SZ1])
{
    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        i_tank.setAttribute(i_attrId, i_pTarget, i_1dArray[d1], d1);
    }
}

/**
 * @brief This template function sets a 2D array attribute into an AttributeTank
 *
 * @param[in] i_attrId  Attribute ID
 * @param[in] i_pTarget Pointer to Target the attribute is for (NULL if system)
 * @param[in] i_tank    Reference to AttributeTank
 * @param[in] i_2dArray Reference to 2D array containing attribute
 */
template <typename T, uint8_t SZ1, uint8_t SZ2>
void setAttributeT(const fapi::AttributeId i_attrId,
                   const fapi::Target * const i_pTarget,
                   fapi::AttributeTank & i_tank,
                   const T(&i_2dArray)[SZ1][SZ2])
{
    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        for (uint8_t d2 = 0; d2 < SZ2; d2++)
        {
            i_tank.setAttribute(i_attrId, i_pTarget, i_2dArray[d1][d2], d1, d2);
        }
    }
}

/**
 * @brief This template function sets a 3D array attribute into an AttributeTank
 *
 * @param[in] i_attrId  Attribute ID
 * @param[in] i_pTarget Pointer to Target the attribute is for (NULL if system)
 * @param[in] i_tank    Reference to AttributeTank
 * @param[in] i_3dArray Reference to 3D array containing attribute
 */
template <typename T, uint8_t SZ1, uint8_t SZ2, uint8_t SZ3>
void setAttributeT(const fapi::AttributeId i_attrId,
                  const fapi::Target * const i_pTarget,
                  fapi::AttributeTank & i_tank,
                  const T(&i_3dArray)[SZ1][SZ2][SZ3])
{
    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        for (uint8_t d2 = 0; d2 < SZ2; d2++)
        {
            for (uint8_t d3 = 0; d3 < SZ3; d3++)
            {
                i_tank.setAttribute(i_attrId, i_pTarget, i_3dArray[d1][d2][d3],
                                    d1, d2, d3);
            }
        }
    }
}

/**
 * @brief This template function sets a 4D array attribute into an AttributeTank
 *
 * @param[in] i_attrId  Attribute ID
 * @param[in] i_pTarget Pointer to Target the attribute is for (NULL if system)
 * @param[in] i_tank    Reference to AttributeTank
 * @param[in] i_4dArray Reference to 4D array containing attribute
 */
template <typename T, uint8_t SZ1, uint8_t SZ2, uint8_t SZ3, uint8_t SZ4>
void setAttributeT(const fapi::AttributeId i_attrId,
                  const fapi::Target * const i_pTarget,
                  fapi::AttributeTank & i_tank,
                  const T(&i_4dArray)[SZ1][SZ2][SZ3][SZ4])
{
    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        for (uint8_t d2 = 0; d2 < SZ2; d2++)
        {
            for (uint8_t d3 = 0; d3 < SZ3; d3++)
            {
                for (uint8_t d4 = 0; d4 < SZ4; d4++)
                {
                    i_tank.setAttribute(i_attrId, i_pTarget,
                                     i_4dArray[d1][d2][d3][d4], d1, d2, d3, d4);
                }
            }
        }
    }
}

/**
 * @brief This template function sets a non-array attribute into an
 *        AttributeTank
 *
 * @param[in] i_attrId  Attribute ID
 * @param[in] i_pTarget Pointer to Target the attribute is for (NULL if system)
 * @param[in] i_tank    Reference to AttributeTank
 * @param[in] i_val     Reference to variable containing attribute
 */
template <typename T>
void setAttributeT(const fapi::AttributeId i_attrId,
                   const fapi::Target * const i_pTarget,
                   fapi::AttributeTank & i_tank,
                   const T & i_val)
{
    i_tank.setAttribute(i_attrId, i_pTarget, i_val);
}

} // namespace fapi

#endif // FAPIATTRTANK_H_
