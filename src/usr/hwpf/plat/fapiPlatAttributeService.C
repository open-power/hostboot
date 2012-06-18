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
#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>

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
// fapiPlatBaseAddrCheckMcsGetTargets
//
// Local function used by fapiPlatGetMemoryBaseAddr / fapiPlatGetMirrorBaseAddr
// to check that the input component is an MCS chiplet and that the parent chip
// Hostboot target can be found
//******************************************************************************
fapi::ReturnCode fapiPlatBaseAddrCheckMcsGetChip(
    const fapi::Target* i_pMcsTarget,
    TARGETING::Target* & o_pMcsTarget,
    TARGETING::Target* & o_pChipTarget)
{
    fapi::ReturnCode l_rc;
    bool l_error = false;

    // Check that the FAPI Target pointer is not NULL
    if (i_pMcsTarget == NULL)
    {
        FAPI_ERR("fapiPlatBaseAddrCheckMcsGetChip. NULL FAPI Target passed");
        l_error = true;
    }
    else
    {
        // Extract the MCS Hostboot Target pointer
        o_pMcsTarget =
            reinterpret_cast<TARGETING::Target*>(i_pMcsTarget->get());

        // Check that the MCS Hostboot Target pointer is not NULL
        if (o_pMcsTarget == NULL)
        {
            FAPI_ERR("fapiPlatBaseAddrCheckMcsGetChip. NULL HB Target passed");
            l_error = true;
        }
        else
        {
            // Check that the Target is an MCS chiplet
            if (o_pMcsTarget->getAttr<TARGETING::ATTR_TYPE>() !=
                TARGETING::TYPE_MCS)
            {
                FAPI_ERR("fapiPlatBaseAddrCheckMcsGetChip. Not an MCS (0x%x)",
                         o_pMcsTarget->getAttr<TARGETING::ATTR_TYPE>());
                l_error = true;
            }
            else
            {
                // Get the parent chip
                TARGETING::TargetHandleList l_parentList;
                TARGETING::targetService().getAssociated(
                    l_parentList,
                    o_pMcsTarget,
                    TARGETING::TargetService::PARENT,
                    TARGETING::TargetService::IMMEDIATE);

                if (l_parentList.size() != 1)
                {
                    FAPI_ERR("fapiPlatBaseAddrCheckMcsGetChip. Did not find single parent chip (%d)",
                             l_parentList.size());
                    l_error = true;
                }
                else
                {
                    o_pChipTarget = l_parentList[0];
                }
            }
        }
    }

    if (l_error)
    {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_BASE_ADDR_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Failed to get MCS base address attribute due to
         *              bad target parameter.
         */
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            fapi::MOD_ATTR_BASE_ADDR_GET,
            fapi::RC_ATTR_BAD_TARGET_PARAM);
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }

    return l_rc;
}

//******************************************************************************
// fapiPlatGetMemoryBaseAddr function.
//******************************************************************************
fapi::ReturnCode fapiPlatGetMemoryBaseAddr(const fapi::Target * i_pMcsTarget,
                                           uint64_t & o_addr)
{
    fapi::ReturnCode l_rc;

    // @TODO - RTC 44949
    // The memory base address will depend on the PHYP System Memory Map
    // Until that is finalized, here is how it will be calculated
    // ProcChip0:MCS0: 0TB
    // ProcChip0:MCS1: 8TB (8TB increment for each MCS chiplet)
    // ProcChip0:MCS7: 56TB
    // ProcChip1:MCS0: 64Tb (64TB increment for each proc chip)

    // Check params and get the Hostboot Target pointers
    TARGETING::Target* l_pMcsTarget;
    TARGETING::Target* l_pChipTarget;

    l_rc = fapiPlatBaseAddrCheckMcsGetChip(i_pMcsTarget, l_pMcsTarget,
                                           l_pChipTarget);

    if (!l_rc)
    {
        uint64_t l_chipPos = l_pChipTarget->getAttr<TARGETING::ATTR_POSITION>();
        uint64_t l_mcsPos = l_pMcsTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();

        // (ChipPos * 64TB) + (McsPos * 8 TB)
        o_addr = ((l_chipPos * 64 * 1024 * 1024 * 1024 * 1024) +
                  (l_mcsPos * 8 * 1024 * 1024 * 1024 * 1024));
    }

    return l_rc;
}

