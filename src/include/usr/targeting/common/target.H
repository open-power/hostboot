/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/target.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#ifdef __HOSTBOOT_MODULE
#include <array>
#endif

// This component
#include <targeting/common/attributes.H>

//******************************************************************************
// Forward declarations to allow friend functions to work
//******************************************************************************
#ifdef __HOSTBOOT_RUNTIME
namespace ERRORLOG
{
    class ErrlEntry;
}
namespace RT_TARG
{
    ERRORLOG::ErrlEntry* saveRestoreAttrs(void *i_rsvdMemPtr,
                                          void *io_lidStructPtr,
                                          uint8_t i_instance);
}
#endif

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


// for friend declaration
namespace Util
{
    void cmd_getattr( char*& o_output,
                      uint32_t i_huid,
                      uint32_t i_attrId,
                      uint32_t i_size );
}

namespace util
{
    class Mutex;
}

// Pre-declare to allow friend-ing
#ifdef __HOSTBOOT_MODULE
namespace TARGETING
{
    namespace UTIL
    {
        void dumpHBAttrs(uint32_t);
    }
}
class AttributeRulesTest;
#endif

// for friend declaration
#ifndef __HOSTBOOT_RUNTIME
#ifdef CONFIG_DEVTREE
namespace DEVTREE
{
    bool devtreeSyncAttrs();
}
#endif
#endif

namespace TARGETING
{

//******************************************************************************
// Type Aliases
//******************************************************************************
class AttributeTank;
class AttrRP;
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
         *  @brief Try to get the target's specified not synced attribute value
         *
         *  A special tryGetAttr function for getting the attribute values
         *  of the attributes which are not synced to system model on FSP.
         *  It returns false (with invalid o_attrValue) if the specified
         *  attribute does not exist for the associated target, true (with a
         *  valid o_attrValue) otherwise.
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
        bool tryGetAttrNotSynced(
            typename AttributeTraits<A>::Type& o_attrValue) const;

        /**
         *  @brief Try to get the target's specified std::array attribute value
         *
         *  A special tryGetAttr function for getting the attribute values
         *  of the attributes which support std::array.
         *  It returns false (with invalid o_attrValue) if the specified
         *  attribute does not exist for the associated target, true (with a
         *  valid o_attrValue) otherwise.
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
// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L
        template<const ATTRIBUTE_ID A>
        bool tryGetAttr(
            typename AttributeTraits<A>::TypeStdArr& o_attrValue) const;
#endif

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
         *  @brief Get the target's specified attribute value
         *
         *  Returns the target's specified attribute value.  If the specified
         *  attribute does not exist for the associated target, the routine
         *  asserts.  Thus callers must be sure the attribute exists for the
         *  given target.
         *
         *  @param[in] i_attrRP Pointer to attribute resource provider
         *  @param[in] i_pAttrId Pointer to array of attribute IDs for target
         *  @param[in] i_ppAttrAddr Pointer to array of attribute addresses
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
        typename AttributeTraits<A>::Type getAttr(AttrRP* i_attrRP,
                                                  ATTRIBUTE_ID* i_pAttrId,
                                                  AbstractPointer<void>*
                                                      i_ppAttrAddr) const;

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
         *  @brief For targets whose attribute value type is an array, return
         *      the array in std::array form.
         *
         *  @pre Target service must be initialized
         *
         *  @post Target's specified attribute value returned as a std::array,
         *      or assert called if specified attribute doesn't exist for the
         *      associated target or type is not an array
         *
         *  @return std::array
         *
         *  @retval Content and dimension varies, see xml file where the
         *      attribute's type is set
         */
// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L
        template<const ATTRIBUTE_ID A>
        typename AttributeTraits<A>::TypeStdArr getAttrAsStdArr() const;
#endif // __cplusplus >= 201103L

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
         *  @brief Tries to set the target's specified not synced attribute value
         *
         *  This special function need to be used on FSP to set the value of
         *  an attribute which is not synced to system model.
         *  It returns false if the specified attribute does not exist for the
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
        bool trySetAttrNotSynced(
            typename AttributeTraits<A>::Type const& i_attrValue);

