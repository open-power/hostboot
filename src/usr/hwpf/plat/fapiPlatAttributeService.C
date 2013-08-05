/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatAttributeService.C $                */
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
 *  @file fapiPlatAttributeService.C
 *
 *  @brief Implements the functions that access attributes
 *
 */

//******************************************************************************
// Includes
//******************************************************************************

#include <hwpf/fapi/fapiTarget.H>
#include <hwpf/fapi/fapiHwpExecutor.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlentry.H>
#include <hwpf/plat/fapiPlatAttributeService.H>
#include <hwpf/hwpf_reasoncodes.H>
#include <vpd/spdenums.H>
#include <devicefw/driverif.H>
#include <hwpf/hwp/mvpd_accessors/getMvpdExL2SingleMemberEnable.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdPhaseRotatorData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdAddrMirrorData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdTermData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdSlopeInterceptData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdSpareDramData.H>

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
// fapi::platAttrSvc::getTargetingTarget
//******************************************************************************
fapi::ReturnCode getTargetingTarget(
    const fapi::Target* i_pFapiTarget,
    TARGETING::Target* & o_pTarget,
    const TARGETING::TYPE i_expectedType = TARGETING::TYPE_NA)
{
    fapi::ReturnCode l_rc;

    if (i_pFapiTarget == NULL)
    {
        TARGETING::targetService().getTopLevelTarget(o_pTarget);
    }
    else
    {
        o_pTarget = reinterpret_cast<TARGETING::Target*>(i_pFapiTarget->get());
    }

    if (o_pTarget == NULL)
    {
        // FAPI Target contained a NULL Targ handle or no top level target!
        FAPI_ERR("getTargetingTarget. NULL Targ Target");

        /*@
         *  @errortype
         *  @moduleid   MOD_ATTR_GET_TARGETING_TARGET
         *  @reasoncode RC_EMBEDDED_NULL_TARGET_PTR
         *  @devdesc    NULL TARG Target passed to attribute access macro
         */
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            MOD_ATTR_GET_TARGETING_TARGET,
            RC_EMBEDDED_NULL_TARGET_PTR);
        l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
    }
    else if (i_expectedType != TARGETING::TYPE_NA)
    {
        TARGETING::TYPE l_type = o_pTarget->getAttr<TARGETING::ATTR_TYPE>();

        if (l_type != i_expectedType)
        {
            FAPI_ERR("getTargetingTarget. Type: %d, expected %d", l_type,
                     i_expectedType);

            /*@
             *  @errortype
             *  @moduleid   MOD_ATTR_GET_TARGETING_TARGET
             *  @reasoncode RC_UNEXPECTED_TARGET_TYPE
             *  @userdata1  Target Type
             *  @userdata2  Expected Target Type
             *  @devdesc    Unexpected Target Type passed to attribute access
             *              macro
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_ATTR_GET_TARGETING_TARGET,
                RC_UNEXPECTED_TARGET_TYPE,
                l_type, i_expectedType);
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }
    }

    return l_rc;
}

//******************************************************************************
// fapi::platAttrSvc::getTargetingAttr
//******************************************************************************
fapi::ReturnCode getTargetingAttr(const fapi::Target * i_pFapiTarget,
                                  const TARGETING::ATTRIBUTE_ID i_targAttrId,
                                  const uint32_t i_attrSize,
                                  void * o_pAttr)
{
    TARGETING::Target * l_pTargTarget = NULL;

    fapi::ReturnCode l_rc = getTargetingTarget(i_pFapiTarget, l_pTargTarget);

    if (l_rc)
    {
        FAPI_ERR("getTargetingAttr: Error from getTargetingTarget");
    }
    else
    {
        // Note directly calling Target's private _tryGetAttr function for code
        // size optimization, the public function is a template function that
        // cannot be called with a variable attribute ID, the template function
        // checks at compile time that the Targeting attribute is readable, but
        // that is already checked by the Targeting compiler
        bool l_success = l_pTargTarget->_tryGetAttr(i_targAttrId, i_attrSize,
                                                    o_pAttr);

        if (!l_success)
        {
            FAPI_ERR("getTargetingAttr: Error from _tryGetAttr");
            /*@
             *  @errortype
             *  @moduleid   MOD_PLAT_ATTR_SVC_GET_TARG_ATTR
             *  @reasoncode RC_FAILED_TO_ACCESS_ATTRIBUTE
             *  @userdata1  Platform attribute ID
             *  @userdata2  FAPI target type, or NULL if system target
             *  @devdesc    Failed to get requested attribute.
             *      Possible causes: Invalid target, attribute not implemented,
             *          attribute not present on given target, target service
             *          not initialized
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_PLAT_ATTR_SVC_GET_TARG_ATTR,
                RC_FAILED_TO_ACCESS_ATTRIBUTE,
                i_targAttrId,
                i_pFapiTarget ? i_pFapiTarget->getType(): NULL);

            l_rc.setPlatError(reinterpret_cast<void *>(l_pError));
        }
    }

    return l_rc;
}

//******************************************************************************
// fapi::platAttrSvc::setTargetingAttr
//******************************************************************************
fapi::ReturnCode setTargetingAttr(const fapi::Target * i_pFapiTarget,
                                  const TARGETING::ATTRIBUTE_ID i_targAttrId,
                                  const uint32_t i_attrSize,
                                  void * i_pAttr)
{
    TARGETING::Target * l_pTargTarget = NULL;

    fapi::ReturnCode l_rc = getTargetingTarget(i_pFapiTarget, l_pTargTarget);

    if (l_rc)
    {
        FAPI_ERR("setTargetingAttr: Error from getTargetingTarget");
    }
    else
    {
        // Note directly calling Target's private _trySetAttr function for code
        // size optimization, the public function is a template function that
        // cannot be called with a variable attribute ID, the template function
        // checks at compile time that the Targeting attribute is writeable, but
        // that is already checked by the Targeting compiler
        bool l_success = l_pTargTarget->_trySetAttr(i_targAttrId, i_attrSize,
                                                    i_pAttr);

        if (!l_success)
        {
            FAPI_ERR("setTargetingAttr: Error from _trySetAttr");
            /*@
             *  @errortype
             *  @moduleid   MOD_PLAT_ATTR_SVC_SET_TARG_ATTR
             *  @reasoncode RC_FAILED_TO_ACCESS_ATTRIBUTE
             *  @userdata1  Platform attribute ID
             *  @userdata2  FAPI target type, or NULL if system target
             *  @devdesc    Failed to Set requested attribute.
             *      Possible causes: Invalid target, attribute not implemented,
             *          attribute not present on given target, target service
             *          not initialized
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_PLAT_ATTR_SVC_SET_TARG_ATTR,
                RC_FAILED_TO_ACCESS_ATTRIBUTE,
                i_targAttrId,
                i_pFapiTarget ? i_pFapiTarget->getType(): NULL);

            l_rc.setPlatError(reinterpret_cast<void *>(l_pError));
        }
    }

    return l_rc;
}

//******************************************************************************
// fapiPlatGetSpdAttr function.
// Call SPD device driver to retrieve the SPD attribute
//******************************************************************************
fapi::ReturnCode fapiPlatGetSpdAttr(const fapi::Target * i_pFapiTarget,
                                    const uint16_t i_keyword,
                                    void * o_data, const size_t i_len)
{
    FAPI_DBG(ENTER_MRK "fapiPlatGetSpdAttr");

    fapi::ReturnCode l_rc;
    TARGETING::Target* l_pTarget = NULL;

    l_rc = getTargetingTarget(i_pFapiTarget, l_pTarget, TARGETING::TYPE_DIMM);

    if (l_rc)
    {
        FAPI_ERR("fapiPlatGetSpdAttr: Error from getTargetingTarget");
    }
    else
    {
        errlHndl_t l_err = NULL;
        size_t l_len = i_len;
        l_err = deviceRead(l_pTarget, o_data, l_len,
                           DEVICE_SPD_ADDRESS(i_keyword));

        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            FAPI_ERR("fapiPlatGetSpdAttr: deviceRead() returns error");
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
        }
        else
        {
            if ((i_len == sizeof(uint32_t)) && (l_len == sizeof(uint16_t)))
            {
                // This is a uint16_t attribute written to a uint32_t type.
                // This is because FAPI attributes can only be uint8/32/64
                // Shift the data to be right aligned
                *(static_cast<uint32_t *>(o_data)) >>= 16;
            }
        }
    }

    FAPI_DBG(EXIT_MRK "fapiPlatGetSpdAttr");
    return l_rc;
}

//******************************************************************************
// fapiPlatSetSpdAttr function.
// Call SPD device driver to set the SPD attribute
//******************************************************************************
fapi::ReturnCode fapiPlatSetSpdAttr(const fapi::Target * i_pFapiTarget,
                                    const uint16_t i_keyword,
                                    void * i_data, const size_t i_len)
{
    FAPI_DBG(ENTER_MRK "fapiPlatSetSpdAttr");

    fapi::ReturnCode l_rc;
    TARGETING::Target* l_pTarget = NULL;

    l_rc = getTargetingTarget(i_pFapiTarget, l_pTarget, TARGETING::TYPE_DIMM);

    if (l_rc)
    {
        FAPI_ERR("fapiPlatSetSpdAttr: Error from getTargetingTarget");
    }
    else
    {
        errlHndl_t l_err = NULL;
        size_t l_len = i_len;
        l_err = deviceWrite(l_pTarget, i_data, l_len,
                            DEVICE_SPD_ADDRESS(i_keyword));

        if (l_err)
        {
            // Add the error log pointer as data to the ReturnCode
            FAPI_ERR("fapiPlatSetSpdAttr: deviceWrite() returns error");
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
        }
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

    l_rc = getTargetingTarget(i_pMcsTarget, o_pMcsTarget, TARGETING::TYPE_MCS);

    if (l_rc)
    {
        FAPI_ERR(
            "fapiPlatBaseAddrCheckMcsGetChip: Error from getTargetingTarget");
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
            /*@
             *  @errortype
             *  @moduleid   MOD_ATTR_BASE_ADDR_GET
             *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
             *  @devdesc    Failed to get MCS base address attribute due to
             *              bad target parameter.
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_ATTR_BASE_ADDR_GET,
                RC_ATTR_BAD_TARGET_PARAM);
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }
        else
        {
            o_pChipTarget = l_parentList[0];
        }
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
fapi::ReturnCode fapiPlatGetDqMapping(const fapi::Target * i_pDimmFapiTarget,
                                      uint8_t (&o_data)[DIMM_DQ_NUM_DQS])
{
    fapi::ReturnCode l_rc;
    TARGETING::Target * l_pDimmTarget = NULL;

    l_rc = getTargetingTarget(i_pDimmFapiTarget, l_pDimmTarget,
                              TARGETING::TYPE_DIMM);

    if (l_rc)
    {
        FAPI_ERR("fapiPlatGetDqMapping: Error from getTargetingTarget");
    }
    else
    {
        if (l_pDimmTarget->getAttr<TARGETING::ATTR_MODEL>() ==
            TARGETING::MODEL_CDIMM)
        {
            // C-DIMM. There is no DQ mapping from Centaur DQ to DIMM Connector
            // DQ because there is no DIMM Connector. Return a direct 1:1 map
            // (0->0, 1->1, etc)
            for (uint8_t i = 0; i < DIMM_DQ_NUM_DQS; i++)
            {
                o_data[i] = i;
            }
        }
        else
        {
            // IS-DIMM. Get the mapping using a Hostboot attribute. Note that
            // getAttr() cannot be used to get an array attribute so using
            // tryGetAttr and ignoring result
            l_pDimmTarget->
                tryGetAttr<TARGETING::ATTR_CEN_DQ_TO_DIMM_CONN_DQ>(o_data);
        }
    }

    return l_rc;
}

//******************************************************************************
// fapiPlatGetTargetName function
//******************************************************************************
fapi::ReturnCode fapiPlatGetTargetName(const fapi::Target * i_pFapiTarget,
                                       uint8_t & o_name)
{
    fapi::ReturnCode l_rc;
    TARGETING::Target * l_pHbTarget = NULL;
    o_name = ENUM_ATTR_NAME_NONE;

    l_rc = getTargetingTarget(i_pFapiTarget, l_pHbTarget);

    if (l_rc)
    {
        FAPI_ERR("fapiPlatGetTargetName: Error from getTargetingTarget");
    }
    else
    {
        TARGETING::MODEL l_model =
            l_pHbTarget->getAttr<TARGETING::ATTR_MODEL>();

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

            /*@
             *  @errortype
             *  @moduleid   MOD_ATTR_GET_TARGET_NAME
             *  @reasoncode RC_ATTR_BAD_TARGET_PARAM
             *  @devdesc    Failed to get the Target name due to bad target
             *              parameter.
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_ATTR_GET_TARGET_NAME,
                RC_ATTR_BAD_TARGET_PARAM);
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
        }
    }

    return l_rc;
}

//******************************************************************************
// fapiPlatGetFunctional function
//******************************************************************************
fapi::ReturnCode fapiPlatGetFunctional(const fapi::Target * i_pFapiTarget,
                                       uint8_t & o_functional)
{
    fapi::ReturnCode l_rc;
    TARGETING::Target * l_pHbTarget = NULL;
    o_functional = 0;

    l_rc = getTargetingTarget(i_pFapiTarget, l_pHbTarget);

    if (l_rc)
    {
        FAPI_ERR("fapiPlatGetFunctional: Error from getTargetingTarget");
    }
    else
    {
        TARGETING::PredicateIsFunctional l_functional;
        if (l_functional(l_pHbTarget))
        {
            o_functional = 1;
        }
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

    // Get the Targeting Target
    l_rc = getTargetingTarget(i_pFapiTarget, l_pTarget);

    if (l_rc)
    {
        FAPI_ERR("getTargetName: Error from getTargetingTarget");
    }
    else
    {
        uint16_t l_pos = l_pTarget->getAttr<TARGETING::ATTR_POSITION>();
        o_pos = l_pos;
    }

    return l_rc;
}

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
 *  @param[in]  -   i_pFapiTarget incoming target
 *  @param[out] -   o_procNum     found processor number of i_pTarget
 *  @apram[out] -   o_isEnabled   ENABLE/DISABLE flag for BAR_ENABLE ATTRS
 *  @return     -   success or appropriate fapi returncode
*/
fapi::ReturnCode barsPreCheck( const fapi::Target * i_pFapiTarget,
                               uint64_t             &o_procNum,
                               uint8_t              &o_isEnabled
                              )
{
    fapi::ReturnCode l_rc;
    TARGETING::Target* l_pTarget = NULL;

    l_rc = getTargetingTarget(i_pFapiTarget, l_pTarget);

    if (l_rc)
    {
        FAPI_ERR("barsPreCheck: Error from getTargetingTarget");
    }
    else
    {
        //  ATTR_POSITION should return the logical proc ID
        o_procNum  =
            static_cast<uint64_t>
                (l_pTarget->getAttr<TARGETING::ATTR_POSITION>() );

        //  if proc is functional then set the BAR_ENABLE ATTR to ENABLE
        TARGETING::PredicateIsFunctional l_functional;
        if (l_functional(l_pTarget))
        {
            o_isEnabled = PROC_BARS_ENABLE;
        }
        else
        {
            o_isEnabled = PROC_BARS_DISABLE;
        }
    }

    return  l_rc;
}


//------------------------------------------------------------------------------
// Routines to support  proc_setup_bars_memory_attributes
//  See proc_setup_bars_memory_attributes.xml for detailed descriptions
//------------------------------------------------------------------------------

fapi::ReturnCode fapiPlatGetProcMemBase(
                                       const fapi::Target * i_pTarget,
                                       uint64_t   &o_memBase )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    FAPI_DBG( "fapiPlatGetProcMemBase: entry" ) ;

    do
    {
        o_memBase   =   0;
        l_rc = barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
        if ( l_rc )
        {
            FAPI_ERR("fapiPlatGetProcMemBase: Error from barsPreCheck");
            break;
        }

        //  To match with fapiPlatGetMemoryBaseAddr
        //      0 for proc 0,  64TB for proc1, etc.
        o_memBase = ( l_procNum * 1024 * 1024 * 1024 * 1024 * 64 ) ;
        FAPI_DBG( "fapiPlatGetProcMemBase: proc %d memBase=0x%016llx",
                  l_procNum, o_memBase );

    } while (0);

    FAPI_DBG( "fapiPlatGetProcMemBase: exit" ) ;

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcMirrorBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_mirrorMemBase )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do
    {
        o_mirrorMemBase   =   0;
        l_rc = barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
        if (l_rc)
        {
            FAPI_ERR("fapiPlatGetProcMirrorBase: Error from barsPreCheck");
            break;
        }

        //  To match with fapiPlatGetMemoryBaseAddr
        //      512TB for proc 0,  512TB + 32TB * N for procN, etc.
        o_mirrorMemBase = ( 512 * 1024 * 1024 ) ;
        o_mirrorMemBase *= ( 1024 * 1024 );
        o_mirrorMemBase += ( (l_procNum) * 32 * 1024 * 1024 * 1024 * 1024 ) ;
        FAPI_DBG( "fapiPlatGetMirrorMemBase: proc %d mirrorMemBase=0x%016llx",
                  l_procNum, o_mirrorMemBase );

    } while (0);

    return  l_rc;
}


