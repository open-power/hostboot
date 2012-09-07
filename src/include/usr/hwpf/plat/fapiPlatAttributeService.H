/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatAttributeService.H $        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
 *  @brief Defines the PLAT attribute access macros and defines which macro
 *         handles each attribute.
 *
 *  Note that platform code must provide the code.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/27/2011  Created.
 *                          bofferdn    09/13/2011  Support fapi->hb mapping
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
#include <hwpf/fapi/fapiAttributeOverride.H>
#include <spd/spdenums.H>
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
 * @brief This wrapper function is called by the getAttrOverride function
 *        templates (which are called by FAPI_PLAT_GET_ATTR_OVERRIDE) to get an
 *        attribute override value
 *
 * This wrapper just invokes getAttrOverride on the AttributeOverrides singleton
 * in the local (plat) module, it is needed because Singletons cannot be
 * accessed outside of a module (this results in a duplicate singleton)
 *
 * @param[in]  i_attrId      Attribute ID
 * @param[in]  i_pTarget     Pointer to Target (NULL if system)
 * @param[out] o_overrideVal Reference to value filled in with the override
 * @param[in]  i_arrayD1     Array dimension 1 if applicable
 * @param[in]  i_arrayD2     Array dimension 2 if applicable
 * @param[in]  i_arrayD3     Array dimension 3 if applicable
 * @param[in]  i_arrayD4     Array dimension 4 if applicable
 * @return bool True if override value was returned
 */
bool getOverrideWrap(const fapi::AttributeId i_attrId,
                     const fapi::Target * const i_pTarget,
                     uint64_t & o_overrideVal,
                     const uint8_t i_arrayD1 = ATTR_ARRAYD_NA,
                     const uint8_t i_arrayD2 = ATTR_ARRAYD_NA,
                     const uint8_t i_arrayD3 = ATTR_ARRAYD_NA,
                     const uint8_t i_arrayD4 = ATTR_ARRAYD_NA);

/**
 * @brief This wrapper function is called by
 *        FAPI_PLAT_CLEAR_NON_CONST_ATTR_OVERRIDE to clear a non-const attribute
 *        override.
 *
 * This wrapper just invokes clearNonConstOverride on the AttributeOverrides
 * singleton in the local (plat) module, it is needed because Singletons cannot
 * be accessed outside of a module (this results in a duplicate singleton)
 *
 * @param[in] i_attrId  Attribute ID
 * @param[in] i_pTarget Pointer to Target (NULL if system)
 */
void clearNonConstOverrideWrap(const fapi::AttributeId i_attrId,
                               const fapi::Target * const i_pTarget);

/**
 * @brief This wrapper function is called by HWP unit test to set an attribute
 *        override. It is not called by production code (outside of unit test,
 *        attribute overrides are set by the FSP or by a debug tool)
 *
 * This wrapper just invokes setOverride on the AttributeOverrides singleton in
 * the local (plat) module, it is needed because Singletons cannot be accessed
 * outside of a module (this results in a duplicate singleton)
 *
 * @param[in] i_override Reference to override
 */
void setOverrideWrap(const AttributeOverride & i_override);

/**
 * @brief This wrapper function is called by HWP unit test to clear all
 *        attribute overrides. It is not called by production code (outside of
 *        unit test, attribute overrides are cleared by the FSP or by a debug
 *        tool)
 *
 * This wrapper just invokes clearOverrides on the AttributeOverrides singleton
 * in the local (plat) module, it is needed because Singletons cannot be
 * accessed outside of a module (this results in a duplicate singleton)
 */
void clearOverridesWrap();

/**
 * @brief This wrapper function is called by HWP unit test to test if any
 *        attribute overrides exist. It is not called by production code.
 *
 * This wrapper just invokes overridesExist on the AttributeOverrides singleton
 * in the local (plat) module, it is needed because Singletons cannot be
 * accessed outside of a module (this results in a duplicate singleton)
 */
bool overridesExistWrap();

/**
 * @brief This function template is called by the FAPI_PLAT_GET_ATTR_OVERRIDE
 *        macro to get any override for a 1D array attribute
 *
 * @param[in]  i_attrId  Attribute ID
 * @param[in]  i_pTarget Pointer to Target (NULL if system)
 * @param[out] o_1dArray Reference to 1D array where override will be copied to
 * @return bool True if override was returned
 */
