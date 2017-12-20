/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/attribute_service.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
///                                Don't need to check the type here, get macro
///                                does it for us, thus use the all type to
///                                allow streamlined dump of ATTR
/// @param[out] o_pos            Output pound v bucket data
/// @return ReturnCode           Always FAPI2_RC_SUCCESS, this cannot fail
///                              if a toplevel target cannot be found then
///                              an assert triggers in the platform call
///
ReturnCode platGetPoundVBucketData(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                  uint8_t * o_poundVData);

///
/// @brief This function is called by the FAPI_ATTR_GET macro when getting
/// ATTR_POUNDW_BUCKET_DATA. It should not be called directly
///
///
/// @param[in]  i_fapiTarget     FAPI2 Target reference
///                                Don't need to check the type here, get macro
///                                does it for us, thus use the all type to
///                                allow streamlined dump of ATTR
/// @param[out] o_pos            Output pound w bucket data
/// @return ReturnCode           Always FAPI2_RC_SUCCESS, this cannot fail
///                              if a toplevel target cannot be found then
///                              an assert triggers in the platform call
///
ReturnCode platGetPoundWBucketData(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                  uint8_t * o_poundWData);

///
/// @brief This function is called by the FAPI_ATTR_GET macro when getting
/// ATTR_WOF_TABLE_DATA. It should not be called directly
///
///
/// @param[in]  i_fapiTarget     FAPI2 Target reference
///                                Currently system target and unused,
///                                Could change to proc target later.
///                                Don't need to check the type here, get macro
///                                does it for us, thus use the all type to
///                                allow streamlined dump of ATTR
/// @param[out] o_pos            Output WOF table data
/// @return ReturnCode           Always FAPI2_RC_SUCCESS, this cannot fail
///                              if a toplevel target cannot be found then
///                              an assert triggers in the platform call
///
ReturnCode platGetWOFTableData(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                               uint8_t * o_wofTableData);

///
/// @brief This function is called by the FAPI_ATTR_GET macro when getting
/// the Bad DQ Bitmap attribute. It should not be called directly.
///
/// @param[in]  i_fapiTarget  DIMM target pointer
/// @param[out] o_data        Bad DIMM DQ Bitmap
/// @return     ReturnCode.   Zero on success, else platform specified error
///
ReturnCode fapiAttrGetBadDqBitmap( const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                   ATTR_BAD_DQ_BITMAP_Type (&o_data) );

///
/// @brief This function is called by the FAPI_ATTR_SET macro when setting
/// the Bad DQ Bitmap attribute. It should not be called directly.
///
/// @param[in]  i_fapiTarget  DIMM target pointer
/// @param[in]  i_data        Bad DIMM DQ Bitmap
/// @return     ReturnCode.   Zero on success, else platform specified error
///
ReturnCode fapiAttrSetBadDqBitmap( const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                   ATTR_BAD_DQ_BITMAP_Type (&i_data) );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
/// the SECURITY_MODE attribute. It should not be called directly.
///
/// @param[out] o_securityMode   Provides the attribute contents to the caller
/// @return ReturnCode           Always FAPI2_RC_SUCCESS, this cannot fail.
///                              If a toplevel target cannot be found then
///                              an assert triggers in the platform call
///
ReturnCode platGetSecurityMode(uint8_t & o_securityMode);

/// @brief This function is called by the FAPI_ATTR_SET macro when setting
/// the SECURITY_MODE attribute. It should not be called directly. There are no
/// parameters. This is intentional as setting this attribute is not supported
/// from FAPI or FAPI runtime code. A FAPI INFO trace will be printed explaining
/// this.
///
/// @return ReturnCode           Always FAPI2_RC_SUCCESS, this cannot fail.
ReturnCode platSetSecurityMode();

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  the VPD_POWER_CONTROL_CAPABLE attribute. It should not be called directly.
//
//  @param[in] i_fapiTarget The target for the attribute operation.
//  @param[out] o_vpdPowerControlCapableVal   The retrieved attribute value.
//  @return ReturnCode       Zero on success, else platform specified error.
ReturnCode platGetControlCapableData(
                                const Target<TARGET_TYPE_ALL>& i_fapiTarget,
        ATTR_CEN_VPD_POWER_CONTROL_CAPABLE_Type& o_vpdPowerControlCapableVal
                                    );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  the VPD_ISDIMMTOC4DQ attribute. It should not be called directly.
