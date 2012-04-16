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

    // TODO
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

    // TODO
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

} // End platAttrSvc namespace

} // End fapi namespace