fapi::ReturnCode fapiPlatGetProcForeignNearBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignNearBase)[ 2 ] )
{
    fapi::ReturnCode    l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do
    {
        l_rc = barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
        if ( l_rc )
        {
            FAPI_ERR("fapiPlatGetProcForeignNearBase: Error from barsPreCheck");
            break;
        }

        // 2012-06-25 Per Dean return 0 here for now
        o_foreignNearBase[0]    =   0;
        o_foreignNearBase[1]    =   0;

    }   while (0);

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcForeignNearSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignNearSize)[ 2 ] )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do
    {
        l_rc = barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
        if ( l_rc )
        {
            FAPI_ERR("fapiPlatGetProcForeignNearSize: Error from barsPreCheck");
            break;
        }

        // 2012-06-25 Per Dean return 0 here for now
        o_foreignNearSize[0]    =   0;
        o_foreignNearSize[1]    =   0;

    }   while(0);

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcForeignFarBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignFarBase)[ 2 ] )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do
    {
        l_rc = barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
        if ( l_rc )
        {
            FAPI_ERR("fapiPlatGetProcForeignFarBase: Error from barsPreCheck");
            break;
        }

        // 2012-06-25 Per Dean return 0 here for now
        o_foreignFarBase[0]    =   0;
        o_foreignFarBase[1]    =   0;

    }   while(0);

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcForeignFarSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_foreignFarSize)[ 2 ] )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do
    {
        l_rc = barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
        if ( l_rc )
        {
            FAPI_ERR("fapiPlatGetProcForeignFarSize: Error from barsPreCheck");
            break;
        }

        // 2012-06-25 Per Dean return 0 here for now
        o_foreignFarSize[0]    =   0;
        o_foreignFarSize[1]    =   0;

    }   while(0);

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcHaBase (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_haBase)[ 8 ] )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do
    {
        l_rc = barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
        if ( l_rc )
        {
            FAPI_ERR("fapiPlatGetProcHaBase: Error from barsPreCheck");
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

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcHaSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t (&o_haSize)[ 8 ] )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    do
    {
        l_rc = barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
        if ( l_rc )
        {
            FAPI_ERR("fapiPlatGetProcHaSize: Error from barsPreCheck");
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

    return  l_rc;
}


//------------------------------------------------------------------------------
//  Prototypes to support proc_setup_bars_mmio_attributes
//  see proc_setup_bars_mmio_attributes for detailed descriptions
//------------------------------------------------------------------------------

fapi::ReturnCode fapiPlatGetProcPsiBridgeBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t     &o_psiBridgeBarEnable )
{
    fapi::ReturnCode l_rc;
    o_psiBridgeBarEnable =   PROC_BARS_DISABLE;
    TARGETING::Target* l_pProcTarget = NULL;

    l_rc = getTargetingTarget(i_pTarget, l_pProcTarget);

    if (l_rc)
    {
        FAPI_ERR(
            "fapiPlatGetProcPsiBridgeBarEnable: Error from getTargetingTarget");
    }
    else
    {
        uint64_t bar = l_pProcTarget->getAttr<TARGETING::ATTR_PSI_BRIDGE_BASE_ADDR>();

        //  if bar is not zero
        if ( bar )
        {
            o_psiBridgeBarEnable =   PROC_BARS_ENABLE;
        }
    }

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcFspBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t     &o_fspBarEnable )
{
    fapi::ReturnCode l_rc;
    o_fspBarEnable =   PROC_BARS_DISABLE;
    TARGETING::Target* l_pProcTarget = NULL;

    l_rc = getTargetingTarget(i_pTarget, l_pProcTarget);

    if (l_rc)
    {
        FAPI_ERR(
            "fapiPlatGetProcFspBarEnable: Error from getTargetingTarget");
    }
    else
    {
        uint64_t bar = l_pProcTarget->getAttr<TARGETING::ATTR_FSP_BASE_ADDR>();

        //  if bar is not zero
        if ( bar )
        {
            o_fspBarEnable =   PROC_BARS_ENABLE;
        }
    }

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcIntpBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t    &o_intpBarEnable )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    l_rc    =   barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
    if ( l_rc )
    {
        FAPI_ERR("fapiPlatGetProcIntpBarEnable: Error from barsPreCheck");
    }
    else
    {
        o_intpBarEnable =   l_isEnabled;
    }

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcNxMmioBarEnable(
                                    const fapi::Target * i_pTarget,
                                    uint8_t     &o_nxMmioBarEnable )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    l_rc    =   barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
    if ( l_rc )
    {
        FAPI_ERR("fapiPlatGetProcNxMmioBarEnable: Error from barsPreCheck");
    }
    else
    {
        o_nxMmioBarEnable   =   l_isEnabled;
    }

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcNxMmioBarSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    &o_nxMmioBarSize )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    l_rc    =   barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
    if ( l_rc )
    {
        FAPI_ERR("fapiPlatGetProcNxMmioBarSize: Error from barsPreCheck");
    }
    else
    {
        o_nxMmioBarSize   =   PROC_RNG_SIZE ;
    }

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcPcieBarEnable (
                                    const fapi::Target * i_pTarget,
                                    uint8_t     (&o_pcieBarEnable) [3][3] )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    l_rc    =   barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
    if ( l_rc )
    {
        FAPI_ERR("fapiPlatGetProcPcieBarEnable: Error from barsPreCheck");
    }
    else
    {
        // In PHYP mode, we need to leave the PCI BARs disabled
        bool phyp_mode = false;
        if( TARGETING::is_phyp_load() )
        {
            phyp_mode = true;
        }

        //  BAR # 0 are the PCIE unit #'s
        //  BAR # 1 is reserved, should be DISabled (per Joe McGill)
        //  BAR # 2 are the PHB REGS
        for( uint8_t u=0; u<3; u++ )
        {
            if( phyp_mode )
            {
                o_pcieBarEnable[u][0]   =   PROC_BARS_DISABLE ;
                o_pcieBarEnable[u][1]   =   PROC_BARS_DISABLE ;
                o_pcieBarEnable[u][2]   =   PROC_BARS_DISABLE ;
            }
            else
            {
                o_pcieBarEnable[u][0]   =   l_isEnabled ;
                o_pcieBarEnable[u][1]   =   PROC_BARS_DISABLE ;
                o_pcieBarEnable[u][2]   =   l_isEnabled ;
            }

            FAPI_DBG( "fapiPlatGetProcPcieBarEnable: Unit %d : %p %p %p",
                      u,
                      o_pcieBarEnable[u][0],
                      o_pcieBarEnable[u][1],
                      o_pcieBarEnable[u][2]    );
        }
    }

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcPcieBarBaseAddr (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    (&o_pcieBarBase) [3][3] )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    l_rc = barsPreCheck(i_pTarget, l_procNum, l_isEnabled);

    if ( l_rc )
    {
        FAPI_ERR("fapiPlatGetProcPcieBarBaseAddr: Error from barsPreCheck");
    }
    else
    {
        TARGETING::Target* l_pProcTarget = NULL;

        l_rc = getTargetingTarget(i_pTarget, l_pProcTarget);

        if (l_rc)
        {
            FAPI_ERR("fapiPlatGetProcPcieBarBaseAddr: Error from getTargetingTarget");
        }
        else
        {
            // Pull the data out of the Hostboot attribute
            uint64_t l_pciMem[4];
            l_pProcTarget->tryGetAttr<TARGETING::ATTR_PCI_BASE_ADDRS>(
                l_pciMem);
            uint64_t l_phbRegs[4];
            l_pProcTarget->tryGetAttr<TARGETING::ATTR_PHB_BASE_ADDRS>(
                l_phbRegs);

            //  BAR # 0 are the PCIE unit #'s
            //  BAR # 1 is disabled, set to 0
            //  BAR # 2 are the PHB REGS
            for ( uint8_t u=0; u < 3; u++ )
            {
               o_pcieBarBase[u][0]  =  l_pciMem[u];
               o_pcieBarBase[u][1]  =  0;
               o_pcieBarBase[u][2]  =  l_phbRegs[u];

               FAPI_DBG( "fapiPlatGetProcPcieBarBaseAddr: Unit %d : %p %p %p",
                         u,
                         o_pcieBarBase[u][0],
                         o_pcieBarBase[u][1],
                         o_pcieBarBase[u][2]    );
            }
        }
    }

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetProcPcieBarSize (
                                    const fapi::Target * i_pTarget,
                                    uint64_t    (&o_pcieBarSize) [3][3] )
{
    fapi::ReturnCode l_rc;
    uint64_t    l_procNum       =   0;
    uint8_t     l_isEnabled     =   PROC_BARS_DISABLE;

    l_rc    =   barsPreCheck(i_pTarget, l_procNum, l_isEnabled);
    if ( l_rc )
    {
        FAPI_ERR("fapiPlatGetProcPcieBarSize: Error from barsPreCheck");
    }
    else
    {
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
    }

    return  l_rc;
}

