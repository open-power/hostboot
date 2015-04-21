/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatAttributeService.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
#include <hwpf/hwp/mvpd_accessors/getMBvpdSlopeInterceptData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdSpareDramData.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdVersion.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdDram2NModeEnabled.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdSensorMap.H>
#include <hwpf/hwp/mvpd_accessors/getMBvpdAttr.H>
#include <hwpf/hwp/mvpd_accessors/accessMBvpdL4BankDelete.H>
#include <hwpf/hwp/chip_accessors/getTdpRdpCurrentFactor.H>
#include <hwpf/hwp/chip_accessors/getPciOscswitchConfig.H>
#include <hwpf/hwp/chip_accessors/getOscswitchCtlAttr.H>
#include <fapiPllRingAttr.H>
#include <hwpf/hwp/pll_accessors/getPllRingAttr.H>
#include <hwpf/hwp/pll_accessors/getPllRingInfoAttr.H>
#include <hwpf/hwp/winkle_ring_accessors/getL3DeltaDataAttr.H>
#include <hwpf/hwp/tp_dbg_data_accessors/getTpDbgDataAttr.H>
#include <fapiAttributeIds.H>
#include <hwas/common/hwasCommon.H>
#include <proc_setup_bars_defs.H>

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
        const bool hbSwError = true;
        errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            MOD_ATTR_GET_TARGETING_TARGET,
            RC_EMBEDDED_NULL_TARGET_PTR,
            0, 0, hbSwError);
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
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_ATTR_GET_TARGETING_TARGET,
                RC_UNEXPECTED_TARGET_TYPE,
                l_type, i_expectedType, hbSwError);
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
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_PLAT_ATTR_SVC_GET_TARG_ATTR,
                RC_FAILED_TO_ACCESS_ATTRIBUTE,
                i_targAttrId,
                i_pFapiTarget ? i_pFapiTarget->getType(): NULL,
                hbSwError);
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
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_PLAT_ATTR_SVC_SET_TARG_ATTR,
                RC_FAILED_TO_ACCESS_ATTRIBUTE,
                i_targAttrId,
                i_pFapiTarget ? i_pFapiTarget->getType(): NULL,
                hbSwError);
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
            FAPI_ERR("fapiPlatGetSpdAttr: Error from deviceRead, keyword 0x%04x, len %d",
                     i_keyword, i_len);
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
            FAPI_ERR("fapiPlatSetSpdAttr: Error from deviceWrite, keyword 0x%04x, len %d",
                     i_keyword, i_len);
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
        }
    }

    FAPI_DBG(EXIT_MRK "fapiPlatSetSpdAttr");
    return l_rc;
}