//
//  @param[in] i_fapiTarget The target for the attribute operation.
//  @param[out] o_vpdIsDimmTOC4DQVal  The retrieved attribute value.
//  @return ReturnCode       Zero on success, else platform specified error.
ReturnCode platGetDQAttrISDIMM(
                           const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                   ATTR_CEN_VPD_ISDIMMTOC4DQ_Type &o_vpdIsDimmTOC4DQVal
                              );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  the VPD_ISDIMMTOC4DQS attribute. It should not be called directly.
//
//  @param[in] i_fapiTarget The target for the attribute operation.
//  @param[out] o_vpdIsDimmTOC4DQSVal The retrieved attribute value.
//  @return ReturnCode       Zero on success, else platform specified error.
ReturnCode platGetDQSAttrISDIMM(
                                const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                      ATTR_CEN_VPD_ISDIMMTOC4DQS_Type &o_vpdIsDimmTOC4DQSVal
                               );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  the DRAM_2N_MODE_ENABLED attribute. It should not be called directly.
//
//  @param[in] i_fapiTarget The target for the attribute operation.
//  @param[out] o_dram2NModeEnabled   The retrieved attribute value.
//  @return ReturnCode       Zero on success, else platform specified error.
ReturnCode platGetMBvpdDram2NModeEnabled(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                    ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_Type& o_dram2NModeEnabled
                                        );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  the VPD_VM_KEYWORD attribute. It should not be called directly.
//
//  @param[in] i_fapiTarget The target for the attribute operation.
//  @param[out] o_vpdVMKeywordVal       The retrieved attribute value.
//  @return ReturnCode       Zero on success, else platform specified error.
ReturnCode platGetMBvpdMemoryDataVersion(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                ATTR_CEN_VPD_VM_KEYWORD_Type& o_vpdVMKeywordVal
                                        );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  the VPD_VD_KEYWORD attribute. It should not be called directly.
//
//  @param[in] i_fapiTarget The target for the attribute operation.
//  @param[out] o_vpdVDKeywordVal        The retrieved attribute value.
//  @return ReturnCode       Zero on success, else platform specified error.
ReturnCode platGetMBvpdSPDXRecordVersion(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                ATTR_CEN_VPD_VD_KEYWORD_Type& o_vpdVDKeywordVal
                                        );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  the VPD_DIMM_SPARE attribute. It should not be called directly.
//
//  @param[in] i_fapiTarget The target for the attribute operation.
//  @param[out] o_vpdDimmSpare  The retrieved attribute value.
//  @return ReturnCode       Zero on success, else platform specified error.
ReturnCode platGetMBvpdSpareDramData(
                                  const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                 ATTR_CEN_VPD_DIMM_SPARE_Type &o_vpdDimmSpare
                                    );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  the VPD_VERSION attribute. It should not be called directly.
//
//  @param[in] i_fapiTarget The target for the attribute operation.
//  @param[out] o_vpdVersion The retrieved attribute value.
//  @return ReturnCode       Zero on success, else platform specified error.
ReturnCode platGetMBvpdVersion(
                                 const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                 ATTR_CEN_VPD_VERSION_Type& o_vpdVersion
                               );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  the VPD_DW_KEYWORD attribute. It should not be called directly.
