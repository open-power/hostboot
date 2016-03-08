/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/target.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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

#ifndef __TARGETING_COMMON_TARGET_H
#define __TARGETING_COMMON_TARGET_H

/**
 *  @file targeting/common/target.H
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
#include <targeting/adapters/assertadapter.H>
#include <targeting/adapters/types.H>
#include <targeting/common/util.H>
#include <targeting/common/pointer.H>
#include <vector>

// This component
#include <targeting/common/attributes.H>

//******************************************************************************
// Forward declarations to allow friend functions to work
//******************************************************************************


namespace fapi2
{

   namespace platAttrSvc
    {

      bool setTargetingAttrHelper(TARGETING::Target * ,
                                  const TARGETING::ATTRIBUTE_ID ,
                                  const uint32_t , void * );
      bool getTargetingAttrHelper(TARGETING::Target * ,
                                  const TARGETING::ATTRIBUTE_ID ,
                                  const uint32_t , void * );
    }
}

namespace util
{
    class Mutex;
}

namespace TARGETING
{

//******************************************************************************
// Type Aliases
//******************************************************************************
class AttributeTank;
class Target;
typedef const Target* ConstTargetHandle_t;
typedef       Target* TargetHandle_t;

typedef std::vector<TargetHandle_t> TargetHandleList;
typedef std::vector<Target>         TargetList;

// Function pointer declaration to install/uninstall the attribute write
// callback
typedef void (*pCallbackFuncPtr) (const Target* const, const ATTRIBUTE_ID, \
    const uint32_t, const void* const);

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
        bool tryGetAttr(typename AttributeTraits<A>::Type& o_attrValue) const;

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
        bool trySetAttr(typename AttributeTraits<A>::Type const& i_attrValue);

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
         *  @brief Returns pointer to fsp mutex attribute associated with the
         *     target
         *
         *  @pre Target service must be initialized and the mutex attribute
         *     must exist. If not initailized then it will be null pointer.
         *
         *  @post See brief section
         *
         *  @return Pointer to the specified mutex attribute
         */
        template<const ATTRIBUTE_ID A>
        util::Mutex* getFspMutexAttr() const;

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
        bool tryGetHbMutexAttr(mutex_t*& o_pMutex) const;

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
        void setAttr(typename AttributeTraits<A>::Type const& i_attrValue);

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
        uint8_t * targetFFDC( uint32_t & o_size ) const;

        /**
         *  @brief Returns the target handle referencing a target whose HUID
         *      matches the caller supplied value
         *
         *  @param[in] i_huid HUID of target to find
         *
         *  @pre Target service must be initialized
         *
         *  @return Target handle referencing a target whose HUID matches the
         *      caller supplied value
         *
         *  @retval !NULL Target handle referencing a target whose HUID matches
         *      the caller supplied value.
         *  @retval NULL No target found whose HUID matches the caller supplied
         *      value.
         */
        static Target* getTargetFromHuid(const ATTR_HUID_type i_huid);

        /**
         *  @brief Return the Targeting Override Attribute Tank
         *
         *  @return Reference to the Attribute Tank
         */
        static AttributeTank & theTargOverrideAttrTank()
        {
            return cv_overrideTank;
        }

        /**
         *  @brief Return the Targeting Sync Attribute Tank
         *
         *  @return Reference to the Attribute Tank
         */
        static AttributeTank & theTargSyncAttrTank()
        {
            return cv_syncTank;
        }

        /**
         *  @brief Install the targeting attribute write callback,
         *  provided by user. This gets triggered on every setAttr/trySetAttr
         *  instantiation on the targeting interface. User might write a
         *  method as per the callback function type provided, to have
         *  use-case as per the requirement.
         *
         *  @param[in] i_callBackFunc, User defined callback function of the
         *  type pCallbackFuncPtr.
         *
         *  @return bool, indicates the status of the request.
         *  @retval true, if the callback installation is success
         *  @retval false, if callback is already installed.
         */
        static bool installWriteAttributeCallback(
                pCallbackFuncPtr & i_callBackFunc);

        /**
         *  @brief uninstall the targeting attribute write callback, provided
         *  by user. which gets installed via installWriteAttributeCallback
         *  method.
         *
         *  @return bool, indicates the status of the request.
         *  @retval true, if the callback is uninstalled
         *  @retval false, if the callback uninstall fails.
         */
        static bool uninstallWriteAttributeCallback();

        /**
         *  @brief Returns the target's position data as used in an attribute
         *         tank.
         *
         *  This target positions are associated with an attribute in an
         *  attribute tank and help identify which target(s) the attribute
         *  belongs to.
         *
         *  @param[out] o_pos     Chip/Dimm Position (ATTR_POS_NA if not found)
         *  @param[out] o_unitPos Unit Position (ATTR_UNIT_POS_NA if not found)
         *  @param[out] o_node    Node Number (ATTR_NODE_NA if not found)
         */
        void getAttrTankTargetPosData(uint16_t & o_pos,
                                      uint8_t & o_unitPos,
                                      uint8_t & o_node) const;
   private: // Private helper interfaces

        /**
         *  @brief Tries to get the target's specified attribute value
         *
         *  Tries to get the target's specified attribute value
         *
         *  @param[in] i_attr Attribute to retrieve
         *  @param[in] i_size Size of the attribute
         *  @param[in/out] io_attrData On input, location to store the attribute
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
         *  @brief Returns pointer to fsp mutex attribute associated with the
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
        util::Mutex* _getFspMutexAttr(
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

        /**
         *  @brief Returns the target's type as used in a Targeting attribute
         *         tank.
         *
         *  This target type is associated with an attribute in an attribute
         *  tank and helps identify which target(s) the attribute belongs to
         *
         *  @return uint32_t The target type
         */
        uint32_t getAttrTankTargetType() const;

        /**
         *  @brief enumeration of assert reasons
         */
        enum TargAssertReason
        {
            SET_ATTR,
            GET_ATTR,
            GET_ATTR_AS_STRING,
            GET_HB_MUTEX_ATTR,
            GET_ATTR_TANK_TARGET_POS_DATA,
            GET_ATTR_TANK_TARGET_POS_DATA_ATTR,
        };

        /**
         *  @brief Invokes a standard assert to end the task
         *
         *  This is called when a function does not want the code size overhead
         *  of the assert macro expansion. This is especially useful for the
         *  asserts performed by the inline attribute
         *
         *  @param[in] i_reason Reason for assertion
         *  @param[in] i_ffdc   FDDC Data (usually the attribute id)
         */