//******************************************************************************
// fapiPlatGetDqMapping function.
//******************************************************************************
fapi::ReturnCode fapiPlatGetDqMapping(const fapi::Target * i_pDimmFapiTarget,
                                      uint8_t (&o_data)[DIMM_DQ_NUM_DQS])
{
    fapi::ReturnCode l_rc;

    do
    {
        TARGETING::Target * l_pDimmTarget = NULL;

        l_rc = getTargetingTarget(i_pDimmFapiTarget, l_pDimmTarget,
                              TARGETING::TYPE_DIMM);

        if (l_rc)
        {
            FAPI_ERR("fapiPlatGetDqMapping: Error from getTargetingTarget");
            break;
        }

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
            // ISDIMM. Work back up from Dimm target to MBA to Mem Buf and
            // gather dimm position to select ATTR_VPD_ISDIMMTOC4DQ data

            // Get DIMM's Port position off the MBA
            uint8_t l_port=l_pDimmTarget->getAttr<TARGETING::ATTR_MBA_PORT>();

            // Find MBA from DIMM
            TARGETING::TargetHandleList l_mbaList;
            getParentAffinityTargets (l_mbaList,l_pDimmTarget,
                                  TARGETING::CLASS_UNIT,
                                  TARGETING::TYPE_MBA, false);

            if (l_mbaList.size () != 1 )
            {
                FAPI_ERR("fapiPlatGetDqMapping: expect 1 mba %d ",
                    l_mbaList.size());

                /*@
                 * @errortype
                 * @moduleid     fapi::MOD_PLAT_ATTR_SVC_CEN_DQ_TO_DIMM_CONN_DQ
                 * @reasoncode   fapi::RC_NO_SINGLE_MBA
                 * @userdata1    Number of MBAs
                 * @userdata2    DIMM HUID
                 * @devdesc      fapiPlatGetVpdVersion could not find the
                 *               expected 1 mba from the passed dimm target
                 */
                const bool hbSwError = true;
                errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    fapi::MOD_PLAT_ATTR_SVC_CEN_DQ_TO_DIMM_CONN_DQ,
                    fapi::RC_NO_SINGLE_MBA,
                    l_mbaList.size(),
                    TARGETING::get_huid(l_pDimmTarget),
                    hbSwError);

                // Attach the error log to the fapi::ReturnCode
                l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
                break;
            }
            fapi::Target l_fapiMbaTarget(TARGET_TYPE_MBA_CHIPLET,
                    static_cast<void *>(l_mbaList[0]));

            // Get MBA position off the Mem Buf
            uint8_t l_mbaPos = l_mbaList[0]->
                                    getAttr<TARGETING::ATTR_CHIP_UNIT>();

            // find mem buff
            fapi::Target l_fapiMbTarget;
            l_rc = fapiGetParentChip(l_fapiMbaTarget, l_fapiMbTarget);
            if (l_rc)
            {
                FAPI_ERR("fapiPlatGetDqMapping: Error getting MBA's parent ");
                break;
            }

            // Read wiring data
            uint8_t l_wiringData[DIMM_TO_C4_PORTS][DIMM_TO_C4_DQ_ENTRIES];
            l_rc = FAPI_ATTR_GET(ATTR_VPD_ISDIMMTOC4DQ,
                                    &l_fapiMbTarget,l_wiringData);
            if (l_rc)
            {
                FAPI_ERR("fapiPlatGetDqMapping:"
                                  " Error getting VPD_ISDIMMTOC4DQ data");
                break;
            }

            // Map data
            uint8_t l_index = l_mbaPos*2+l_port;
            for (uint8_t i = 0; i < DIMM_DQ_NUM_DQS; i++)
            {
                o_data[i] = l_wiringData[l_index][i];
            }
        }
    } while (0);

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
        else if (l_model == TARGETING::MODEL_NAPLES)
        {
            o_name = ENUM_ATTR_NAME_NAPLES;
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
             *  @devdesc    Failed to get the FAPI Target name due to
             *              unrecognized TARGETING Target model
             *  @userdata1  TARGETING Target model
             */
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_ATTR_GET_TARGET_NAME,
                RC_ATTR_BAD_TARGET_PARAM,
                l_model, 0, hbSwError);
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
                                    uint8_t     (&o_pcieBarEnable) [4][3] )
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

        //  BAR # 0 are the PCIE Mem 64
        //  BAR # 1 are the PCIE Mem 32
        //  BAR # 2 are the PHB REGS
        for( uint8_t u=0; u< PROC_SETUP_BARS_PCIE_NUM_UNITS; u++ )
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
                o_pcieBarEnable[u][1]   =   l_isEnabled ;
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
                                    uint64_t    (&o_pcieBarBase) [4][3] )
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
            uint64_t l_pciMem32[4];
            uint64_t l_pciMem64[4];
            l_pProcTarget->tryGetAttr<TARGETING::ATTR_PCI_BASE_ADDRS_32>(
                l_pciMem32);
            l_pProcTarget->tryGetAttr<TARGETING::ATTR_PCI_BASE_ADDRS_64>(
                l_pciMem64);
            uint64_t l_phbRegs[4];
            l_pProcTarget->tryGetAttr<TARGETING::ATTR_PHB_BASE_ADDRS>(
                l_phbRegs);

            //  BAR # 0 are the PCIE mem 64, 64GB window
            //  BAR # 1 are the PCIE mem 32, 2GB window
            //  BAR # 2 are the PHB REGS

            //If we are in sapphire mode we need to shift the PCI
            //Mem addresses down below the 48 bit limit for an NVIDA
            //adapter.  This is a workaround for GA1 so the adapter
            //can be supported.  Largest (theoretically dimm) is 1TB,
            //so max mem is ~32TB for non brazos system.

            //Place mem64 @ 59TB-63TB (0x00003B0000000000)
            //Place mem32 @ 63.875TB-64TB (0x00030FE000000000)

            //TODO RTC 100773 -- Fix this the correct way by
            //having base addresses per payload type

            //We will change the base addr down 4 bits, but need to keep
            //the proc/node offsets the same
            for ( uint8_t u=0; u < PROC_SETUP_BARS_PCIE_NUM_UNITS; u++ )
            {
               if(TARGETING::is_sapphire_load())
               {
                   o_pcieBarBase[u][0] = SAPPHIRE_PCIE_BAR0_BASE +
                                     (l_pciMem64[u] & PCIE_BAR0_OFFSET_MASK);
                   o_pcieBarBase[u][1] = SAPPHIRE_PCIE_BAR1_BASE +
                                     (l_pciMem32[u] & PCIE_BAR1_OFFSET_MASK);
               }
               else
               {
                   o_pcieBarBase[u][0] = l_pciMem64[u];
                   o_pcieBarBase[u][1] = l_pciMem32[u];
               }

               o_pcieBarBase[u][2] = l_phbRegs[u];

               FAPI_DBG( "fapiPlatGetProcPcieBarBaseAddr: Chip %x Unit %d : %p %p %p",
                         TARGETING::get_huid(l_pProcTarget),
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
                                    uint64_t    (&o_pcieBarSize) [4][3] )
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
        //  NOTE: only supported BAR2 size is 4KB
        for ( uint8_t u=0; u < PROC_SETUP_BARS_PCIE_NUM_UNITS; u++ )
        {
           o_pcieBarSize[u][0]  =   PCIE_BAR0_SIZE ;
           o_pcieBarSize[u][1]  =   PCIE_BAR1_SIZE ;
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

fapi::ReturnCode fapiPlatGetAddrMirrorData (
             const fapi::Target * i_pTarget,
             uint8_t   (& o_val) [2][2] )
{
    // Get the data using the HWP accessor
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getMBvpdAddrMirrorData, *i_pTarget, o_val);
    return l_rc;
}

fapi::ReturnCode fapiPlatGetAttrData (
             const fapi::Target * i_pTarget,
             const fapi::AttributeId i_attr,
             void  * o_pVal,
             const size_t i_valSize)
{
    // Call a VPD Accessor HWP to get the data
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getMBvpdAttr,
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

fapi::ReturnCode fapiPlatGetVpdVersion (
             const fapi::Target * i_pFapiTarget,
             uint32_t    &o_val )
{
    fapi::ReturnCode l_rc;
    TARGETING::Target * l_pTarget = NULL;
    TARGETING::TargetHandleList l_mbaList;

    do {
        // Get the Targeting Target
        l_rc = getTargetingTarget(i_pFapiTarget, l_pTarget);
        if (l_rc)
        {
            FAPI_ERR("fapiPlatGetVpdVersion: Error from getTargetingTarget");
            break;
        }

        // Find MBA target from DIMM target
        getParentAffinityTargets (l_mbaList, l_pTarget, TARGETING::CLASS_UNIT,
                                  TARGETING::TYPE_MBA, false);

        if (l_mbaList.size () != 1 )
        {
            FAPI_ERR("fapiPlatGetVpdVersion: expect 1 mba %d ",
               l_mbaList.size());

            /*@
             * @errortype
             * @moduleid     fapi::MOD_PLAT_ATTR_SVC_GET_VPD_VERSION
             * @reasoncode   fapi::RC_NO_SINGLE_MBA
             * @userdata1    Number of MBAs
             * @userdata2    DIMM HUID
             * @devdesc      fapiPlatGetVpdVersion could not find the
             *               expected 1 mba from the passed dimm target
             */
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_PLAT_ATTR_SVC_GET_VPD_VERSION,
                fapi::RC_NO_SINGLE_MBA,
                l_mbaList.size(),
                TARGETING::get_huid(l_pTarget),
                hbSwError);

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
            break;
        }

        // Get the Fapi Target
        fapi::Target l_fapiTarget(TARGET_TYPE_MBA_CHIPLET,
                    static_cast<void *>(l_mbaList[0]));

        // Get the data using the HWP accessor
        FAPI_EXEC_HWP(l_rc, getMBvpdVersion, l_fapiTarget, o_val);
        if (l_rc)
        {
            FAPI_ERR("fapiPlatGetVpdVersion:"
                     " Error from getMBvpdVersion");
            break;
        }

    } while (0);
    return l_rc;
}

fapi::ReturnCode fapiPlatGetDram2NModeEnabled (
             const fapi::Target * i_pFapiTarget,
             uint8_t    &o_val )
{
    // Get the data using the HWP accessor
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getMBvpdDram2NModeEnabled, * i_pFapiTarget, o_val);
    return l_rc;
}

