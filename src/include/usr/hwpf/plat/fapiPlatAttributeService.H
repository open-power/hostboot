/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatAttributeService.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
/* [+] Google Inc.                                                        */
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
 *  @file fapiPlatAttributeService.H
 *
 *  @brief Defines the PLAT attribute access macros and the functions that
 *         access attributes
 *
 *  Note that platform code must provide the code.
 */

#ifndef FAPIPLATATTRIBUTESERVICE_H_
#define FAPIPLATATTRIBUTESERVICE_H_

//******************************************************************************
// Includes
//******************************************************************************

#include <stdint.h>
#include <fapiAttributeIds.H>
#include <targeting/common/attributes.H>
#include <attributeenums.H>
#include <fapiplatattrmacros.H>
#include <hwpf/fapi/fapiReturnCode.H>
#include <hwpf/fapi/fapiTarget.H>
#include <hwpf/plat/fapiPlatAttrOverrideSync.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdPhaseRotatorData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdAddrMirrorData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdTermData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdSlopeInterceptData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdSpareDramData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdVersion.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdDram2NModeEnabled.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdSensorMap.H>
#include <hwpf/hwp/mvpd_accessors/getControlCapableData.H>
#include <hwpf/hwp/mvpd_accessors/accessMBvpdL4BankDelete.H>
#include <hwpf/hwp/mvpd_accessors/getISDIMMTOC4DAttrs.H>
#include <hwpf/hwp/spd_accessors/getSpdAttrAccessor.H>
#include <hwpf/hwp/pll_accessors/getPllRingInfoAttr.H>
#include <hwpf/hwp/chip_accessors/getOscswitchCtlAttr.H>
#include <vpd/spdenums.H>
#include <dimmConsts.H>
#include <util/singleton.H>
#include <procMemConsts.H>
#include <fapiL3DeltaDataAttr.H>
#include <config.h>

//******************************************************************************
// Interface
//******************************************************************************

namespace fapi
{

namespace platAttrSvc
{

/**
 *  @brief Compile time check that a variable is the same type as a Targeting
 *         attribute.
 *
 *  Used when mapping a FAPI Attribute to a Targeting attribute to ensure that
 *  the type is correct, if not correct then this function will not be found
 *  and a compile error will result
 *
 *  @param[in] T Type of Targeting attribute
 *  @param[in]   Reference to user's FAPI Attribute variable that must be of
 *               type T
 */
template<typename T> void failIfTargTypeMismatch(T &) { }

/**
 *  @brief Gets a Targeting attribute, this is called by the macro that maps a
 *         FAPI Attribute get to a TARGETING attribute and should not be called
 *         directly
 *
 *  @param[in] i_pFapiTarget Pointer to FAPI Target
 *  @param[in] i_targAttrId  TARGETING Attribute ID
 *  @param[in] i_attrSize    Size of attribute in bytes
 *  @param[in] o_pAttr       Pointer to attribute where value is copied to
 *
 *  @return ReturnCode
 */
fapi::ReturnCode getTargetingAttr(const fapi::Target * i_pFapiTarget,
                                  const TARGETING::ATTRIBUTE_ID i_targAttrId,
                                  const uint32_t i_attrSize,
                                  void * o_pAttr);

/**
 *  @brief Sets a Targeting attribute, this is called by the macro that maps a
 *         FAPI Attribute set to a TARGETING attribute and should not be called
 *         directly
 *
 *  @param[in] i_pFapiTarget Pointer to FAPI Target
 *  @param[in] i_targAttrId  TARGETING Attribute ID
 *  @param[in] i_attrSize    Size of attribute in bytes
 *  @param[in] i_pAttr       Pointer to attribute where value is retrieved from
 *
 *  @return ReturnCode
 */
fapi::ReturnCode setTargetingAttr(const fapi::Target * i_pFapiTarget,
                                  const TARGETING::ATTRIBUTE_ID i_targAttrId,
                                  const uint32_t i_attrSize,
                                  void * i_pAttr);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when accessing
 * an attribute where zero needs to be returned. The use-case is for attributes
 * that exist solely for overriding
 *
 * @param[out] o_data Pointer to user's attribute variable
 * @param[in]  i_len  Size of o_data
 * @return ReturnCode.  Zero on success, else platform specified error
 */
inline fapi::ReturnCode fapiPlatGetZeroAttrData(void * o_data,
                                                size_t i_len)
{
    memset(o_data, 0, i_len);
    return fapi::FAPI_RC_SUCCESS;
}

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when accessing
 * SPD ATTR. It should not be called directly
 *
 * @param[in]  i_pFapiTarget Target pointer to operate on
 * @param[in]  i_keyword     SPD keyword
 * @param[out] o_data        Address of Storage for saving the attribute value
 * @param[in]  i_len         Size of storage
 * @return ReturnCode.  Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetSpdAttr(const fapi::Target * i_pFapiTarget,
                                    const uint16_t i_keyword,
                                    void * o_data,
                                    size_t i_len );

/**
 * @brief This function is called by the FAPI_ATTR_SET macro when accessing
 * SPD ATTR. It should not be called directly
 *
 * @param[in] i_pFapiTarget Target pointer to operate on
 * @param[in] i_keyword     SPD keyword
 * @param[in] i_data        Pointer to data
 * @param[in] i_len         Size of data
 * @return ReturnCode.  Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatSetSpdAttr(const fapi::Target * i_pFapiTarget,
                                    const uint16_t i_keyword,
                                    void * i_data,
                                    size_t i_len );

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_CEN_DQ_TO_DIMM_CONN_DQ. It should not be called directly
 *
 * @param[in]  i_pDimmFapiTarget DIMM target pointer
 * @param[out] o_data            Output data
 * @return ReturnCode.  Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetDqMapping(const fapi::Target * i_pDimmFapiTarget,
                                      uint8_t (&o_data)[DIMM_DQ_NUM_DQS]);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_NAME. It should not be called directly
 *
 * @param[in]  i_pFapiTarget Target pointer
 * @param[out] o_name        Output Name (from enum ATTR_NAME_Enum)
 * @return ReturnCode.   Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetTargetName(const fapi::Target * i_pFapiTarget,
                                       uint8_t & o_name);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_FUNCTIONAL. It should not be called directly
 *
 * @param[in]  i_pFapiTarget    Target pointer
 * @param[out] o_functional     1 = functional, else 0
 * @return ReturnCode.   Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetFunctional(const fapi::Target * i_pFapiTarget,
                                       uint8_t & o_functional);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_POS. It should not be called directly
 *
 * This is needed because the HWPF attribute is a uint32_t and the Hostboot
 * attribute is a uint16_t so a direct map will not work
 *
 * @param[in]  i_pFapiTarget Target pointer
 * @param[out] o_pos         Output Posititon
 * @return ReturnCode.   Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetTargetPos(const fapi::Target * i_pFapiTarget,
                                      uint32_t & o_pos);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_NX_ENABLE, ATTR_PROC_PCIE_ENABLE, ATTR_PROC_L3_ENABLE,
 * ATTR_PROC_A_ENABLE, and ATTR_PROC_X_ENABLE.
 *  It should not be called directly
 *
 * @param[in]  i_id          Fapi Attribute Id
 * @param[in]  i_pFapiTarget Target pointer
 * @param[out] o_enable      Output enable state
 * @return ReturnCode.   Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetEnableAttr( fapi::AttributeId i_id,
    const fapi::Target * i_pFapiTarget, uint8_t & o_enable );

//------------------------------------------------------------------------------
// Prototypes to support  proc_setup_bars_memory_attributes
//  See proc_setup_bars_memory_attributes.xml for detailed descriptions
//------------------------------------------------------------------------------
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_FOREIGN_NEAR_BASE .
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_foreignNearBase   Foreign (near) address region base address
 *                          @note:  the array size of 2 was pulled from
 *                          the xml file and is not expected to change.
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcForeignNearBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignNearBase)[ 2 ] );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_FOREIGN_NEAR_SIZE .
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_foreignNearSize   Size of foreign (near) region
 *                          @note:  the array size of 2 was pulled from
 *                          the xml file and is not expected to change.
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcForeignNearSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignNearSize)[ 2 ] );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_FOREIGN_FAR_BASE .
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_foreignFarBase    Foreign (far) address region base address
 *                          @note:  the array size of 2 was pulled from
 *                          the xml file and is not expected to change.
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcForeignFarBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignFarBase)[ 2 ] );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_FOREIGN_FAR_SIZE .
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_foreignFarSize    Size of foreign (far) region
 *                          @note:  the array size of 2 was pulled from
 *                          the xml file and is not expected to change.
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcForeignFarSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignFarSize)[ 2 ] );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_HA_BASE .
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_haBase    HA logging base address
 *                          @note:  the array size of 8 was pulled from
 *                          the xml file and is not expected to change.
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcHaBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_haBase)[ 8 ] );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_HA_SIZE .
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_haSize    Size of HA memory region
 *                          @note:  the array size of 8 was pulled from
 *                          the xml file and is not expected to change.
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcHaSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_haBase)[ 8 ] );
//------------------------------------------------------------------------------
//  Prototypes to support proc_setup_bars_mmio_attributes
//  see proc_setup_bars_mmio_attributes for detailed descriptions
//------------------------------------------------------------------------------
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_PSI_BRIDGE_BAR_ENABLE
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_psiBridgeBarEnable    PSI Bridge BAR enable
 *  @return     ReturnCode. Zero on success, else platform specified error
 */

fapi::ReturnCode fapiPlatGetProcPsiBridgeBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t     &o_psiBridgeBarEnable );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_FSP_BAR_ENABLE
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_fspBarEnable  FSP BAR enable
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcFspBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t     &o_fspBarEnable );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_INTP_BAR_ENABLE
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_intpBarEnable     INTP BAR enable
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcIntpBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t    &o_intpBarEnable );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_NX_MMIO_BAR_ENABLE
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_nxMmioBarEnable   NX MMIO BAR enable
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcNxMmioBarEnable(
                                    const fapi::Target * i_pTarget,
                                    uint8_t     &o_nxMmioBarEnable );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_NX_MMIO_BAR_SIZE
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_nxMmioBarSize     NX MMIO BAR size value
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcNxMmioBarSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_nxMmioBarSize );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_PCIE_BAR_ENABLE
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_pcieBarEnable     PCIE BAR enable
 *                          @note:  the array size of 3,3 was pulled from
 *                          the xml file and is not expected to change.
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcPcieBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t     (&o_pcieBarEnable) [3][3] );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_PCIE_BAR_BASE_ADDR_
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_pcieBarBase       PCIE BAR base address value
 *                          @note:  the array size of 3,3 was pulled from
 *                          the xml file and is not expected to change.
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcPcieBarBaseAddr (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    (&o_pcieBarBase) [3][3] );
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_PROC_PCIE_BAR_SIZE
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_pcieBarSize       PCIE BAR size value
 *                          @note:  the array size of 3,3 was pulled from
 *                          the xml file and is not expected to change.
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetProcPcieBarSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    (&o_pcieBarSize) [3][3] );

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_EX_L2_SINGLE_MEMBER_ENABLE. It should not be called directly.
 *
 *  @param[in]  i_pTarget Target MB pointer
 *  @param[out] o_val     ATTR_EX_L2_SINGLE_MEMBER_ENABLE value
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetSingleMemberEnableAttr(
    const fapi::Target * i_pTarget,
    uint32_t & o_val);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the Phase Rotator Data attributes
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target mba pointer
 *  @param[in]  i_attr      Phase Rotator Data enumerator item
 *  @param[out] o_val       Phase Rotator Data for each of the 2 ports
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetPhaseRotatorData (
                                    const fapi::Target * i_pTarget,
                                    const fapi::MBvpdPhaseRotatorData i_attr,
                                    uint8_t    (&o_val) [2] );

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the Address Mirroring Data attributes
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target mba pointer
 *  @param[out] o_val       Address Mirroring Data for mba
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetAddrMirrorData (
                                    const fapi::Target * i_pTarget,
                                    uint8_t (&o_val) [2][2] );

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the Termination Data attributes
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target MB pointer
 *  @param[in]  i_attr      Termination Data attribute enumerator
 *  @param[out] o_pVal      Pointer to variable typed output values
 *  @param[in]  i_valSize   Size of output variable
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetTermData (
                              const fapi::Target * i_pTarget,
                              const fapi::MBvpdTermData i_attr,
                              void  * o_pVal,
                              const uint32_t i_valSize);
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the Slope Intercept Data attributes
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target MB pointer
 *  @param[in]  i_attr      Slope Intercept Data attribute enumerator
 *  @param[out] o_Val       Slope Intercept Data
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetSlopeInterceptData (
                              const fapi::Target * i_pTarget,
                              const fapi::MBvpdSlopeIntercept i_attr,
                              uint32_t  & o_val);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the sensor map attributes
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target MB pointer
 *  @param[in]  i_attr      Sensor map attribute enumerator
 *  @param[out] o_Val       Sensor map data
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetSensorMap (
                              const fapi::Target * i_pTarget,
                              const fapi::MBvpdSensorMap i_attr,
                              uint8_t  & o_val);

