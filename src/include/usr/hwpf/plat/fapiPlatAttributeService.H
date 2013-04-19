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
 *  @brief Returns the system target
 *
 *  @par Detailed Description:
 *      Returns the system target.  If the target service has not been
 *      initialized -or- there is any failure to acquire it, the function
 *      will assert
 *
 *  @return Target handle to the system target
 *
 *  @retval !NULL An actual target handle
 *  @retval NULL Not possible
 */
TARGETING::Target* getSystemTarget();

/**
 *  @brief Returns a fapiReturn code containing information on an attribute
 *      access error
 *
 *  @param[in] i_targAttrId Platform attribute ID
 *  @param[in] i_fapiAttrId FAPI attribute ID which maps to the platform
 *      attribute ID
 *  @param[in] i_pFapiTarget Pointer to the FAPI target holding the
 *      requested attribute
 *
 *  @return fapiReturn code containing a platform generated error log
 *
 *  @retval FAPI_RC_PLAT_ERR_SEE_DATA (return code value) which informs
 *      caller there is a host boot error log attached
 */
fapi::ReturnCode createAttrAccessError(
    const TARGETING::ATTRIBUTE_ID i_targAttrId,
    const fapi::AttributeId       i_fapiAttrId,
    const fapi::Target*           i_pFapiTarget);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when accessing
 * SPD ATTR. It should not be called directly
 *
 * @param[in]  i_target Target pointer to operate on
 * @param[in]  i_keyword SPD keyword
 * @param[out] o_data   Address of Storage for saving the attribute value
 * @param[in]  i_len    Size of storage
 * @return ReturnCode.  Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetSpdAttr(const fapi::Target * i_target,
                                    const uint16_t i_keyword,
                                    void * o_data,
                                    size_t i_len );

/**
 * @brief This function is called by the FAPI_ATTR_SET macro when accessing
 * SPD ATTR. It should not be called directly
 *
 * @param[in] i_target  Target pointer to operate on
 * @param[in] i_keyword SPD keyword
 * @param[in] i_data    Pointer to data
 * @param[in] i_len     Size of data
 * @return ReturnCode.  Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatSetSpdAttr(const fapi::Target * i_target,
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
 * @param[in]  i_pDimmTarget DIMM target pointer
 * @param[out] o_data        Output data
 * @return ReturnCode.  Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetDqMapping(const fapi::Target * i_pDimmTarget,
                                      uint8_t (&o_data)[DIMM_DQ_NUM_DQS]);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_NAME. It should not be called directly
 *
 * @param[in]  i_pTarget Target pointer
 * @param[out] o_name    Output Name (from enum ATTR_NAME_Enum)
 * @return ReturnCode.   Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetTargetName(const fapi::Target * i_pTarget,
                                       uint8_t & o_name);

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * ATTR_FUNCTIONAL. It should not be called directly
 *
 * @param[in]  i_pTarget    Target pointer
 * @param[out] o_functional 1 = functional, else 0
 * @return ReturnCode.   Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatGetFunctional(const fapi::Target * i_pTarget,
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

} // namespace platAttrSvc

} // namespace fapi

/**
 *  @brief Macro which directly maps a FAPI request to get a platform
 *      attribute to the equivalent host boot request
 */
#define FAPI_PLAT_ATTR_SVC_GETMACRO_DIRECT(ID, PTARGET, VAL) \
    ( ((PTARGET > 0) ? \
        static_cast<TARGETING::Target*>( \
            static_cast<const fapi::Target*>(PTARGET)->get()) \
    : fapi::platAttrSvc::getSystemTarget())->tryGetAttr< \
        FAPI_PLAT_ATTR_SVC_MACRO_DIRECT_FAPI_##ID>(VAL)) \
            ? fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::createAttrAccessError( \
                FAPI_PLAT_ATTR_SVC_MACRO_DIRECT_FAPI_##ID,fapi::ID,PTARGET)
/**
 *  @brief Macro which directly maps a FAPI request to set a platform
 *      attribute to the equivalent host boot request
 */
#define FAPI_PLAT_ATTR_SVC_SETMACRO_DIRECT(ID, PTARGET, VAL) \
    ( ((PTARGET > 0) ? \
        static_cast<TARGETING::Target*>( \
            static_cast<const fapi::Target*>(PTARGET)->get()) \
    : fapi::platAttrSvc::getSystemTarget())->trySetAttr< \
         FAPI_PLAT_ATTR_SVC_MACRO_DIRECT_FAPI_##ID>(VAL)) \
            ? fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::createAttrAccessError( \
                FAPI_PLAT_ATTR_SVC_MACRO_DIRECT_FAPI_##ID,fapi::ID,PTARGET)


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

#endif // FAPIPLATATTRIBUTESERVICE_H_