        /**
         *
         *  @brief Tries to set the target's specified std::array attribute value
         *
         *  A special trySetAttr function for setting the attribute values
         *  of the attributes which support std::array.
         *  It returns false if the specified attribute does not exist for the
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
// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L
        template<const ATTRIBUTE_ID A>
        bool trySetAttr(
            typename AttributeTraits<A>::TypeStdArr const& i_attrValue);
#endif

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
         *  @brief For targets whose attribute value type is an array, set value
         *      from a std::array of any dimension
         *
         *  @param[in] i_attrValue Value of the attribute
         *
         *  @pre Target service must be initialized
         *
         *  @post Target's attribute value updated if it exists and if it
         *  suppports TypeStdArr type, otherwise routine asserts
         */
// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L
        template<const ATTRIBUTE_ID A>
        void setAttrFromStdArr(typename AttributeTraits<A>::TypeStdArr const&
            i_attrValue);
#endif

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


        /**
         *  @brief Tries to set the target's specified attribute value
         *         Only use if template attribute system can't be used
         *         Relies on assumptions instead of enforcing them.
         *         Assumes it is a writeable attribute
         *         Assumes i_size matches the size of the attribute
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
        bool unsafeTrySetAttr(
            ATTRIBUTE_ID i_attr,
            uint32_t     i_size,
            const void*  i_pAttrData) const
        {
            // no check for size or if attribute is writable
            return _trySetAttr(i_attr, i_size, i_pAttrData);
        }

        /**
         *  @brief Tries to get the target's specified attribute value
         *         Only use if template attribute system can't be used
         *         Relies on assumptions instead of enforcing them.
         *         Assumes it is a readable attribute
         *         Assumes i_size matches the size of the attribute
         *
         *  Tries to get the target's specified attribute value
         *
         *  @param[in] i_attr Attribute to retrieve
         *  @param[in] i_size Size of the attribute
         *  @param[in] i_pAttrData Location holding the buffer to write attribute data to
         *
         *  @pre Target service must be initialized
         *
         *  @post If attribute exists for the associated target, attribute value
         *      read and success (true) returned.  Otherwise, attribute value
         *      not read and failure (false) returned.
         *
         *  @return bool indicating if attribute read succeeded or not
         *
         *  @retval true Attribute read succeeded
         *  @retval false Attribute read failed
         */
        bool unsafeTryGetAttr(
            ATTRIBUTE_ID i_attr,
            uint32_t     i_size,
            void*        i_pAttrData) const
        {
            // no check for size or if attribute is readable
            return _tryGetAttr(i_attr, i_size, i_pAttrData);
        }

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
            void*        io_attrData) const
        #ifdef __HOSTBOOT_MODULE
        ; // not inlined for hostboot case, defined in persistrwattrcheck.C
          // where the enum value and range checks are performed
          // runtime case is handled there separately
        #else
        {
            // inlined to _tryGetAttrUnsafe for FSP case
            return _tryGetAttrUnsafe(i_attr, i_size, io_attrData);
        }
        #endif


        /**
         *  @brief Tries to get the target's specified attribute value without
         *         checking for valid values. Do not call this function
         *         directly. This function is private.
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
        bool _tryGetAttrUnsafe(
            ATTRIBUTE_ID i_attr,
            uint32_t     i_size,
            void*        io_attrData) const;

        /**
         *  @brief Tries to get the target's specified attribute value without
         *         checking for valid values. Do not call this function
         *         directly. This function is private.
         *
         *  Tries to get the target's specified attribute value
         *
         *  @param[in] i_attr Attribute to retrieve
         *  @param[in] i_size Size of the attribute
         *  @param[in] i_attrRP Pointer to attribute resource provider
         *  @param[in] i_pAttrId Pointer to array of attribute IDs for target
         *  @param[in] i_ppAttrAddr Pointer to array of attribute addresses
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
        bool _tryGetAttrUnsafe(
            ATTRIBUTE_ID i_attr,
            uint32_t     i_size,
            AttrRP*      i_attrRP,
            ATTRIBUTE_ID* i_pAttrId,
            AbstractPointer<void>* i_ppAttrAddr,
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
         *  @brief Gets a pointer to the target's associated attribute
         *
         *  Gets a pointer to the target's associated attribute
         *
         *  @param[in] i_attr Attribute to retrieve
         *  @param[in] i_attrRP Pointer to attribute resource provider
         *  @param[in] i_pAttrId Pointer to array of attribute IDs for target
         *  @param[in] i_ppAttrAddr Pointer to array of attribute addresses
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
            ATTRIBUTE_ID  i_attr,
            AttrRP*       i_attrRP,
            ATTRIBUTE_ID* i_pAttrId,
            AbstractPointer<void>* i_ppAttrAddr,
            void*&        o_pAttr) const;

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
         *  @brief enumeration of assert reasons
         */
        enum TargAssertReason
        {
            SET_ATTR,
            SET_ATTR_FROM_STD_ARR,
            GET_ATTR,
            GET_ATTR_AS_STRING,
            GET_ATTR_AS_STD_ARRAY,
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
        // CHILD_BY_AFFINTY, PERVASIVE_CHILD, PARENT_PERVASIVE,
        // OMI_CHILD, OMIC_PARENT, PAUC_CHILD and PAUC_PARENT.
        // The number of pointers should exactly equal value
        // of TargetService::MAX_ASSOCIATION_TYPES defined in
        // targeting/common/targetservice.H.  Due to the huge code changes
        // necessary to directly use that enum value, a compile time assert in
        // targeting/common/targetservice.C enforces that restriction.
        TARGETING::AbstractPointer< AbstractPointer<Target> >
            iv_ppAssociations[10];

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

#ifdef __HOSTBOOT_RUNTIME
        friend ERRORLOG::ErrlEntry* RT_TARG::saveRestoreAttrs(void *,
                                                              void *,
                                                              uint8_t);
#endif

        friend class AttrRP;

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

        /*
         * @brief allow rt_cmds to use private _tryGetAttr.
         */
        friend void Util::cmd_getattr( char*& o_output,
                                       uint32_t i_huid,
                                       uint32_t i_attrId,
                                       uint32_t i_size );

#ifdef __HOSTBOOT_MODULE
        friend void UTIL::dumpHBAttrs(uint32_t i_huid);
        friend class ::AttributeRulesTest;
#endif

#ifndef __HOSTBOOT_RUNTIME
#ifdef CONFIG_DEVTREE
        friend bool DEVTREE::devtreeSyncAttrs();
#endif
#endif
} PACKED;