fapi::ReturnCode fapiPlatGetSingleMemberEnableAttr(
    const fapi::Target * i_pTarget,
    uint32_t & o_val)
{
    // Call a VPD Accessor HWP to get the data
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getMvpdExL2SingleMemberEnable, *i_pTarget, o_val);
    return l_rc;
}

fapi::ReturnCode fapiPlatGetPhaseRotatorData (
             const fapi::Target * i_pTarget,
             const fapi::MBvpdPhaseRotatorData i_attr,
             uint8_t    (&o_val) [2] )
{
    // Call a VPD Accessor HWP to get the data
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getMBvpdPhaseRotatorData, *i_pTarget, i_attr, o_val);
    return l_rc;
}

fapi::ReturnCode fapiPlatGetAddrMirrorData (
             const fapi::Target * i_pFapiTarget,
             uint8_t    &o_val )
{
    fapi::ReturnCode l_rc;
    TARGETING::Target * l_pTarget = NULL;
    TARGETING::TargetHandleList l_mbaList;
    uint8_t l_val[2][2] = {{0xFF,0xFF},{0xFF,0xFF}};

    do {
        // Get the Targeting Target
        l_rc = getTargetingTarget(i_pFapiTarget, l_pTarget);
        if (l_rc)
        {
            FAPI_ERR("fapiPlatGetAddrMirrorData:Error from getTargetingTarget");
            break;
        }

        // Find the port and DIMM position
        TARGETING::ATTR_MBA_PORT_type l_portPos =
                          l_pTarget->getAttr<TARGETING::ATTR_MBA_PORT>();
        TARGETING::ATTR_MBA_DIMM_type l_dimmPos =
                          l_pTarget->getAttr<TARGETING::ATTR_MBA_DIMM>();

        // Find MBA target from DIMM target
        getParentAffinityTargets (l_mbaList, l_pTarget, TARGETING::CLASS_UNIT,
                                  TARGETING::TYPE_MBA, false);

        if (l_mbaList.size () != 1 )
        {
            FAPI_ERR("fapiPlatGetAddrMirrorData: expect 1 mba %d ",
               l_mbaList.size());

            /*@
             * @errortype
             * @moduleid     fapi::MOD_PLAT_ATTR_SVC_GET_MIRR_DATA
             * @reasoncode   fapi::RC_NO_SINGLE_MBA
             * @userdata1    Number of MBAs
             * @devdesc      fapiPlatGetAddrMirrorData could not find the
             *               expected 1 mba from the passed dimm target
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_PLAT_ATTR_SVC_GET_MIRR_DATA,
                fapi::RC_NO_SINGLE_MBA,
                l_mbaList.size());

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
            break;
        }

        // Get the Fapi Target
        fapi::Target l_fapiTarget(TARGET_TYPE_MBA_CHIPLET,
                    static_cast<void *>(l_mbaList[0]));

        // Get the data using the HWP accessor
        FAPI_EXEC_HWP(l_rc, getMBvpdAddrMirrorData, l_fapiTarget, l_val);
        if (l_rc)
        {
            FAPI_ERR("fapiPlatGetAddrMirrorData:"
                     " Error from getMBvpdAddrMirrorData");
            break;
        }

        // return the address mirroring data for the passed DIMM
        o_val = l_val[l_portPos][l_dimmPos];

    } while (0);
    return l_rc;
}

fapi::ReturnCode fapiPlatGetTermData (
             const fapi::Target * i_pTarget,
             const fapi::MBvpdTermData i_attr,
             void  * o_pVal,
             const uint32_t i_valSize)
{
    // Call a VPD Accessor HWP to get the data
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getMBvpdTermData,
                        *i_pTarget, i_attr, o_pVal, i_valSize);
    return l_rc;
}

fapi::ReturnCode fapiPlatGetSlopeInterceptData (
             const fapi::Target * i_pTarget,
             const fapi::MBvpdSlopeIntercept i_attr,
             uint32_t  & o_Val)
{
    // Call a VPD Accessor HWP to get the data
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getMBvpdSlopeInterceptData,
                        *i_pTarget, i_attr, o_Val);
    return l_rc;
}


fapi::ReturnCode fapiPlatGetEnableAttr ( fapi::AttributeId i_id,
     const fapi::Target * i_pFapiTarget, uint8_t & o_enable )
{
    fapi::ReturnCode l_rc;
    TARGETING::Target * l_pTarget = NULL;

    // Get the Targeting Target
    l_rc = getTargetingTarget(i_pFapiTarget, l_pTarget);

    if (l_rc)
    {
        FAPI_ERR("fapiPlatGetEnableAttr: Error from getTargetingTarget");
    }
    else
    {
        TARGETING::TargetHandleList l_buses;
        switch (i_id)
        {
            case fapi::ATTR_PROC_NX_ENABLE:
            case fapi::ATTR_PROC_L3_ENABLE:
                // The enable flag is based on the target's functional state
                TARGETING::HwasState hwasState;
                hwasState = l_pTarget->getAttr<TARGETING::ATTR_HWAS_STATE>();
                o_enable = hwasState.functional;
                break;
            case fapi::ATTR_PROC_PCIE_ENABLE:
                // The enable flag is 1 if one of the pci target is functional
                getChildChiplets( l_buses, l_pTarget, TARGETING::TYPE_PCI );
                o_enable = l_buses.size() ? 1 : 0;
                break;
            case fapi::ATTR_PROC_A_ENABLE:
                // The enable flag is 1 if one of the abus target is functional
                getChildChiplets( l_buses, l_pTarget, TARGETING::TYPE_ABUS );
                o_enable = l_buses.size() ? 1 : 0;
                break;
            case fapi::ATTR_PROC_X_ENABLE:
                // The enable flag is 1 if one of the xbus target is functioanl
                getChildChiplets( l_buses, l_pTarget, TARGETING::TYPE_XBUS );
                o_enable = l_buses.size() ? 1 : 0;
                break;
            default:
                o_enable = 0;
                break;
        }
    }

    return l_rc;
}


//------------------------------------------------------------------------------
//  Functions to support BAD_DQ_BITMAP_attribute
//  See dimm_spd_attributes.xml for detailed descriptions
//------------------------------------------------------------------------------


/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the Bad DQ Bitmap attribute
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_data      Bad DIMM DQ Bitmap
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatDimmGetBadDqBitmap (
                                    const   fapi::Target * i_pTarget,
                                    uint8_t (&o_data)[DIMM_DQ_MAX_DIMM_RANKS]\
                                                     [DIMM_DQ_RANK_BITMAP_SIZE])
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, dimmBadDqBitmapAccessHwp, *i_pTarget, o_data, true);

    if (l_rc)
    {
        FAPI_ERR("dimmGetBadDqBitmap: "
                 "Error from dimmBadDqBitmapAccessHwp (get)");
    }
    return l_rc;
}


/**
 * @brief This function is called by the FAPI_ATTR_SET macro when setting
 * the Bad DQ Bitmap attribute
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[in]  i_data      Bad DIMM DQ Bitmap
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatDimmSetBadDqBitmap (
                                    const fapi::Target * i_pTarget,
                                    uint8_t (&i_data)[DIMM_DQ_MAX_DIMM_RANKS]\
                                                     [DIMM_DQ_RANK_BITMAP_SIZE])
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, dimmBadDqBitmapAccessHwp, *i_pTarget, i_data, false);

    if (l_rc)
    {
        FAPI_ERR("dimmSetBadDqBitmap: "
                 "Error from dimmBadDqBitmapAccessHwp (set)");
    }
    return l_rc;
}

//------------------------------------------------------------------------------
// Function to support VPD_DIMM_SPARE attribute
//  See dimm_spd_attributes.xml for detailed description
//------------------------------------------------------------------------------

/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting
 * the VPD DIMM Spare attribute
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   Target pointer
 *  @param[out] o_data      Spare DRAM availability for DIMM
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatDimmGetSpareDram (
                                    const fapi::Target * i_pTarget,
                                    uint8_t &o_data)
{

    fapi::ReturnCode l_rc;
    TARGETING::Target * l_pTarget = NULL;
    TARGETING::TargetHandleList l_mbaList;
    do
    {
        // Get the Targeting Target
        l_rc = getTargetingTarget(i_pTarget, l_pTarget);
        if (l_rc)
        {
            FAPI_ERR("fapiPlatDimmGetSpareDram:Error from getTargetingTarget");
            break;
        }

        // Find MBA target from DIMM target
        getParentAffinityTargets(l_mbaList, l_pTarget, TARGETING::CLASS_UNIT,
                                 TARGETING::TYPE_MBA, false);


        if (l_mbaList.size() != 1 )
        {
            FAPI_ERR("fapiPlatDimmGetSpareDram: expect 1 mba %d ",
               l_mbaList.size());

            /*@
             * @errortype
             * @moduleid     fapi::MOD_PLAT_ATTR_SVC_GET_SPARE_DATA
             * @reasoncode   fapi::RC_NO_SINGLE_MBA
             * @userdata1    Number of MBAs
             * @devdesc      fapiPlatDimmGetSpareDram could not find the
             *               expected 1 mba from the passed dimm target
             */
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_PLAT_ATTR_SVC_GET_SPARE_DATA,
                fapi::RC_NO_SINGLE_MBA,
                l_mbaList.size());

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
            break;
        }


        // Create the Fapi Target
        fapi::Target l_mbaTarget(TARGET_TYPE_MBA_CHIPLET,
                                 static_cast<void *>(l_mbaList[0]));


        FAPI_EXEC_HWP(l_rc, getMBvpdSpareDramData, l_mbaTarget, *i_pTarget,
                      o_data);

        if (l_rc)
        {
            FAPI_ERR("fapiPlatDimmGetSpareDram: "
                     "Error from getMBvpdSpareDramData");
            break;
        }

    }while(0);

    return l_rc;
}

} // End platAttrSvc namespace

} // End fapi namespace
