/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/attributeTank.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
 *  @file attributeTank.H
 *
 *  @brief Defines the AttributeTank and its associated classes. These are used
 *         to store attributes for Attribute Overriding and Synchronization
 */
#ifndef __TARGETING_COMMON_ATTRTANK_H
#define __TARGETING_COMMON_ATTRTANK_H

#include <stdint.h>
#include <list>
#include <vector>
#include <targeting/adapters/mutexadapter.H>
#include <targeting/common/error.H>

namespace TARGETING
{

/**
 * @class AttributeTank
 *
 * This class is used to store Attributes
 */
class AttributeTank
{
public:
    /**
     * @brief Allocation types
     *
     * This is passed to serializeAttributes
     */
    enum AllocType
    {
        ALLOC_TYPE_MALLOC = 1,
        ALLOC_TYPE_NEW = 2,
    };

    /**
     * @enum AttributeFlags
     *
     * Enumeration of the possible attribute flags. This is a bitmap
     *
     * This is passed to setAttribute
     */
    enum AttributeFlags
    {
        ATTR_FLAG_CONST = 0x01, // Use-case is a constant Attribute Override
        // NEXT         = 0x02,
        // NEXT         = 0x04,
        // NEXT         = 0x08,
    };

    /**
     * @enum TankLayer
     *
     * Enumeration of the software layers that contain AttributeTanks
     */
    enum TankLayer
    {
        TANK_LAYER_NONE,
        TANK_LAYER_FAPI,
        TANK_LAYER_TARG,
        TANK_LAYER_PERM,
        TANK_LAYER_LAST = TANK_LAYER_PERM,
        TANK_LAYER_TERM = 0xFFFFFFFF,
    };

    /**
     * @brief Enumeration of node filter values
     *
     * This is passed to serializeAttributes and clearAllAttributes
     */
    enum NodeFilter
    {
        NODE_FILTER_NONE,
        NODE_FILTER_NOT_ALL_NODES,
        NODE_FILTER_SPECIFIC_NODE_AND_ALL,
        NODE_FILTER_SPECIFIC_NODE,
    };

    // Constants for various fields in AttributeHeader
    static const uint16_t ATTR_POS_NA = 0xffff;      // iv_pos N/A
    static const uint8_t  ATTR_UNIT_POS_NA = 0xff;   // iv_unitPos N/A
    static const uint8_t  ATTR_NODE_NA = 0xf;        // iv_node N/A

    /**
     * @struct AttributeHeader
     *
     * This structure defines all the data for an attribute without the actual
     * attribute value.
     *
     * This is used in an AttributeSerializedChunk and used to store attributes
     * in an AttributeTank
     */
    struct AttributeHeader
    {
        /**
         * @brief Constructor
         */
        AttributeHeader();

        // Public data
        uint32_t iv_attrId;     // Attribute ID
        uint32_t iv_targetType; // Target Type attribute is for
        uint16_t iv_pos;        // For chips/dimms the position
                                // For chiplets the parent chip position
        uint8_t  iv_unitPos;    // For chiplets the position
        uint8_t  iv_node  : 4;  // Target Node number
        uint8_t  iv_flags : 4;  // AttributeFlags enum value(s)
        uint32_t iv_valSize;    // Size of the attribute value in bytes
    };

    /**
     * @struct AttributeSerializedChunk
     *
     * This structure defines a chunk of memory for containing serialized
     * attributes. The memory chunk contains a set of attributes, each is an
     * AttributeHeader followed by a buffer containing the attribute value.
     *
     * A vector of AttributeSerializedChunks is returned by serializeAttributes
     * and a single AttributeSerializedChunk is passed to deserializeAttributes
     *
     * The user must free the memory pointed to by iv_pAttributes before
     * deleting this structure, the reason is that the allocType (malloc/new)
     * and therefore the free type (free/delete[]) was specified in
     * serializeAttributes and the use case is to pass attributes over a
     * mailbox interface which may free memory automatically.
     */
    struct AttributeSerializedChunk
    {
        /**
         * @brief Constructor
         */
        AttributeSerializedChunk();

        uint32_t  iv_size;          // Chunk size in bytes
        uint8_t * iv_pAttributes;   // Pointer to chunk of memory
    };


