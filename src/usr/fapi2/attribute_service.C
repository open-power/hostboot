/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/attribute_service.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
///
/// @file attribute_service.C
///
/// @brief Implements the platform functions that access attributes for FAPI2
///

//******************************************************************************
// Includes
//******************************************************************************

// The following file checks at compile time that all HWPF attributes are
// handled by Hostboot. This is done to ensure that the HTML file listing
// supported HWPF attributes lists attributes handled by Hostboot

#include <stdint.h>
#include <return_code.H>
#include <fapi2platattrmacros.H>
#include <fapi2_attribute_service.H>
#include <attribute_service.H>
#include <attribute_plat_check.H>
#include <attribute_ids.H>
#include <targeting/common/attributes.H>
#include <attributeenums.H>
#include <target.H>
#include <target_types.H>
#include <hwpf_fapi2_reasoncodes.H>

#include <devicefw/driverif.H>
#include <plat_attr_override_sync.H>
#include <vpd/spdenums.H>
#include <p9_pm_get_poundv_bucket.H>
#include <errl/errlmanager.H>

#include <targeting/common/targetservice.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/util.H>

//******************************************************************************
// Implementation
//******************************************************************************

namespace fapi2
{
namespace platAttrSvc
{

///
/// @brief Gets the TARGETING object for the input FAPI target
///        See doxygen in attribute_service.H
///
errlHndl_t getTargetingTarget(const Target<TARGET_TYPE_ALL>& i_pFapiTarget,
                   TARGETING::Target* & o_pTarget,
                   const TARGETING::TYPE i_expectedType)
{
    errlHndl_t l_errl = NULL;
    do
    {
        if (i_pFapiTarget.get() == NULL)
        {
            // Fapi Target object isnt point to a real target
            FAPI_ERR("getTargetingTarget. NULL Fapi Target");

            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_GET_TARGETING_TARGET
            * @reasoncode        RC_NULL_FAPI_TARGET
            * @userdata1[0:31]   Fapi2 Expected Type
            * @userdata1[32:63]  <unused>
            * @userdata2[0:7]    Is Chip
            * @userdata2[8:15]   Is Chiplet
            * @userdata2[16:63]  <unused>
            * @devdesc           Unable to resolve FapiTarget from input
            * @custdesc          Firmware Error
            */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MOD_FAPI2_GET_TARGETING_TARGET,
                                            RC_NULL_FAPI_TARGET,
                                            i_expectedType,
                                            TWO_UINT8_TO_UINT16(
                                            i_pFapiTarget.isChip(),
                                            i_pFapiTarget.isChiplet()));

            l_errl->collectTrace(FAPI_TRACE_NAME);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME);

            break;
        }

        o_pTarget = reinterpret_cast<TARGETING::Target*>(i_pFapiTarget.get());
        if(i_expectedType != TARGETING::TYPE_NA)
        {
            TARGETING::TYPE l_type = o_pTarget->getAttr<TARGETING::ATTR_TYPE>();

            if (l_type != i_expectedType)
            {
                FAPI_ERR("getTargetingTarget. Type: %d, expected %d", l_type,
                        i_expectedType);
                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_GET_TARGETING_TARGET
                * @reasoncode        RC_MISMATCHED_FAPI_TARG_TARGET
                * @userdata1[0:31]   Actual Type
                * @userdata1[32:63]  Expected Type
                * @userdata2[0:31]   Initial FAPI2 Type
                * @userdata2[32:47]  Is Chip
                * @userdata2[48:63]  Is Chiplet
                * @devdesc           When coverting from FAPI2::target to
                *                    Targeting::target the resulting
                                    Targeting::target's was incorrect
                * @custdesc          Firmware Error
                */
                l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                MOD_FAPI2_GET_TARGETING_TARGET,
                                                RC_MISMATCHED_FAPI_TARG_TARGET,
                                                TWO_UINT32_TO_UINT64(l_type,
                                                i_expectedType),
                                                TWO_UINT32_TO_UINT64(
                                                i_pFapiTarget.getType(),
                                                TWO_UINT16_TO_UINT32(
                                                i_pFapiTarget.isChip(),
                                                i_pFapiTarget.isChiplet())));

                l_errl->collectTrace(FAPI_TRACE_NAME);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME);
                break;
            }
        }
    } while(0);

    return l_errl;
}