fapi::ReturnCode fapiPlatGetSensorMap (
              const   fapi::Target * i_pFapiTarget,
              const   fapi::MBvpdSensorMap i_attr,
              uint8_t & o_val)
{
    // Get the data using the HWP accessor
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getMBvpdSensorMap, * i_pFapiTarget, i_attr, o_val);
    return l_rc;
}

fapi::ReturnCode fapiPlatL4BankDelete (
             const fapi::Target * i_pTarget,
             uint32_t  & io_val,
             const fapi::MBvpdL4BankDeleteMode i_mode)
{
    // Call a VPD Accessor HWP to get or set the data
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, accessMBvpdL4BankDelete,
                        *i_pTarget, io_val, i_mode);
    return l_rc;
}

fapi::ReturnCode fapiPlatGetEnableAttr ( fapi::AttributeId i_id,
     const fapi::Target * i_pFapiTarget, uint8_t & o_enable )
{
    fapi::ReturnCode l_rc;
    TARGETING::Target * l_pTarget = NULL;
    o_enable = 0;

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
                // The enable flag reflects the state of the pervasive chiplet,
                //  NOT the bus logic, so always return true since we don't
                //  support partial good on the ABUS chiplet
                o_enable = 1;
                break;
            case fapi::ATTR_PROC_X_ENABLE:
                // Need to support having the X bus chiplet partial good
                // Look at the saved away PG data
                TARGETING::ATTR_CHIP_REGIONS_TO_ENABLE_type l_chipRegionData;
                l_rc = FAPI_ATTR_GET(ATTR_CHIP_REGIONS_TO_ENABLE, i_pFapiTarget,
                                     l_chipRegionData);
                if (l_rc) {
                    FAPI_ERR("fapi_attr_get( ATTR_CHIP_REGIONS_TO_ENABLE ) failed. With rc = 0x%x",
                             (uint32_t) l_rc );
                    break;
                }
                else if (l_chipRegionData[HWAS::VPD_CP00_PG_XBUS_INDEX] != 0)
                {
                    o_enable = 0x1;
                }
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
 *  @param[in]  i_pTarget   DIMM target pointer
 *  @param[out] o_data      Bad DIMM DQ Bitmap
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatDimmGetBadDqBitmap (
                                    const   fapi::Target * i_pTarget,
                                    uint8_t (&o_data)[DIMM_DQ_MAX_DIMM_RANKS]\
                                                     [DIMM_DQ_RANK_BITMAP_SIZE])
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
            FAPI_ERR("fapiPlatDimmGetBadDqBitmap:Error from getTargetingTarget");
            break;
        }

        // Find MBA target from DIMM target
        getParentAffinityTargets(l_mbaList, l_pTarget, TARGETING::CLASS_UNIT,
                                 TARGETING::TYPE_MBA, false);


        if (l_mbaList.size() != 1 )
        {
            FAPI_ERR("fapiPlatDimmGetBadDqBitmap: expect 1 mba %d ",
               l_mbaList.size());

            /*@
             * @errortype
             * @moduleid     fapi::MOD_PLAT_ATTR_SVC_GET_BADDQ_DATA
             * @reasoncode   fapi::RC_NO_SINGLE_MBA
             * @userdata1    Number of MBAs
             * @userdata2    DIMM HUID
             * @devdesc      fapiPlatDimmGetBadDqBitmap could not find the
             *               expected 1 mba from the passed dimm target
             */
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_PLAT_ATTR_SVC_GET_BADDQ_DATA,
                fapi::RC_NO_SINGLE_MBA,
                l_mbaList.size(),
                TARGETING::get_huid(l_pTarget),
                hbSwError);

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
            break;
        }


        // Create the Fapi Target
        fapi::Target l_mbaTarget(TARGET_TYPE_MBA_CHIPLET,
                                 static_cast<void *>(l_mbaList[0]));


        FAPI_EXEC_HWP(l_rc, dimmBadDqBitmapAccessHwp,
                      l_mbaTarget, *i_pTarget, o_data, true);

        if (l_rc)
        {
            FAPI_ERR("fapiPlatDimmGetBadDqBitmap: "
                     "Error from dimmBadDqBitmapAccessHwp (get)");
        }

    }while(0);
    return l_rc;
}