    typedef std::vector<AttributeTank::AttributeSerializedChunk>
                AttributeSerializedChunks_t;
    /**
     * @brief Default constructor
     */
    AttributeTank();

    /**
     * @brief Destructor. Deletes all Attributes
     */
    virtual ~AttributeTank();

    /**
     * @brief Checks if the platform has enabled synchronization
     *
     * Can be called before storing attributes in a tank for the purposes of
     * synchronization.
     */
    static bool syncEnabled();

    /**
     * @brief Clear all attributes
     *
     * @param[in] i_nodeFilter NODE_FILTER_NONE:
     *                           Clear all attributes
     *                         NODE_FILTER_NOT_ALL_NODES:
     *                           Clear only those attributes that are not for
     *                           all nodes
     *                         NODE_FILTER_SPECIFIC_NODE_AND_ALL:
     *                           Clear only those attributes that are for a
     *                           specific node (i_node) or all nodes
     *                         NODE_FILTER_SPECIFIC_NODE
     *                           Clear only those attributes that are for a
     *                           specific node (i_node)
     * @param[in]  i_node      See i_nodeFilter
     */
    virtual void clearAllAttributes(
        const NodeFilter i_nodeFilter = NODE_FILTER_NONE,
        const uint8_t i_node = ATTR_NODE_NA);

    /**
     * @brief Clear any non-const attribute for a specified ID and Target
     *
     * This is called on an OverrideAttributeTank to clear any non-const
     * Attribute Override when an attribute is set
     *
     * @param[in] i_attrId     Attribute ID
     * @param[in] i_targetType Target Type attribute is for
     * @param[in] i_pos        Target Position
     * @param[in] i_unitPos    Target Unit Position
     * @param[in] i_node       Target Node
     */
    virtual void clearNonConstAttribute(const uint32_t i_attrId,
                                        const uint32_t i_targetType,
                                        const uint16_t i_pos,
                                        const uint8_t i_unitPos,
                                        const uint8_t i_node);

    /**
     * @brief Set an Attribute
     *
     * The attribute value is copied from i_pVal. If the attribute already
     * exists then it is replaced with the new one
     *
     * This is called on an OverrideAttributeTank to setup an override.
     *
     * This is called on a SyncAttributeTank to save an Attribute for syncing
     * when an attribute is set
     *
     * @param[in] i_attrId     Attribute ID
     * @param[in] i_targetType Target Type attribute is for
     * @param[in] i_pos        Target Position
     * @param[in] i_unitPos    Target Unit Position
     * @param[in] i_node       Target Node
     * @param[in] i_flags      Flags (ORed set of AttributeFlags)
     * @param[in] i_valSize    Size of attribute value in bytes
     * @param[in] i_pVal       Pointer to attribute value
     */
    virtual void setAttribute(const uint32_t i_attrId,
                              const uint32_t i_targetType,
                              const uint16_t i_pos,
                              const uint8_t i_unitPos,
                              const uint8_t i_node,
                              const uint8_t i_flags,
                              const uint32_t i_valSize,
                              const void * i_pVal);

    /**
     * @brief Get a copy of an Attribute
     *
     * This is called on an OverrideAttributeTank to query/get an Attribute
     * Override when an attribute is got
     *
     * @param[in]  i_attrId     Attribute ID
     * @param[in]  i_targetType Target Type attribute is for
     * @param[in]  i_pos        Target Position
     * @param[in]  i_unitPos    Target Unit Position
     * @param[in]  i_node       Target Node
     * @param[out] o_pVal       Pointer to attribute value
     *
     * return true if attribute exists and a copy was written to o_pVal
     */
    virtual bool getAttribute(const uint32_t i_attrId,
                              const uint32_t i_targetType,
                              const uint16_t i_pos,
                              const uint8_t i_unitPos,
                              const uint8_t i_node,
                              void * o_pVal) const;