//------------------------------------------------------------------------------
// Prototypes to support BAD_DQ_BITMAP attribute
//  See dimm_spd_attributes.xml for detailed descriptions
//------------------------------------------------------------------------------

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the Bad DQ Bitmap attribute
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   DIMM target pointer
 *  @param[out] o_data      Bad DIMM DQ Bitmap
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatDimmGetBadDqBitmap (
                                   const fapi::Target * i_pTarget,
                                   uint8_t (&o_data)[DIMM_DQ_MAX_DIMM_RANKS]
                                                    [DIMM_DQ_RANK_BITMAP_SIZE]);
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the vpd version
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target DIMM pointer
 *  @param[out] o_val       vpd version
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetVpdVersion (
                                    const fapi::Target * i_pTarget,
                                    uint32_t & o_val );

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the Dram 2N Mode Enabled attribute
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target mba pointer
 *  @param[out] o_val       Dram 2N Mode Enabled attr enumeration value
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetDram2NModeEnabled (
                                    const fapi::Target * i_pTarget,
                                    uint8_t & o_val );

/**
 * @brief This function is called by the FAPI_ATTR_GET macro and
 * FAPI_ATTR_SET macro when getting or setting the L4 Bank Delete
 * record VSPD keyword MX vpd value
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target MB pointer
 *  @param[in,out] io_val   Retrieved or value to set
 *  @param[in] i_mode       Get or Set mode
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatL4BankDelete (
                                    const fapi::Target * i_pTarget,
                                    uint32_t & io_val,
                                    const fapi::MBvpdL4BankDeleteMode i_mode );
/**
 * @brief This function is called by the FAPI_ATTR_SET macro when setting
 * the Bad DQ Bitmap attribute
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   DIMM target pointer
 *  @param[in]  i_data      Bad DIMM DQ Bitmap
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatDimmSetBadDqBitmap (
                                   const fapi::Target * i_pTarget,
                                   uint8_t (&i_data)[DIMM_DQ_MAX_DIMM_RANKS]
                                                    [DIMM_DQ_RANK_BITMAP_SIZE]);

//------------------------------------------------------------------------------
// Prototype to support VPD_DIMM_SPARE attribute
//  See dimm_spd_attributes.xml for detailed description
//------------------------------------------------------------------------------

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the VPD DIMM Spare attribute
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   MBA target pointer
 *  @param[out] o_data      Spare DRAM availability for all DIMMs on MBA
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatDimmGetSpareDram (
                                    const fapi::Target * i_pTarget,
                                    uint8_t (&o_data)[DIMM_DQ_MAX_MBA_PORTS]
                                                 [DIMM_DQ_MAX_MBAPORT_DIMMS]
                                                    [DIMM_DQ_MAX_DIMM_RANKS]);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * PLL ring attributes. It should not be called directly.
 *
 *  @param[in] i_targAttrId  fapi attribute ID
 *  @param[in]  i_target Target pointer to operate on
 *  @param[in] o_data       Pointer to ring data (or flush data)
 */