template <typename T, uint8_t SZ1>
bool getOverrideT(const fapi::AttributeId i_attrId,
                  const fapi::Target * const i_pTarget,
                  T(&o_1dArray)[SZ1])
{
    uint64_t l_overrideVal = 0;

    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        if (!(getOverrideWrap(i_attrId, i_pTarget, l_overrideVal, d1)))
        {
            // For array attributes, all elements must be overridden
            return false;
        }
        else
        {
            // Standard conversion converts uint64_t to attribute type
            o_1dArray[d1] = l_overrideVal;
        }
    }

    return true;
}

/**
 * @brief This function template is called by the FAPI_PLAT_GET_ATTR_OVERRIDE
 *        macro to get any override for a 2D array attribute
 *
 * @param[in]  i_attrId  Attribute ID
 * @param[in]  i_pTarget Pointer to Target (NULL if system)
 * @param[out] o_2dArray Reference to 2D array where override will be copied to
 * @return bool True if override was returned
 */
template <typename T, uint8_t SZ1, uint8_t SZ2>
bool getOverrideT(const fapi::AttributeId i_attrId,
                  const fapi::Target * const i_pTarget,
                  T(&o_2dArray)[SZ1][SZ2])
{
    uint64_t l_overrideVal = 0;

    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        for (uint8_t d2 = 0; d2 < SZ2; d2++)
        {
            if (!(getOverrideWrap(i_attrId, i_pTarget, l_overrideVal, d1, d2)))
            {
                // For array attributes, all elements must be overridden
                return false;
            }
            else
            {
                // Standard conversion converts uint64_t to attribute type
                o_2dArray[d1][d2] = l_overrideVal;
            }
        }
    }

    return true;
}

/**
 * @brief This function template is called by the FAPI_PLAT_GET_ATTR_OVERRIDE
 *        macro to get any override for a 3D array attribute
 *
 * @param[in]  i_attrId  Attribute ID
 * @param[in]  i_pTarget Pointer to Target (NULL if system)
 * @param[out] o_3dArray Reference to 3D array where override will be copied to
 * @return bool True if override was returned
 */
template <typename T, uint8_t SZ1, uint8_t SZ2, uint8_t SZ3>
bool getOverrideT(const fapi::AttributeId i_attrId,
                  const fapi::Target * const i_pTarget,
                  T(&o_3dArray)[SZ1][SZ2][SZ3])
{
    uint64_t l_overrideVal = 0;

    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        for (uint8_t d2 = 0; d2 < SZ2; d2++)
        {
            for (uint8_t d3 = 0; d3 < SZ3; d3++)
            {
                if (!(getOverrideWrap(i_attrId, i_pTarget, l_overrideVal, d1,
                                      d2, d3)))
                {
                    // For array attributes, all elements must be overridden
                    return false;
                }
                else
                {
                    // Standard conversion converts uint64_t to attribute type
                    o_3dArray[d1][d2][d3] = l_overrideVal;
                }
            }
        }
    }

    return true;
}

/**
 * @brief This function template is called by the FAPI_PLAT_GET_ATTR_OVERRIDE
 *        macro to get any override for a 4D array attribute
 *
 * @param[in]  i_attrId  Attribute ID
 * @param[in]  i_pTarget Pointer to Target (NULL if system)
 * @param[out] o_4dArray Reference to 4D array where override will be copied to
 * @return bool True if override was returned
 */
template <typename T, uint8_t SZ1, uint8_t SZ2, uint8_t SZ3, uint8_t SZ4>
bool getOverrideT(const fapi::AttributeId i_attrId,
                  const fapi::Target * const i_pTarget,
                  T(&o_4dArray)[SZ1][SZ2][SZ3][SZ4])
{
    uint64_t l_overrideVal = 0;

    for (uint8_t d1 = 0; d1 < SZ1; d1++)
    {
        for (uint8_t d2 = 0; d2 < SZ2; d2++)
        {
            for (uint8_t d3 = 0; d3 < SZ3; d3++)
            {
                for (uint8_t d4 = 0; d4 < SZ4; d4++)
                {
                    if (!(getOverrideWrap(i_attrId, i_pTarget, l_overrideVal,
                                          d1, d2, d3, d4)))
                    {
                        // For array attributes, all elements must be overridden
                        return false;
                    }
                    else
                    {
                        // Standard conversion converts uint64_t to attribute
                        // type
                        o_4dArray[d1][d2][d3][d4] = l_overrideVal;
                    }
                }
            }
        }
    }

    return true;
}

