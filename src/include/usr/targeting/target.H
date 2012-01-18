//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/targeting/target.H $
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

#ifndef TARG_TARGET_H
#define TARG_TARGET_H

/**
 *  @file target.H
 *
 *  @brief Interface for the target class
 *
 *  This header file contains the interface for the target class which
 *  associates entities of interest to host boot to their various attributes
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>

// This component
#include <targeting/attributes.H>

namespace TARGETING
{

//******************************************************************************
// Type Aliases
//******************************************************************************

class Target;
typedef const Target* ConstTargetHandle_t;
typedef       Target* TargetHandle_t;

typedef std::vector<TargetHandle_t> TargetHandleList;
typedef std::vector<Target>         TargetList;

class Target
{
    public: // Constructors and destructors

        /**
         *  @brief Destroys the target
         *
         *  Destroys the target, and any exclusively owned resources
         *
         *  @post Target is destroyed, and all exclusively owned resources are
         *      reclaimed
         */
        ~Target();

    public: // User interface

        /**
         *  @brief Try to get the target's specified attribute value
         *
         *  Attempts to return the target's specified attribute value.  It
         *  returns false (with invalid o_attrValue) if the specified attribute
         *  does not exist for the associated target, true (with a valid
         *  o_attrValue) otherwise.
         *
         *  @param[out] o_attrValue Value of the attribute
         *
         *  @pre Target service must be initialized
         *
         *  @post See "return"
         *
         *  @return bool indicating whether the specified attribute was returned
         *      or not
         *
         *  @retval true Attribute returned in o_attrValue
         *  @retval false Attribute not found; o_attValue not valid
         */
        template<const ATTRIBUTE_ID A>
        inline bool tryGetAttr(
            typename AttributeTraits<A>::Type& o_attrValue) const
        {
            // Note: the compiler optimizes the following check (which fails
            // at compile time if the attribute is not readable) away
            if(AttributeTraits<A>::readable) { }
            if(AttributeTraits<A>::notHbMutex) { }
            return _tryGetAttr(A,sizeof(o_attrValue),&o_attrValue);
        }

        /**
         *  @brief Get the target's specified attribute value
         *
         *  Returns the target's specified attribute value.  If the specified
         *  attribute does not exist for the associated target, the routine
         *  asserts.  Thus callers must be sure the attribute exists for the
         *  given target.
         *
         *  @pre Target service must be initialized
         *
         *  @post Target's specified attribute value returned, or assert
         *      called if specified attribute doesn't exist for the
         *      associated target
         *
         *  @return Data type associated with the attribute being returned
         *
         *  @retval Varies The attribute data
         */
        template<const ATTRIBUTE_ID A>
        typename AttributeTraits<A>::Type getAttr() const;

        /**
         *  @brief DEBUG ONLY!  Returns the requested attribute as a string
         *
         *  Returns the attribute value (for the associated target) as a string.
         *  If the specified attribute does not have a string conversion, the
         *  compile will fail.
         *
         *  @pre Target service must be initialized
         *
         *  @post Specified attribute's value returned as a string.  If the
         *      specified attribute does not exist, the routine asserts.
         *
         *  @return String representing the attribute
         *
         *  @retval Varies based on the attribute type and value
         */
        template<const ATTRIBUTE_ID A>
        const char* getAttrAsString() const;

        /**
         *  @brief Tries to set the target's specified attribute value
         *
         *  Attempts to set the target's specified attribute value.  It
         *  returns false if the specified attribute does not exist for the
         *  associated target, true otherwise.
         *
         *  @param[in] i_attrValue Value of the attribute
         *
         *  @pre Target service must be initialized
         *
         *  @post Target's attribute value updated (if it exists), and caller
         *      notified whether the update occurred or not.
         *
         *  @return bool indicating whether the specified attribute was updated
         *      or not
         *
         *  @retval true Attribute updated
         *  @retval false Attribute not updated
         */
        template<const ATTRIBUTE_ID A>
        bool trySetAttr(
            typename AttributeTraits<A>::Type const& i_attrValue)
        {
            // Note: the compiler optimizes the following check (which fails
            // at compile time if the attribute is not writable) away
            if(AttributeTraits<A>::writeable) { }
            if(AttributeTraits<A>::notHbMutex) { }
            return _trySetAttr(A,sizeof(i_attrValue),&i_attrValue);
        }

        /**
         *  @brief Returns pointer to a mutex attribute associated with the
         *     target
         *
         *  @pre Target service must be initialized and the mutex attribute 
         *      must exist
         *
         *  @post See brief section
         *
         *  @return Pointer to the specified mutex attribute
         */
        template<const ATTRIBUTE_ID A>
        mutex_t* getHbMutexAttr() const;

        /**
         *  @brief Returns pointer to a mutex attribute associated with the
         *     target, if it exists
         *
         *  @param[out] o_pMutex Reference to a mutex pointer, which will be
         *      updated with the address of the mutex attribute if it exists
         *      (ignored otherwise)
         *
         *  @pre Target service must be initialized 
         *
         *  @post See brief section
         *
         *  @return bool indicating whether the attribute was found or not
         *
         *  @retval true Attribute was found (and returned)
         *  @retval false Attribute was not found, o_pMutex was not updated
         */        
        template<const ATTRIBUTE_ID A>
        bool tryGetHbMutexAttr(
            mutex_t*& o_pMutex) const;

        /**
         *  @brief Sets the target's specified attribute value
         *
         *  Sets the target's specified attribute value.
         *
         *  @param[in] i_attrValue Value of the attribute
         *
         *  @pre Target service must be initialized
         *
         *  @post Target's attribute value updated if it exists, otherwise
         *      routine asserts
         */
        template<const ATTRIBUTE_ID A>
        void setAttr(
            typename AttributeTraits<A>::Type const& i_attrValue)
        {
            bool l_wrote = trySetAttr<A>(i_attrValue);
            
            //@TODO: Remove assert once release has stabilized
            assert(l_wrote,"TARGETING::Target::setAttr<%d>: trySetAttr "
                   "returned false",A);
        }

        /**
         *  @brief Perform FFDC for the target instance
         *
         *  @param[out] io_size
         *              number of bytes of buffer filled with FFDC
         *
         *  @return pointer to dynamically allocated FFDC buffer
         *
         *  @post caller must call free() to release the buffer
         */
        char * targetFFDC( uint32_t & o_size ) const;

    private: // Private helper interfaces

        /**
         *  @brief Tries to get the target's specified attribute value
         *
         *  Tries to get the target's specified attribute value
         *
         *  @param[in] i_attr Attribute to retrieve
         *  @param[in] i_size Size of the attribute
         *  @param[in/out] io_attrData On input, location to store the attribute.
         *      On output, location updated with attribute data
         *
         *  @pre Target service must be initialized
         *
         *  @post Caller notified if attribute retrieval succeeded or not.  If
         *      so, the attribute data is stored at io_addrData
         *
         *  @return bool indicating if attribute retrieval succeeded or not
         *
         *  @retval true Attribute retrieval succeeded
         *  @retval false Attribute retrieval failed
         */
        bool _tryGetAttr(
            ATTRIBUTE_ID i_attr,
            uint32_t     i_size,
            void*        io_attrData) const;

        /**
         *  @brief Tries to set the target's specified attribute value
         *
         *  Tries to set the target's specified attribute value
         *
         *  @param[in] i_attr Attribute to retrieve
         *  @param[in] i_size Size of the attribute
         *  @param[in] i_pAttrData Location holding the attribute data to set
         *
         *  @pre Target service must be initialized
         *
         *  @post If attribute exists for the associated target, attribute value
         *      updated and success (true) returned.  Otherwise, attribute value
         *      not updated and failure (false) returned.
         *
         *  @return bool indicating if attribute update succeeded or not
         *
         *  @retval true Attribute update succeeded
         *  @retval false Attribute update failed
         */
        bool _trySetAttr(
            ATTRIBUTE_ID i_attr,
            uint32_t     i_size,
            const void*  i_pAttrData) const;

        /**
         *  @brief Gets a pointer to the target's associated attribute
         *
         *  Gets a pointer to the target's associated attribute
         *
         *  @param[in] i_attr Attribute to retrieve
         *  @param[out] o_pAttr Pointer to data location to hold the attribute
         *      data
         *
         *  @pre Target service must be initialized
         *
         *  @post If attribute exists for the associated target, caller's
         *      pointer updated with associated attribute pointer.  Otherwise,
         *      caller's pointer updated to NULL.
         */
        void _getAttrPtr(
            ATTRIBUTE_ID i_attr,
            void*&       o_pAttr) const;

        /**
         *  @brief Returns pointer to a mutex attribute associated with the
         *     target
         *
         *  @param[in] i_attribute Mutex attribute to return
         *
         *  @pre Target service must be initialized and the mutex attribute 
         *      must exist
         *
         *  @post See brief section
         *
         *  @return Pointer to the specified mutex attribute
         */
        mutex_t* _getHbMutexAttr(
            const ATTRIBUTE_ID i_attribute) const;

        /**
         *  @brief Returns pointer to a mutex attribute associated with the
         *     target, if it exists
         *
         *  @param[in]  i_attribute Mutex attribute to return
         *  @param[out] o_pMutex Reference to a mutex pointer, which will be
         *      updated with the address of the mutex attribute if it exists
         *      (ignored otherwise)
         *
         *  @pre Target service must be initialized 
         *
         *  @post See brief section
         *
         *  @return bool indicating whether the attribute was found or not
         *
         *  @retval true Attribute was found (and returned)
         *  @retval false Attribute was not found, o_pMutex was not updated
         */  
        bool _tryGetHbMutexAttr(
            const ATTRIBUTE_ID i_attribute,
                  mutex_t*&    o_pMutex) const;

    private: // Private instance variables

        uint32_t       iv_attrs;          ///< Total attributes allowed for this
                                          ///< instance
        ATTRIBUTE_ID (*iv_pAttrNames)[];  ///< Pointer to array of valid
                                          ///< attributes
        void*        (*iv_pAttrValues)[]; ///< Pointer to array of void*'s
                                          ///< (which point to individual
                                          ///< attributes)

    private: // Private CTORs/DTORs/Operators

        /**
         *  @brief Build a target object
         *
         *  Builds a target object; currently there is little to no need to
         *  construct new targets; they are already preloaded in PNOR.
         */
        Target();

        // Disable the copy constructor/assignment operator.

        Target(
            const Target& i_right);

        Target& operator=(
            const Target& i_right);

      friend class PnorBuilderService;

} PACKED;