fapi::ReturnCode fapiPlatGetPllAttr(const fapi::AttributeId i_attrId,
                                    const fapi::Target * const i_pChipTarget,
                                    uint8_t *o_data);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * PLL ring attributes. It should not be called directly.
 *
 *  @param[in] i_targAttrId  fapi attribute ID
 *  @param[in]  i_target Target pointer to operate on
 *  @param[in] o_pllRingLength       PLL ring length
 */
fapi::ReturnCode fapiPlatGetPllAttr(const fapi::AttributeId i_attrId,
                                    const fapi::Target * const i_pChipTarget,
                                    uint32_t (&o_pllRingLength));

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * PLL ring info attributes. It should not be called directly.
 *
 * @param[in]  i_pProcChip Pointer to Processor Chip fapi target
 * @param[in]  i_attr      The Attribute to get
 * @param[out] o_pVal      Pointer to data buffer filled in with attribute data
 * @param[in]  i_len       Size of o_pVal
 */
fapi::ReturnCode fapiPlatGetPllInfoAttr(
    const fapi::Target * i_pProcChip,
    const fapi::getPllRingInfo::Attr i_attr,
    void * o_pVal,
    const size_t i_len);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 *        DIMM SPD Attributes that are handled by an Accessor HWP
 *        It should not be called directly.
 *
 *  @param[in]  i_pDimm DIMM target pointer
 *  @param[in]  i_attr  Attribute ID
 *  @param[out] o_pVal  Pointer to output variable
 *  @param[in]  i_len   Size of o_pVal
 *  @return     ReturnCode. Zero on success, else error
 */
fapi::ReturnCode fapiPlatGetSpdAttrAccessor (
    const fapi::Target * i_pDimm,
    const fapi::getSpdAttr::Attr i_attr,
    void * o_pVal,
    size_t i_len);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting the
 *        ATTR_PROC_EX_FUNC_L3_DELTA_DATA attribute. It should not be called
 *        directly.
 *
 *  @param[in]  i_pProcTarget Processor Chip Target pointer
 *  @param[out] o_data        Reference to output data
 */
fapi::ReturnCode fapiPlatGetL3DDAttr(const fapi::Target * i_pProcTarget,
                                     uint32_t (&o_data)[DELTA_DATA_SIZE]);
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting the
 *        ATTR_PROC_EX_FUNC_L3_LENGTH attribute. It should not be called
 *        directly.
 *
 *  @param[in]  i_pProcTarget Processor Chip Target pointer
 *  @param[out] o_ringLength  length of decompressed ring
 */
fapi::ReturnCode fapiPlatGetL3Length(const fapi::Target * i_pProcTarget,
                                    uint32_t (&o_ringLength));
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting the
 *        ATTR_PCI_OSCSWITCH_CONFIG attribute. It should not be called
 *        directly.
 *
 *  @param[in]  i_pProcTarget Processor Chip Target pointer
 *  @param[out] o_data        Reference to output data
 */
fapi::ReturnCode fapiPlatGetPciOscswitchConfig
                                     (const fapi::Target * i_pProcTarget,
                                     uint8_t &o_val);
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting the
 *        ATTR_SPD_MODSPEC_COM_REF_RAW_CARD attribute.
 *        It should not be called directly.
 *
 *  @param[in]  i_pDimmTarget Dimm Target pointer
 *  @param[out] o_data        Reference to output data
 */
fapi::ReturnCode fapiPlatGetSpdModspecComRefRawCard
                                     (const fapi::Target * i_pDimmTarget,
                                     uint8_t &o_val);
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting the
 *        ATTR_SPD_MODSPEC_COM_REF_RAW_CARD attribute.
 *        ATTR_OSCSWITCH_CNTL0,1,2  attributes. It should not be called
 *        directly.
 *
 *  @param[in]  i_pProcTarget Processor Chip Target pointer
 *  @param[in]  i_attr        Attribute selection
 *  @param[out] o_pVal        Pointer to output variable
 *  @param[in]  i_len         Size of o_pVal
 */
fapi::ReturnCode fapiPlatGetOscswitchCtl
                              (const fapi::Target * i_pProcTarget,
                               const fapi::getOscswitchCtl::Attr i_attr,
                               void * o_pVal,
                               const size_t i_len);

/**
 * @brief This function supports a new memory attribute. Called by the
 * FAPI_ATTR_GET macro when getting the ATTR_VPD_POWER_CONTROL_CAPABLE
 * attribute.
 * It should not be called directly.
 *
 * @param[in]  i_pTarget Mem Buf Target pointer
 * @param[out] o_val     Pointer to output variable
 *
 */
fapi::ReturnCode fapiPlatGetControlCapable(const fapi::Target * i_pTarget,
                uint8_t  & o_val);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting the
 *        ATTR_VPD_ISDIMMTOC4DQ attribute.
 *        It should not be called directly
 *
 * @param[in] i_pTarget MBA Target pointer
 * @param[out] o_val    Pointer to output array
 */
fapi::ReturnCode getIsDimmToC4DQ
               (const fapi::Target * i_pTarget,
                uint8_t (&o_val) [DIMM_TO_C4_PORTS][DIMM_TO_C4_DQ_ENTRIES]);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting the
 *        ATTR_VPD_ISDIMMTOC4DQS attribute.
 *        It should not be called directly.
 *
 * @param[in] i_pTarget MBA Target pointer
 * @param[out] o_val    Pointer to the output array
 */
fapi::ReturnCode getIsDimmToC4DQS
               (const fapi::Target * i_pTarget,
                uint8_t (&o_val) [DIMM_TO_C4_PORTS][DIMM_TO_C4_DQS_ENTRIES]);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the ATTR_VPD_DIMM_RCD_CNTL_WORD_0_15 attribute.
 * It should not be called directly.
 *
 * @param[in]  i_pTarget Mem Buf Target pointer
 * @param[out] o_val     Pointer to output variable
 *
 */
fapi::ReturnCode fapiPlatGetRCDCntlWord015 (const fapi::Target * i_pTarget,
                                            uint64_t & o_val);

} // namespace platAttrSvc

} // namespace fapi

/**
 *  @brief Macro that directly maps a FAPI_ATTR_GET to a Targeting attr get
 *
 *  Firstly there is a compile time check that the user's VAL variable matches
 *  the Targeting attribute type, this is optimized out, then there is a
 *  single function call
 */