/**
 * @brief This function template is called by the FAPI_PLAT_GET_ATTR_OVERRIDE
 *        macro to get any override for a non-array attribute
 *
 * @param[in]  i_attrId  Attribute ID
 * @param[in]  i_pTarget Pointer to Target (NULL if system)
 * @param[out] o_val     Reference to variable where override will be copied to
 * @return bool True if override was returned
 */
template <typename T>
bool getOverrideT(const fapi::AttributeId i_attrId,
                  const fapi::Target * const i_pTarget,
                  T & o_val)
{
    uint64_t l_overrideVal = 0;

    if (!(getOverrideWrap(i_attrId, i_pTarget, l_overrideVal)))
    {
        return false;
    }

    o_val = static_cast<T>(l_overrideVal);
    return true;
}

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

//@fixme begin  RTC:42293
fapi::ReturnCode return0_uint8( uint8_t &o_data );
fapi::ReturnCode return0_uint32( uint32_t &o_data );
fapi::ReturnCode set_ignore( void );
//@fixme end

} // namespace platAttrSvc

} // namespace fapi

/**
 *  @brief Macro that returns any attribute override
 */
#define FAPI_PLAT_GET_ATTR_OVERRIDE(ID, PTARGET, VAL) \
    fapi::platAttrSvc::getOverrideT(ID, PTARGET, VAL)

/**
 *  @brief Macro that clears any non-const attribute override
 */
#define FAPI_PLAT_CLEAR_NON_CONST_ATTR_OVERRIDE(ID, PTARGET) \
    fapi::platAttrSvc::clearNonConstOverrideWrap(ID, PTARGET)

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
// MACROs to route each ATTR_SPD access to the Hostboot SPD function
//------------------------------------------------------------------------------
#define ATTR_SPD_DRAM_DEVICE_TYPE_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::BASIC_MEMORY_TYPE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_TYPE_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_TYPE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_BANKS_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::BANK_ADDRESS_BITS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_DENSITY_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::DENSITY, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_ROWS_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::ROW_ADDRESS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_COLUMNS_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::COL_ADDRESS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_NOMINAL_VOLTAGE_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_NOMINAL_VOLTAGE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_NUM_RANKS_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_RANKS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_DRAM_WIDTH_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_DRAM_WIDTH, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_MEMORY_BUS_WIDTH_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_MEMORY_BUS_WIDTH, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FTB_DIVIDEND_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::FTB_DIVIDEND, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FTB_DIVISOR_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::FTB_DIVISOR, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MTB_DIVIDEND_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MTB_DIVIDEND, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MTB_DIVISOR_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MTB_DIVISOR, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TCKMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET,  SPD::TCK_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_CAS_LATENCIES_SUPPORTED_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::CAS_LATENCIES_SUPPORTED, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TAAMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MIN_CAS_LATENCY, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TWRMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TWR_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRCDMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRCD_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRRDMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRRD_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRPMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRP_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRASMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRAS_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRCMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRC_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRFCMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRFC_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TWTRMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TWTR_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TRTPMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRTP_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_TFAWMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TFAW_MIN, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_OPTIONAL_FEATURES_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SPD_SDRAM_OPTIONAL_FEATURES, &(VAL), sizeof(VAL) )
#define ATTR_SPD_SDRAM_THERMAL_AND_REFRESH_OPTIONS_GETMACRO(ID, PTARGET, VAL ) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SPD_SDRAM_THERMAL_REFRESH_OPTIONS, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_THERMAL_SENSOR_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::SPD_MODULE_THERMAL_SENSOR, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TCKMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TCKMIN_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TAAMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TAAMIN_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TRCDMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRCDMIN_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TRPMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRPMIN_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_FINE_OFFSET_TRCMIN_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::TRCMIN_FINE_OFFSET, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_SPECIFIC_SECTION_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_TYPE_SPECIFIC_SECTION, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_ID_MODULE_MANUFACTURERS_JEDEC_ID_CODE_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_MANUFACTURER_ID, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_ID_MODULE_MANUFACTURING_LOCATION_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_MANUFACTURING_LOCATION, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_ID_MODULE_MANUFACTURING_DATE_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_MANUFACTURING_DATE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_ID_MODULE_SERIAL_NUMBER_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_SERIAL_NUMBER, &(VAL), sizeof(VAL) )
#define ATTR_SPD_CYCLICAL_REDUNDANCY_CODE_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_CRC, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_PART_NUMBER_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_PART_NUMBER, &(VAL), sizeof(VAL) )
#define ATTR_SPD_MODULE_REVISION_CODE_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::MODULE_REVISION_CODE, &(VAL), sizeof(VAL) )
#define ATTR_SPD_DRAM_MANUFACTURER_JEDEC_ID_CODE_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::DRAM_MANUFACTURER_ID, &(VAL), sizeof(VAL) )
#define ATTR_SPD_BAD_DQ_DATA_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetSpdAttr( PTARGET, SPD::DIMM_BAD_DQ_DATA, &(VAL), sizeof(VAL) )
#define ATTR_SPD_BAD_DQ_DATA_SETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatSetSpdAttr( PTARGET, SPD::DIMM_BAD_DQ_DATA, &(VAL), sizeof(VAL) )