//******************************************************************************
// fapiPlatGetMirrorBaseAddr function.
//******************************************************************************
fapi::ReturnCode fapiPlatGetMirrorBaseAddr(const fapi::Target * i_pMcsTarget,
                                           uint64_t & o_addr)
{
    fapi::ReturnCode l_rc;

    // @TODO - RTC 44949
    // The mirrored memory base address will depend on the PHYP System Memory Map
    // Until that is finalized, here is how it will be calculated
    // ProcChip0:MCS0: 512TB
    // ProcChip0:MCS1: 516TB (4TB increment for each MCS chiplet)
    // ProcChip0:MCS7: 540TB
    // ProcChip1:MCS0: 544Tb (32TB increment for each proc chip)

    // Check params and get the Hostboot Target pointers
    TARGETING::Target* l_pMcsTarget;
    TARGETING::Target* l_pChipTarget;

    l_rc = fapiPlatBaseAddrCheckMcsGetChip(i_pMcsTarget, l_pMcsTarget,
                                           l_pChipTarget);

    if (!l_rc)
    {
        uint64_t l_chipPos = l_pChipTarget->getAttr<TARGETING::ATTR_POSITION>();
        uint64_t l_mcsPos = l_pMcsTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();

        // 512TB + (ChipPos * 32TB) + (McsPos * 4 TB)
        o_addr = ((static_cast<uint64_t>(512) * 1024 * 1024 * 1024 * 1024) +
                  (l_chipPos * 32 * 1024 * 1024 * 1024 * 1024) +
                  (l_mcsPos * 4 * 1024 * 1024 * 1024 * 1024));
    }

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

/**
 *  @enum
 *  Return values for ATTR_PROC_*_BAR_ENABLE
*/
enum
{
    PROC_BARS_DISABLE   = 0x0,
    PROC_BARS_ENABLE    = 0x1,
};

/**
 *  @brief  Internal routine
 *          Do common checks and return an error if necessary for functions
 *          supporting proc/mss_setup_bars attributes
 *          Return useful parameters
 *
 *  @param[in]  -   i_pTarget   incoming target
 *  @param[in]  -   i_modid     mod id to report if error
 *  @param[out] -   o_procNum   found processor number of i_pTarget
 *  @apram[out] -   o_isEnabled ENABLE/DISABLE flag for BAR_ENABLE ATTRS
 *  @return     -   success or appropriate fapi returncode
*/
fapi::ReturnCode barsPreCheck( const fapi::Target * i_pTarget,
                               const uint8_t        i_modId,
                               uint64_t             &o_procNum,
                               uint8_t              &o_isEnabled
                              )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );

    do  {
        if (i_pTarget == NULL)
        {
            FAPI_ERR("Error: NULL FAPI Target passed");
            /*
                Error tag block should be where this routine is called,
                hopefully the script is smart enough to figure that out.
            */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                i_modId,
                fapi::RC_ATTR_BAD_TARGET_PARAM );
            l_fapirc.setPlatError(reinterpret_cast<void *> (l_pError));
            break;
        }

        const TARGETING::Target* l_pProcTarget =
            reinterpret_cast<const TARGETING::Target*>(i_pTarget->get());

        //  ATTR_POSITION should return the logical proc ID
        o_procNum  =
            static_cast<uint64_t>
                (l_pProcTarget->getAttr<TARGETING::ATTR_POSITION>() );

        TARGETING::HwasState hwasState =
            l_pProcTarget->getAttr<TARGETING::ATTR_HWAS_STATE>();


        //  if proc is functional then set the BAR_ENABLE ATTR to ENABLE
        if ( hwasState.functional )
        {
            o_isEnabled =   PROC_BARS_ENABLE;
        }
        else
        {
            o_isEnabled =   PROC_BARS_DISABLE;
        }

    }   while(0);

    return  l_fapirc;
}


