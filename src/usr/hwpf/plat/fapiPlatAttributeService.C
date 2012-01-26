//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/plat/fapiPlatAttributeService.C $
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
 *  @file fapiPlatAttributeService.C
 *
 *  @brief Implements HWP attribute -> HB attribute bridging functions
 *
 *  Note that platform code must provide the implementation.
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <targeting/targetservice.H>
#include <errl/errlentry.H>
#include <errl/errltypes.H>
#include <hwpf/plat/fapiPlatAttributeService.H>
#include <hwpf/plat/fapiPlatReasonCodes.H>

// The following file checks at compile time that all HWPF attributes are
// handled by Hostboot. This is done to ensure that the HTML file listing
// supported HWPF attributes lists attributes handled by Hostboot
#include <fapiAttributePlatCheck.H>

//******************************************************************************
// Implementation
//******************************************************************************

namespace fapi
{

namespace platAttrSvc
{

//******************************************************************************
// fapi::platAttrSvc::getSystemTarget
//******************************************************************************

TARGETING::Target* getSystemTarget()
{ 
    TARGETING::Target* l_pTarget = NULL; 
    TARGETING::targetService().getTopLevelTarget(l_pTarget);  
    assert(l_pTarget);
    return l_pTarget;
}

//******************************************************************************
// fapi::platAttrSvc::createAttrAccessError
//******************************************************************************

fapi::ReturnCode createAttrAccessError(
    const TARGETING::ATTRIBUTE_ID i_targAttrId,
    const fapi::AttributeId       i_fapiAttrId,
    const fapi::Target* const     i_pFapiTarget)
{
    /*@
     *  @errortype
     *  @moduleid   MOD_PLAT_ATTR_SVC_CREATE_ATTR_ACCESS_ERROR
     *  @reasoncode RC_FAILED_TO_ACCESS_ATTRIBUTE
     *  @userdata1  Top 32 bits = platform attribute ID, lower 32 bits = 
     *                  FAPI attribute ID
     *  @userdata2  FAPI target type, or NULL if system target
     *  @devdesc    Failed to get requested attribute.  
     *      Possible causes: Invalid target, attribute not implemented,
     *          attribute not present on given target, target service not
     *          initialized
     */
    errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
        ERRORLOG::ERRL_SEV_INFORMATIONAL,
        fapi::MOD_PLAT_ATTR_SVC_CREATE_ATTR_ACCESS_ERROR,
        fapi::RC_FAILED_TO_ACCESS_ATTRIBUTE,
          (static_cast<uint64_t>(i_targAttrId) << 32)
        | (static_cast<uint64_t>(i_fapiAttrId)),
        i_pFapiTarget ? i_pFapiTarget->getType(): NULL);

    fapi::ReturnCode l_rc;
    l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    return l_rc;
}

} // End platAttrSvc namespace

} // End fapi namespace