//------------------------------------------------------------------------------
// MACROs to route ATTR Base Address accesses to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_MSS_MEMORY_BASE_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetMemoryBaseAddr(PTARGET, VAL)
#define ATTR_MSS_MIRROR_BASE_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetMirrorBaseAddr(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_CEN_DQ_TO_DIMM_CONN_DQ access to the correct Hostboot
// function
//------------------------------------------------------------------------------
#define ATTR_CEN_DQ_TO_DIMM_CONN_DQ_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetDqMapping(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_NAME access to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_NAME_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetTargetName(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_FUNCTIONAL access to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_FUNCTIONAL_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetFunctional(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACRO to route ATTR_POS access to the correct Hostboot function
//------------------------------------------------------------------------------
#define ATTR_POS_GETMACRO(ID, PTARGET, VAL) \
    fapi::platAttrSvc::fapiPlatGetTargetPos(PTARGET, VAL)

//------------------------------------------------------------------------------
// MACROS to support  proc_setup_bars_memory_attributes.xml
//------------------------------------------------------------------------------
#define ATTR_PROC_FOREIGN_NEAR_BASE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::fapiPlatGetProcForeignNearBase (PTARGET, VAL )
#define ATTR_PROC_FOREIGN_NEAR_SIZE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::fapiPlatGetProcForeignNearSize (PTARGET, VAL )
#define ATTR_PROC_FOREIGN_FAR_BASE_GETMACRO( ID, PTARGET, VAL ) \
    fapi::platAttrSvc::fapiPlatGetProcForeignFarBase (PTARGET, VAL )
#define ATTR_PROC_FOREIGN_FAR_SIZE_GETMACRO( ID, PTARGET, VAL ) \
    fapi::platAttrSvc::fapiPlatGetProcForeignFarSize (PTARGET, VAL )
#define ATTR_PROC_HA_BASE_GETMACRO( ID, PTARGET, VAL )  \
    fapi::platAttrSvc::fapiPlatGetProcHaBase (PTARGET, VAL )
#define ATTR_PROC_HA_SIZE_GETMACRO( ID, PTARGET, VAL )  \
    fapi::platAttrSvc::fapiPlatGetProcHaSize (PTARGET, VAL )

//------------------------------------------------------------------------------
//  MACROS to support proc_setup_bars_mmio_attributes.xml
//------------------------------------------------------------------------------
#define ATTR_PROC_PSI_BRIDGE_BAR_ENABLE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::fapiPlatGetProcPsiBridgeBarEnable (PTARGET, VAL )
#define ATTR_PROC_FSP_BAR_ENABLE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::platAttrSvc::fapiPlatGetProcFspBarEnable (PTARGET, VAL )
#define ATTR_PROC_INTP_BAR_ENABLE_GETMACRO( ID, PTARGET, VAL )  \
    fapi::platAttrSvc::fapiPlatGetProcIntpBarEnable (PTARGET, VAL )