//
//  @param[in] i_fapiTarget The target for the attribute operation.
//  @param[out] o_vpdDWKeyword  The retrieved attribute value.
//  @return ReturnCode       Zero on success, else platform specified error.
ReturnCode platGetMBvpdVoltageSettingData(
                                const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                ATTR_CEN_VPD_DW_KEYWORD_Type& o_vpdDWKeyword
                                         );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  a Memory Buffer vpd attribute. It should not be called directly.
//
// @param[in] i_fapiTarget The fapi target for the attribute get.
// @param[in] i_attr The MBVpd attribute to fetch.
// @param[out] o_pVal A pointer to a buffer in which to copy the
//             attribute value.
// @param[in] i_valSize The size of the buffer for the attribute value.
ReturnCode platGetMBvpdAttr(
                          const fapi2::Target<TARGET_TYPE_ALL>& i_fapiTarget,
                          const fapi2::AttributeId i_attr,
                          void*   o_pVal,
                          const size_t i_valSize
                         );

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  a Memory Buffer vpd attribute. It should not be called directly.
//
// @param[in] i_attr The MBVpd attribute to fetch.
// @param[in] i_fapiTarget The MBA target for the attribute get.
// @param[out] o_MBvpdAttrVal A variable into which the attribute will
//             be copied
template<typename T>
ReturnCode platGetMBvpdAttr(
                            const fapi2::AttributeId i_attrId,
                            const fapi2::Target<TARGET_TYPE_ALL>& i_fapiTarget,
                            T& o_MBvpdAttrVal
                           )
{
    return platGetMBvpdAttr(i_fapiTarget,
                            i_attrId,
                            reinterpret_cast<void*>(&o_MBvpdAttrVal),
                            sizeof(T));
}

/// @brief Function to be called by GETMACRO_OB[0,1,2,3]_PLL_BUCKET
///         functions
/// @param[in] i_fapiTarget      FAPI2 Target pointer
/// @param[out] o_bucket_val     corresponding number in PLL frequency list
/// @param[in] i_index           The index number of the OBUS (0,1,2,3)
ReturnCode getPllBucket(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                        uint8_t &o_bucket_val,
                        const uint8_t i_index);

/// @brief This function is called by the FAPI_ATTR_GET macro when getting
//  the CEN_CDIMM_VPD_* attributes. It should not be called directly.
//
//  @param[in] i_fapiTarget  The target for the attribute operation.
//  @param[in] i_attr        Which ATTR extracting from VPD
//  @param[out] o_val        The retrieved attribute value.
//  @return ReturnCode       Zero on success, else platform specified error.
ReturnCode platGetMBvpdSlopeInterceptData(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                   const uint32_t i_attr,
                                   uint32_t& o_val);

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
// MACRO to route ATTR_OB[0..3]_PLL_BUCKET access to the correct HB function
//------------------------------------------------------------------------------
#define ATTR_OB0_PLL_BUCKET_GETMACRO(ID,PTARGET,VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, PTARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::getPllBucket(PTARGET, VAL, 0)

#define ATTR_OB1_PLL_BUCKET_GETMACRO(ID,PTARGET,VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, PTARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::getPllBucket(PTARGET, VAL, 1)

#define ATTR_OB2_PLL_BUCKET_GETMACRO(ID,PTARGET,VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, PTARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::getPllBucket(PTARGET, VAL, 2)

#define ATTR_OB3_PLL_BUCKET_GETMACRO(ID,PTARGET,VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, PTARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::getPllBucket(PTARGET, VAL, 3)

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

//------------------------------------------------------------------------------
// MACRO to route ATTR_POUNDW_BUCKET_DATA access to the correct HB function
//------------------------------------------------------------------------------
#define ATTR_POUNDW_BUCKET_DATA_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetPoundWBucketData(TARGET,VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_WOF_TABLE_DATA access to the correct HB function
//------------------------------------------------------------------------------
#define ATTR_WOF_TABLE_DATA_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetWOFTableData(TARGET,VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_BAD_DQ_BITMAP read access to the correct HB function
//------------------------------------------------------------------------------
#define ATTR_BAD_DQ_BITMAP_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::fapiAttrGetBadDqBitmap(TARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_BAD_DQ_BITMAP write access to the correct HB function
//------------------------------------------------------------------------------
#define ATTR_BAD_DQ_BITMAP_SETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::fapiAttrSetBadDqBitmap(TARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_SECURITY_MODE access to the correct HB function
//------------------------------------------------------------------------------
#define ATTR_SECURITY_MODE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetSecurityMode(VAL)