//------------------------------------------------------------------------------
// Routines to support  proc_setup_bars_memory_attributes
//  See proc_setup_bars_memory_attributes.xml for detailed descriptions
//------------------------------------------------------------------------------

fapi::ReturnCode fapiPlatGetProcMemBase(
                                       const fapi::Target * i_pTarget,
                                       uint64_t   &o_memBase )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    FAPI_DBG( "fapiPlatGetProcMemBase: entry" ) ;

    do  {

        o_memBase   =   0;

        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_MEMBASE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null or non functional FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_MEMBASE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        //  To match with fapiPlatGetMemoryBaseAddr
        //      0 for proc 0,  64TB for proc1, etc.
        o_memBase = ( l_procNum * 1024 * 1024 * 1024 * 1024 * 64 ) ;
        FAPI_DBG( "fapiPlatGetProcMemBase: proc %d memBase=%p",
                  l_procNum,
                  o_memBase );

    } while (0);

    FAPI_DBG( "fapiPlatGetProcMemBase: exit" ) ;

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcMirrorBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_mirrorMemBase )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {

        o_mirrorMemBase   =   0;

        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_MIRRORBASE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_MEMBASE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        //  To match with fapiPlatGetMemoryBaseAddr
        //      512TB for proc 0,  512TB + 32TB * N for procN, etc.
        o_mirrorMemBase = ( 512 * 1024 * 1024 ) ;
        o_mirrorMemBase *= ( 1024 * 1024 );
        o_mirrorMemBase += ( (l_procNum) * 32 * 1024 * 1024 * 1024 * 1024 ) ;
        FAPI_DBG( "fapiPlatGetMirrorMemBase: proc %d mirrorMemBase=%p",
                  l_procNum,
                  o_mirrorMemBase );

    } while (0);

    return  l_fapirc;
}


fapi::ReturnCode fapiPlatGetProcForeignNearBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignNearBase)[ 2 ] )
{
    fapi::ReturnCode    l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_FOREIGN_NEAR_BASE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_FOREIGN_NEAR_BASE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        // 2012-06-25 Per Dean return 0 here for now
        o_foreignNearBase[0]    =   0;
        o_foreignNearBase[1]    =   0;

    }   while (0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcForeignNearSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignNearSize)[ 2 ] )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_FOREIGN_NEAR_SIZE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_FOREIGN_NEAR_SIZE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        // 2012-06-25 Per Dean return 0 here for now
        o_foreignNearSize[0]    =   0;
        o_foreignNearSize[1]    =   0;

    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcForeignFarBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignFarBase)[ 2 ] )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_FOREIGN_FAR_BASE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_FOREIGN_FAR_BASE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        // 2012-06-25 Per Dean return 0 here for now
        o_foreignFarBase[0]    =   0;
        o_foreignFarBase[1]    =   0;

    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcForeignFarSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignFarSize)[ 2 ] )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_FOREIGN_FAR_SIZE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_FOREIGN_FAR_SIZE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        // 2012-06-25 Per Dean return 0 here for now
        o_foreignFarSize[0]    =   0;
        o_foreignFarSize[1]    =   0;

    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcHaBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_haBase)[ 8 ] )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_HA_BASE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_HA_BASE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        // 2012-06-25 Per Dean return 0 here for now
        o_haBase[0]    =   0;
        o_haBase[1]    =   0;
        o_haBase[2]    =   0;
        o_haBase[3]    =   0;
        o_haBase[4]    =   0;
        o_haBase[5]    =   0;
        o_haBase[6]    =   0;
        o_haBase[7]    =   0;

    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcHaSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_haSize)[ 8 ] )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_HA_SIZE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_HA_SIZE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        // 2012-06-25 Per Dean return 0 here for now
        o_haSize[0]    =   0;
        o_haSize[1]    =   0;
        o_haSize[2]    =   0;
        o_haSize[3]    =   0;
        o_haSize[4]    =   0;
        o_haSize[5]    =   0;
        o_haSize[6]    =   0;
        o_haSize[7]    =   0;

    } while(0);

    return  l_fapirc;
}


