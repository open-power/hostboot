/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/plat/fapiPlatAttributeService.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file fapiPlatAttributeService.C
 *
 *  @brief Implements HWP attribute -> HB attribute bridging functions
 *
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <hwpf/fapi/fapiTarget.H>
#include <targeting/common/targetservice.H>
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
// fapi::platAttrSvc::getHostbootTarget
//******************************************************************************
fapi::ReturnCode getHostbootTarget(
    const fapi::Target* i_pFapiTarget,
    TARGETING::Target* & o_pTarget,
    const TARGETING::TYPE i_expectedType = TARGETING::TYPE_NA)
{
    fapi::ReturnCode l_rc;

    // Check that the FAPI Target pointer is not NULL
    if (i_pFapiTarget == NULL)
    {
        FAPI_ERR("getHostbootTarget. NULL FAPI Target passed");

        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_GET_HB_TARGET
         *  @reasoncode RC_NULL_FAPI_TARGET
         *  @devdesc    NULL FAPI Target passed to attribute access macro
         */
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            fapi::MOD_ATTR_GET_HB_TARGET,
            fapi::RC_NULL_FAPI_TARGET);
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }
    else
    {
        // Extract the Hostboot Target pointer
        o_pTarget = reinterpret_cast<TARGETING::Target*>(i_pFapiTarget->get());

        // Check that the Hostboot Target pointer is not NULL
        if (o_pTarget == NULL)
        {
            FAPI_ERR("getHostbootTarget. NULL Hostbot Target passed");

            /*@
             *  @errortype
             *  @moduleid   MOD_ATTR_GET_HB_TARGET
             *  @reasoncode RC_EMBEDDED_NULL_TARGET_PTR
             *  @devdesc    NULL HOSTBOOT Target passed to attribute access macro
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                fapi::MOD_ATTR_GET_HB_TARGET,
                fapi::RC_EMBEDDED_NULL_TARGET_PTR);
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }
        else
        {
            // Check that the Target Type is as expected
            if (i_expectedType != TARGETING::TYPE_NA)
            {
                TARGETING::TYPE l_type =
                    o_pTarget->getAttr<TARGETING::ATTR_TYPE>();

                if (l_type != i_expectedType)
                {
                    FAPI_ERR("getHostbootTarget. Type: %d, expected %d",
                             l_type, i_expectedType);

                    /*@
                     *  @errortype
                     *  @moduleid   MOD_ATTR_GET_HB_TARGET
                     *  @reasoncode RC_UNEXPECTED_TARGET_TYPE
                     *  @userdata1  Target Type
                     *  @userdata2  Expected Target Type
                     *  @devdesc    Unexpected Target Type passed to attribute access macro
                     */
                    errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                        fapi::MOD_ATTR_GET_HB_TARGET,
                        fapi::RC_UNEXPECTED_TARGET_TYPE,
                        l_type, i_expectedType);
                    l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
                }
            }
        }
    }

    return l_rc;
}

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
    l_err = deviceRead(l_target, o_data, l_len, DEVICE_SPD_ADDRESS(i_keyword));

    if (l_err)
    {
        // Add the error log pointer as data to the ReturnCode
        FAPI_ERR("platGetSpdAttr: deviceRead() returns error");
        l_rc.setPlatError(reinterpret_cast<void *> (l_err));
    }
    else
    {
        platUpdateAttrValue(i_keyword, o_data);
    }

    FAPI_DBG(EXIT_MRK "fapiPlatGetSpdAttr");
    return l_rc;
}

//******************************************************************************
// fapiPlatSetSpdAttr function.
// Call SPD device driver to set the SPD attribute
//******************************************************************************
fapi::ReturnCode fapiPlatSetSpdAttr(const fapi::Target * i_target,
                                    const uint16_t i_keyword,
                                    void * i_data, const size_t i_len)
{
    FAPI_DBG(ENTER_MRK "fapiPlatSetSpdAttr");

    fapi::ReturnCode l_rc;

    // Extract the component pointer
    TARGETING::Target* l_target =
                         reinterpret_cast<TARGETING::Target*>(i_target->get());

    errlHndl_t l_err = NULL;
    size_t l_len = i_len;
    l_err = deviceWrite(l_target, i_data, l_len, DEVICE_SPD_ADDRESS(i_keyword));

    if (l_err)
    {
        // Add the error log pointer as data to the ReturnCode
        FAPI_ERR("platSetSpdAttr: deviceWrite() returns error");
        l_rc.setPlatError(reinterpret_cast<void *> (l_err));
    }

    FAPI_DBG(EXIT_MRK "fapiPlatSetSpdAttr");
    return l_rc;
}

