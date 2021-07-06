/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/attributeTank.H $            */
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
#include <attributeenums.H>       // TARGETING::ATTRIBUTE_ID
#ifndef STANDALONE_COMPILE
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
#else
namespace AttributeTank
{
#endif
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
#if __BYTE_ORDER == __BIG_ENDIAN
        // Public data
        uint32_t iv_attrId;     // Attribute ID
        uint32_t iv_targetType; // Target Type attribute is for
        uint16_t iv_pos;        // For chips/dimms the position
                                // For chiplets the parent chip position
        uint8_t  iv_unitPos;    // For chiplets the position
        uint8_t  iv_node  : 4;  // Target Node number
        uint8_t  iv_flags : 4;  // AttributeFlags enum value(s)
        uint32_t iv_valSize;    // Size of the attribute value in bytes
#else
        uint32_t iv_attrId;     // Attribute ID
        uint32_t iv_targetType; // Target Type attribute is for
        uint16_t iv_pos;        // For chips/dimms the position
                                // For chiplets the parent chip position
        uint8_t  iv_unitPos;    // For chiplets the position
        uint8_t  iv_flags : 4;  // AttributeFlags enum value(s)
        uint8_t  iv_node  : 4;  // Target Node number
        uint32_t iv_valSize;    // Size of the attribute value in bytes
#endif
    };