#define FAPI_PLAT_ATTR_SVC_GETMACRO_DIRECT(ID, PTARGET, VAL) \
    (fapi::platAttrSvc::failIfTargTypeMismatch \
        <TARGETING::AttributeTraits \
            <FAPI_PLAT_ATTR_SVC_MACRO_DIRECT_FAPI_##ID>::Type>(VAL), \
     fapi::platAttrSvc::getTargetingAttr(PTARGET, \
         FAPI_PLAT_ATTR_SVC_MACRO_DIRECT_FAPI_##ID, sizeof(VAL), &(VAL)))

/**
 *  @brief Macro that directly maps a FAPI_ATTR_SET to a Targeting attr set
 *
 *  Firstly there is a compile time check that the user's VAL variable matches
 *  the Targeting attribute type, this is optimized out, then there is a
 *  single function call
 */
#define FAPI_PLAT_ATTR_SVC_SETMACRO_DIRECT(ID, PTARGET, VAL) \
    (fapi::platAttrSvc::failIfTargTypeMismatch \
        <TARGETING::AttributeTraits \
            <FAPI_PLAT_ATTR_SVC_MACRO_DIRECT_FAPI_##ID>::Type>(VAL), \
     fapi::platAttrSvc::setTargetingAttr(PTARGET, \
         FAPI_PLAT_ATTR_SVC_MACRO_DIRECT_FAPI_##ID, sizeof(VAL), &(VAL)))

//------------------------------------------------------------------------------
// MACRO to support the overriding of Chip EC Feature Attributes
//------------------------------------------------------------------------------
#define PLAT_GET_CHIP_EC_FEATURE_OVERRIDE(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL)

//------------------------------------------------------------------------------
// MACRO to support the RCD Control Word attribute
//------------------------------------------------------------------------------
#define ATTR_VPD_DIMM_RCD_CNTL_WORD_0_15_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetRCDCntlWord015(PTARGET,VAL)

//------------------------------------------------------------------------------
// MACRO to support the power control capable memory attribute
//------------------------------------------------------------------------------
#define ATTR_VPD_POWER_CONTROL_CAPABLE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetControlCapable(PTARGET,VAL)

//------------------------------------------------------------------------------
// MACRO to support the DQ and DQS attributes.
//------------------------------------------------------------------------------
#define ATTR_VPD_ISDIMMTOC4DQ_GETMACRO(ID,PTARGET,VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID,PTARGET,&VAL)?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::getIsDimmToC4DQ(PTARGET,VAL)

#define ATTR_VPD_ISDIMMTOC4DQS_GETMACRO(ID,PTARGET,VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID,PTARGET,&VAL)?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::getIsDimmToC4DQS(PTARGET,VAL)

//------------------------------------------------------------------------------
// MACROs to route each ATTR_SPD access to the Hostboot SPD function
//------------------------------------------------------------------------------
#define ATTR_SPD_DRAM_DEVICE_TYPE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::BASIC_MEMORY_TYPE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_TYPE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_TYPE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_DENSITY_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::DENSITY, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_ROWS_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::ROW_ADDRESS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_COLUMNS_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::COL_ADDRESS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_NUM_RANKS_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_RANKS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_DRAM_WIDTH_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_DRAM_WIDTH, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_MEMORY_BUS_WIDTH_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_MEMORY_BUS_WIDTH, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FTB_DIVIDEND_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::FTB_DIVIDEND, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FTB_DIVISOR_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::FTB_DIVISOR, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MTB_DIVIDEND_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MTB_DIVIDEND, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MTB_DIVISOR_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MTB_DIVISOR, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TCKMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET,  SPD::TCK_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TAAMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MIN_CAS_LATENCY, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TWRMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TWR_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRCDMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRCD_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRRDMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRRD_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRPMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRP_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRASMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRAS_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRCMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRC_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRFCMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRFC_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TWTRMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TWTR_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRTPMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRTP_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TFAWMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TFAW_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_OPTIONAL_FEATURES_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SDRAM_OPTIONAL_FEATURES, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS_GETMACRO(ID, PTARGET, VAL ) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SDRAM_THERMAL_REFRESH_OPTIONS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_THERMAL_SENSOR_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_THERMAL_SENSOR, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_DEVICE_TYPE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SDRAM_DEVICE_TYPE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_DEVICE_TYPE_SIGNAL_LOADING_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SDRAM_DEVICE_TYPE_SIGNAL_LOADING, &(VAL), sizeof(VAL) )
#define ATTR_SPD_CUSTOM_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::CUSTOM, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_DIE_COUNT_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SDRAM_DIE_COUNT, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TCKMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TCKMIN_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TAAMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TAAMIN_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TRCDMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRCDMIN_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TRPMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRPMIN_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TRCMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRCMIN_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_NUM_OF_REGISTERS_USED_ON_RDIMM_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::RMM_REGS_RDIMM, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_SPECIFIC_SECTION_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_TYPE_SPECIFIC_SECTION, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_MANUFACTURER_ID, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_MANUFACTURING_LOCATION, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_MANUFACTURING_DATE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_ID_MODULE_SERIAL_NUMBER_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_SERIAL_NUMBER, &(VAL), sizeof(VAL) )
#define ATTR_SPD_CYCLICAL_REDUNDANCY_CODE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_CRC, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_PART_NUMBER_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_PART_NUMBER, &(VAL), sizeof(VAL) )
#define ATTR_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::DRAM_MANUFACTURER_ID, &(VAL), sizeof(VAL) )
#define ATTR_SPD_BAD_DQ_DATA_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::DIMM_BAD_DQ_DATA, &(VAL), sizeof(VAL) )
#define ATTR_SPD_BAD_DQ_DATA_SETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::setAttrActionsFunc(fapi::ID, PTARGET, sizeof(VAL), &(VAL)), \
    fapi::platAttrSvc::fapiPlatSetSpdAttr( PTARGET, SPD::DIMM_BAD_DQ_DATA, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_ADDR_MIRRORING_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_MIRRORING, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F0RC3_F0RC2_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F0RC3_F0RC2, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F0RC5_F0RC4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F0RC5_F0RC4, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F1RC11_F1RC8_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F1RC11_F1RC8, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F1RC13_F1RC12_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F1RC13_F1RC12, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F1RC15_F1RC14_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F1RC15_F1RC14, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F3RC9_F3RC8_FOR_800_1066_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F3RC9_F3RC8_800_1066, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F34RC11_F34RC10_FOR_800_1066_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F34RC11_F34RC10_800_1066, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F56RC11_F56RC10_FOR_800_1066_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F56RC11_F56RC10_800_1066, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F78RC11_F78RC10_FOR_800_1066_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F78RC11_F78RC10_800_1066, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F910RC11_F910RC10_FOR_800_1066_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F910RC11_F910RC10_800_1066, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_MR12_FOR_800_1066_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_MR12_800_1066, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F3RC9_F3RC8_FOR_1333_1600_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F3RC9_F3RC8_1333_1600, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F34RC11_F34RC10_FOR_1333_1600_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F34RC11_F34RC10_1333_1600, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F56RC11_F56RC10_FOR_1333_1600_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F56RC11_F56RC10_1333_1600, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F78RC11_F78RC10_FOR_1333_1600_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F78RC11_F78RC10_1333_1600, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F910RC11_F910RC10_FOR_1333_1600_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F910RC11_F910RC10_1333_1600, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_MR12_FOR_1333_1600_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_MR12_1333_1600, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F3RC9_F3RC8_FOR_1866_2133_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F3RC9_F3RC8_1866_2133, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F34RC11_F34RC10_FOR_1866_2133_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F34RC11_F34RC10_1866_2133, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F56RC11_F56RC10_FOR_1866_2133_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F56RC11_F56RC10_1866_2133, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F78RC11_F78RC10_FOR_1866_2133_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F78RC11_F78RC10_1866_2133, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_F910RC11_F910RC10_FOR_1866_2133_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_F910RC11_F910RC10_1866_2133, &(VAL), sizeof(VAL) )
#define ATTR_SPD_LR_MR12_FOR_1866_2133_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::LRMM_MR12_FOR_1866_2133, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_BANKS_DDR3_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::BANK_ADDRESS_BITS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR3_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::CAS_LATENCIES_SUPPORTED, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_REVISION_CODE_DDR3_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_REVISION_CODE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR3_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_NOMINAL_VOLTAGE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_BANKGROUPS_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::BANK_GROUP_BITS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_BANKS_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::BANK_ADDRESS_BITS_DDR4, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_NOMINAL_VOLTAGE_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_NOMINAL_VOLTAGE_DDR4, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TIMEBASE_MTB_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TIMEBASES_MTB, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TIMEBASE_FTB_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TIMEBASES_FTB, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TCKMAX_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TCK_MAX, &(VAL), sizeof(VAL) )
#define ATTR_SPD_CAS_LATENCIES_SUPPORTED_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::CAS_LATENCIES_SUPPORTED_DDR4, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRFC1MIN_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRFC1_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRFC2MIN_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRFC2_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRFC4MIN_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRFC4_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRRDSMIN_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRRDS_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRRDLMIN_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRRDL_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TCCDLMIN_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TCCDL_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TCCDLMIN_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TCCDL_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TRRDLMIN_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRRDL_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TRRDSMIN_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRRDS_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TCKMAX_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TCKMAX_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_CRC_BASE_CONFIG_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::BASE_CONFIG_CRC, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_REVISION_CODE_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_REVISION_CODE_DDR4, &(VAL), sizeof(VAL) )
#define ATTR_SPD_DRAM_STEPPING_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::DRAM_STEPPING, &(VAL), sizeof(VAL) )
#define ATTR_SPD_CRC_MNFG_SEC_DDR4_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MANUFACTURING_SECTION_CRC, &(VAL), sizeof(VAL) )

//------------------------------------------------------------------------------
// MACRO to route ATTR_CEN_DQ_TO_DIMM_CONN_DQ access to the correct Hostboot
// function
//------------------------------------------------------------------------------
#define ATTR_CEN_DQ_TO_DIMM_CONN_DQ_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetDqMapping(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_NAME access to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_NAME_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetTargetName(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_FUNCTIONAL access to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_FUNCTIONAL_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetFunctional(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_POS access to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_POS_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetTargetPos(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACROS to support  proc_setup_bars_memory_attributes.xml
//------------------------------------------------------------------------------
#define ATTR_PROC_FOREIGN_NEAR_BASE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcForeignNearBase (PTARGET, VAL )
#define ATTR_PROC_FOREIGN_NEAR_SIZE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcForeignNearSize (PTARGET, VAL )
#define ATTR_PROC_FOREIGN_FAR_BASE_GETMACRO( ID, PTARGET, VAL ) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcForeignFarBase (PTARGET, VAL )
#define ATTR_PROC_FOREIGN_FAR_SIZE_GETMACRO( ID, PTARGET, VAL ) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcForeignFarSize (PTARGET, VAL )
#define ATTR_PROC_HA_BASE_GETMACRO( ID, PTARGET, VAL )  \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcHaBase (PTARGET, VAL )
#define ATTR_PROC_HA_SIZE_GETMACRO( ID, PTARGET, VAL )  \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcHaSize (PTARGET, VAL )

//------------------------------------------------------------------------------
//  MACROS to support proc_setup_bars_mmio_attributes.xml
//------------------------------------------------------------------------------
#define ATTR_PROC_PSI_BRIDGE_BAR_ENABLE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcPsiBridgeBarEnable (PTARGET, VAL )
#define ATTR_PROC_FSP_BAR_ENABLE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcFspBarEnable (PTARGET, VAL )
#define ATTR_PROC_INTP_BAR_ENABLE_GETMACRO( ID, PTARGET, VAL )  \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcIntpBarEnable (PTARGET, VAL )
#define ATTR_PROC_NX_MMIO_BAR_ENABLE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcNxMmioBarEnable(PTARGET, VAL )
#define ATTR_PROC_NX_MMIO_BAR_SIZE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcNxMmioBarSize (PTARGET, VAL )
#define ATTR_PROC_PCIE_BAR_ENABLE_GETMACRO( ID, PTARGET, VAL )  \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcPcieBarEnable (PTARGET, VAL )
#define ATTR_PROC_PCIE_BAR_BASE_ADDR_GETMACRO( ID, PTARGET, VAL )   \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcPcieBarBaseAddr (PTARGET, VAL )
#define ATTR_PROC_PCIE_BAR_SIZE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetProcPcieBarSize (PTARGET, VAL )

//------------------------------------------------------------------------------
//  MACROS to support enable attributes in p8_xip_customize_attributes.xml
//------------------------------------------------------------------------------
#define ATTR_PROC_NX_ENABLE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetEnableAttr ( fapi::ID, PTARGET, VAL )
#define ATTR_PROC_PCIE_ENABLE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetEnableAttr ( fapi::ID, PTARGET, VAL )
#define ATTR_PROC_L3_ENABLE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetEnableAttr ( fapi::ID, PTARGET, VAL )
#define ATTR_PROC_A_ENABLE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetEnableAttr ( fapi::ID, PTARGET, VAL )
#define ATTR_PROC_X_ENABLE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetEnableAttr ( fapi::ID, PTARGET, VAL )


//------------------------------------------------------------------------------
//  MACROS to support MVPD attributes
//------------------------------------------------------------------------------
#define ATTR_EX_L2_SINGLE_MEMBER_ENABLE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS :\
    fapi::platAttrSvc::fapiPlatGetSingleMemberEnableAttr ( PTARGET, VAL )

//------------------------------------------------------------------------------
//  MACROS to support MBVPD Phase Rotator attributes
//------------------------------------------------------------------------------
#ifndef CONFIG_VPD_GETMACRO_USE_EFF_ATTR
#define ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CLK_P0, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CLK_P1, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CLK_P0, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CLK_P1, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A0, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A1, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A2, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A3, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A4_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A4, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A5_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A5, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A6_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A6, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A7_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A7, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A8_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A8, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A9_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A9, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A10_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A10, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A11_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A11, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A12_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A12, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A13_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A13, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A14_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A14, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A15_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A15, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_BA0, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_BA1, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_BA2, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_CASN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_CASN, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_RASN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_RASN, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_WEN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_WEN, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_PAR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_PAR, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_ACTN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_ACTN, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CKE0, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CKE1, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CKE2, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CKE3, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CSN0, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CSN1, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CSN2, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CSN3, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_ODT0, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_ODT1, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CKE0, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CKE1, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CKE2, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CKE3, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CSN0, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CSN1, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CSN2, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CSN3, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_ODT0, VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_ODT1, VAL)
#define ATTR_VPD_TSYS_ADR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_TSYS_ADR, VAL)
#define ATTR_VPD_TSYS_DP18_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_TSYS_DP18, VAL)
#else
#define ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A3, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A4_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A4, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A5_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A5, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A6_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A6, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A7_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A7, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A8_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A8, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A9_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A9, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A10_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A10, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A11_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A11, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A12_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A12, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A13_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A13, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A14_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A14, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A15_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A15, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_CASN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_CASN, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_RASN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_RASN, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_WEN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_WEN, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_PAR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_PAR, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_ACTN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_ACTN, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE3, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN3, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE3, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN3, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT1, sizeof(VAL), &VAL)
#define ATTR_VPD_TSYS_ADR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_TSYS_ADR, sizeof(VAL), &VAL)
#define ATTR_VPD_TSYS_DP18_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_TSYS_DP18, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P1_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P1_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A1_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A2_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A3_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A3, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A4_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A4, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A5_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A5, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A6_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A6, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A7_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A7, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A8_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A8, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A9_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A9, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A10_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A10, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A11_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A11, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A12_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A12, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A13_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A13, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A14_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A14, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_A15_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_A15, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA1_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA2_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_CASN_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_CASN, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_RASN_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_RASN, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_WEN_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_WEN, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_PAR_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_PAR, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M_ACTN_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_ACTN, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE1_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE2_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE3_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE3, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN1_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN2_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN3_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN3, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT1_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE1_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE2_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE3_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE3, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN1_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN1, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN2_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN2, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN3_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN3, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT0, sizeof(VAL), &VAL)
#define ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT1_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT1, sizeof(VAL), &VAL)

#endif // CONFIG_VPD_GETMACRO_USE_EFF_ATTR

//------------------------------------------------------------------------------
//  MACROS to support MBVPD Address Mirror attributes
//------------------------------------------------------------------------------
#ifndef CONFIG_VPD_GETMACRO_USE_EFF_ATTR
#define ATTR_VPD_DRAM_ADDRESS_MIRRORING_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetAddrMirrorData\
        (PTARGET, VAL)
#else
#define ATTR_VPD_DRAM_ADDRESS_MIRRORING_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_ADDRESS_MIRRORING, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_ADDRESS_MIRRORING_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_ADDRESS_MIRRORING, sizeof(VAL), &VAL)

#endif // CONFIG_VPD_GETMACRO_USE_EFF_ATTR

//------------------------------------------------------------------------------
//  MACROS to support MBVPD Termination Data attributes
//------------------------------------------------------------------------------
#ifndef CONFIG_VPD_GETMACRO_USE_EFF_ATTR
#define ATTR_VPD_DRAM_RON_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_DRAM_RON>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_DRAM_RON , VAL, sizeof(VAL)))
#define ATTR_VPD_DRAM_RTT_NOM_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_DRAM_RTT_NOM>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_DRAM_RTT_NOM , VAL, sizeof(VAL)))
#define ATTR_VPD_DRAM_RTT_WR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_DRAM_RTT_WR>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_DRAM_RTT_WR , VAL, sizeof(VAL)))
#define ATTR_VPD_ODT_RD_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_ODT_RD>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_ODT_RD , VAL, sizeof(VAL)))
#define ATTR_VPD_ODT_WR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_ODT_WR>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_ODT_WR , VAL, sizeof(VAL)))
#define ATTR_VPD_DIMM_RCD_IBT_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_DIMM_RCD_IBT>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_DIMM_RCD_IBT , VAL, sizeof(VAL)))
#define ATTR_VPD_DIMM_RCD_OUTPUT_TIMING_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_DIMM_RCD_OUTPUT_TIMING>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_DIMM_RCD_OUTPUT_TIMING , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_RD_VREF_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_RD_VREF>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_RD_VREF , VAL, sizeof(VAL)))
#define ATTR_VPD_DRAM_WR_VREF_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_DRAM_WR_VREF>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_DRAM_WR_VREF , VAL, sizeof(VAL)))
#define ATTR_VPD_DRAM_WRDDR4_VREF_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_DRAM_WRDDR4_VREF>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_DRAM_WRDDR4_VREF , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_RCV_IMP_DQ_DQS_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_RCV_IMP_DQ_DQS>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_RCV_IMP_DQ_DQS , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_DRV_IMP_DQ_DQS_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_DRV_IMP_DQ_DQS>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_DRV_IMP_DQ_DQS , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_DRV_IMP_CNTL_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_DRV_IMP_CNTL>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_DRV_IMP_CNTL , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_DRV_IMP_ADDR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_DRV_IMP_ADDR>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_DRV_IMP_ADDR , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_DRV_IMP_CLK_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_DRV_IMP_CLK>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_DRV_IMP_CLK , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_DRV_IMP_SPCKE_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_DRV_IMP_SPCKE>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_DRV_IMP_SPCKE , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_SLEW_RATE_DQ_DQS>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_SLEW_RATE_DQ_DQS , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_SLEW_RATE_CNTL_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_SLEW_RATE_CNTL>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_SLEW_RATE_CNTL , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_SLEW_RATE_ADDR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_SLEW_RATE_ADDR>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_SLEW_RATE_ADDR , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_SLEW_RATE_CLK_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_SLEW_RATE_CLK>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_SLEW_RATE_CLK , VAL, sizeof(VAL)))
#define ATTR_VPD_CEN_SLEW_RATE_SPCKE_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CEN_SLEW_RATE_SPCKE>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CEN_SLEW_RATE_SPCKE , VAL, sizeof(VAL)))
#define ATTR_VPD_RLO_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_RLO>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_RLO , VAL, sizeof(VAL)))
#define ATTR_VPD_WLO_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_WLO>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_WLO , VAL, sizeof(VAL)))
#define ATTR_VPD_GPO_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_GPO>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_GPO , VAL, sizeof(VAL)))
#define ATTR_VPD_CKE_PRI_MAP_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CKE_PRI_MAP>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CKE_PRI_MAP , VAL, sizeof(VAL)))
#define ATTR_VPD_CKE_PWR_MAP_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
    (checkTermDataType<fapi::TERM_DATA_CKE_PWR_MAP>(VAL), \
        fapi::platAttrSvc::fapiPlatGetTermData\
           (PTARGET, fapi::TERM_DATA_CKE_PWR_MAP , &VAL, sizeof(VAL)))
#else
#define ATTR_VPD_DRAM_RON_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_RON, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_RTT_NOM_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_RTT_NOM, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_RTT_WR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_RTT_WR, sizeof(VAL), &VAL)

#define ATTR_VPD_ODT_RD_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_ODT_RD, sizeof(VAL), &VAL)

#define ATTR_VPD_ODT_WR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_ODT_WR, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_RD_VREF_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_RD_VREF, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_WR_VREF_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_WR_VREF, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_WRDDR4_VREF_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_WRDDR4_VREF, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_RCV_IMP_DQ_DQS_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_RCV_IMP_DQ_DQS, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_DQ_DQS_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_DQ_DQS, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_CNTL_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_CNTL, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_ADDR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_ADDR, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_CLK_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_CLK, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_SPCKE_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_SPCKE, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_SLEW_RATE_CNTL_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_SLEW_RATE_CNTL, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_SLEW_RATE_ADDR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_SLEW_RATE_ADDR, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_SLEW_RATE_CLK_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_SLEW_RATE_CLK, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_SLEW_RATE_SPCKE_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_SLEW_RATE_SPCKE, sizeof(VAL), &VAL)

#define ATTR_VPD_RLO_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_RLO, sizeof(VAL), &VAL)

#define ATTR_VPD_WLO_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_WLO, sizeof(VAL), &VAL)

#define ATTR_VPD_GPO_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_GPO, sizeof(VAL), &VAL)

#define ATTR_VPD_CKE_PRI_MAP_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CKE_PRI_MAP, sizeof(VAL), &VAL)

#define ATTR_VPD_CKE_PWR_MAP_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CKE_PWR_MAP, sizeof(VAL), &VAL)

#define ATTR_VPD_ODT_WR_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_ODT_WR, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_RON_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_RON, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_RTT_NOM_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_RTT_NOM, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_RTT_WR_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_RTT_WR, sizeof(VAL), &VAL)

#define ATTR_VPD_CKE_PRI_MAP_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CKE_PRI_MAP, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_CNTL_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_CNTL, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA0, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_CNTL_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_CNTL, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_ADDR_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_ADDR, sizeof(VAL), &VAL)

#define ATTR_VPD_CKE_PWR_MAP_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CKE_PWR_MAP, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_CLK_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_CLK, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_SPCKE_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_SPCKE, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_RD_VREF_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_RD_VREF, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_SLEW_RATE_CNTL_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_SLEW_RATE_CNTL, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_SLEW_RATE_ADDR_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_SLEW_RATE_ADDR, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_SLEW_RATE_CLK_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_SLEW_RATE_CLK, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_SLEW_RATE_SPCKE_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_SLEW_RATE_SPCKE, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_WR_VREF_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_WR_VREF, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_WRDDR4_VREF_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_WRDDR4_VREF, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_RCV_IMP_DQ_DQS_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_RCV_IMP_DQ_DQS, sizeof(VAL), &VAL)

#define ATTR_VPD_ODT_RD_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_ODT_RD, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_DRV_IMP_DQ_DQS_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_DRV_IMP_DQ_DQS, sizeof(VAL), &VAL)

#define ATTR_VPD_CEN_SLEW_RATE_DQ_DQS_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_CEN_SLEW_RATE_DQ_DQS, sizeof(VAL), &VAL)

#define ATTR_VPD_RLO_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_RLO, sizeof(VAL), &VAL)

#define ATTR_VPD_WLO_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_WLO, sizeof(VAL), &VAL)

#define ATTR_VPD_GPO_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_GPO, sizeof(VAL), &VAL)

#endif // CONFIG_VPD_GETMACRO_USE_EFF_ATTR

//------------------------------------------------------------------------------
//  MACROS to support MBVPD Slope Intercept attributes
//------------------------------------------------------------------------------
#define ATTR_CDIMM_VPD_MASTER_POWER_SLOPE_GETMACRO(ID, PTARGET, VAL)  \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? \
    fapi::FAPI_RC_SUCCESS :                                           \
    fapi::platAttrSvc::fapiPlatGetSlopeInterceptData                  \
        (PTARGET, fapi::MASTER_POWER_SLOPE , VAL)
#define ATTR_CDIMM_VPD_MASTER_POWER_INTERCEPT_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? \
    fapi::FAPI_RC_SUCCESS :                                           \
    fapi::platAttrSvc::fapiPlatGetSlopeInterceptData                  \
        (PTARGET, fapi::MASTER_POWER_INTERCEPT , VAL)
#define ATTR_CDIMM_VPD_SUPPLIER_POWER_SLOPE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? \
    fapi::FAPI_RC_SUCCESS :                                           \
    fapi::platAttrSvc::fapiPlatGetSlopeInterceptData                  \
        (PTARGET, fapi::SUPPLIER_POWER_SLOPE , VAL)
#define ATTR_CDIMM_VPD_SUPPLIER_POWER_INTERCEPT_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? \
    fapi::FAPI_RC_SUCCESS :                                           \
    fapi::platAttrSvc::fapiPlatGetSlopeInterceptData                  \
        (PTARGET, fapi::SUPPLIER_POWER_INTERCEPT , VAL)

//------------------------------------------------------------------------------
//  MACRO to support BAD_DQ_BITMAP Attribute
//------------------------------------------------------------------------------
#define ATTR_BAD_DQ_BITMAP_GETMACRO(ID, PTARGET, VAL)                 \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? \
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatDimmGetBadDqBitmap \
        (PTARGET, VAL)
#define ATTR_BAD_DQ_BITMAP_SETMACRO(ID, PTARGET, VAL)                 \
    fapi::AttrOverrideSync::setAttrActionsFunc(fapi::ID, PTARGET,     \
                                               sizeof(VAL), &VAL),    \
    fapi::platAttrSvc::fapiPlatDimmSetBadDqBitmap(PTARGET, VAL)

//------------------------------------------------------------------------------
//  MACRO to support VPD_DIMM_SPARE Attribute
//------------------------------------------------------------------------------
#ifndef CONFIG_VPD_GETMACRO_USE_EFF_ATTR
#define ATTR_VPD_DIMM_SPARE_GETMACRO(ID, PTARGET, VAL)                \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? \
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatDimmGetSpareDram \
        (PTARGET, VAL)
#else
#define ATTR_VPD_DIMM_SPARE_GETMACRO(ID, PTARGET, VAL)                \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? \
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DIMM_SPARE, sizeof(VAL), &VAL)

#define ATTR_VPD_DIMM_SPARE_SETMACRO(ID, PTARGET, VAL)                \
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DIMM_SPARE, sizeof(VAL), &VAL)
#endif // CONFIG_VPD_GETMACRO_USE_EFF_ATTR

//------------------------------------------------------------------------------
// MACROs to route ATTR PLL Ring accesses to the correct HWSV function
//------------------------------------------------------------------------------
// DATA accesses
#define PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        ( fapi::platAttrSvc::fapiPlatGetPllAttr( \
          fapi::ID, PTARGET, VAL ))