//******************************************************************************
// fapiPlatGetDqMapping function.
//******************************************************************************
fapi::ReturnCode fapiPlatGetDqMapping(const fapi::Target * i_pDimmTarget,
                                      uint8_t (&o_data)[DIMM_DQ_NUM_DQS])
{
    fapi::ReturnCode l_rc;
    bool l_error = false;

    // Check that the FAPI Target pointer is not NULL
    if (i_pDimmTarget == NULL)
    {
        FAPI_ERR("fapiPlatGetDqMapping. NULL FAPI Target passed");
        l_error = true;
    }
    else
    {
        // Extract the DIMM Hostboot Target pointer
        TARGETING::Target * l_pDimmTarget =
            reinterpret_cast<TARGETING::Target*>(i_pDimmTarget->get());

        // Check that the DIMM Hostboot Target pointer is not NULL
        if (l_pDimmTarget == NULL)
        {
            FAPI_ERR("fapiPlatGetDqMapping. NULL HB Target passed");
            l_error = true;
        }
        else
        {
            // Check that the Target is a DIMM
            if (l_pDimmTarget->getAttr<TARGETING::ATTR_TYPE>() !=
                TARGETING::TYPE_DIMM)
            {
                FAPI_ERR("fapiPlatGetDqMapping. Not a DIMM (0x%x)",
                         l_pDimmTarget->getAttr<TARGETING::ATTR_TYPE>());
                l_error = true;
            }
            else
            {
                if (l_pDimmTarget->getAttr<TARGETING::ATTR_MODEL>() ==
                    TARGETING::MODEL_CDIMM)
                {
                    // C-DIMM. There is no DQ mapping from Centaur DQ to DIMM
                    // Connector DQ because there is no DIMM Connector. Return
                    // a direct 1:1 map (0->0, 1->1, etc)
                    for (uint8_t i = 0; i < DIMM_DQ_NUM_DQS; i++)
                    {
                        o_data[i] = i;
                    }
                }
                else
                {
                    // IS-DIMM. Get the mapping using a Hostboot attribute
                    // Note that getAttr() cannot be used to get an array
                    // attribute so using tryGetAttr and ignoring result
                    l_pDimmTarget->
                        tryGetAttr<TARGETING::ATTR_CEN_DQ_TO_DIMM_CONN_DQ>
                            (o_data);
                }
            }
        }
    }

    if (l_error)
    {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_DQ_MAP_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Failed to get DIMM DQ mapping attribute due to
         *              bad target parameter.
         */
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            fapi::MOD_ATTR_DQ_MAP_GET,
            fapi::RC_ATTR_BAD_TARGET_PARAM);
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }

    return l_rc;
}

//******************************************************************************
// fapiPlatGetTargetName function
//******************************************************************************
fapi::ReturnCode fapiPlatGetTargetName(const fapi::Target * i_pTarget,
                                       uint8_t & o_name)
{
    fapi::ReturnCode l_rc;
    o_name = ENUM_ATTR_NAME_NONE;
    bool l_error = false;

    // Check that the FAPI Target pointer is not NULL
    if (i_pTarget == NULL)
    {
        FAPI_ERR("fapiPlatGetTargetName. NULL FAPI Target passed");
        l_error = true;
    }
    else
    {
        // Extract the MCS Hostboot Target pointer
        TARGETING::Target * l_pHbTarget = reinterpret_cast<TARGETING::Target*>(
            i_pTarget->get());

        // Check that the MCS Hostboot Target pointer is not NULL
        if (l_pHbTarget == NULL)
        {
            FAPI_ERR("fapiPlatGetTargetName. NULL HB Target passed");
            l_error = true;
        }
        else
        {
            TARGETING::MODEL l_model = l_pHbTarget->
                getAttr<TARGETING::ATTR_MODEL>();

            if (l_model == TARGETING::MODEL_VENICE)
            {
                o_name = ENUM_ATTR_NAME_VENICE;
            }
            else if (l_model == TARGETING::MODEL_MURANO)
            {
                o_name = ENUM_ATTR_NAME_MURANO;
            }
            else if (l_model == TARGETING::MODEL_CENTAUR)
            {
                o_name = ENUM_ATTR_NAME_CENTAUR;
            }
            else
            {
                FAPI_ERR("fapiPlatGetTargetName. Unknown name 0x%x", l_model);
                l_error = true;
            }
        }
    }

    if (l_error)
    {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_GET_TARGET_NAME
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Failed to get the Target name due to bad target
         *              parameter.
         */
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            fapi::MOD_ATTR_GET_TARGET_NAME,
            fapi::RC_ATTR_BAD_TARGET_PARAM);
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }

    return l_rc;
}