/**
 * @brief This function is called by the FAPI_ATTR_SET macro when setting
 * the Bad DQ Bitmap attribute
 * It should not be called directly.
 *
 *  @param[in]  i_pTarget   DIMM target pointer
 *  @param[in]  i_data      Bad DIMM DQ Bitmap
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatDimmSetBadDqBitmap (
                                    const fapi::Target * i_pTarget,
                                    uint8_t (&i_data)[DIMM_DQ_MAX_DIMM_RANKS]\
                                                     [DIMM_DQ_RANK_BITMAP_SIZE])
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
            FAPI_ERR("fapiPlatDimmSetBadDqBitmap:Error from getTargetingTarget");
            break;
        }

        // Find MBA target from DIMM target
        getParentAffinityTargets(l_mbaList, l_pTarget, TARGETING::CLASS_UNIT,
                                 TARGETING::TYPE_MBA, false);


        if (l_mbaList.size() != 1 )
        {
            FAPI_ERR("fapiPlatDimmSetBadDqBitmap: expect 1 mba %d ",
               l_mbaList.size());

            /*@
             * @errortype
             * @moduleid     fapi::MOD_PLAT_ATTR_SVC_SET_BADDQ_DATA
             * @reasoncode   fapi::RC_NO_SINGLE_MBA
             * @userdata1    Number of MBAs
             * @userdata2    DIMM HUID
             * @devdesc      fapiPlatDimmSetBadDqBitmap could not find the
             *               expected 1 mba from the passed dimm target
             */
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                fapi::MOD_PLAT_ATTR_SVC_SET_BADDQ_DATA,
                fapi::RC_NO_SINGLE_MBA,
                l_mbaList.size(),
                TARGETING::get_huid(l_pTarget),
                hbSwError);

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
            break;
        }


        // Create the Fapi Target
        fapi::Target l_mbaTarget(TARGET_TYPE_MBA_CHIPLET,
                                 static_cast<void *>(l_mbaList[0]));


        FAPI_EXEC_HWP(l_rc, dimmBadDqBitmapAccessHwp,
                      l_mbaTarget, *i_pTarget, i_data, false);

        if (l_rc)
        {
            FAPI_ERR("fapiPlatdimmSetBadDqBitmap: "
                     "Error from dimmBadDqBitmapAccessHwp (set)");
        }

    }while(0);
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
 *  @param[in]  i_pTarget   MBA target pointer
 *  @param[out] o_data      Spare DRAM availability for MBA
 *  @return     ReturnCode. Zero on success, else platform specified error
 */
