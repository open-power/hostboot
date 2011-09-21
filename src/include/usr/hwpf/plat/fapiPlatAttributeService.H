//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/plat/fapiPlatAttributeService.H $
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
#include <targeting/target.H>
#include <targeting/attributes.H>
#include <attributeenums.H>
#include <fapiplatattrmacros.H>
#include <hwpf/fapi/fapiReturnCode.H>
#include <hwpf/fapi/fapiTarget.H>

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
     *  @brief Macro which directly maps a FAPI request to get a platform
     *      attribute to the equivalent host boot request 
     */
    #define FAPI_PLAT_ATTR_SVC_GETMACRO_DIRECT(ID, PTARGET, VAL) \
        ( ((PTARGET) ? \
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
        ( ((PTARGET) ? \
            static_cast<TARGETING::Target*>( \
                static_cast<const fapi::Target*>(PTARGET)->get()) \
        : fapi::platAttrSvc::getSystemTarget())->trySetAttr< \
             FAPI_PLAT_ATTR_SVC_MACRO_DIRECT_FAPI_##ID>(VAL)) \
                ? fapi::FAPI_RC_SUCCESS : fapi::platAttrSvc::createAttrAccessError( \
                    FAPI_PLAT_ATTR_SVC_MACRO_DIRECT_FAPI_##ID,fapi::ID,PTARGET)
}

}

#endif // FAPIPLATATTRIBUTESERVICE_H_