#define ATTR_PROC_AB_BNDY_PLL_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PB_BNDY_DMIPLL_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PCI_BNDY_PLL_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PERV_BNDY_PLL_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_FOR_RUNTIME_DATA_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)

// FLUSH accesses
#define ATTR_PROC_AB_BNDY_PLL_FLUSH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PB_BNDY_DMIPLL_FLUSH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PCI_BNDY_PLL_FLUSH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PERV_BNDY_PLL_FLUSH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_FLUSH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)

// LENGTH accesses
#define ATTR_PROC_AB_BNDY_PLL_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PB_BNDY_DMIPLL_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PCI_BNDY_PLL_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PERV_BNDY_PLL_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_FOR_DCCAL_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1066_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1333_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1600_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4000_MEM1866_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1066_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1333_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1600_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_NEST4800_MEM1866_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_MEMB_TP_BNDY_PLL_FOR_RUNTIME_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_PB_BNDY_DMIPLL_FOR_DCCAL_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)
#define ATTR_PROC_AB_BNDY_PLL_FOR_DCCAL_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    PLL_ATTR_GENERIC_GETMACRO(ID,PTARGET,VAL)

// INFO accesses
#define ATTR_PROC_DMI_CUPLL_PFD360_OFFSET_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetPllInfoAttr(PTARGET, fapi::getPllRingInfo::PROC_DMI_CUPLL_PFD360_OFFSET, &VAL, sizeof(VAL))
#define ATTR_PROC_DMI_CUPLL_REFCLKSEL_OFFSET_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetPllInfoAttr(PTARGET, fapi::getPllRingInfo::PROC_DMI_CUPLL_REFCLKSEL_OFFSET, &VAL, sizeof(VAL))
#define ATTR_PROC_ABUS_CUPLL_PFD360_OFFSET_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetPllInfoAttr(PTARGET, fapi::getPllRingInfo::PROC_ABUS_CUPLL_PFD360_OFFSET, &VAL, sizeof(VAL))
#define ATTR_PROC_ABUS_CUPLL_REFCLKSEL_OFFSET_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetPllInfoAttr(PTARGET, fapi::getPllRingInfo::PROC_ABUS_CUPLL_REFCLKSEL_OFFSET, &VAL, sizeof(VAL))
#define ATTR_MEMB_DMI_CUPLL_PFD360_OFFSET_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetPllInfoAttr(PTARGET, fapi::getPllRingInfo::MEMB_DMI_CUPLL_PFD360_OFFSET, &VAL, sizeof(VAL))
#define ATTR_MEMB_DMI_CUPLL_REFCLKSEL_OFFSET_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetPllInfoAttr(PTARGET, fapi::getPllRingInfo::MEMB_DMI_CUPLL_REFCLKSEL_OFFSET, &VAL, sizeof(VAL))
#define ATTR_MEMB_MEM_PLL_CFG_UPDATE_OFFSET_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetPllInfoAttr(PTARGET,\
        fapi::getPllRingInfo::MEMB_MEM_PLL_CFG_UPDATE_OFFSET, &VAL, sizeof(VAL))