#define ATTR_PROC_NX_MMIO_BAR_ENABLE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::platAttrSvc::fapiPlatGetProcNxMmioBarEnable(PTARGET, VAL )
#define ATTR_PROC_NX_MMIO_BAR_SIZE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::fapiPlatGetProcNxMmioBarSize (PTARGET, VAL )
#define ATTR_PROC_PCIE_BAR_ENABLE_GETMACRO( ID, PTARGET, VAL )  \
    fapi::platAttrSvc::fapiPlatGetProcPcieBarEnable (PTARGET, VAL )
#define ATTR_PROC_PCIE_BAR_BASE_ADDR_GETMACRO( ID, PTARGET, VAL )   \
    fapi::platAttrSvc::fapiPlatGetProcPcieBarBaseAddr (PTARGET, VAL )
#define ATTR_PROC_PCIE_BAR_SIZE_GETMACRO( ID, PTARGET, VAL )   \
    fapi::platAttrSvc::fapiPlatGetProcPcieBarSize (PTARGET, VAL ) 

//------------------------------------------------------------------------------
//  MACROS to support proc_fab_smp_fabric_attributes.xml
//------------------------------------------------------------------------------

//@fixme : RTC:42293
//------------------------------------------------------------------------------
//  MACROS to support pm_plat_attributes.xml
//------------------------------------------------------------------------------
#define ATTR_PM_EXTERNAL_VRM_STEPSIZE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_EXTERNAL_VRM_STEPDELAY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PSTATE_UNDERVOLTING_MAXIMUM_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_FREQUENCY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SPIVID_PORT_ENABLE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SAFE_FREQUENCY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_RESONANT_CLOCK_FULL_CLOCK_SECTOR_BUFFER_FREQUENCY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_RESONANT_CLOCK_LOW_BAND_LOWER_FREQUENCY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_RESONANT_CLOCK_LOW_BAND_UPPER_FREQUENCY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_RESONANT_CLOCK_HIGH_BAND_LOWER_FREQUENCY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_RESONANT_CLOCK_HIGH_BAND_UPPER_FREQUENCY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SPIPSS_FREQUENCY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_APSS_CHIP_SELECT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PBAX_NODEID_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PBAX_CHIPID_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PBAX_BRDCST_ID_VECTOR_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PROC_R_LOADLINE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PROC_R_DISTLOSS_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PROC_VRM_VOFFSET_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_FREQ_CORE_MAX_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PSTATE_UNDERVOLTING_MINIMUM_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )

//@fixme : RTC:42293
//------------------------------------------------------------------------------
//  MACROS to support pm_hwp_attributes.xml
//------------------------------------------------------------------------------
#define ATTR_PM_POWER_PROXY_TRACE_TIMER_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PPT_TIMER_MATCH_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PPT_TIMER_TICK_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_AISS_TIMEOUT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PSTATE_STEPSIZE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_EXTERNAL_VRM_STEPDELAY_RANGE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_EXTERNAL_VRM_STEPDELAY_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PMC_HANGPULSE_DIVIDER_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PVSAFE_PSTATE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_FRAME_SIZE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_IN_DELAY_FRAME1_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_IN_DELAY_FRAME2_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_CLOCK_POLARITY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_CLOCK_PHASE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_CLOCK_DIVIDER_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SPIVID_INTER_RETRY_DELAY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SPIVID_CRC_GEN_ENABLE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_CRC_CHECK_ENABLE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_MAX_RETRIES_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_OCC_HEARTBEAT_TIME_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SLEEP_WINKLE_REQUEST_TIMEOUT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SLEEP_ENTRY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SLEEP_EXIT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SLEEP_TYPE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_WINKLE_TYPE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PFET_POWERUP_CORE_DELAY0_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERUP_CORE_DELAY1_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERUP_CORE_DELAY0_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PFET_POWERUP_CORE_DELAY1_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERUP_ECO_DELAY0_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERUP_ECO_DELAY1_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERUP_ECO_DELAY0_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PFET_POWERUP_ECO_DELAY1_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_VALUE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PSTATE0_FREQUENCY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_IVRMS_ENABLED_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SAFE_PSTATE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_RESONANT_CLOCK_ENABLE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_RESONANT_CLOCK_FULL_CSB_PSTATE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_RESONANT_CLOCK_LFRLOW_PSTATE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_RESONANT_CLOCK_LFRUPPER_PSTATE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_RESONANT_CLOCK_HFRLOW_PSTATE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_RESONANT_CLOCK_HFRHIGH_PSTATE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIPSS_FRAME_SIZE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIPSS_OUT_COUNT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIPSS_IN_DELAY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIPSS_IN_COUNT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIPSS_CLOCK_POLARITY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIPSS_CLOCK_PHASE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIPSS_CLOCK_DIVIDER_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPIPSS_INTER_FRAME_DELAY_SETTING_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SPIPSS_INTER_FRAME_DELAY_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_PBAX_RCV_RESERV_TIMEOUT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PBAX_SND_RETRY_COUNT_OVERCOMMIT_ENABLE_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PBAX_SND_RETRY_THRESHOLD_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_PBAX_SND_RESERV_TIMEOUT_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint8( VAL )
#define ATTR_PM_SPWUP_FSP_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SPWUP_OCC_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )
#define ATTR_PM_SPWUP_PHYP_GETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::return0_uint32( VAL )