#ifndef STANDALONE_COMPILE

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
        Attribute()
        : iv_hdr(),
          iv_pVal(NULL)
        {
        }

        /**
         * @brief Destructor. Frees memory
         */
        ~Attribute()
        {
            delete[] iv_pVal;
            iv_pVal = NULL;
        }

        /**
         * @brief Set the Attribute ID
         */
        void setId(const uint32_t i_attrId)
        {
            iv_hdr.iv_attrId = i_attrId;
        }

        /**
         * @brief Set the Attribute Target Type
         */
        void setTargetType(const uint32_t i_targetType)
        {
            iv_hdr.iv_targetType = i_targetType;
        }

        /**
         * @brief Set the Attribute Position
         */
        void setPosition(const uint16_t i_pos)
        {
            iv_hdr.iv_pos = i_pos;
        }

        /**
         * @brief Set the Attribute Unit Position
         */
        void setUnitPosition(const uint8_t i_unitPos)
        {
            iv_hdr.iv_unitPos = i_unitPos;
        }

        /**
         * @brief Set the Attribute Node
         */
        void setNode(const uint8_t i_node)
        {
            iv_hdr.iv_node = i_node;
        }

        /**
         * @brief Set the Attribute Flags
         */
        void setFlags(const uint8_t i_flags)
        {
            iv_hdr.iv_flags = i_flags;
        }

        /**
         * @brief Get the size of all the Attribute's data members,
         *        aggregated together
         *
         * return Aggregated size of the Attribute's data members
         */
        uint32_t getSize() const
        {
            return (sizeof(iv_hdr) + iv_hdr.iv_valSize);
        }

        /**
         * @brief Get a constant reference to the Attribute Header.
         *        Returning a reference for fast retrieval.
         *
         * @note Caller should not attempt to modify contents of the
         *       Attribute Header.  Use appropriate Attribute set methods
         *
         * return A constant reference to the Attribute Header
         */
        const AttributeHeader & getHeader() const
        {
            return iv_hdr;
        }

        /**
         * @brief Set the Attribute Value to a copy of the given buffer
         *
         * @pre Passing in nonsensical parameters will produce unpredictable
         *      results, ie passing in a null buffer with size > 0
         *
         * @note Passing in a null buffer with size 0 will clear the value
         *
         * @param[in] i_buffer The buffer that contains the value to
         *                     be copied
         * @param[in] i_bufferSize Size of the given buffer
         *
         * return The size of the data that was copied
         */
        uint32_t setValue(const void * const i_buffer,
                          const uint32_t i_bufferSize)

        {
            // Reuse storage when possible
            if (i_bufferSize != iv_hdr.iv_valSize)
            {
                // Clean up current Attribute Value
                delete []iv_pVal;
                iv_pVal = NULL;

                // Set size and allocate memory space
                iv_hdr.iv_valSize = i_bufferSize;
                if (iv_hdr.iv_valSize)
                {
                    iv_pVal = new uint8_t[iv_hdr.iv_valSize];
                }
            }

            // Make a copy of the data.  Passing in a size of 0
            // or NULL turns this call to no-op
            memcpy(iv_pVal, i_buffer, iv_hdr.iv_valSize);

            return iv_hdr.iv_valSize;
        }

        /**
         * @brief Get a constant pointer to the Attribute Value.
         *        Returning a constant pointer for fast retrieval.
         *
         * @note Caller should not attempt to modify the contents nor
         *       delete the pointer, use method setValue if
         *       need be.
         *
         * return A constant pointer to the Attribute Value
         */
        const void* getValue() const
        {
            return iv_pVal;
        }

        /**
         * @brief Return a copy of the Attribute Value into caller's bufffer
         *
         * @param[in] i_buffer The buffer to copy Attribute Value into
         * @param[in] i_bufferSize Size of the given buffer
         *
         * return The size of the Attribute Value that was copied
         *        or 0 if unable to copy the Attribute Value - buffer
         *        size to small will cause this
         */
        uint32_t cloneValue(void* const o_buffer,
                            const uint32_t i_bufferSize) const
        {
            // Return the size of the cloned data
            uint32_t l_attributeValueSize(0);

            // Is the buffer large enough to contain the Attribute Value?
            if (i_bufferSize >= iv_hdr.iv_valSize)
            {
                // Buffer is large enough to contain the Attribute Value -
                // copy the Attribute Value to given buffer
                memcpy(o_buffer, iv_pVal, iv_hdr.iv_valSize);

                // Return the size of the cloned data
                l_attributeValueSize = iv_hdr.iv_valSize;
            }

            return l_attributeValueSize;
        }

        /**
         * @brief Serialize the Attribute, if the buffer given is large
         *        enough to contain the Attribute's data members
         *
         * @param[out] o_buffer The buffer to contain the serialized
         *                      data members
         * @param[in]  i_bufferSize Size of the given buffer
         *
         * return 0 if buffer is to small to contain the data members;
         *        otherwise the aggregated size of the Attribute's data
         *        members copied
         */
        uint32_t serialize(void* const    o_buffer,
                           const uint32_t i_bufferSize) const
        {
            // Return the size of the serialized data
            uint32_t l_attributeSize(0);

            // If buffer size greater than or equal to the size of the
            // Attribute's data members aggregated together then
            // copy the data members to buffer
            if (i_bufferSize >= getSize())
            {
                // Get an Attribute handle to buffer for easy access
                uint8_t* l_attribute = static_cast<uint8_t*>(o_buffer);

                // Copy the Attribute Header
                memcpy(l_attribute, &iv_hdr, sizeof(iv_hdr));
                l_attribute += sizeof(iv_hdr);

                // Copy the Attribute Value
                memcpy(l_attribute, iv_pVal, iv_hdr.iv_valSize);

                // Return the size of the serialized data
                l_attributeSize = sizeof(iv_hdr) + iv_hdr.iv_valSize;
            }

            return l_attributeSize;
        }

        /**
         * @brief Deserialize the buffer, if the buffer given is at least
         *        the same size as an Attribute
         *
         * @param[out] i_buffer The buffer to deserialize
         * @param[in]  i_bufferSize Size of the given buffer
         *
         * @post If the buffer is large enough to populate the Attribute, then
         *       the Attribute will be populated, with it's own copy of the
         *       data.  If the buffer is too small, then the Attribute is
         *       untouched.
         *
         * return 0 if buffer is to small to populate an Attribute;
         *        otherwise the aggregated size of the Attribute's data
         *        members deserialized
         */
        uint32_t deserialize(const void* const i_buffer,
                             const uint32_t    i_bufferSize)
        {
            // Return the size of the Attribute
            uint32_t l_attributeSize(0);

            // Get an Attribute handle to buffer for easy access
            const Attribute* const l_attribute =
                             reinterpret_cast<const Attribute* const>(i_buffer);

            // Get the minimum size needed to check for values
            uint32_t l_attributeHeaderSize(sizeof(iv_hdr));

            // Make sure the buffer is not just large enough to inspect the
            // Attribute Header but large enough to read Values if they exist
            // Need to make sure size is at minimum threshold before calling
            // getSize(), because getSize assumes the data is there to read
            if ( (i_bufferSize >= l_attributeHeaderSize) &&
                 (i_bufferSize >= (l_attribute->getSize())) )
            {
                // Get an uint8_t handle to buffer for easy access
                const uint8_t* l_attributeData =
                             reinterpret_cast<const uint8_t*>(i_buffer);

                // Copy header data
                memcpy(&iv_hdr, l_attributeData, l_attributeHeaderSize);

                // Free iv_pVal data, if it currently has data, and set to NULL
                delete []iv_pVal;  // OK to delete a NULL ptr
                iv_pVal = NULL;

                // Populate values if they exist
                uint32_t l_valueSize = iv_hdr.iv_valSize;
                if (l_valueSize)
                {
                    // Copy the Attribute Value
                    iv_pVal = new uint8_t[l_valueSize];
                    l_attributeData += l_attributeHeaderSize;
                    memcpy(iv_pVal, l_attributeData, l_valueSize);
                }

                // Return the size of the Attribute
                l_attributeSize = getSize();
            }

            return l_attributeSize;
        }


        /**
         * @brief Assignment operator defined
         */
        Attribute& operator=(const Attribute& rhs)
        {
            // check for self-assignment
            if (&rhs != this)
            {
                // Deep copy the attribute value
                setValue(rhs.iv_pVal, rhs.iv_hdr.iv_valSize);
                // Copy the Attribute header
                iv_hdr = rhs.iv_hdr;
            }

            return *this;
        }

        /**
         * @brief Copy constructor defined
         */
        Attribute(const Attribute& rhs)
        : iv_hdr(),
          iv_pVal(NULL)
        {
            // Call the assignment operator to do the work
            *this = rhs;
        }

        // Private data
        private:
        AttributeHeader iv_hdr;
        uint8_t * iv_pVal;      // Pointer to attribute value
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
    ~AttributeTank();

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
    void clearAllAttributes(const NodeFilter i_nodeFilter = NODE_FILTER_NONE,
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
    void clearNonConstAttribute(const uint32_t i_attrId,
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
    void setAttribute(const uint32_t i_attrId,
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
     * @note Caller's responsibility to ensure the passed in buffer
     *       is large enough to contain the Attribute Value.
     *
     * @param[in]  i_attrId     Attribute ID
     * @param[in]  i_targetType Target Type attribute is for
     * @param[in]  i_pos        Target Position
     * @param[in]  i_unitPos    Target Unit Position
     * @param[in]  i_node       Target Node
     * @param[out] o_pVal       Pointer to a copy of the attribute value
     *
     * return true if attribute exists and a copy was written to o_pVal
     */
    bool getAttribute(const uint32_t i_attrId,
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
    void serializeAttributes(
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
    void deserializeAttributes(const AttributeSerializedChunk & i_attributes);


    /**
     * @brief Deserialize a chunk of Attributes into the tank and
     *        select whether to echo the attributes after they have been stored
     *
     * The use case is for receiving a chunk of serialized attributes from
     * another AttributeTank on a another subsystem. The caller is responsible
     * for freeing/deleting the memory in the chunk after calling this function.
     *
     * @param[in]  i_attributes Reference to AttributeSerializedChunk containing
     *                          attributes.
     *
     * @param[in]  i_echoAttributes Select whether or not to echo the attributes
     */
    void deserializeAttributes(const AttributeSerializedChunk & i_attributes,
                               bool  i_echoAttributes );


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
    bool attributesExist() const { return iv_attributesExist; }

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
    bool attributeExists(const uint32_t i_attrId) const;

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

    /**
     * @brief Return a copy of all attributes in the tank
     *
     * @param[out] List of all attributes in this tank
     * @return n/a
     */
    void getAllAttributes( std::list<Attribute *>& o_attributes ) const;

    /**
     * @brief Return a string description of the given tank layer
     *
     * @return String representation of layer
     */
    static const char* layerToString( TankLayer i_layer );

private:
    // Copy constructor and assignment operator disabled
    AttributeTank(const AttributeTank & i_right);
    AttributeTank & operator=(const AttributeTank & i_right);

    // The attributes
    // Note: A possible performance boost could be to store the elements in a
    //       map, the key could be a sub-structure.
    bool iv_attributesExist;
    std::list<Attribute *> iv_attributes;
    typedef std::list<Attribute *>::iterator AttributesItr_t;
    typedef std::list<Attribute *>::const_iterator AttributesCItr_t;

    // Lock for thread safety (class provided by platform)
    mutable TARG_MUTEX_TYPE iv_mutex;

};  // end AttributeTank


#endif //STANDALONE_COMPILE

} // namespace TARGETING/AttributeTank

#endif