template<const ATTRIBUTE_ID A>
bool Target::tryGetAttrNotSynced(
    typename AttributeTraits<A>::Type& o_attrValue) const
{
    if(AttributeTraits<A>::readable == AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::notHbMutex == AttributeTraits<A>::notHbMutex) { }
    if(AttributeTraits<A>::notFspMutex == AttributeTraits<A>::notFspMutex) { }
    return _tryGetAttr(A,sizeof(o_attrValue),&o_attrValue);
}

template<const ATTRIBUTE_ID A>
bool Target::tryGetAttr(typename AttributeTraits<A>::Type& o_attrValue) const
{
    if(AttributeTraits<A>::readable == AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::notHbMutex == AttributeTraits<A>::notHbMutex) { }
#if !defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)
    if(AttributeTraits<A>::notFspMutex == AttributeTraits<A>::notFspMutex) { }
#endif //!defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)
    if(AttributeTraits<A>::fspAccessible == AttributeTraits<A>::fspAccessible)
       { }
    return _tryGetAttr(A,sizeof(o_attrValue),&o_attrValue);
}

// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L
template<const ATTRIBUTE_ID A>
bool Target::tryGetAttr(
    typename AttributeTraits<A>::TypeStdArr& o_attrValue) const
{
    if(AttributeTraits<A>::readable == AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::notHbMutex == AttributeTraits<A>::notHbMutex) { }
    if(AttributeTraits<A>::fspAccessible == AttributeTraits<A>::fspAccessible)
       { }
    return _tryGetAttr(A, sizeof(o_attrValue), &o_attrValue);
}
#endif