fapi::ReturnCode fapiPlatDimmGetSpareDram (
                                    const fapi::Target * i_pTarget,
                                    uint8_t (&o_data)[DIMM_DQ_MAX_MBA_PORTS]
                                                 [DIMM_DQ_MAX_MBAPORT_DIMMS]
                                                    [DIMM_DQ_MAX_DIMM_RANKS])
{

    fapi::ReturnCode l_rc;
    do
    {
        FAPI_EXEC_HWP(l_rc, getMBvpdSpareDramData, *i_pTarget, o_data);

        if (l_rc)
        {
            FAPI_ERR("fapiPlatDimmGetSpareDram: "
                     "Error from getMBvpdSpareDramData");
            break;
        }

    }while(0);

    return l_rc;
}

//******************************************************************************
// fapi::platAttrSvc::fapiPlatGetPllAttr function
//******************************************************************************
fapi::ReturnCode fapiPlatGetPllAttr(const fapi::AttributeId i_targAttrId,
                                    const fapi::Target * const i_pChipTarget,
                                    uint8_t * o_data )
{
    // Call a PLL Ring Attribute HWP to get the data
    fapi::ReturnCode l_rc;
    uint32_t l_ringLength = 0;
    FAPI_EXEC_HWP(l_rc, getPllRingAttr, i_targAttrId, *i_pChipTarget,
                  l_ringLength, o_data);
    return l_rc;
}

fapi::ReturnCode fapiPlatGetPllAttr(const fapi::AttributeId i_targAttrId,
                                    const fapi::Target * const i_pChipTarget,
                                    uint32_t (&o_pllRingLength))
{
    // Call a PLL Ring Attribute HWP to get the data
    fapi::ReturnCode l_rc;
    uint8_t l_data[MAX_PLL_RING_SIZE_BYTES] = {};
    FAPI_EXEC_HWP(l_rc, getPllRingAttr, i_targAttrId, *i_pChipTarget,
                  o_pllRingLength, l_data);
    return l_rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode fapiPlatGetPllInfoAttr(
    const fapi::Target * i_pProcChip,
    const fapi::getPllRingInfo::Attr i_attr,
    void * o_pVal,
    const size_t i_len)
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getPllRingInfoAttr, *i_pProcChip, i_attr, o_pVal, i_len);
    return l_rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode fapiPlatGetSpdAttrAccessor(
    const fapi::Target * i_pDimm,
    const fapi::getSpdAttr::Attr i_attr,
    void  * o_pVal,
    const size_t i_len)
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getSpdAttrAccessor, *i_pDimm, i_attr, o_pVal, i_len);
    return l_rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode fapiPlatGetL3DDAttr(const fapi::Target * i_pProcTarget,
                                     uint32_t (&o_data)[DELTA_DATA_SIZE])
{
    fapi::ReturnCode l_rc;
    uint32_t l_ringLength=0;
    FAPI_EXEC_HWP(l_rc, getL3DeltaDataAttr,*i_pProcTarget,o_data,l_ringLength);
    return l_rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode fapiPlatGetL3Length(const fapi::Target * i_pProcTarget,
                                     uint32_t (&o_ringLength))
{
    fapi::ReturnCode l_rc;
    uint32_t l_data [DELTA_DATA_SIZE] = {};
    FAPI_EXEC_HWP(l_rc, getL3DeltaDataAttr,*i_pProcTarget,l_data,o_ringLength);
    return l_rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode fapiPlatGetPciOscswitchConfig
                                     (const fapi::Target * i_pProcTarget,
                                     uint8_t &o_val)
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getPciOscswitchConfig, *i_pProcTarget, o_val);
    return l_rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode fapiPlatGetTdpRdpCurrentFactor
                                     (const fapi::Target * i_pProcTarget,
                                     uint32_t &o_val)
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getTdpRdpCurrentFactor, *i_pProcTarget, o_val);
    return l_rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode fapiPlatGetSpdModspecComRefRawCard
                                     (const fapi::Target * i_pDimmTarget,
                                     uint8_t &o_val)
{
    fapi::ReturnCode l_rc;
    uint8_t l_cardExt = 0;
    uint8_t l_card = 0;

    do {

        // Get the Reference Raw Card Extension (0 or 1)
        l_rc = fapiPlatGetSpdAttr(i_pDimmTarget,
            SPD::MODSPEC_COM_REF_RAW_CARD_EXT,
            &l_cardExt, sizeof(l_cardExt));
        if (l_rc)
        {
            break; //break with error
        }

        // Get the References Raw Card (bits 4-0)
        // When Reference Raw Card Extension = 0
        //    Reference raw cards A through AL
        // When Reference Raw Card Extension = 1
        //    Reference raw cards AM through CB
        l_rc = fapiPlatGetSpdAttr(i_pDimmTarget, SPD::MODSPEC_COM_REF_RAW_CARD,
            &l_card, sizeof(l_card));
        if (l_rc)
        {
            break; //break with error
        }

        // Raw Card = 0x1f(ZZ) means no JEDEC reference raw card design used.
        //   Have one ZZ in the return merged enumeration.
        if (0x1f == l_card)
        {
            l_cardExt = 1;  //Just one ZZ in the enumeration (0x3f)
        }

        // Merge into a single enumeration
        o_val = (l_cardExt <<5) | l_card;

    } while (0);

    return l_rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode fapiPlatGetOscswitchCtl
                              (const fapi::Target * i_pProcTarget,
                               const fapi::getOscswitchCtl::Attr i_attr,
                               void * o_pVal,
                               const size_t i_len)
{
    fapi::ReturnCode l_rc;

    FAPI_EXEC_HWP(l_rc,getOscswitchCtlAttr,*i_pProcTarget,i_attr,o_pVal,i_len);

    return l_rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode fapiPlatGetControlCapable(const fapi::Target * i_pTarget,
                uint8_t  & o_val)
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc,getControlCapableData,*i_pTarget,o_val);
    return l_rc;
}

