/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/attribute_service.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
///
/// @file src/include/usr/hwpf/plat/attribute_service.H
///
/// @brief Defines the PLAT attribute access macros and the functions that
///        access attributes for FAPI2
///
/// Note that platform code must provide the code.
///

#ifndef ATTRIBUTESERVICE_H_
#define ATTRIBUTESERVICE_H_

//******************************************************************************
// Includes
//******************************************************************************

#include <stdint.h>
#include <return_code.H>
#include <target.H>
#include <target_types.H>

#include <plat_attribute_service.H>
#include <fapi2_attribute_service.H>
#include <targeting/common/attributes.H>
#include <fapi2platattrmacros.H>

#include <devicefw/driverif.H>
#include <plat_attr_override_sync.H>
#include <vpd/spdenums.H>


//******************************************************************************
// Interface
//******************************************************************************

namespace fapi2
{

namespace platAttrSvc
{

///
/// @brief Gets the TARGETING object for the input FAPI target
///
/// @param[in] i_pFapiTarget   FAPI2 Target reference
/// @param[o]  o_pTarget       Output TARGETING object
/// @param[in] i_expectedType  Expecting TARGETING object type
/// @return errlHndl_t
///
errlHndl_t getTargetingTarget(const Target<TARGET_TYPE_ALL>& i_pFapiTarget,
                   TARGETING::Target* & o_pTarget,
                   const TARGETING::TYPE i_expectedType = TARGETING::TYPE_NA);

///
/// @brief Helper function for getTargetingAttr, this function is a friend of
///        TARGETING::Target so it can call _tryGetAttr
///
///
/// @param[in] i_pTargTarget Targeting Target reference
/// @param[in] i_targAttrId  TARGETING Attribute ID
/// @param[in] i_attrSize    Size of attribute in bytes
/// @param[in] o_pAttr       Pointer to attribute where value is copied to
/// @return                  boolean describing if it was successful
bool getTargetingAttrHelper(TARGETING::Target * l_pTargTarget,
                            const TARGETING::ATTRIBUTE_ID i_targAttrId,
                            const uint32_t i_attrSize, void * o_pAttr);

///
/// @brief Gets a Targeting attribute, this is called by the macro that maps a
///        FAPI Attribute get to a TARGETING attribute and should not be called
///        directly
///
/// @param[in] i_pFapiTarget FAPI2 Target reference
/// @param[in] i_targAttrId  TARGETING Attribute ID
/// @param[in] i_attrSize    Size of attribute in bytes
/// @param[in] o_pAttr       Pointer to attribute where value is copied to
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
ReturnCode getTargetingAttr(const Target<TARGET_TYPE_ALL,
                                        plat_target_handle_t >& i_pFapiTarget,
                            const TARGETING::ATTRIBUTE_ID i_targAttrId,
                            const uint32_t i_attrSize,
                            void * o_pAttr);

///
/// @brief Helper function for setTargetingAttr, this function is a friend of
///        TARGETING::Target so it can call _trySetAttr
///
///
/// @param[in] i_pTargTarget Targeting Target reference
/// @param[in] i_targAttrId  TARGETING Attribute ID
/// @param[in] i_attrSize    Size of attribute in bytes
/// @param[in] o_pAttr       Pointer to attribute where value is copied to
/// @return                  boolean describing if it was successful
///
bool setTargetingAttrHelper(TARGETING::Target * l_pTargTarget,
                            const TARGETING::ATTRIBUTE_ID i_targAttrId,
                            const uint32_t i_attrSize,
                            void * o_pAttr);

///
/// @brief Sets a Targeting attribute, this is called by the macro that maps a
///        FAPI Attribute set to a FAPI2 TARGETING attribute and should not be
///        called directly
///
/// @param[in] i_pFapiTarget FAPI2 Target reference
/// @param[in] i_targAttrId  TARGETING Attribute ID
/// @param[in] i_attrSize    Size of attribute in bytes
/// @param[in] i_pAttr       Pointer to attribute where value is retrieved from
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
ReturnCode setTargetingAttr(const Target<TARGET_TYPE_ALL>& i_pFapiTarget,
                            const TARGETING::ATTRIBUTE_ID i_targAttrId,
                            const uint32_t i_attrSize,
                            void * i_pAttr);

///
/// @brief This function is called by the FAPI_ATTR_GET macro when accessing
/// an attribute where zero needs to be returned. The use-case is for attributes
/// that exist solely for overriding
///
/// @param[out] o_data Pointer to user's attribute variable
/// @param[in]  i_len  Size of o_data
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
inline ReturnCode platGetZeroAttrData(void * o_data,
                                          size_t i_len)
{
    memset(o_data, 0, i_len);
    return fapi2::FAPI2_RC_SUCCESS;
}


///
/// @brief This function is called by the FAPI_ATTR_GET macro when getting
/// ATTR_NAME. It should not be called directly
///
/// @param[in]  i_pFapiTarget FAPI2 Target reference
/// @param[out] o_name        Output Name (from enum ATTR_NAME_Enum)
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
ReturnCode platGetTargetName(const Target<TARGET_TYPE_ALL>& i_pFapiTarget,
                                 uint8_t & o_name);

///
/// @brief This function is called by the FAPI_ATTR_GET macro when getting
/// ATTR_FUNCTIONAL. It should not be called directly
///
/// @param[in]  i_pFapiTarget    FAPI2 Target reference
/// @param[out] o_functional     1 = functional, else 0
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
ReturnCode platGetFunctional(const Target<TARGET_TYPE_ALL>& i_pFapiTarget,
                                  uint8_t & o_functional);

///
/// @brief This function is called by the FAPI_ATTR_GET macro when getting
/// ATTR_POS. It should not be called directly
///
/// This is needed because the HWPF attribute is a uint32_t and the Hostboot
/// attribute is a uint16_t so a direct map will not work
///
/// @param[in]  i_pFapiTarget FAPI2 Target reference
/// @param[out] o_pos         Output Posititon
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
ReturnCode platGetTargetPos(const Target<TARGET_TYPE_ALL>& i_pFapiTarget,
                                 uint32_t & o_pos);


///
/// @brief This function is called by the FAPI_ATTR_GET macro when getting
/// ATTR_FUSED_CORE_MODE. It should not be called directly
///
///
/// @param[out] o_isFused         0 if not fused
/// @return ReturnCode           Always FAPI2_RC_SUCCESS, this cannot fail
///                              if a toplevel target cannot be found then
///                              an assert triggers in the platform call
///
ReturnCode platGetFusedCoreMode(uint8_t & o_isFused);

///
/// @brief This function is called by the FAPI_ATTR_GET macro when getting
/// ATTR_POUNDV_BUCKET_DATA. It should not be called directly
///
///
/// @param[in]  i_fapiTarget     FAPI2 Target reference
/// @param[out] o_pos            Output pound v bucket data
/// @return ReturnCode           Always FAPI2_RC_SUCCESS, this cannot fail
///                              if a toplevel target cannot be found then
///                              an assert triggers in the platform call
///
ReturnCode platGetPoundVBucketData(const Target<TARGET_TYPE_EQ>& i_fapiTarget,
                                  uint8_t * o_poundVData);

// -----------------------------------------------------------------------------
// End TODO: End to be supported functions
// -----------------------------------------------------------------------------

} // namespace platAttrSvc

} // namespace fapi2

