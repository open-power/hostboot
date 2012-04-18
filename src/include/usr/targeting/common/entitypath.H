//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/targeting/entitypath.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

#ifndef __TARGETING_COMMON_ENTITYPATH_H
#define __TARGETING_COMMON_ENTITYPATH_H

/**
 *  @file targeting/common/entitypath.H
 *
 *  @brief Interface for the EntityPath class
 *
 *  This header file contains the interface for the EntityPath class which
 *  supports hierarchical path representation of various flavors
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
#include <stdlib.h>
#include <vector>

namespace TARGETING
{

class Target;

/**
 *  @brief Entity path class which represents a target's relationship(s) to
 *      other targets
 *
 *  Entity path class which represents a target's relationship(s) to other
 *  targets via hierarchical paths.  Entity paths can represent different
 *  relationships, such as logical containment (where part X contains part Y
 *  contains part Z), hardware affinity, etc.  An entity path is composed of
 *  a number of type/instance pairs that represent a given target in a given
 *  hierarchy.  In the logical containment example, part Z's logical containment
 *  path would look something like partX-0/partY-1/partZ-0.
 */
class EntityPath
{
    public:

        /**
         *  @brief Maximum number of path elements than an entity path can have
         */
        enum
        {
            MAX_PATH_ELEMENTS = 10,
        };

        /**
         *  @brief Entity Path Types
         *
         *  An entity path type indicates which specific set of relationships is
         *  modeled by a particular entity path.  For example, PATH_AFFINITY
         *  models how targets are connected to each other from a hardware
         *  affinity perspective.
         */
        enum PATH_TYPE
        {
            PATH_NA       = 0x00, ///< Not applicable
            PATH_AFFINITY = 0x01, ///< Entity path models hardware affinity
                                  ///< relationships
            PATH_PHYSICAL = 0x02, ///< Entity path models logical containment
                                  ///< relationships
            PATH_DEVICE   = 0x03, ///< Entity path models a device driver path
            PATH_POWER    = 0x04, ///< Entity path models power provider and
                                  ///< power consumer relationships
        };

        /**
         *  @brief Entity Path Element Definition
         *
         *  Any entity path models one level of an entity path hierarchy
         */
        struct PathElement
        {
           TYPE    type : 8; ///< Type of element at this level in the hierarchy
           uint8_t instance; ///< Instance ID for the element, relative to
                             ///< the parent

        } PACKED;

        /**
         *  @brief Creates an entity path object, based on path type
         *
         *  Creates an entity path of the specified type, but does not populate
         *  it with any path elements.
         *
         *  @param[in] i_pathType Type of entity path to create
         *
         *  @post Entity path of specified type created with no path elements
         */
        EntityPath(
            PATH_TYPE i_pathType);

        /**
         *  @brief Creates an empty entity path object
         *
         *  Creates an empty entity path of N/A type and does not populate it
         *  with any path elements. The caller must initialize the type and
         *  populate it with path elements as needed
         *
         *  @post Entity path created with default type and no path elements
         */
        EntityPath();

        /**
         *  @brief Destroys an entity path object
         *
         *  Destroys an entity path object and frees all resources it
         *  exclusively owns.
         *
         *  @post Entity path destroyed and all previously owned exclusive
         *      resources freed
         */
        ~EntityPath();

        /**
         *  @brief Removes/clears the last path element from an entity path
         *
         *  Removes/clears the last path element from an entity path.  If the
         *  caller attempts this operation and no path elements exist, the
         *  routine asserts.
         *
         *  @post Entity path element removed from path
         *
         *  @return Reference to the same EntityPath, for chaining
         */
        EntityPath& removeLast();

        /**
         *  @brief Returns a copy of the entity path with the last path
         *      element removed.  The original entity path is not altered
         *
         *  Returns a copy of the entity path with the last path
         *  element removed, useful for non-destructive transformations.
         *  caller attempts this operation and no path elements exist, the
         *  routine asserts.  The original entity path is not altered.
         *  Equivalent to p1 = p2; p1.removeLast();
         *
         *  @post Copy of entity path with last element removed returned
         *
         *  @return Copy of the EntityPath
         */
        EntityPath copyRemoveLast() const;