#define ATTR_PM_POWER_PROXY_TRACE_TIMER_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PPT_TIMER_MATCH_VALUE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PPT_TIMER_TICK_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_AISS_TIMEOUT_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PSTATE_STEPSIZE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_EXTERNAL_VRM_STEPDELAY_RANGE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_EXTERNAL_VRM_STEPDELAY_VALUE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PMC_HANGPULSE_DIVIDER_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PVSAFE_PSTATE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_FRAME_SIZE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_IN_DELAY_FRAME1_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_IN_DELAY_FRAME2_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_CLOCK_POLARITY_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_CLOCK_PHASE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_CLOCK_DIVIDER_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_INTERFRAME_DELAY_WRITE_STATUS_VALUE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_INTER_RETRY_DELAY_VALUE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_INTER_RETRY_DELAY_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_CRC_GEN_ENABLE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_CRC_CHECK_ENABLE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_MAJORITY_VOTE_ENABLE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_MAX_RETRIES_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIVID_CRC_POLYNOMIAL_ENABLES_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SLEEP_WINKLE_REQUEST_TIMEOUT_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SLEEP_ENTRY_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SLEEP_EXIT_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SLEEP_TYPE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_WINKLE_TYPE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERUP_CORE_DELAY0_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERUP_CORE_DELAY1_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERUP_CORE_SEQUENCE_DELAY_SELECT_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERDOWN_CORE_DELAY0_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERDOWN_CORE_DELAY1_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERDOWN_CORE_SEQUENCE_DELAY_SELECT_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERUP_ECO_DELAY0_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERUP_ECO_DELAY1_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERUP_ECO_SEQUENCE_DELAY_SELECT_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERDOWN_ECO_DELAY0_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERDOWN_ECO_DELAY1_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_PFET_POWERDOWN_ECO_SEQUENCE_DELAY_SELECT_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_IVRMS_ENABLED_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SAFE_PSTATE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_RESONANT_CLOCK_ENABLE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_RESONANT_CLOCK_FULL_CSB_PSTATE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_RESONANT_CLOCK_LFRLOW_PSTATE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_RESONANT_CLOCK_LFRUPPER_PSTATE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_RESONANT_CLOCK_HFRLOW_PSTATE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_RESONANT_CLOCK_HFRHIGH_PSTATE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIPSS_FRAME_SIZE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIPSS_OUT_COUNT_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIPSS_IN_DELAY_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIPSS_IN_COUNT_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIPSS_CLOCK_POLARITY_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIPSS_CLOCK_PHASE_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIPSS_CLOCK_DIVIDER_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIPSS_INTER_FRAME_DELAY_SETTING_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPIPSS_INTER_FRAME_DELAY_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPWUP_FSP_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPWUP_OCC_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()
#define ATTR_PM_SPWUP_PHYP_SETMACRO( ID, PTARGET, VAL )    \
    fapi::platAttrSvc::set_ignore()


#endif // FAPIPLATATTRIBUTESERVICE_H_