//------------------------------------------------------------------------------
//  MACROs to support DIMM SPD Attributes that are handled by an Accessor HWP
//------------------------------------------------------------------------------
#define ATTR_SPD_SDRAM_BANKS_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttrAccessor(PTARGET, fapi::getSpdAttr::SPD_SDRAM_BANKS, &VAL, sizeof(VAL))
#define ATTR_SPD_MODULE_NOMINAL_VOLTAGE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttrAccessor(PTARGET, fapi::getSpdAttr::SPD_MODULE_NOMINAL_VOLTAGE, &VAL, sizeof(VAL))
#define ATTR_SPD_CAS_LATENCIES_SUPPORTED_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttrAccessor(PTARGET, fapi::getSpdAttr::SPD_CAS_LATENCIES_SUPPORTED, &VAL, sizeof(VAL))
#define ATTR_SPD_MODULE_REVISION_CODE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttrAccessor(PTARGET, fapi::getSpdAttr::SPD_MODULE_REVISION_CODE, &VAL, sizeof(VAL))

//------------------------------------------------------------------------------
//  MACROs to support PM Attributes that always get 0 (sole purpose is override)
//------------------------------------------------------------------------------
#define ATTR_FREQ_EXT_BIAS_UP_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetZeroAttrData(&VAL, sizeof(VAL))
#define ATTR_FREQ_EXT_BIAS_DOWN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetZeroAttrData(&VAL, sizeof(VAL))
#define ATTR_VOLTAGE_EXT_VDD_BIAS_UP_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetZeroAttrData(&VAL, sizeof(VAL))
#define ATTR_VOLTAGE_EXT_VDD_BIAS_DOWN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetZeroAttrData(&VAL, sizeof(VAL))
#define ATTR_VOLTAGE_EXT_VCS_BIAS_UP_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetZeroAttrData(&VAL, sizeof(VAL))
#define ATTR_VOLTAGE_EXT_VCS_BIAS_DOWN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetZeroAttrData(&VAL, sizeof(VAL))
#define ATTR_VOLTAGE_INT_VDD_BIAS_UP_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetZeroAttrData(&VAL, sizeof(VAL))
#define ATTR_VOLTAGE_INT_VDD_BIAS_DOWN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetZeroAttrData(&VAL, sizeof(VAL))
#define ATTR_VOLTAGE_INT_VCS_BIAS_UP_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetZeroAttrData(&VAL, sizeof(VAL))
#define ATTR_VOLTAGE_INT_VCS_BIAS_DOWN_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetZeroAttrData(&VAL, sizeof(VAL))