bool getTargetingAttrHelper(TARGETING::Target * l_pTargTarget,
                            const TARGETING::ATTRIBUTE_ID i_targAttrId,
                            const uint32_t i_attrSize, void * o_pAttr)
{
    return l_pTargTarget->_tryGetAttr(i_targAttrId, i_attrSize, o_pAttr);
}

///
/// @brief Gets a Targeting attribute, this is called by the macro that maps a
///        FAPI Attribute get to a TARGETING attribute and should not be called
///        directly.
///        See doxygen in H file.
///
ReturnCode getTargetingAttr(
           const Target< TARGET_TYPE_ALL, plat_target_handle_t >& i_pFapiTarget,
           const TARGETING::ATTRIBUTE_ID i_targAttrId,
           const uint32_t i_attrSize,
           void * o_pAttr)
{
    errlHndl_t l_errl = NULL;
    ReturnCode l_rc;
    TARGETING::Target * l_pTargTarget = NULL;
    l_errl = getTargetingTarget(i_pFapiTarget, l_pTargTarget);

    if (l_errl)
    {
        FAPI_ERR("getTargetingAttr: Error from getTargetingTarget");
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        // Note directly calling Target's private _tryGetAttr function for code
        // size optimization, the public function is a template function that
        // cannot be called with a variable attribute ID, the template function
        // checks at compile time that the Targeting attribute is readable, but
        // that is already checked by the Targeting compiler
        bool l_success = getTargetingAttrHelper(l_pTargTarget,
                                                i_targAttrId,
                                                i_attrSize, o_pAttr);

        if (!l_success)
        {
            FAPI_ERR("getTargetingAttr: Error from _tryGetAttr");
        }
    }
    return l_rc;
}

bool setTargetingAttrHelper(TARGETING::Target * l_pTargTarget,
                            const TARGETING::ATTRIBUTE_ID i_targAttrId,
                            const uint32_t i_attrSize,
                            void * o_pAttr)
{
    return l_pTargTarget->_trySetAttr(i_targAttrId, i_attrSize, o_pAttr);
}

///
/// @brief Sets a Targeting attribute, this is called by the macro that maps a
///        FAPI Attribute set to a FAPI2 TARGETING attribute and should not be
///        called directly
///        See doxygen in H file
///
ReturnCode setTargetingAttr(
           const Target<TARGET_TYPE_ALL, plat_target_handle_t >& i_pFapiTarget,
           const TARGETING::ATTRIBUTE_ID i_targAttrId,
           const uint32_t i_attrSize,
           void * i_pAttr)
{
    ReturnCode l_rc;
    errlHndl_t l_errl = NULL;
    TARGETING::Target * l_pTargTarget = NULL;
    l_errl = getTargetingTarget(i_pFapiTarget, l_pTargTarget);

    if (l_errl)
    {
        FAPI_ERR("setTargetingAttr: Error from getTargetingTarget");
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        // Note directly calling Target's private _trySetAttr function for code
        // size optimization, the public function is a template function that
        // cannot be called with a variable attribute ID, the template function
        // checks at compile time that the Targeting attribute is readable, but
        // that is already checked by the Targeting compiler
        bool l_success = setTargetingAttrHelper(l_pTargTarget,
                                                i_targAttrId,
                                                i_attrSize,
                                                    i_pAttr);

        if (!l_success)
        {
            FAPI_ERR("setTargetingAttr: Error from _trySetAttr");
        }
    }
    return l_rc;
}