//------------------------------------------------------------------------------
//  Prototypes to support proc_setup_bars_mmio_attributes
//  see proc_setup_bars_mmio_attributes for detailed descriptions
//------------------------------------------------------------------------------

fapi::ReturnCode fapiPlatGetProcPsiBridgeBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t     &o_psiBridgeBarEnable )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_PSI_BRIDGE_BAR_ENABLE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck(
                                  i_pTarget,
                                  fapi::MOD_ATTR_PROC_PSI_BRIDGE_BAR_ENABLE_GET,
                                  l_procNum,
                                  l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        //  return
        o_psiBridgeBarEnable    =   l_isEnabled;


    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcPsiBridgeBarBaseAddr (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_psiBridgeBarBase )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck(
                              i_pTarget,
                              fapi::MOD_ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR_GET,
                              l_procNum,
                              l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        // The spreadsheet shows the base address ( SPPSIStart ) is
        //  0x0003FFFE80000000.
        //  On the Service Processor page there are 63
        //  links, incrementing by 1 MB , i.e.
        //  0x0003FFFE80000000 - 0x0003FFFE83F00000
        //  For now it doesn't matter which link is assigned to which proc
        //  @todo further work done in RTC 34095

        o_psiBridgeBarBase  =   SP_PSI_START + ( l_procNum * SP_PSI_SIZE );

    }   while(0);


    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcFspBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t     &o_fspBarEnable )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_FSP_BAR_ENABLE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_FSP_BAR_ENABLE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        o_fspBarEnable  =   l_isEnabled;

    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcFspBarBaseAddr (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_fspBarBase )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_FSP_BAR_BASE_ADDR_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_FSP_BAR_BASE_ADDR_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        //  There are 16 FSP's starting at 0x0003FFE000000000, incrementing
        //  every 4GB.
        //  For now, map each FSP to a different proc
        //  @todo further work done in RTC 34095
        o_fspBarBase    =   SP_BAR_START + ( l_procNum * SP_BAR_SIZE );

    }   while(0);


    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcFspBarSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_fspBarSize )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_FSP_BAR_SIZE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_FSP_BAR_SIZE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        o_fspBarSize    =   FSP_BAR_SIZE ;

    }   while(0);


    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcFspMmioMaskSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_fspMmioMaskSize )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_FSP_MMIO_MASK_SIZE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_FSP_MMIO_MASK_SIZE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        o_fspMmioMaskSize    =  FSP_MMIO_MASK_SIZE ;

    }   while(0);


    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcIntpBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t    &o_intpBarEnable )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_INTP_BAR_ENABLE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_INTP_BAR_ENABLE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        o_intpBarEnable =   l_isEnabled;

    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcIntpBarBaseAddr (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_intpBarBaseAddr )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_INTP_BAR_BASE_ADDR_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_INTP_BAR_BASE_ADDR_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        //  @todo further work done in RTC 34095
        o_intpBarBaseAddr   =   PROC_INTP_START + (l_procNum * PROC_INTP_SIZE );


    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcNxMmioBarEnable(
                                    const fapi::Target * i_pTarget,
                                    uint8_t     &o_nxMmioBarEnable )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_NX_MMIO_BAR_ENABLE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_NX_MMIO_BAR_ENABLE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        o_nxMmioBarEnable   =   l_isEnabled;

    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcNxMmioBarBaseAddr (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_nxMmioBarBase )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_NX_MMIO_BAR_BASE_ADDR_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                  fapi::MOD_ATTR_PROC_NX_MMIO_BAR_BASE_ADDR_GET,
                                  l_procNum,
                                  l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

          o_nxMmioBarBase   =   PROC_RNG_START + (l_procNum * PROC_RNG_SIZE );

    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcNxMmioBarSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_nxMmioBarSize )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_NX_MMIO_BAR_SIZE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                  fapi::MOD_ATTR_PROC_NX_MMIO_BAR_SIZE_GET,
                                  l_procNum,
                                  l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

          o_nxMmioBarSize   =   PROC_RNG_SIZE ;

    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcPcieBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t     (&o_pcieBarEnable) [3][3] )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_PCIE_BAR_ENABLE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_PCIE_BAR_ENABLE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }


        //  BAR # 0 are the PCIE unit #'s
        //  BAR # 1 is reserved, should be DISabled (per Joe McGill)
        //  BAR # 2 are the PHB REGS
        for( uint8_t u=0; u<3; u++ )
        {
            o_pcieBarEnable[u][0]   =   l_isEnabled ;
            o_pcieBarEnable[u][1]   =   PROC_BARS_DISABLE ;
            o_pcieBarEnable[u][2]   =   l_isEnabled ;

            FAPI_DBG( "fapiPlatGetProcPcieBarEnable: Unit %d : %p %p %p",
                      u,
                      o_pcieBarEnable[u][0],
                      o_pcieBarEnable[u][1],
                      o_pcieBarEnable[u][2]    );
        }

    }   while(0);

    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcPcieBarBaseAddr (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    (&o_pcieBarBase) [3][3] )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_PCIE_BAR_BASE_ADDR_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_PCIE_BAR_BASE_ADDR_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        //  BAR # 0 are the PCIE unit #'s
        //  BAR # 1 is disabled, set to 0
        //  BAR # 2 are the PHB REGS
        for ( uint8_t u=0; u < 3; u++ )
        {
           o_pcieBarBase[u][0]  =  ( PCI_MEM_START +
                                      (u+(l_procNum*4)) * PCI_MEM_SIZE );
           o_pcieBarBase[u][1]  =   0;
           o_pcieBarBase[u][2]  =   ( PHB_REGS_START +
                                       (u+(l_procNum*4)) * PHB_REGS_SIZE );

           FAPI_DBG( "fapiPlatGetProcPcieBarBaseAddr: Unit %d : %p %p %p",
                     u,
                     o_pcieBarBase[u][0],
                     o_pcieBarBase[u][1],
                     o_pcieBarBase[u][2]    );
        }

    }   while(0);


    return  l_fapirc;
}