/**
 *  @brief Macro that directly maps a FAPI_ATTR_GET to a Targeting attr get
 *
 *  Firstly there is a compile time check that the user's VAL variable matches
 *  the Targeting attribute type, this is optimized out, then there is a
 *  single function call
 */
#define FAPI2_PLAT_ATTR_SVC_GETMACRO_DIRECT(ID, PTARGET, VAL) \
platAttrSvc::getTargetingAttr(PTARGET, (const TARGETING::ATTRIBUTE_ID)\
fapiToTargeting::ID, sizeof(VAL), &(VAL))


/**
 *  @brief Macro that directly maps a FAPI_ATTR_SET to a Targeting attr set
 *
 *  Firstly there is a compile time check that the user's VAL variable matches
 *  the Targeting attribute type, this is optimized out, then there is a
 *  single function call
 */
#define FAPI2_PLAT_ATTR_SVC_SETMACRO_DIRECT(ID, PTARGET, VAL) \
platAttrSvc::setTargetingAttr(PTARGET, (const TARGETING::ATTRIBUTE_ID)\
fapiToTargeting::ID, sizeof(VAL), &(VAL))



//------------------------------------------------------------------------------
// MACRO to route ATTR_NAME access to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_NAME_GETMACRO(ID, PTARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, PTARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetTargetName(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_FUNCTIONAL access to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_FUNCTIONAL_GETMACRO(ID, PTARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, PTARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetFunctional(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_POS access to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_POS_GETMACRO(ID, PTARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, PTARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetTargetPos(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_FUSED_CORE access to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_FUSED_CORE_MODE_GETMACRO(ID, PTARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, PTARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetFusedCoreMode(VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_POUNDV_BUCKET_DATA access to the correct HB function
//------------------------------------------------------------------------------
#define ATTR_POUNDV_BUCKET_DATA_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetPoundVBucketData(TARGET,VAL)

#endif // ATTRIBUTESERVICE_H_