//-----------------------------------------------------------------------------
fapi::ReturnCode fapiPlatGetRCDCntlWord015(const fapi::Target * i_pFapiTarget,
                uint64_t  & o_val)
{
    fapi::ReturnCode l_rc;
    errlHndl_t l_err = NULL;
    o_val = 0;
    size_t  l_nibbleSize = 4;
    const uint8_t  l_keywordSize = 16;
    const uint16_t l_keywords [l_keywordSize] = { SPD::RMM_RC0,
                                                  SPD::RMM_RC1,
                                                  SPD::RMM_RC2,
                                                  SPD::RMM_RC3,
                                                  SPD::RMM_RC4,
                                                  SPD::RMM_RC5,
                                                  SPD::RMM_RC6,
                                                  SPD::RMM_RC7,
                                                  SPD::RMM_RC8,
                                                  SPD::RMM_RC9,
                                                  SPD::RMM_RC10,
                                                  SPD::RMM_RC11,
                                                  SPD::RMM_RC12,
                                                  SPD::RMM_RC13,
                                                  SPD::RMM_RC14,
                                                  SPD::RMM_RC15 };
    do
    {
        uint8_t l_dimmType =0;
        l_rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_TYPE, i_pFapiTarget,l_dimmType);
        if (l_rc)
        {
            FAPI_ERR("fapiPlatGetRCDCntlWord015: Error getting ATTR_SPD_MODULE_TYPE");
            break;
        }


        if (l_dimmType == ENUM_ATTR_SPD_MODULE_TYPE_RDIMM)
        {
            TARGETING::Target* l_pTarget = NULL;
            l_rc = getTargetingTarget(i_pFapiTarget, l_pTarget, TARGETING::TYPE_DIMM);
            if (l_rc)
            {
                FAPI_ERR("fapiPlatGetRCDCntlWord015: Error from getTargetingTarget");
                break;
            }

            uint8_t l_nibbleRead;

            for (int i = 0; i < l_keywordSize; i++)
            {
                l_nibbleRead = 0;
                l_err = deviceRead(l_pTarget, &l_nibbleRead, l_nibbleSize,
                           DEVICE_SPD_ADDRESS(l_keywords[i]));
                if (l_err)
                {
                    FAPI_ERR("fapiPlatGetRCDCntlWord015:Error from deviceRead");
                    l_rc.setPlatError(reinterpret_cast<void *> (l_err));
                    break;
                }
                o_val = (o_val << 4) | (l_nibbleRead & 0x0F);
            }
        }
        else if ((l_dimmType == ENUM_ATTR_SPD_MODULE_TYPE_UDIMM) ||
                 (l_dimmType == ENUM_ATTR_SPD_MODULE_TYPE_CDIMM))
        {
            o_val = 0;
            break;
        }
        else
        {
            /*@
             * @errortype
             * @moduleid   MOD_GET_RCD_CNTL_WORD
             * @reasoncode RC_INVALID_DIMM_TYPE
             * @userdata1  DIMM TYPE
             * @devdesc    Failed due to wrong DIMM type
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            MOD_GET_RCD_CNTL_WORD,
                                            RC_INVALID_DIMM_TYPE,
                                            l_dimmType, 0, true);
            FAPI_ERR("fapiPlatGetRCDCntlWord015:Wrong dimm type");
            l_rc.setPlatError(reinterpret_cast<void *> (l_err));
            break;
        }
    } while (0);
    return l_rc;
}

fapi::ReturnCode getIsDimmToC4DQ
                            (const fapi::Target * i_pTarget,
                             uint8_t (&o_val) [4][80])
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc,getDQAttrISDIMM,*i_pTarget,o_val);
    return FAPI_RC_SUCCESS;
}

fapi::ReturnCode getIsDimmToC4DQS
                            (const fapi::Target * i_pTarget,
                             uint8_t (&o_val) [4][20])
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc,getDQSAttrISDIMM,*i_pTarget,o_val);
    return FAPI_RC_SUCCESS;
}

/**
 * @brief Get the Perv Vitle ring length.  See doxygen in .H file
 */
fapi::ReturnCode fapiPlatGetPervVitlRingLengthAttr(
                               const fapi::Target * i_pProcTarget,
                               uint32_t (&o_ringLength))
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getPervVitlRingLengthAttr,
                  *i_pProcTarget, o_ringLength);
    return l_rc;
}

