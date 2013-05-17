/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatAttributeService.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
 *  @file fapiPlatAttributeService.H
 *
 *  @brief Defines the PLAT attribute access macros and the functions that
 *         access attributes
 *
 *  Note that platform code must provide the code.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/27/2011  Created.
 *                          bofferdn    09/13/2011  Support fapi->hb mapping
 *                          thi         01/28/2013  Add SPD CUSTOM attr
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
#include <vpd/spdenums.H>
#include <dimmConsts.H>
#include <util/singleton.H>
#include <procMemConsts.H>

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
 * ATTR_MSS_MEMORY_BASE. It should not be called directly
 *
 * @param[in]  i_pMcsTarget MCS target pointer
 * @param[out] o_addr       Address of MCS BAR register
 * @return ReturnCode.  Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetMemoryBaseAddr(const fapi::Target * i_pMcsTarget,
                                           uint64_t & o_addr);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_MSS_MIRROR_BASE. It should not be called directly
 *
 * @param[in]  i_pMcsTarget MCS target pointer
 * @param[out] o_addr       Address of MCS BAR register
 * @return ReturnCode.  Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetMirrorBaseAddr(const fapi::Target * i_pMcsTarget,
                                           uint64_t & o_addr);

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
 *  @param[in]  i_pTarget Target pointer
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
 *  @param[in]  i_pTarget   Target pointer
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
 *  @param[in]  i_pTarget   Target DIMM pointer
 *  @param[out] o_val       Address Mirroring Data for DIMM
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetAddrMirrorData (
                                    const fapi::Target * i_pTarget,
                                    uint8_t    &o_val);


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
// MACROs to route each ATTR_SPD access to the Hostboot SPD function
//------------------------------------------------------------------------------
#define ATTR_SPD_DRAM_DEVICE_TYPE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::BASIC_MEMORY_TYPE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_TYPE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_TYPE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_BANKS_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::BANK_ADDRESS_BITS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_DENSITY_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::DENSITY, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_ROWS_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::ROW_ADDRESS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_COLUMNS_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::COL_ADDRESS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_NOMINAL_VOLTAGE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_NOMINAL_VOLTAGE, &(VAL), sizeof(VAL) )
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
#define ATTR_SPD_CAS_LATENCIES_SUPPORTED_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::CAS_LATENCIES_SUPPORTED, &(VAL), sizeof(VAL) )
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
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SPD_SDRAM_OPTIONAL_FEATURES, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS_GETMACRO(ID, PTARGET, VAL ) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SPD_SDRAM_THERMAL_REFRESH_OPTIONS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_THERMAL_SENSOR_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SPD_MODULE_THERMAL_SENSOR, &(VAL), sizeof(VAL) )
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
#define ATTR_SPD_MODULE_REVISION_CODE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_REVISION_CODE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::DRAM_MANUFACTURER_ID, &(VAL), sizeof(VAL) )
#define ATTR_SPD_BAD_DQ_DATA_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::DIMM_BAD_DQ_DATA, &(VAL), sizeof(VAL) )
#define ATTR_SPD_BAD_DQ_DATA_SETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::setAttrActionsFunc(fapi::ID, PTARGET, sizeof(VAL), &(VAL)), \
    fapi::platAttrSvc::fapiPlatSetSpdAttr( PTARGET, SPD::DIMM_BAD_DQ_DATA, &(VAL), sizeof(VAL) )

//------------------------------------------------------------------------------
// MACROs to route ATTR Base Address accesses to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_MSS_MEMORY_BASE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetMemoryBaseAddr(PTARGET, VAL)
#define ATTR_MSS_MIRROR_BASE_GETMACRO(ID, PTARGET, VAL) \
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ? fapi::FAPI_RC_SUCCESS : \
    fapi::platAttrSvc::fapiPlatGetMirrorBaseAddr(PTARGET, VAL)

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
    fapi::platAttrSvc::fapiPlatGetSingleMemberEnableAttr ( PTARGET, VAL )

// TODO: RTC 69935 complete Phase Rotator Data.
// Use this code to fully implements 59048.
// Remove Phase Rotator attributes from attribute_types.xml
// and target_types.xml then enable the following.
// The "sets" are only needed to temporarily allow mss_eff_config_termination.C
// to do FAPI_ATTR_SET, but need to be removed when fully complete.
#define RTC69935 0
#if RTC69935
//------------------------------------------------------------------------------
//  MACROS to support MBVPD Phase Rotator attributes
//------------------------------------------------------------------------------
#define ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CLK_P0, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CLK_P1, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CLK_P0, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CLK_P1, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A0, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A1, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A2, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A3, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A4_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A4, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A5_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A5, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A6_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A6, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A7_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A7, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A8_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A8, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A9_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A9, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A10_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A10, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A11_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A11, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A12_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A12, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A13_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A13, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A14_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A14, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A15_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_A15, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_BA0, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_BA1, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_BA2, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_CASN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_CASN, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_RASN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_RASN, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_WEN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_CMD_WEN, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_PAR_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_PAR, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M_ACTN_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M_ACTN, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CKE0, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CKE1, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CKE2, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CKE3, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CSN0, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CSN1, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CSN2, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_CSN3, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_ODT0, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M0_CNTL_ODT1, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CKE0, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CKE1, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CKE2, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CKE3, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CSN0, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CSN1, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN2_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CSN2, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN3_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_CSN3, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT0_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_ODT0, VAL)
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT1_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetPhaseRotatorData\
        (PTARGET, PHASE_ROT_M1_CNTL_ODT1, VAL)
// TODO: RTC 69935: remove the no op sets once work around in
//       mss_eff_config_termination.C is removed
#define ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P0_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CLK_P1_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P0_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CLK_P1_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A0_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A1_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A2_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A3_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A4_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A5_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A6_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A7_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A8_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A9_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A10_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A11_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A12_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A13_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A14_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_A15_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA0_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA1_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_BA2_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_CASN_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_RASN_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_CMD_WEN_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_PAR_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M_ACTN_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE0_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE1_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE2_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CKE3_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN0_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN1_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN2_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_CSN3_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT0_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M0_CNTL_ODT1_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE0_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE1_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE2_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CKE3_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN0_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN1_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN2_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_CSN3_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT0_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#define ATTR_EFF_CEN_PHASE_ROT_M1_CNTL_ODT1_SETMACRO(ID, PTARGET, VAL)\
    fapi::FAPI_RC_SUCCESS
#endif
//------------------------------------------------------------------------------
//  MACROS to support MBVPD Address Mirror attributes
//------------------------------------------------------------------------------
#define ATTR_VPD_DRAM_ADDRESS_MIRRORING_GETMACRO(ID, PTARGET, VAL)\
    fapi::AttrOverrideSync::getAttrOverrideFunc(fapi::ID, PTARGET, &VAL) ?\
    fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::fapiPlatGetAddrMirrorData\
        (PTARGET, VAL)

#endif // FAPIPLATATTRIBUTESERVICE_H_