//******************************************************************************
// fapiPlatGetFunctional function
//******************************************************************************
fapi::ReturnCode fapiPlatGetFunctional(const fapi::Target * i_pTarget,
                                       uint8_t & o_functional)
{
    fapi::ReturnCode l_rc;
    o_functional = 0;
    bool l_error = false;

    // TODO. Move the checking of the FAPI Target pointer and embedded Hostboot
    // Target pointer to a common function. Not doing it here because there are
    // currently other changes to this file going through review.

    // Check that the FAPI Target pointer is not NULL
    if (i_pTarget == NULL)
    {
        FAPI_ERR("fapiPlatGetFunctional. NULL FAPI Target passed");
        l_error = true;
    }
    else
    {
        // Extract the MCS Hostboot Target pointer
        TARGETING::Target * l_pHbTarget = reinterpret_cast<TARGETING::Target*>(
            i_pTarget->get());

        // Check that the MCS Hostboot Target pointer is not NULL
        if (l_pHbTarget == NULL)
        {
            FAPI_ERR("fapiPlatGetFunctional. NULL HB Target passed");
            l_error = true;
        }
        else
        {
            TARGETING::PredicateIsFunctional l_functional;
            if (l_functional(l_pHbTarget))
            {
                o_functional = 1;
            }
        }
    }

    if (l_error)
    {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_GET_FUNCTIONAL
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Failed to get the functional state due to bad target
         *              parameter.
         */
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            fapi::MOD_ATTR_GET_FUNCTIONAL,
            fapi::RC_ATTR_BAD_TARGET_PARAM);
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }

    return l_rc;
}

//******************************************************************************
// fapi::platAttrSvc::fapiPlatGetTargetPos function
//******************************************************************************
fapi::ReturnCode fapiPlatGetTargetPos(const fapi::Target * i_pFapiTarget,
                                      uint32_t & o_pos)
{
    fapi::ReturnCode l_rc;
    TARGETING::Target * l_pTarget = NULL;

    // Get the Hostboot Target
    l_rc = getHostbootTarget(i_pFapiTarget, l_pTarget);

    if (l_rc)
    {
        FAPI_ERR("getTargetName: Error getting Hostboot Target");
    }
    else
    {
        uint16_t l_pos = l_pTarget->getAttr<TARGETING::ATTR_POSITION>();
        o_pos = l_pos;
    }

    return l_rc;
}

//******************************************************************************
// fapi::platAttrSvc::getOverrideWrap function
//******************************************************************************
bool getOverrideWrap(const fapi::AttributeId i_attrId,
                     const fapi::Target * const i_pTarget,
                     uint64_t & o_overrideVal,
                     const uint8_t i_arrayD1,
                     const uint8_t i_arrayD2,
                     const uint8_t i_arrayD3,
                     const uint8_t i_arrayD4)
{
    return Singleton<fapi::AttributeOverrides>::instance().getOverride(
        i_attrId, i_pTarget, o_overrideVal, i_arrayD1, i_arrayD2, i_arrayD3,
        i_arrayD4);
}

//******************************************************************************
// fapi::platAttrSvc::clearNonConstOverrideWrap function
//******************************************************************************
void clearNonConstOverrideWrap(const fapi::AttributeId i_attrId,
                               const fapi::Target * const i_pTarget)
{
    Singleton<fapi::AttributeOverrides>::instance().clearNonConstOverride(
        i_attrId, i_pTarget);
}

//******************************************************************************
// fapi::platAttrSvc::setOverrideWrap function
//******************************************************************************
void setOverrideWrap(const AttributeOverride & i_override)
{
    Singleton<fapi::AttributeOverrides>::instance().setOverride(i_override);
}

//******************************************************************************
// fapi::platAttrSvc::clearOverridesWrap function
//******************************************************************************
void clearOverridesWrap()
{
    Singleton<fapi::AttributeOverrides>::instance().clearOverrides();
}

//******************************************************************************
// fapi::platAttrSvc::overridesExistWrap function
//******************************************************************************
bool overridesExistWrap()
{
    return Singleton<fapi::AttributeOverrides>::instance().overridesExist();
}

//******************************************************************************
// fapi::platAttrSvc::AttributeOverridesLock class
// This is a simple container for a mutex
//******************************************************************************
class AttributeOverridesLock
{
public:
    AttributeOverridesLock()
    {
        mutex_init(&iv_mutex);
    }
    
    ~AttributeOverridesLock()
    {
        mutex_destroy(&iv_mutex);
    }
    mutex_t iv_mutex;
};

} // End platAttrSvc namespace

//******************************************************************************
// fapi::AttributeOverrides::platLock function
// This is the Hostboot PLAT implementation of the FAPI function
//******************************************************************************
void AttributeOverrides::platLock()
{
    mutex_lock(&(Singleton
        <fapi::platAttrSvc::AttributeOverridesLock>::instance().iv_mutex));
}

//******************************************************************************
// fapi::AttributeOverrides::platUnlock function
// This is the Hostboot PLAT implementation of the FAPI function
//******************************************************************************
void AttributeOverrides::platUnlock()
{
    mutex_unlock(&(Singleton
        <fapi::platAttrSvc::AttributeOverridesLock>::instance().iv_mutex));
}

} // End fapi namespace