/**
 * @brief Get the TP Vitle spy length.  See doxygen in .H file
 */
fapi::ReturnCode fapiPlatGetTpVitlSpyLengthAttr(
                       const fapi::Target * i_pProcTarget,
                       uint32_t (&o_spyLength))
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getTpVitlSpyLengthAttr, *i_pProcTarget, o_spyLength);
    return l_rc;
}

/**
 * @brief Get the TP Vitle spy offsets.  See doxygen in .H file
 */
fapi::ReturnCode fapiPlatGetTpVitlSpyOffsetAttr(
                               const fapi::Target * i_pProcTarget,
                               uint32_t (&o_data)[SPY_OFFSET_SIZE])
{
    fapi::ReturnCode l_rc;
    FAPI_EXEC_HWP(l_rc, getTpVitlSpyOffsetAttr, *i_pProcTarget, o_data);
    return l_rc;
}

fapi::ReturnCode fapiPlatGetMemAttrData (
                              const fapi::Target * i_pTarget,
                              const TARGETING::ATTRIBUTE_ID i_attr,
                              uint32_t & o_val)
{

    FAPI_DBG("fapiPlatGetMemAttrData: START: i_attr=0x%X", i_attr);

    fapi::ReturnCode l_rc;
    TARGETING::Target * l_pTgt = NULL;

    do {

        // Get non-FAPI Centaur Target
        l_rc = getTargetingTarget(i_pTarget, l_pTgt,
                                  TARGETING::TYPE_MEMBUF);

        if (l_rc)
        {
            FAPI_ERR("fapiPlatGetMemAttrData: Error from getTargetingTarget");
            break;
        }

        // Get NODE from MEMBUF target
        TARGETING::TargetHandleList l_nodeList;
        TARGETING::TargetService& tS = TARGETING::targetService();

        TARGETING::PredicateCTM isaNode(TARGETING::CLASS_ENC,
                                        TARGETING::TYPE_NODE);
        tS.getAssociated( l_nodeList,
                          l_pTgt,
                          TARGETING::TargetService::PARENT,
                          TARGETING::TargetService::ALL,
                          &isaNode);

        // Node list should only have 1 tgt
        if (l_nodeList.size() != 1 )
        {
            FAPI_ERR("fapiPlatGetMemAttrData: expect 1 node %d ",
                     l_nodeList.size());

            /*@
             * @errortype
             * @moduleid     MOD_PLAT_ATTR_SVC_GET_MEM_ATTR_DATA
             * @reasoncode   RC_NO_SINGLE_NODE
             * @userdata1    Number of Nodes
             * @userdata2    MEMBUF Target HUID
             * @devdesc      fapiPlatGetMemAttrData could not find the single
             *               node associated with this membuf target
             */
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                MOD_PLAT_ATTR_SVC_GET_MEM_ATTR_DATA,
                RC_NO_SINGLE_NODE,
                l_nodeList.size(),
                TARGETING::get_huid(l_pTgt),
                hbSwError);

            // Attach the error log to the fapi::ReturnCode
            l_rc.setPlatError(reinterpret_cast<void *> (l_pError));
            break;
        }

        // Get the attribute from the node level
        // NOTE: Using switch statement to explicitly track the attributes
        //       that need to do this lookup.
        bool l_success = false;

        switch ( i_attr )
        {
            case TARGETING::ATTR_MSS_CENT_VDD_SLOPE_ACTIVE:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_CENT_VDD_SLOPE_ACTIVE>(o_val);
                break;

            case TARGETING::ATTR_MSS_CENT_VDD_SLOPE_INACTIVE:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_CENT_VDD_SLOPE_INACTIVE>(o_val);
                break;

            case TARGETING::ATTR_MSS_CENT_VDD_INTERCEPT:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_CENT_VDD_INTERCEPT>(o_val);
                break;

            case TARGETING::ATTR_MSS_CENT_VCS_SLOPE_ACTIVE:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_CENT_VCS_SLOPE_ACTIVE>(o_val);
                break;

            case TARGETING::ATTR_MSS_CENT_VCS_SLOPE_INACTIVE:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_CENT_VCS_SLOPE_INACTIVE>(o_val);
                break;

            case TARGETING::ATTR_MSS_CENT_VCS_INTERCEPT:
                l_success = l_nodeList[0]->tryGetAttr<
                            TARGETING::ATTR_MSS_CENT_VCS_INTERCEPT>(o_val);
                break;

            case TARGETING::ATTR_MSS_VOLT_VPP_SLOPE_EFF_CONFIG:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_VOLT_VPP_SLOPE_EFF_CONFIG>(o_val);
                break;

            case TARGETING::ATTR_MSS_VOLT_VPP_INTERCEPT_EFF_CONFIG:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_VOLT_VPP_INTERCEPT_EFF_CONFIG>
                            (o_val);
                break;

            case TARGETING::ATTR_MSS_VOLT_DDR3_VDDR_SLOPE_EFF_CONFIG:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_VOLT_DDR3_VDDR_SLOPE_EFF_CONFIG>
                            (o_val);
                break;

            case TARGETING::ATTR_MSS_VOLT_DDR3_VDDR_INTERCEPT_EFF_CONFIG:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_VOLT_DDR3_VDDR_INTERCEPT_EFF_CONFIG
                        >(o_val);
                break;

            case TARGETING::ATTR_MRW_DDR3_VDDR_MAX_LIMIT_EFF_CONFIG:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MRW_DDR3_VDDR_MAX_LIMIT_EFF_CONFIG>
                            (o_val);
                break;

            case TARGETING::ATTR_MSS_VOLT_DDR4_VDDR_SLOPE_EFF_CONFIG:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_VOLT_DDR4_VDDR_SLOPE_EFF_CONFIG>
                            (o_val);
                break;

            case TARGETING::ATTR_MSS_VOLT_DDR4_VDDR_INTERCEPT_EFF_CONFIG:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MSS_VOLT_DDR4_VDDR_INTERCEPT_EFF_CONFIG
                        >(o_val);
                break;

            case TARGETING::ATTR_MRW_DDR4_VDDR_MAX_LIMIT_EFF_CONFIG:
                l_success =
                    l_nodeList[0]->tryGetAttr<
                        TARGETING::ATTR_MRW_DDR4_VDDR_MAX_LIMIT_EFF_CONFIG>
                            (o_val);
                break;

            default:
                // Use error creation below
                l_success = false;
                break;
        }

        if (!l_success)
        {
            FAPI_ERR("fapiPlatGetMemAttrData: Error from _tryGetAttr");

            /*@
             *  @errortype
             *  @moduleid   MOD_PLAT_ATTR_SVC_GET_MEM_ATTR_DATA
             *  @reasoncode RC_FAILED_TO_ACCESS_ATTRIBUTE
             *  @userdata1[0:31]  Platform attribute ID
             *  @userdata1[32:64] MEMBUF Target
             *  @userdata2  FAPI target type, or NULL if system target
             *  @devdesc    Failed to get requested attribute.
             *      Possible causes: Invalid target, attribute not implemented,
             *          attribute not present on given target, target service
             *          not initialized
             */
            const bool hbSwError = true;
            errlHndl_t l_pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_PLAT_ATTR_SVC_GET_MEM_ATTR_DATA,
                RC_FAILED_TO_ACCESS_ATTRIBUTE,
                TWO_UINT32_TO_UINT64(
                    i_attr,
                    TARGETING::get_huid(l_pTgt)),
                i_pTarget ? i_pTarget->getType(): NULL,
                hbSwError);
            l_rc.setPlatError(reinterpret_cast<void *>(l_pError));
        }

    } while (0);

    FAPI_DBG("fapiPlatGetMemAttrData: EXIT: i_attr=0x%X --> o_val = %d (0x%X)",
             i_attr, o_val, o_val);

    return l_rc;

}

} // End platAttrSvc namespace

} // End fapi namespace