//-----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_POWER_CONTROL_CAPABLE access to the correct
// HB function
//-----------------------------------------------------------------------------
#define ATTR_CEN_VPD_POWER_CONTROL_CAPABLE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetControlCapableData(TARGET, VAL)

//-----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_ISDIMMTOC4DQ access to the correct HB function
//-----------------------------------------------------------------------------
#define ATTR_CEN_VPD_ISDIMMTOC4DQ_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetDQAttrISDIMM(TARGET, VAL)

//-----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_ISDIMMTOC4DQS access to the correct HB function
//-----------------------------------------------------------------------------
#define ATTR_CEN_VPD_ISDIMMTOC4DQS_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetDQSAttrISDIMM(TARGET, VAL)

//-----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED access to the correct
// HB function
//-----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetMBvpdDram2NModeEnabled(TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_VM_KEYWORD access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_VM_KEYWORD_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetMBvpdMemoryDataVersion(TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_VD_KEYWORD access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_VD_KEYWORD_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetMBvpdSPDXRecordVersion(TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DIMM_SPARE access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DIMM_SPARE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetMBvpdSpareDramData(TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_VERSION access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_VERSION_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetMBvpdVersion(TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DW_KEYWORD access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DW_KEYWORD_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::platGetMBvpdVoltageSettingData(TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_TSYS_ADR access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_TSYS_ADR_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_TSYS_ADR_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_TSYS_DP18 access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_TSYS_DP18_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_TSYS_DP18_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRAM_RON access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRAM_RON_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRAM_RON_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRAM_RTT_NOM access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRAM_RTT_NOM_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRAM_RTT_NOM_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRAM_RTT_WR access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRAM_RTT_WR_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRAM_RTT_WR_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_ODT_RD access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_ODT_RD_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_ODT_RD_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_ODT_WR access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_ODT_WR_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_ODT_WR_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DIMM_RCD_IBT access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DIMM_RCD_IBT_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DIMM_RCD_IBT_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_RD_VREF access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_RD_VREF_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_RD_VREF_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRAM_WR_VREF access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRAM_WR_VREF_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRAM_WR_VREF_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRAM_WRDDR4_VREF access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRAM_WRDDR4_VREF_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRAM_WRDDR4_VREF_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_RCV_IMP_DQ_DQS access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_RCV_IMP_DQ_DQS_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_RCV_IMP_DQ_DQS_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRV_IMP_DQ_DQS access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRV_IMP_DQ_DQS_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRV_IMP_DQ_DQS_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRV_IMP_CNTL access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRV_IMP_CNTL_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRV_IMP_CNTL_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRV_IMP_ADDR access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRV_IMP_ADDR_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRV_IMP_ADDR_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRV_IMP_CLK access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRV_IMP_CLK_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRV_IMP_CLK_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRV_IMP_SPCKE access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRV_IMP_SPCKE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRV_IMP_SPCKE_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_SLEW_RATE_DQ_DQS access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_SLEW_RATE_DQ_DQS_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_SLEW_RATE_CNTL access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_SLEW_RATE_CNTL_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_SLEW_RATE_CNTL_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_SLEW_RATE_ADDR access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_SLEW_RATE_ADDR_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_SLEW_RATE_ADDR_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_SLEW_RATE_CLK access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_SLEW_RATE_CLK_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_SLEW_RATE_CLK_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_SLEW_RATE_SPCKE access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_SLEW_RATE_SPCKE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_SLEW_RATE_SPCKE_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_CKE_PRI_MAP access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_CKE_PRI_MAP_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_CKE_PRI_MAP_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_CKE_PWR_MAP access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_CKE_PWR_MAP_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_CKE_PWR_MAP_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_RLO access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_RLO_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_RLO_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_WLO access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_WLO_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_WLO_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_GPO access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_GPO_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_GPO_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_PAR access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_PAR_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_PAR_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M_ACTN access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M_ACTN_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M_ACTN_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1 access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_PERIODIC_MEMCAL_MODE_OPTIONS access to the
// correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_PERIODIC_MEMCAL_MODE_OPTIONS_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_PERIODIC_MEMCAL_MODE_OPTIONS_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_DRAM_RTT_PARK access to the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_DRAM_RTT_PARK_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_DRAM_RTT_PARK_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_RD_CTR_WINDAGE_OFFSET access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_RD_CTR_WINDAGE_OFFSET_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_RD_CTR_WINDAGE_OFFSET_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_MR_VERSION_BYTE access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_MR_VERSION_BYTE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_MR_VERSION_BYTE_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_MR_DATA_CONTROL_BYTE access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_MR_DATA_CONTROL_BYTE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_MR_DATA_CONTROL_BYTE_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_MT_VERSION_BYTE access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_MT_VERSION_BYTE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_MT_VERSION_BYTE_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_VPD_MT_DATA_CONTROL_BYTE access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_VPD_MT_DATA_CONTROL_BYTE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdAttr<fapi2::ATTR_CEN_VPD_MT_DATA_CONTROL_BYTE_Type>(ID, TARGET, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_CDIMM_VPD_MASTER_POWER_INTERCEPT access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_CDIMM_VPD_MASTER_POWER_INTERCEPT_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdSlopeInterceptData(TARGET, ID, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_CDIMM_VPD_MASTER_POWER_SLOPE access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_CDIMM_VPD_MASTER_POWER_SLOPE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdSlopeInterceptData(TARGET, ID, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_CDIMM_VPD_MASTER_TOTAL_POWER_INTERCEPT access to
// the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_CDIMM_VPD_MASTER_TOTAL_POWER_INTERCEPT_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdSlopeInterceptData(TARGET, ID, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_CDIMM_VPD_MASTER_TOTAL_POWER_SLOPE access to
// the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_CDIMM_VPD_MASTER_TOTAL_POWER_SLOPE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdSlopeInterceptData(TARGET, ID, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_CDIMM_VPD_SUPPLIER_POWER_INTERCEPT access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_CDIMM_VPD_SUPPLIER_POWER_INTERCEPT_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdSlopeInterceptData(TARGET, ID, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_CDIMM_VPD_SUPPLIER_POWER_SLOPE access to the correct
// HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_CDIMM_VPD_SUPPLIER_POWER_SLOPE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdSlopeInterceptData(TARGET, ID, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_CDIMM_VPD_SUPPLIER_TOTAL_POWER_INTERCEPT access to
// the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_CDIMM_VPD_SUPPLIER_TOTAL_POWER_INTERCEPT_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdSlopeInterceptData(TARGET, ID, VAL)

//----------------------------------------------------------------------------
// MACRO to route ATTR_CEN_CDIMM_VPD_SUPPLIER_TOTAL_POWER_SLOPE access to
// the correct HB function
//----------------------------------------------------------------------------
#define ATTR_CEN_CDIMM_VPD_SUPPLIER_TOTAL_POWER_SLOPE_GETMACRO(ID, TARGET, VAL) \
    AttrOverrideSync::getAttrOverrideFunc(ID, TARGET, &VAL)\
    ? fapi2::ReturnCode() : \
    fapi2::platAttrSvc::\
    platGetMBvpdSlopeInterceptData(TARGET, ID, VAL)



#endif // ATTRIBUTESERVICE_H_