        /**
         *  @brief Adds a path element to the end of an existing entity path
         *      object
         *
         *  Adds a path element to the end of an existing entity path object.
         *  If the new path exceeds the maximum allowable number of path
         *  elements, the routine asserts
         *
         *  @param[in] i_type Type of path element to add
         *  @param[in] i_instance Instance # of path element to add
         *
         *  @pre N/A
         *
         *  @post Entity path will increased by one path element, as specified
         *      by the input parameters
         *
         *  @return Reference to the larger entity path
         */
        EntityPath& addLast(
            TYPE    i_type,
            uint8_t i_instance);

        /**
         *  @brief Returns a copy of the entity path with the specified
         *      path element added to the end. The original entity path is not
         *      altered
         *
         *  Returns a copy of the entity path with the specified path element
         *  added to the end. If the new path exceeds the maximum allowable
         *  number of path elements, the routine asserts.  The original entity
         *  path is not altered.  Equivalent to p1 = p2.  p1.addLast(..);
         *
         *  @param[in] i_type Type of path element to add
         *  @param[in] i_instance Instance # of path element to add
         *
         *  @pre N/A
         *
         *  @post Copy of entity path with additional path element returned to
         *      caller
         *
         *  @return Copy of the entity path with an additional path element
         */
        EntityPath copyAddLast(
            TYPE    i_type,
            uint8_t i_instance) const;

        /**
         *  @brief Returns a target handle to the target referred to by the
         *      entity path object
         *
         *  Returns a target handle to the target referred to by the
         *  entity path object if it exists (NULL otherwise)
         *
         *  @pre N/A
         *
         *  @post Target handle returned to caller or NULL (if related target
         *      doesn't exist)
         *
         *  @return Target handle
         *
         *  @retval NULL Target doesn't exist
         *  @retval !NULL Target handle to the target referred to by the entity
         *      path
         */
        Target* operator->(void);

        /**
         *  @brief Returns whether two entity paths are logically equal
         *
         *  Returns whether two entity paths are logically equal.  This
         *  determination takes into account the entity path type, the number
         *  of path elements, and the values of the path elements themselves.
         *
         *  @param[in] i_rhs Const reference to entity path to compare
         *
         *  @pre N/A
         *
         *  @post Equality returned to caller
         *
         *  @return bool indicating whether two entity paths are logically equal
         *
         *  @retval true The entity paths are logically equal
         *  @retval false The entity paths are not logically equal
         */
        bool operator==(
            const EntityPath& i_rhs) const;

        /**
         *  @brief Returns whether two entity paths are logically equal, but
         *      only for the specified number of path elements
         *
         *  Returns whether two entity paths are logically equal, but only for
         *  the specified number of path elements.  This determination takes
         *  into account the entity path type, the specified number of path
         *  elements, and the values of the subset of path elements to be
         *  compared.  For example, a device path of
         *  fsi0/cfam0/fsi0/cfam1/engine0 is equal to fsi0/cfam0 if the
         *  specified number of path elements is 1 or 2.
         *
         *  @param[in] i_rhs Const reference to entity path to compare
         *  @param[in] i_size Number of path elements to compare; must be
         *      <= this->size() (otherwise routine will assert)
         *
         *  @pre N/A
         *
         *  @post Equality (for specified number of path elements) returned to
         *      caller
         *
         *  @return bool indicating whether two entity paths are logically equal
         *        for the specified number of path elements (or assertion if
         *        specified size > this->size())
         *
         *  @retval true The entity paths are logically equal for the specified
         *      number of path elements
         *  @retval false The entity paths are not logically equal for the
         *      specified number of path elements
         */
        bool equals(
            const EntityPath& i_rhs,
                  uint32_t    i_size) const;