//******************************************************************************
// platGetTargetName function
//******************************************************************************
ReturnCode platGetTargetName(const Target<TARGET_TYPE_ALL>& i_pFapiTarget,
                                 uint8_t & o_name)
{
    ReturnCode l_rc;
    errlHndl_t l_errl = NULL;
    TARGETING::Target * l_pHbTarget = NULL;
    o_name = ENUM_ATTR_NAME_NONE;

    do
    {
        l_errl = getTargetingTarget(i_pFapiTarget, l_pHbTarget);

        if (l_errl)
        {
            FAPI_ERR("platGetTargetName: Error from getTargetingTarget");
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
            break;
        }

        TARGETING::MODEL l_model =
            l_pHbTarget->getAttr<TARGETING::ATTR_MODEL>();

        if (l_model == TARGETING::MODEL_NIMBUS)
        {
            o_name = ENUM_ATTR_NAME_NIMBUS;
        }
        else if (l_model == TARGETING::MODEL_CUMULUS)
        {
            o_name = ENUM_ATTR_NAME_CUMULUS;
        }
        else if (l_model == TARGETING::MODEL_CENTAUR)
        {
            o_name = ENUM_ATTR_NAME_CENTAUR;
        }
        else
        {
            FAPI_ERR("platGetTargetName. Unknown name 0x%x", l_model);

            /*@
            * @errortype
            * @moduleid          fapi2::MOD_FAPI2_GET_TARGETING_TARGET
            * @reasoncode        RC_UNKNOWN_MODEL
            * @userdata1[0:31]    FAPI2 Type
            * @userdata1[32:63]   HB Target HUID
            * @userdata2[0:31]    HB Type
            * @userdata2[32:63]   HB Model
            * @devdesc           HB target found with unknown model attribute
            * @custdesc          Firmware Error
            */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MOD_FAPI2_GET_TARGETING_TARGET,
                                            RC_UNKNOWN_MODEL,
                                            TWO_UINT32_TO_UINT64(
                                            i_pFapiTarget.getType(),
                                            TARGETING::get_huid(l_pHbTarget)
                                            ),
                                            TWO_UINT32_TO_UINT64(
                                            l_pHbTarget->
                                            getAttr<TARGETING::ATTR_TYPE>(),
                                            l_model));

            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
            break;
        }
    } while (0);

    return l_rc;
}

//******************************************************************************
// platGetFunctional function
//******************************************************************************
ReturnCode platGetFunctional(const Target<TARGET_TYPE_ALL>& i_pFapiTarget,
                                 uint8_t & o_functional)
{
    errlHndl_t l_errl = NULL;
    ReturnCode l_rc;
    TARGETING::Target * l_pHbTarget = NULL;
    o_functional = 0;

    l_errl = getTargetingTarget(i_pFapiTarget, l_pHbTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetFunctional: Error from getTargetingTarget");
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
// fapi::platAttrSvc::platGetTargetPos function
//******************************************************************************
ReturnCode platGetTargetPos(const Target<TARGET_TYPE_ALL>& i_pFapiTarget,
                                uint32_t & o_pos)
{
    errlHndl_t l_errl = NULL;
    ReturnCode l_rc;
    TARGETING::Target * l_pTarget = NULL;

    // Get the Targeting Target
    l_errl = getTargetingTarget(i_pFapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("getTargetName: Error from getTargetingTarget");
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        uint16_t l_pos = l_pTarget->getAttr<TARGETING::ATTR_POSITION>();
        o_pos = l_pos;
    }

    return l_rc;
}

//******************************************************************************
// fapi::platAttrSvc::platGetFusedCoreMode function
//******************************************************************************
ReturnCode platGetFusedCoreMode(uint8_t & o_isFused)
{
    o_isFused = TARGETING::is_fused_mode();
    return fapi2::ReturnCode();
}

//******************************************************************************
// fapi2::platAttrSvc::platGetPoundVBucketData function
//******************************************************************************
// ReturnCode platGetPoundVBucketData(const Target<TARGET_TYPE_EQ>& i_fapiTarget,
//                              uint8_t * o_poundVData)
// {
//     fapi2::ReturnCode rc;
//     if(i_fapiTarget.getType() != TARGET_TYPE_EQ)
//     {
//         /*@
//         * @errortype         ERRORLOG::ERRL_SEV_UNRECOVERABLE
//         * @moduleid          fapi2::MOD_FAPI2_MVPD_ACCESS
//         * @reasoncode        RC_INCORRECT_TARGET
//         * @userdata1         Actual Target Type
//         * @userdata2         Expected Target Type
//         * @devdesc           Attempted to read attribute from wrong target type
//         * @custdesc          Firmware Error
//         */
//         errlHndl_t l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
//                                               MOD_FAPI2_MVPD_ACCESS,
//                                               RC_INCORRECT_TARGET,
//                                               i_fapiTarget.getType(),
//                                               TARGET_TYPE_EQ,
//                                               true);
//         rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
//     }
//     else
//     {
//         rc = p9_pm_get_poundv_bucket_attr(i_fapiTarget,o_poundVData);
//     }
//     return rc;
// }




} // End platAttrSvc namespace

} // End fapi2 namespace