//------------------------------------------------------------------------------
//  MACROS to support MBVPD Get vpd version attribute
//------------------------------------------------------------------------------
#define ATTR_VPD_VERSION_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetVpdVersion\
        (PTARGET, VAL)

#ifdef CONFIG_VPD_GETMACRO_USE_EFF_ATTR
#define ATTR_VPD_VERSION_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_MSS_EFF_VPD_VERSION, sizeof(VAL), &VAL)
#endif

//------------------------------------------------------------------------------
//  MACROS to support MBVPD Get Dram 2N Mode Enabled
//------------------------------------------------------------------------------
#ifndef CONFIG_VPD_GETMACRO_USE_EFF_ATTR
#define ATTR_VPD_DRAM_2N_MODE_ENABLED_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetDram2NModeEnabled\
        (PTARGET, VAL)
#else
#define ATTR_VPD_DRAM_2N_MODE_ENABLED_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS :\
        fapi::platAttrSvc::getTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_2N_MODE_ENABLED, sizeof(VAL), &VAL)

#define ATTR_VPD_DRAM_2N_MODE_ENABLED_SETMACRO(ID, PTARGET, VAL)\
        fapi::platAttrSvc::setTargetingAttr\
           (PTARGET, TARGETING::ATTR_EFF_DRAM_2N_MODE_ENABLED, sizeof(VAL), &VAL)

