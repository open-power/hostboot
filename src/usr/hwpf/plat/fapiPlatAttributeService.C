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

#include <hwpf/fapi/fapiTarget.H>
#include <targeting/targetservice.H>
#include <errl/errlentry.H>
#include <hwpf/plat/fapiPlatAttributeService.H>
#include <hwpf/plat/fapiPlatReasonCodes.H>
#include <spd/spdenums.H>
#include <devicefw/driverif.H>

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

//******************************************************************************
// platUpdateAttrValue function reformats the Attribute value if needed based
// on the format documented in the HWPF attributei xml file.
//******************************************************************************
static void platUpdateAttrValue( const uint16_t i_keyword, void * o_data )
{
    FAPI_DBG(ENTER_MRK "platUpdateAttrValue");

    uint32_t l_word = 0;
    uint8_t *l_byte = static_cast<uint8_t *>(o_data);
    bool l_update = true;

    switch( i_keyword )
    {
        // These attributes are 4-byte uint32_t values. The DD returns 2-byte
        // left-aligned value. Need to move it to right-aligned format.
        case SPD::CAS_LATENCIES_SUPPORTED:
        case SPD::TRAS_MIN:
        case SPD::TRC_MIN:
        case SPD::TRFC_MIN:
        case SPD::TFAW_MIN:
        case SPD::MODULE_MANUFACTURING_DATE:
        case SPD::MODULE_MANUFACTURER_ID:
            l_word |= (*l_byte++ << 8);
            l_word |= (*l_byte);
            break;
        // These attributes are 4-bytes uint32_t values. The DD returns 2-byte
        // left-aligned and byte-swapped value. Need to move it to right-aligned
        // and reverse the bytes
        case SPD::MODULE_CRC:
        case SPD::MODULE_REVISION_CODE:
        case SPD::DRAM_MANUFACTURER_ID:
            l_word |= (*l_byte++);
            l_word |= (*l_byte << 8);
            break;
        // This attribute are 4-bytes uint32_t. The DD returns in big-endian
        // format. Need to change to little endian
        case SPD::MODULE_SERIAL_NUMBER:
            l_word |= (*l_byte++);
            l_word |= (*l_byte++ << 8);
            l_word |= (*l_byte++ << 16);
            l_word |= (*l_byte << 24);
            break;
        default:
            l_update = false;
            break;
    }

    if (l_update)
    {
        memcpy( o_data, &l_word, sizeof(l_word) );
    }

    FAPI_DBG(EXIT_MRK "platUpdateAttrValue");

}

//******************************************************************************
// fapiPlatGetSpdAttr function.
// Call SPD device driver to retrieve the SPD attribute
//******************************************************************************
fapi::ReturnCode fapiPlatGetSpdAttr(const fapi::Target * i_target,
                                    const uint16_t i_keyword,
                                    void * o_data, const size_t i_len)
{
    FAPI_DBG(ENTER_MRK "fapiPlatGetSpdAttr");

    fapi::ReturnCode l_rc;

    // Extract the component pointer
    TARGETING::Target* l_target =
                         reinterpret_cast<TARGETING::Target*>(i_target->get());

    errlHndl_t l_err = NULL;
    size_t l_len = i_len;
    l_err = deviceRead( l_target, o_data, l_len, DEVICE_SPD_ADDRESS(i_keyword));

    if (l_err)
    {
        // Add the error log pointer as data to the ReturnCode
        FAPI_ERR("platGetSpdAttr: deviceOp() returns error");
        l_rc.setPlatError(reinterpret_cast<void *> (l_err));
    }
    else
    {
        platUpdateAttrValue( i_keyword, o_data );
    }

    FAPI_DBG(EXIT_MRK "fapiPlatGetSpdAttr");
    return l_rc;

}

} // End platAttrSvc namespace

} // End fapi namespace