    /**
     * @brief Serialize all Attributes into newly allocated memory chunks
     *
     * The use case is for getting the attributes to send across an interface
     * to another AttributeTank on a another subsystem. The alloc type can be
     * specified to support interface code that automatically frees buffers
     * after sending (Hostboot mailbox uses malloc/free, FSP mailbox uses
     * new[]/delete[]).
     *
     * @param[in]  i_allocType  Which allocation is used to allocated memory
     * @param[in]  i_chunkSize  Max chunk size to use
     * @param[out] o_attributes Ref to vector that AttributeSerializedChunk
     *                          structs are added to.
     *                          The caller must free (if MALLOC)
     *                          or delete[] (if NEW) each chunk's memory
     * @param[in]  i_nodeFilter NODE_FILTER_NONE:
     *                            Get all attributes
     *                          NODE_FILTER_NOT_ALL_NODES:
     *                            Get only those attributes that are not for all
     *                            nodes
     *                          NODE_FILTER_SPECIFIC_NODE_AND_ALL:
     *                            Get only those attributes that are for a
     *                            specific node (i_node) or all nodes
     *                          NODE_FILTER_SPECIFIC_NODE
     *                            Get only those attributes that are for a
     *                            specific node (i_node)
     * @param[in]  i_node       See i_nodeFilter
     */
    virtual void serializeAttributes(
        const AllocType i_allocType,
        const uint32_t i_chunkSize,
        std::vector<AttributeSerializedChunk> & o_attributes,
        const NodeFilter i_nodeFilter = NODE_FILTER_NONE,
        const uint8_t i_node = ATTR_NODE_NA) const;

    /**
     * @brief Deserialize a chunk of Attributes into the tank
     *
     * The use case is for receiving a chunk of serialized attributes from
     * another AttributeTank on a another subsystem. The caller is responsible
     * for freeing/deleting the memory in the chunk after calling this function.
     *
     * @param[in]  i_attributes Reference to AttributeSerializedChunk containing
     *                          attributes.
     */
    virtual void deserializeAttributes(
        const AttributeSerializedChunk & i_attributes);

    /**
     * @brief Fast inline check if any attributes exist in the tank
     *
     * The use case is for performing a very fast check to see if attributes
     * exist in the tank before calling attributeExists to check that an
     * attribute with the specified ID exists in the tank. This is done without
     * a lock for maximum performance.
     *
     * return true if any attributes exist
     */
    virtual bool attributesExist() const { return iv_attributesExist; }

    /**
     * @brief Check if an attribute exists in the tank
     *
     * The use case is for performing a check to see if the specified attribute
     * exists in the tank before doing the work to figure out a Target's type/
     * position and calling a function to clear or get attributes. The user is
     * expected to call attributesExist() to check if any attributes exist in
     * the tank before calling this function.
     *
     * @param[in] i_attrId Attribute ID
     *
     * return true if any attributes exist
     */
    virtual bool attributeExists(const uint32_t i_attrId) const;

    /**
     * @brief This function writes attributes in an AttributeTank to targeting
     *
     * This is called for the permanent AttributeTank in getAttrOverrides()
     *
     * @return errlHndl_t Error log handle.
     */
    errlHndl_t writePermAttributes();

    /**
     * @brief This retuns the number of attributes overrides in an attr tank
     *
     * @return size_t Number of overrides in attr tank
     */
    size_t size() const;

private:
    // Copy constructor and assignment operator disabled
    AttributeTank(const AttributeTank & i_right);
    AttributeTank & operator=(const AttributeTank & i_right);

    /**
     * @struct Attribute
     *
     * This structure defines a single attribute.
     */
    struct Attribute
    {
        /**
         * @brief Constructor
         */
        Attribute();

        /**
         * @brief Destructor. Frees memory
         */
        ~Attribute();

        // Public data
        AttributeHeader iv_hdr;
        uint8_t * iv_pVal;      // Pointer to attribute value
    };

    // The attributes
    // Note: A possible performance boost could be to store the elements in a
    //       map, the key could be a sub-structure.
    bool iv_attributesExist;
    std::list<Attribute *> iv_attributes;
    typedef std::list<Attribute *>::iterator AttributesItr_t;
    typedef std::list<Attribute *>::const_iterator AttributesCItr_t;

    // Lock for thread safety (class provided by platform)
    mutable TARG_MUTEX_TYPE iv_mutex;
};

} // namespace TARGETING

#endif