template<const ATTRIBUTE_ID A>
typename AttributeTraits<A>::Type Target::getAttr() const
{
    typename AttributeTraits<A>::Type l_attrValue;
    bool l_read = tryGetAttr<A>(l_attrValue);
    
    //@TODO Remove assert once release has stablized 
    assert(l_read,"TARGETING::Target::getAttr<%d>: tryGetAttr "
           "returned false",A);
    return l_attrValue;
}

template<const ATTRIBUTE_ID A>
mutex_t* Target::getHbMutexAttr() const
{
    if(AttributeTraits<A>::hbMutex) { }
    if(AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::writeable) { }
    return _getHbMutexAttr(A);
}

template<const ATTRIBUTE_ID A>
bool Target::tryGetHbMutexAttr(
    mutex_t*& o_pMutex) const
{
    if(AttributeTraits<A>::hbMutex) { }
    if(AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::writeable) { }
    return _tryGetHbMutexAttr(A,o_pMutex);
}

template<const ATTRIBUTE_ID A>
const char* Target::getAttrAsString() const
{
    // Note: the compiler optimizes the following check (which fails
    // at compile time if the attribute does not have a string
    // conversion) away
    if(AttributeTraits<A>::hasStringConversion) { }
    typename AttributeTraits<A>::Type l_attrValue;
    bool l_read = tryGetAttr<A>(l_attrValue);

    //@TODO Remove assert once release has stabilized
    assert(l_read,"TARGETING::Target::getAttrAsString<%d>: tryGetAttr "
           "returned false",A);
    return attrToString<A>(l_attrValue);
}

} // End namespace TARGETING

#endif // TARG_TARGET_H