#endif // CONFIG_VPD_GETMACRO_USE_EFF_ATTR

//------------------------------------------------------------------------------
//  MACROS to support MBVPD Get Sensor Map Data
//------------------------------------------------------------------------------
#define ATTR_VPD_CDIMM_SENSOR_MAP_PRIMARY_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetSensorMap\
        (PTARGET, fapi::SENSOR_MAP_PRIMARY, VAL)
#define ATTR_VPD_CDIMM_SENSOR_MAP_SECONDARY_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetSensorMap\
        (PTARGET, fapi::SENSOR_MAP_SECONDARY, VAL)

//------------------------------------------------------------------------------
//  MACROS to support MBVPD Get and Set L4 Bank Delete VPD
//------------------------------------------------------------------------------
#define ATTR_L4_BANK_DELETE_VPD_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatL4BankDelete\
        (PTARGET, VAL, fapi::GET_L4_BANK_DELETE_MODE)

#define ATTR_L4_BANK_DELETE_VPD_SETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::setAttrActionsFunc(fapi::ID, PTARGET,\
                                               sizeof(VAL), &VAL),\
    fapi::platAttrSvc::fapiPlatL4BankDelete\
        (PTARGET, VAL, fapi::SET_L4_BANK_DELETE_MODE)

//------------------------------------------------------------------------------
//  MACROS to support L3 DELTA DATA Ring Attributes
//------------------------------------------------------------------------------
#define ATTR_PROC_EX_FUNC_L3_DELTA_DATA_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetL3DDAttr(PTARGET, VAL)
#define ATTR_PROC_EX_FUNC_L3_LENGTH_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetL3Length(PTARGET, VAL)

//------------------------------------------------------------------------------
//  MACRO to support pci osc switch config
//------------------------------------------------------------------------------
#define ATTR_PCI_OSCSWITCH_CONFIG_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetPciOscswitchConfig(PTARGET, VAL)

//------------------------------------------------------------------------------
//  MACRO to support Modspec raw card info
//------------------------------------------------------------------------------
#define ATTR_SPD_MODSPEC_COM_REF_RAW_CARD_REV_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr \
        (PTARGET, SPD::MODSPEC_COM_REF_RAW_CARD_REV, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODSPEC_COM_REF_RAW_CARD_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdModspecComRefRawCard(PTARGET, VAL)

//------------------------------------------------------------------------------
//  MACROS to support osc switch control
//------------------------------------------------------------------------------
#define ATTR_OSCSWITCH_CTL0_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetOscswitchCtl \
        (PTARGET,fapi::getOscswitchCtl::CTL0,&VAL,sizeof(VAL))
#define ATTR_OSCSWITCH_CTL1_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetOscswitchCtl \
        (PTARGET,fapi::getOscswitchCtl::CTL1,&VAL,sizeof(VAL))
#define ATTR_OSCSWITCH_CTL2_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
        fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetOscswitchCtl \
        (PTARGET,fapi::getOscswitchCtl::CTL2,&VAL,sizeof(VAL))

#endif // FAPIPLATATTRIBUTESERVICE_H_