        /**
         *  @brief Returns the path element at the specified index
         *
         *  Returns the path element at the specified index (zero based).  The
         *  routine will assert if the index exceeds this->size()-1;
         *
         *  @param[in] i_index Path element to return (0 based indexing)
         *
         *  @pre N/A
         *
         *  @post Path element returned to caller on valid index.  Assert
         *      triggered on invalid index.
         *
         *  @return PathElement at the position in the entity path specified by
         *      index
         */
        const PathElement& operator[](
            uint32_t i_index) const;

        /**
         *  @brief Returns the first path element of the given type
         *
         *  Returns the first occurrence of a path element that matches the
         *  selected type.  Will return a PathElement with type=TYPE_NA if
         *  no match is found.
         *
         *  @param[in] i_type Element type to return
         *
         *  @pre N/A
         *
         *  @return PathElement of the given type else invalid PathElement
         */
        const PathElement pathElementOfType(
            const TYPE i_type) const;

        /**
         *  @brief Returns the number of path elements
         *
         *  Returns the number of path elements for the entity path.
         *
         *  @pre N/A
         *
         *  @post Number of path elements returned to caller
         *
         *  @return uint32_t giving the number of path elements
         */
        uint32_t size() const;

        /**
         *  @brief Sets the path type
         *
         *  Sets the path type for the entity path
         *
         *  @param[in] i_pathType Path type specifier
         *
         *  @pre N/A
         *
         *  @post Path type set to the specified value
         *
         *  @return N/A
         */
        void setType(
            PATH_TYPE i_pathType);

        /**
         *  @brief Returns the path type
         *
         *  Returns the path type for the entity path
         *
         *  @pre N/A
         *
         *  @post Path type returned to caller
         *
         *  @return PATH_TYPE indicating the entity path's path type
         */
        PATH_TYPE type() const;

        /**
         *  @brief DEBUG ONLY.  Returns the path type as a string.
         *
         *  Returns the string encoding of the path type
         *
         *  @pre N/A
         *
         *  @post Path type string returned to caller
         *
         *  @return String representation of the path type
         */
        const char* pathTypeAsString() const;

        /**
         *  @brief DEBUG ONLY.  Returns the path element type as a string.
         *
         *  Returns the string encoding of the path element type
         *
         *  @param[in] i_type Path element type to translate
         *
         *  @pre N/A
         *
         *  @post Path element type string returned to caller
         *
         *  @return String representation of the path element type
         */
        const char* pathElementTypeAsString(
            TYPE i_type) const;

        /**
         *  @brief DEBUG ONLY.  Returns the path element engine instance as a
         *      string.
         *
         *  @param[in] i_engine Path element engine instance to translate
         *
         *  Returns the string encoding of the path element engine instance
         *
         *  @pre N/A
         *
         *  @post Path element engine instance string returned to caller
         *
         *  @return String representation of the path element engine instance
         */
        const char* pathEngineInstanceAsString(
            ENGINE_TYPE i_engine) const;

        /**
         *  @brief DEBUG ONLY.  Dump the entity path
         *
         *  Dumps the entity path
         *
         *  @pre N/A
         *
         *  @post Entity path dumped
         *
         *  @return N/A
         */
        void dump() const;

        /**
         *  @brief Save the entity path as a c-string
         *
         *  @return The dynamic buffer (malloc'd) pointer of the c-string
         *
         *  @note      caller must call free() to release the buffer
         */
        char * toString() const;

    private:

        PATH_TYPE   iv_type : 4; ///< Entity path type (4 bits)
        uint8_t     iv_size : 4; ///< Number of path elements (4 bits)
        PathElement iv_pathElement[MAX_PATH_ELEMENTS]; ///< Array of path
                                                       ///< elements

        // Compiler generated copy and assignment operators explicitly
        // allowed and used

} PACKED;

} // End namespace TARGETING

#endif // __TARGETING_COMMON_ENTITYPATH_H