#ifdef NO_RETURN
        NO_RETURN
#endif
        static void targAssert(TargAssertReason i_reason,
                               uint32_t i_ffdc);

    private: // Function pointer variable declaration

        static pCallbackFuncPtr cv_pCallbackFuncPtr;

    private: // Private instance variables

        uint32_t       iv_attrs;          ///< Total attributes allowed for this
                                          ///< instance

        // Pointer to  array of valid attributes
        TARGETING::AbstractPointer<ATTRIBUTE_ID> iv_pAttrNames;

        // Pointer to array of void* (which point to attributes)
        TARGETING::AbstractPointer< AbstractPointer<void> > iv_pAttrValues;

        // Array of pointers to target handles.  Currently there is one pointer
        // for each supported association type.  The currently supported
        // association types are PARENT, CHILD, PARENT_BY_AFFINITY,
        // CHILD_BY_AFFINTY, PERVASIVE_CHILD, and PARENT_PERVASIVE.
        // The number of pointers should exactly equal value
        // of TargetService::MAX_ASSOCIATION_TYPES defined in
        // targeting/common/targetservice.H.  Due to the huge code changes
        // necessary to directly use that enum value, a compile time assert in
        // targeting/common/targetservice.C enforces that restriction.
        TARGETING::AbstractPointer< AbstractPointer<Target> >
            iv_ppAssociations[6];

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

    private: // Private class variables

        // Attribute Tanks
        static AttributeTank cv_overrideTank;
        static AttributeTank cv_syncTank;

        friend class PnorBuilderService;
        friend class TargetCloner;
        friend class TargetService;
        friend class AssociationManager;
        friend class AttributeTank;




         friend bool fapi2::
                     platAttrSvc::
                     setTargetingAttrHelper(TARGETING::Target*,
                                            const TARGETING::ATTRIBUTE_ID ,
                                            const uint32_t , void * );
         friend bool fapi2::
                     platAttrSvc::
                     getTargetingAttrHelper(TARGETING::Target * ,
                                            const TARGETING::ATTRIBUTE_ID ,
                                            const uint32_t , void * );
      /*
       * @brief allow targetattrbulksync access to the target class store.
       */
      friend class TargetAttrBulkSync;

} PACKED;

template<const ATTRIBUTE_ID A>
bool Target::tryGetAttr(typename AttributeTraits<A>::Type& o_attrValue) const
{
    if(AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::notHbMutex) { }
    if(AttributeTraits<A>::notFspMutex) { }
    return _tryGetAttr(A,sizeof(o_attrValue),&o_attrValue);
}

template<const ATTRIBUTE_ID A>
bool Target::trySetAttr(typename AttributeTraits<A>::Type const& i_attrValue)
{
    if(AttributeTraits<A>::writeable) { }
    if(AttributeTraits<A>::notHbMutex) { }
    return _trySetAttr(A,sizeof(i_attrValue),&i_attrValue);
}

template<const ATTRIBUTE_ID A>
typename AttributeTraits<A>::Type Target::getAttr() const
{
    typename AttributeTraits<A>::Type l_attrValue;
    bool l_read = tryGetAttr<A>(l_attrValue);
    if (unlikely(!l_read))
    {
        targAssert(GET_ATTR, A);
    }
    return l_attrValue;
}

template<const ATTRIBUTE_ID A>
void Target::setAttr(typename AttributeTraits<A>::Type const& i_attrValue)
{
    bool l_wrote = trySetAttr<A>(i_attrValue);
    if (unlikely(!l_wrote))
    {
        targAssert(SET_ATTR, A);
    }
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
util::Mutex* Target::getFspMutexAttr() const
{
    if(AttributeTraits<A>::fspMutex) { }
    if(AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::writeable) { }
    return _getFspMutexAttr(A);
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
    if (unlikely(!l_read))
    {
        targAssert(GET_ATTR_AS_STRING, A);
    }
    return attrToString<A>(l_attrValue);
}

// Function to set various frequency related attributes
/**
 * @brief - sets various attributes directly related to the nest frequency.
 *
 * @param[in] i_sys - top level system target to set attributes for
 * @param[in] i_newNestFreq - the new nest frequency to base all the attributes
 *                            off of.
 */
void setFrequencyAttributes(Target * i_sys, uint32_t i_newNestFreq);


// WARNING: The following #include imports any platform specific template
// specializations for getAttr and tryGetAttr
#include <targeting/adapters/targetadapter.H>

} // End namespace TARGETING

#endif // __TARGETING_COMMON_TARGET_H