fapi::ReturnCode fapiPlatGetProcPcieBarSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    (&o_pcieBarSize) [3][3] )
{
    fapi::ReturnCode l_fapirc( fapi::FAPI_RC_SUCCESS );
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do  {
        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_PROC_PCIE_BAR_SIZE_GET
         *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
         *  @devdesc    Null FAPI Target passed to ATTR_GET
         */
        l_fapirc    =   barsPreCheck( i_pTarget,
                                      fapi::MOD_ATTR_PROC_PCIE_BAR_SIZE_GET,
                                      l_procNum,
                                      l_isEnabled );
        if ( l_fapirc )
        {
            FAPI_ERR("ERROR : NULL FAPI Target");
            break;
        }

        //  Just support proc 0 , 1 for now.
        if ( l_procNum > 1 )
        {
            /*@
             *  @errortype
             *  @moduleid   MOD_ATTR_PROC_PCIE_BAR_SIZE_GET
             *  @reasoncode RC_ATTR_UNSUPPORTED_PROC_NUM
             *  @devdesc    Null FAPI Target passed to ATTR_GET
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                fapi::MOD_ATTR_PROC_PCIE_BAR_SIZE_GET,
                fapi::RC_ATTR_UNSUPPORTED_PROC_NUM );
            l_fapirc.setPlatError(reinterpret_cast<void *> (l_pError));
            break;
        }

        //  NOTE: supported BAR0/1 sizes are from 64KB-1PB
        //  NOTE: BAR1 is disabled, set to 0
        //  NOTE: only supported BAR2 size is 4KB
        for ( uint8_t u=0; u < 3; u++ )
        {
           o_pcieBarSize[u][0]  =   PCIE_BAR0_SIZE ;
           o_pcieBarSize[u][1]  =   0 ;
           o_pcieBarSize[u][2]  =   PCIE_BAR2_SIZE;

           FAPI_DBG( "fapiPlatGetProcPcieBarSize: Unit %d : %p %p %p",
                     u,
                     o_pcieBarSize[u][0],
                     o_pcieBarSize[u][1],
                     o_pcieBarSize[u][2]    );
        }

    }   while(0);


    return  l_fapirc;
}

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