template<const ATTRIBUTE_ID A>
bool Target::trySetAttr(typename AttributeTraits<A>::Type const& i_attrValue)
{
    if(AttributeTraits<A>::writeable == AttributeTraits<A>::writeable) { }
    if(AttributeTraits<A>::notHbMutex == AttributeTraits<A>::notHbMutex) { }
#if !defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)
    if(AttributeTraits<A>::fspAccessible == AttributeTraits<A>::fspAccessible)
       { }
#endif //!defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)
    return _trySetAttr(A,sizeof(i_attrValue),&i_attrValue);
}

template<const ATTRIBUTE_ID A>
bool Target::trySetAttrNotSynced(
    typename AttributeTraits<A>::Type const& i_attrValue)
{
    if(AttributeTraits<A>::writeable == AttributeTraits<A>::writeable) { }
    if(AttributeTraits<A>::notHbMutex == AttributeTraits<A>::notHbMutex) { }
    return _trySetAttr(A,sizeof(i_attrValue),&i_attrValue);
}

// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L
template<const ATTRIBUTE_ID A>
bool Target::trySetAttr(typename AttributeTraits<A>::TypeStdArr
    const& i_attrValue)
{
    if(AttributeTraits<A>::writeable == AttributeTraits<A>::writeable) { }
    if(AttributeTraits<A>::notHbMutex == AttributeTraits<A>::notHbMutex) { }
    return _trySetAttr(A,sizeof(i_attrValue),&i_attrValue);
}
#endif

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
typename AttributeTraits<A>::Type Target::getAttr(AttrRP* i_attrRP,
                                                  ATTRIBUTE_ID* i_pAttrId,
                                                  AbstractPointer<void>*
                                                      i_ppAttrAddr) const
{
    typename AttributeTraits<A>::Type l_attrValue;
    if(AttributeTraits<A>::readable == AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::notHbMutex == AttributeTraits<A>::notHbMutex) { }
    if(AttributeTraits<A>::notFspMutex == AttributeTraits<A>::notFspMutex) { }

    bool l_read = _tryGetAttrUnsafe(A,
                                    sizeof(l_attrValue),
                                    i_attrRP,
                                    i_pAttrId,
                                    i_ppAttrAddr,
                                    reinterpret_cast<void*>(&l_attrValue));

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

// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L
template<const ATTRIBUTE_ID A>
void Target::setAttrFromStdArr(typename AttributeTraits<A>::TypeStdArr const&
    i_attrValue)
{
    bool l_wrote = trySetAttr<A>(i_attrValue);
    if (unlikely(!l_wrote))
    {
        targAssert(SET_ATTR_FROM_STD_ARR, A);
    }
}
#endif

template<const ATTRIBUTE_ID A>
mutex_t* Target::getHbMutexAttr() const
{
    if(AttributeTraits<A>::hbMutex == AttributeTraits<A>::hbMutex) { }
    if(AttributeTraits<A>::readable == AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::writeable == AttributeTraits<A>::writeable) { }
    return _getHbMutexAttr(A);
}

template<const ATTRIBUTE_ID A>
util::Mutex* Target::getFspMutexAttr() const
{
    if(AttributeTraits<A>::fspMutex == AttributeTraits<A>::fspMutex) { }
    if(AttributeTraits<A>::readable == AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::writeable == AttributeTraits<A>::writeable) { }
    return _getFspMutexAttr(A);
}

template<const ATTRIBUTE_ID A>
bool Target::tryGetHbMutexAttr(
    mutex_t*& o_pMutex) const
{
    if(AttributeTraits<A>::hbMutex == AttributeTraits<A>::hbMutex) { }
    if(AttributeTraits<A>::readable == AttributeTraits<A>::readable) { }
    if(AttributeTraits<A>::writeable == AttributeTraits<A>::writeable) { }
    return _tryGetHbMutexAttr(A,o_pMutex);
}

template<const ATTRIBUTE_ID A>
const char* Target::getAttrAsString() const
{
    // Note: the compiler optimizes the following check (which fails
    // at compile time if the attribute does not have a string
    // conversion) away
    if(AttributeTraits<A>::hasStringConversion ==
            AttributeTraits<A>::hasStringConversion) { }
    typename AttributeTraits<A>::Type l_attrValue;
    bool l_read = tryGetAttr<A>(l_attrValue);
    if (unlikely(!l_read))
    {
        targAssert(GET_ATTR_AS_STRING, A);
    }
    return attrToString<A>(l_attrValue);
}

// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L
template<const ATTRIBUTE_ID A>
typename AttributeTraits<A>::TypeStdArr Target::getAttrAsStdArr() const
{
    typename AttributeTraits<A>::TypeStdArr l_stdArr;

    bool l_read = tryGetAttr<A>(l_stdArr);

    if (unlikely(!l_read))
    {
        targAssert(GET_ATTR_AS_STD_ARRAY, A);
    }

    return l_stdArr;
}
#endif // __cplusplus >= 201103L

// WARNING: The following #include imports any platform specific template
// specializations for getAttr and tryGetAttr
#include <targeting/adapters/targetadapter.H>

// Keep secureboot-related attribute value checking code out of runtime and FSP
#ifndef __HOSTBOOT_RUNTIME
#ifdef __HOSTBOOT_MODULE

// Function to handle secureboot attribute enum check failures
/**
 * @brief  Creates an error log with target and attribute information
 *         and halts the IPL.
 *
 * @param[in] i_pTarget The target associated with the attribute that failed
 *                      enum value checking. Cannot be nullptr.
 * @param[in] i_attr    The attribute id of the attribute that failed enum
 *                      value checking.
 * @param[in] i_invalidValue The invalid value that failed the enum check.
 */
void handleEnumCheckFailure(const Target* i_pTarget,
                            const ATTRIBUTE_ID i_attr,
                            const uint64_t i_invalidValue);

// Function to handle secureboot attribute range check failures
/**
 * @brief  Creates an error log with target and attribute information
 *         and halts the IPL.
 *
 * @param[in] i_pTarget The target associated with the attribute that failed.
 *                      Cannot be nullptr.
 *
 * @param[in] i_attr The attribute id of the attribute that failed
 *
 * @param[in] i_outOfRangeValue The value that was out of range
 */
void handleRangeCheckFailure(const Target* i_pTarget,
                             const ATTRIBUTE_ID i_attr,
                             const uint64_t i_outOfRangeValue);

// Function to handle validation of all persistent r/w attributes for runtime
/**
 * @brief  Attempts to get all persistent r/w attributes for a given target.
 *         Those that are non-present for that target are skipped. All others
 *         are checked for valid enum values and ranges.
 *
 * @param[in] i_pTarget The target for which all attributes will be checked.
 *                      Cannot be nullptr.
 */
void validateAllRwNvAttr(const Target* i_pTarget);


// The following #include ensures that persistent read/write attributes are
// value-checked for validity upon calling getAttr. This is done via
// autogenerated template specializations for each attribute. External calls
// directly to _tryGetAttr would bypass these specializations and are handled
// separately via an autogenerated wrapper around _tryGetAttr. See the
// definition of _tryGetAttr and autogenerated file persistrwattrcheck.C
// for details.
#include <persistrwattrcheck.H>

#endif
#endif
// end of secureboot-related attribute value checking code
} // End namespace TARGETING

#endif // __TARGETING_COMMON_TARGET_H
