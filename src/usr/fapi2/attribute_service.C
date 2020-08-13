/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/attribute_service.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#include <attribute_ids.H>
#include <attributeenums.H>
#include <fapi2platattrmacros.H>
#include <fapi2_attribute_service.H>
#include <attribute_service.H>
#include <attribute_plat_check.H>
#include <targeting/common/attributes.H>
#include <target.H>
#include <target_types.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <chipids.H>

#include <devicefw/driverif.H>
#include <plat_attr_override_sync.H>
#include <vpd/spdenums.H>
#include <p9_pm_get_poundv_bucket_attr.H>
#include <p9_pm_get_poundw_bucket_attr.H>
#include <p9_frequency_buckets.H>
#include <errl/errlmanager.H>

#include <targeting/common/targetservice.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/util.H>
#include <../memory/lib/shared/dimmConsts.H>
#include <../memory/lib/shared/mss_const.H>
#include <../memory/lib/rosetta_map/rosetta_map.H>
#include <util/utilcommonattr.H>

#include <secureboot/service.H>

#include<vpd_accessors/accessMBvpdL4BankDelete.H>
#include<vpd_accessors/getControlCapableData.H>
#include<vpd_accessors/getDQAttrISDIMM.H>
#include<vpd_accessors/getDQSAttrISDIMM.H>
#include<vpd_accessors/getISDIMMTOC4DAttrs.H>
#include<vpd_accessors/getMBvpdAddrMirrorData.H>
#include<vpd_accessors/getMBvpdDram2NModeEnabled.H>
#include<vpd_accessors/getMBvpdMemoryDataVersion.H>
#include<vpd_accessors/getMBvpdSPDXRecordVersion.H>
#include<vpd_accessors/getMBvpdSlopeInterceptData.H>
#include<vpd_accessors/getMBvpdSensorMap.H>
#include<vpd_accessors/getMBvpdSpareDramData.H>
#include<vpd_accessors/getMBvpdVersion.H>
#include<vpd_accessors/getMBvpdVoltageSettingData.H>
#include<vpd_accessors/getMBvpdAttr.H>

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

bool getTargetingAttrHelper(TARGETING::Target * i_pTargTarget,
                            const TARGETING::ATTRIBUTE_ID i_targAttrId,
                            const uint32_t i_attrSize, void * o_pAttr)
{
    return i_pTargTarget->_tryGetAttr(i_targAttrId, i_attrSize, o_pAttr);
}

///
/// @brief Gets a Targeting attribute, this is called by the macro that maps a
///        FAPI Attribute get to a TARGETING attribute and should not be called
///        directly.
///        See doxygen in H file.
///
ReturnCode getTargetingAttr(
           const Target< TARGET_TYPE_ALL, MULTICAST_OR,
                plat_target_handle_t >& i_pFapiTarget,
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
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_errl);
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
            FAPI_ERR("getTargetingAttr: Error from getTargetingAttrHelper "
                     "for target 0x%.8X and attribute 0x%x",
                     TARGETING::get_huid(l_pTargTarget), i_targAttrId);

            /*@
             * @errortype
             * @moduleid          fapi2::MOD_FAPI2_GET_TARGETING_ATTR
             * @reasoncode        RC_INVALID_ATTRIBUTE
             * @userdata1[0:31]   FAPI2 Target Type
             * @userdata1[32:63]  HB Target HUID
             * @userdata2         Requested attribute ID
             * @devdesc           Invalid attribute read request
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             MOD_FAPI2_GET_TARGETING_ATTR,
                                             RC_INVALID_ATTRIBUTE,
                                             TWO_UINT32_TO_UINT64(
                                              i_pFapiTarget.getType(),
                                              TARGETING::get_huid(l_pTargTarget)
                                             ),
                                             i_targAttrId);

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
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
           const Target<TARGET_TYPE_ALL, MULTICAST_OR,
                plat_target_handle_t >& i_pFapiTarget,
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
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_errl);
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
            FAPI_ERR("setTargetingAttr: Error from setTargetingAttrHelper "
                     "for target 0x%.8X and attribute 0x%x",
                     TARGETING::get_huid(l_pTargTarget), i_targAttrId);

            /*@
             * @errortype
             * @moduleid          fapi2::MOD_FAPI2_SET_TARGETING_ATTR
             * @reasoncode        RC_INVALID_ATTRIBUTE
             * @userdata1[0:31]   FAPI2 Target Type
             * @userdata1[32:63]  HB Target HUID
             * @userdata2         Requested attribute ID
             * @devdesc           Invalid attribute write request
             * @custdesc          Firmware Error
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             MOD_FAPI2_SET_TARGETING_ATTR,
                                             RC_INVALID_ATTRIBUTE,
                                             TWO_UINT32_TO_UINT64(
                                              i_pFapiTarget.getType(),
                                              TARGETING::get_huid(l_pTargTarget)
                                             ),
                                             i_targAttrId);

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
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
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
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
        else if (l_model == TARGETING::MODEL_AXONE)
        {
            o_name = ENUM_ATTR_NAME_AXONE;
        }
        else if (l_model == TARGETING::MODEL_OCMB)
        {
            // For MODEL_OCMB the ATTR_CHIP_ID determines if it is a
            // Gemini or an Explorer chip
            uint32_t l_chipID =
                l_pHbTarget->getAttr<TARGETING::ATTR_CHIP_ID>();

            if (l_chipID == POWER_CHIPID::EXPLORER_16)
            {
                o_name = ENUM_ATTR_NAME_EXPLORER;
            }
            else if (l_chipID == POWER_CHIPID::GEMINI_16)
            {
                o_name = ENUM_ATTR_NAME_GEMINI;
            }
            else
            {
                FAPI_ERR("platGetTargetName. Unknown CHIP_ID 0x%x for MODEL_OCMB 0x%x", l_chipID, l_model);

                /*@
                * @errortype
                * @moduleid          fapi2::MOD_FAPI2_GET_TARGETING_TARGET
                * @reasoncode        RC_UNKNOWN_OCMB_CHIP_TYPE
                * @userdata1[0:31]    FAPI2 Type
                * @userdata1[32:63]   HB Target HUID
                * @userdata2[0:31]    HB Type
                * @userdata2[32:63]   HB Target CHIP_ID
                * @devdesc           HB OCMB_CHIP target found with unknown
                *                    model based on ATTR_CHIP_ID
                * @custdesc          Firmware Error
                */
                l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MOD_FAPI2_GET_TARGETING_TARGET,
                                            RC_UNKNOWN_OCMB_CHIP_TYPE,
                                            TWO_UINT32_TO_UINT64(
                                            i_pFapiTarget.getType(),
                                            TARGETING::get_huid(l_pHbTarget)
                                            ),
                                            TWO_UINT32_TO_UINT64(
                                            l_pHbTarget->
                                            getAttr<TARGETING::ATTR_TYPE>(),
                                            l_chipID));

                // Add the error log pointer as data to the ReturnCode
                addErrlPtrToReturnCode(l_rc, l_errl);
                break;
            }
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

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
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
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_errl);
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
        FAPI_ERR("platGetTargetPos: Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_errl);
    }
    else
    {
        uint16_t l_pos = l_pTarget->getAttr<TARGETING::ATTR_FAPI_POS>();

        //@todo-RTC:161594-ATTR_POS is defined as per-drawer, so need to
        //  mod the value down appropriately

        o_pos = l_pos;
    }

    return l_rc;
}

//******************************************************************************
// fapi::platAttrSvc::platErrorOnSet function
//******************************************************************************
ReturnCode platErrorOnSet( TARGETING::Target * i_pTargTarget,
                           const fapi2::AttributeId i_fapiAttrId )
{
    // Just create an error to return back
    FAPI_ERR("platErrorOnSet: Set not valid for Attribute %X on Target %.8X",
             i_fapiAttrId, TARGETING::get_huid(i_pTargTarget) );
    /*@
     * @errortype
     * @moduleid     fapi2::MOD_FAPI2_PLAT_ERROR_ON_SET
     * @reasoncode   fapi2::RC_SET_ATTR_NOT_VALID
     * @userdata1    Target HUID
     * @userdata2    FAPI Attribute Id
     * @devdesc      platErrorOnSet> Set operation not valid
     * @custdesc     Firmware error
     */
    errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                                     ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     fapi2::MOD_FAPI2_PLAT_ERROR_ON_SET,
                                     fapi2::RC_SET_ATTR_NOT_VALID,
                                     TARGETING::get_huid(i_pTargTarget),
                                     i_fapiAttrId,
                                     ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    l_errl->collectTrace(FAPI_TRACE_NAME);
    l_errl->collectTrace(FAPI_IMP_TRACE_NAME);

    // attach our log to the fapi RC and return it
    ReturnCode l_rc;
    // Add the error log pointer as data to the ReturnCode
    addErrlPtrToReturnCode(l_rc, l_errl);
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
ReturnCode platGetPoundVBucketData(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                             uint8_t * o_poundVData)
{
    fapi2::ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);
    if (l_errl)
    {
        FAPI_ERR("platGetPoundVBucketData: Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        fapi2::Target<TARGET_TYPE_EQ> l_fapiTarget( l_pTarget);
        rc = p9_pm_get_poundv_bucket_attr(l_fapiTarget,o_poundVData);
    }

    return rc;
}

//******************************************************************************
// fapi2::platAttrSvc::platGetPoundWBucketData function
//******************************************************************************
ReturnCode platGetPoundWBucketData(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                             uint8_t * o_poundWData)
{
    fapi2::ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);
    if (l_errl)
    {
        FAPI_ERR("platGetPoundWBucketData: Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        fapi2::Target<TARGET_TYPE_EQ> l_fapiTarget( l_pTarget);
        rc = p9_pm_get_poundw_bucket_attr(l_fapiTarget,o_poundWData);
    }

    return rc;
}

ReturnCode platParseWOFTables(uint8_t* o_wofData);

//******************************************************************************
// fapi2::platAttrSvc::platGetWOFTableData function
//******************************************************************************
ReturnCode platGetWOFTableData(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                               uint8_t * o_wofTableData)
{
    fapi2::ReturnCode rc;

    // Parse the tables and return a single wof table
    rc = platParseWOFTables(o_wofTableData);

    return rc;
}

//******************************************************************************
// fapi2::platAttrSvc::__getChipModel function
//******************************************************************************
TARGETING::ATTR_MODEL_type __getChipModel()
{
    // determine the chip's model
    TARGETING::Target * masterProc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle(masterProc);

    return masterProc->getAttr<TARGETING::ATTR_MODEL>();
}

//******************************************************************************
// ATTR_BAD_DQ_BITMAP getter/setter constant definitions
//******************************************************************************

// define structure for the format of DIMM_BAD_DQ_DATA
struct dimmBadDqDataFormat
{
    uint32_t iv_magicNumber;
    uint8_t  iv_version;
    uint8_t  iv_reserved1;
    uint8_t  iv_reserved2;
    uint8_t  iv_reserved3;
    uint8_t  iv_bitmaps[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT];
    uint8_t  iv_rowRepairData[mss::MAX_RANK_PER_DIMM]
                             [mss::ROW_REPAIR_BYTE_COUNT];
    uint8_t  iv_unused[16];
};

// constant definitions
const uint8_t  SPARE_DRAM_DQ_BYTE_NUMBER_INDEX =
    (TARGETING::MODEL_AXONE == __getChipModel()) ? 5 : 9;
const uint32_t DIMM_BAD_DQ_MAGIC_NUMBER = 0xbadd4471;
const uint8_t  DIMM_BAD_DQ_VERSION = 1;
const uint8_t  DIMM_BAD_DQ_NUM_BYTES = 80;
size_t DIMM_BAD_DQ_SIZE_BYTES = 0x50;

union wiringData
{
    uint8_t nimbus[mss::PORTS_PER_MCS][mss::MAX_DQ_BITS];
    uint8_t cumulus[MAX_PORTS_PER_CEN][DIMM_BAD_DQ_NUM_BYTES];
    uint8_t memport[mss::MAX_DQ_BITS];
};

//******************************************************************************
// fapi2::platAttrSvc::__getTranslationPortSlct function
//******************************************************************************
ReturnCode __getTranslationPortSlct( const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
                                     uint8_t &o_ps )
{
    // NOTE: this function returns the port select we need for the translation
    // attribute. This means, for Cumulus it returns the MBA port from the
    // centaur perspective (0-3), and for Nimbus it returns the port select from
    // an MCS perspective (0-1).

    o_ps = 0;
    TARGETING::ATTR_MODEL_type l_procType = __getChipModel();

    // If the proc is Cumulus, we need to get the MBA.
    if ( TARGETING::MODEL_CUMULUS == l_procType )
    {
        Target<TARGET_TYPE_MBA> l_fapiMba =
            i_fapiDimm.getParent<TARGET_TYPE_MBA>();

        // Get the MBA's position
        uint8_t mbaPos = 0;
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_fapiMba, mbaPos) );
        mbaPos = mbaPos % MAX_MBA_PER_CEN; // 0-1

        // Get the port select from the MBA perspective
        uint8_t mbaPort = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, i_fapiDimm, mbaPort));
        mbaPort = mbaPort % MAX_PORTS_PER_MBA; // 0-1

        // Find the port select from the Centaur perspective
        o_ps = (mbaPos*MAX_PORTS_PER_MBA)+mbaPort; // 0-3
    }
    // If the proc is Nimbus, we need to get the MCA.
    else if ( TARGETING::MODEL_NIMBUS == l_procType )
    {
        Target<TARGET_TYPE_MCA> l_fapiMca =
            i_fapiDimm.getParent<TARGET_TYPE_MCA>();

        // Get the port select from the MCS perspective
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_fapiMca, o_ps) );
        o_ps = o_ps % mss::PORTS_PER_MCS; // 0-1
    }
    else
    {
        // In the generic case, the translation attribute exists on the MEM_PORT
        // trgt so there's no need to know the port slct, so just set it to 0.
        o_ps = 0;
    }


fapi_try_exit:
    return fapi2::current_err;
}


//******************************************************************************
// fapi2::platAttrSvc::__badDqBitmapGetHelperAttrs function
//******************************************************************************
ReturnCode __badDqBitmapGetHelperAttrs(
    const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    wiringData &o_wiringData, uint64_t &o_allMnfgFlags, uint8_t &o_ps )
{
    TARGETING::ATTR_MODEL_type procType = __getChipModel();

    FAPI_TRY( __getTranslationPortSlct(i_fapiDimm, o_ps) );

    // Get the DQ to DIMM Connector DQ Wiring attribute.
    // Note that for C-DIMMs, this will return a simple 1:1 mapping.
    // This code cannot tell the difference between C-DIMMs and IS-DIMMs.
    if ( TARGETING::MODEL_NIMBUS == procType )
    {
        // memset to avoid known syntax issue with previous compiler
        // versions and ensure zero initialized array.
        memset( o_wiringData.nimbus, 0, sizeof(o_wiringData.nimbus) );

        Target<TARGET_TYPE_MCA> l_fapiMca =
            i_fapiDimm.getParent<TARGET_TYPE_MCA>();

        // Get the MCS.
        Target<TARGET_TYPE_MCS> l_fapiMcs;
        l_fapiMcs = l_fapiMca.getParent<TARGET_TYPE_MCS>();

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_VPD_DQ_MAP, l_fapiMcs,
                                o_wiringData.nimbus) );
    }
    else if ( TARGETING::MODEL_CUMULUS == procType )
    {
        // memset to avoid known syntax issue with previous compiler
        // versions and ensure zero initialized array.
        memset( o_wiringData.cumulus, 0, sizeof(o_wiringData.cumulus) );

        // Check DIMM type
        uint8_t l_dimmType = 0;

        Target<TARGET_TYPE_MBA> l_fapiMba =
            i_fapiDimm.getParent<TARGET_TYPE_MBA>();

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, l_fapiMba,
                                l_dimmType) );

        // C-DIMMs return a direct 1:1 mapping
        if ( fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES == l_dimmType )
        {
            for ( uint8_t port = 0; port < MAX_PORTS_PER_CEN; port++ )
            {
                for ( uint8_t i = 0; i < DIMM_BAD_DQ_NUM_BYTES; i++ )
                {
                    o_wiringData.cumulus[port][i] = i;
                }
            }
        }
        // ISDIMMs require the mapping from ATTR_CEN_VPD_ISDIMMTOC4DQ
        else
        {
            Target<TARGET_TYPE_MEMBUF_CHIP> l_fapiMembuf =
                l_fapiMba.getParent<TARGET_TYPE_MEMBUF_CHIP>();

            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_ISDIMMTOC4DQ,
                                    l_fapiMembuf, o_wiringData.cumulus) );
        }
    }
    else
    {
        // memset to avoid known syntax issue with previous compiler
        // versions and ensure zero initialized array.
        memset( o_wiringData.memport, 0, sizeof(o_wiringData.memport) );

        // Get the MEM_PORT target
        Target<TARGET_TYPE_MEM_PORT> l_fapiMemPort =
            i_fapiDimm.getParent<TARGET_TYPE_MEM_PORT>();

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_VPD_DQ_MAP, l_fapiMemPort,
                                o_wiringData.memport) );
    }


    // Manufacturing flags attribute
    o_allMnfgFlags = 0;

    // Get the manufacturing flags bitmap to be used in both get and set
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MNFG_FLAGS,
                            fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            o_allMnfgFlags) );

fapi_try_exit:
    return fapi2::current_err;
}

//******************************************************************************
// fapi2::platAttrSvc::__dimmUpdateDqBitmapEccByte function
//******************************************************************************
ReturnCode __dimmUpdateDqBitmapEccByte(
    const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    uint8_t (&o_data)[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT] )
{
    ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;

    const uint8_t ECC_DQ_BYTE_NUMBER_INDEX = 8;
    const uint8_t ENUM_ATTR_SPD_MODULE_MEMORY_BUS_WIDTH_WE8 = 0x08;
    size_t MEM_BUS_WIDTH_SIZE = 0x01;
    uint8_t *l_eccBits = static_cast<uint8_t*>(malloc(MEM_BUS_WIDTH_SIZE));

    do
    {
        TARGETING::TargetHandle_t l_dimm = nullptr;
        l_errl = getTargetingTarget( i_fapiDimm, l_dimm );
        if ( l_errl )
        {
            FAPI_ERR( "__dimmUpdateDqBitmapEccByte: Error from "
                      "getTargetingTarget" );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        l_errl = deviceRead( l_dimm, l_eccBits, MEM_BUS_WIDTH_SIZE,
                             DEVICE_SPD_ADDRESS(SPD::MODULE_MEMORY_BUS_WIDTH) );
        if ( l_errl )
        {
            FAPI_ERR( "__dimmUpdateDqBitmapEccByte: Failed to get "
                      "SPD::MODULE_MEMORY_BUS_WIDTH." );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        // The ATTR_SPD_MODULE_MEMORY_BUS_WIDTH contains ENUM values
        // for bus widths of 8, 16, 32, and 64 bits both with ECC
        // and without ECC.  WExx ENUMS denote the ECC extension
        // is present, and all have bit 3 set.  Therefore,
        // it is only required to check against the WE8 = 0x08 ENUM
        // value in order to determine if ECC lines are present.
        if ( !(ENUM_ATTR_SPD_MODULE_MEMORY_BUS_WIDTH_WE8 & *l_eccBits) )
        {
            // Iterate through each rank and set DQ bits in
            // caller's data.
            for ( uint8_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++ )
            {
                // Set DQ bits in caller's data
                o_data[i][ECC_DQ_BYTE_NUMBER_INDEX] = 0xFF;
            }
        }
    }while(0);

    if ( l_eccBits != nullptr )
    {
        free( l_eccBits );
        l_eccBits = nullptr;
    }

    return l_rc;
}

//******************************************************************************
// fapi2::platAttrSvc::__dimmGetDqBitmapSpareByte function
//******************************************************************************
ReturnCode __dimmGetDqBitmapSpareByte(
    const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    uint8_t (&o_spareByte)[mss::MAX_RANK_PER_DIMM])
{
    ReturnCode l_rc;
    TARGETING::ATTR_MODEL_type procType = __getChipModel();
    uint8_t l_ps = 0;

    // Spare DRAM Attribute: Returns spare DRAM availability for
    // all DIMMs associated with the target MCS.
    uint8_t l_dramSpare[mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT]
                       [mss::MAX_RANK_PER_DIMM] = {};

    uint32_t l_ds = 0;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS, i_fapiDimm, l_ds) );
    l_ds = l_ds % mss::MAX_DIMM_PER_PORT;

    if ( TARGETING::MODEL_NIMBUS == procType )
    {
        // We need the port select from the MCS perspective here so we
        // can just use __getTranslationPortSlct.
        __getTranslationPortSlct( i_fapiDimm, l_ps );

        Target<TARGET_TYPE_MCA> l_fapiMca =
            i_fapiDimm.getParent<TARGET_TYPE_MCA>();

        // Get the MCS.
        Target<TARGET_TYPE_MCS> l_fapiMcs;
        l_fapiMcs = l_fapiMca.getParent<TARGET_TYPE_MCS>();

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_EFF_DIMM_SPARE, l_fapiMcs,
                                l_dramSpare) );
    }
    else if ( TARGETING::MODEL_CUMULUS == procType )
    {
        // In this case we need the port select from the MBA perspective
        // not the centaur perspective that __getTranslationPortSlct gives
        // us, so we can't use that function.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_PORT, i_fapiDimm, l_ps));
        l_ps = l_ps % MAX_PORTS_PER_MBA;

        Target<TARGET_TYPE_MBA> l_fapiMba =
            i_fapiDimm.getParent<TARGET_TYPE_MBA>();

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CEN_VPD_DIMM_SPARE, l_fapiMba,
                                l_dramSpare) );
    }
    else
    {
        // Get the MEM_PORT target
        Target<TARGET_TYPE_MEM_PORT> l_fapiMemPort =
            i_fapiDimm.getParent<TARGET_TYPE_MEM_PORT>();

        // The attribute exists on the MEM_PORT so we don't need to worry about
        // the port slct, just set the attribute in the space for port slct 0.
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DIMM_SPARE, l_fapiMemPort,
                                l_dramSpare[0]) );
        l_ps = 0;
    }

    // Iterate through each rank of this DIMM
    for ( uint8_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++ )
    {
        // Handle spare DRAM configuration cases
        switch ( l_dramSpare[l_ps][l_ds][i] )
        {
            case fapi2::ENUM_ATTR_EFF_DIMM_SPARE_NO_SPARE:
                // Set DQ bits reflecting unconnected
                // spare DRAM in caller's data
                o_spareByte[i] = 0xFF;
                break;

            case fapi2::ENUM_ATTR_EFF_DIMM_SPARE_LOW_NIBBLE:
                o_spareByte[i] = 0x0F;
                break;

            case fapi2::ENUM_ATTR_EFF_DIMM_SPARE_HIGH_NIBBLE:
                o_spareByte[i] = 0xF0;
                break;

                // As erroneous value will not be encountered.
            case fapi2::ENUM_ATTR_EFF_DIMM_SPARE_FULL_BYTE:
            default:
                o_spareByte[i] = 0x0;
                break;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

//******************************************************************************
// fapi2::platAttrSvc::__dimmUpdateDqBitmapSpareByte function
//******************************************************************************
ReturnCode __dimmUpdateDqBitmapSpareByte(
    const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    uint8_t (&o_data)[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT] )
{
    ReturnCode l_rc;

    uint8_t spareByte[mss::MAX_RANK_PER_DIMM];
    memset( spareByte, 0, sizeof(spareByte) );

    FAPI_TRY( __dimmGetDqBitmapSpareByte(i_fapiDimm, spareByte) );

    for ( uint32_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++ )
    {
        o_data[i][SPARE_DRAM_DQ_BYTE_NUMBER_INDEX] |= spareByte[i];
    }

fapi_try_exit:
    return fapi2::current_err;
}

//******************************************************************************
// fapi2::platAttrSvc::__compareEccAndSpare function
//******************************************************************************
ReturnCode __compareEccAndSpare(const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    bool & o_mfgModeBadBitsPresent,
    uint8_t i_bitmap[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT],
    uint8_t (&o_eccSpareBitmap)[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT])
{
    // This function will compare o_eccSpareBitmap, which represents a bad dq
    // bitmap with the appropriate spare/ECC bits set (if any) and all other DQ
    // lines functional, to the caller's data. If discrepancies are found, we
    // know this is the result of a manufacturing mode process and these bits
    // should not be recorded.

    ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;

    do
    {
        // Set a clean bitmap with only the appropriate spare/ECC bits set
        memset( o_eccSpareBitmap, 0, sizeof(o_eccSpareBitmap) );
        FAPI_TRY( __dimmUpdateDqBitmapEccByte(i_fapiDimm, o_eccSpareBitmap) );
        FAPI_TRY( __dimmUpdateDqBitmapSpareByte(i_fapiDimm, o_eccSpareBitmap) );

        // Compare o_eccSpareBitmap to i_bitmap.
        for ( uint8_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++ )
        {
            for (uint8_t j = 0; j < mss::BAD_DQ_BYTE_COUNT; j++)
            {
                if ( i_bitmap[i][j] != o_eccSpareBitmap[i][j] )
                {
                    o_mfgModeBadBitsPresent = true;
                    break;
                }
            }
            if ( o_mfgModeBadBitsPresent ) break;
        }

        // Create and log error if discrepancies were found.
        if ( o_mfgModeBadBitsPresent )
        {
            FAPI_ERR( "__compareEccAndSpare: Read/write requested while in "
                      "DISABLE_DRAM_REPAIRS mode found extra bad bits set for "
                      "DIMM" );

            TARGETING::TargetHandle_t l_dimm = nullptr;
            l_errl = getTargetingTarget( i_fapiDimm, l_dimm );
            if ( l_errl )
            {
                FAPI_ERR("__compareEccAndSpare: Error from getTargetingTarget");
                // Add the error log pointer as data to the ReturnCode
                addErrlPtrToReturnCode(l_rc, l_errl);
                break;
            }

            /*@
             * @errortype
             * @moduleid     MOD_FAPI2_BAD_DQ_BITMAP
             * @reasoncode   RC_BAD_DQ_MFG_MODE_BITS
             * @userdata1    DIMM Target HUID
             * @userdata2    <unused>
             * @devdesc      Extra bad bits set for DIMM
             * @custdesc     Read/write requested while in
             *               DISABLE_DRAM_REPAIRS mode found
             *               extra bad bits set for DIMM
             */
            l_errl = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_PREDICTIVE,
                    MOD_FAPI2_BAD_DQ_BITMAP,
                    RC_BAD_DQ_MFG_MODE_BITS,
                    TARGETING::get_huid(l_dimm) );

            l_errl->addFFDC( HWPF_COMP_ID, &o_eccSpareBitmap[0],
                             sizeof(o_eccSpareBitmap[0]), 1,
                             CLEAN_BAD_DQ_BITMAP_RANK0 );

            l_errl->addFFDC( HWPF_COMP_ID, &o_eccSpareBitmap[1],
                             sizeof(o_eccSpareBitmap[1]), 1,
                             CLEAN_BAD_DQ_BITMAP_RANK1 );

            l_errl->addFFDC( HWPF_COMP_ID, &o_eccSpareBitmap[2],
                             sizeof(o_eccSpareBitmap[2]), 1,
                             CLEAN_BAD_DQ_BITMAP_RANK2 );

            l_errl->addFFDC( HWPF_COMP_ID, &o_eccSpareBitmap[3],
                             sizeof(o_eccSpareBitmap[3]), 1,
                             CLEAN_BAD_DQ_BITMAP_RANK3 );

            l_errl->addFFDC( HWPF_COMP_ID, &i_bitmap[0],
                             sizeof(i_bitmap[0]), 1,
                             CURRENT_BAD_DQ_BITMAP_RANK0 );

            l_errl->addFFDC( HWPF_COMP_ID, &i_bitmap[1],
                             sizeof(i_bitmap[1]), 1,
                             CURRENT_BAD_DQ_BITMAP_RANK1 );

            l_errl->addFFDC( HWPF_COMP_ID, &i_bitmap[2],
                             sizeof(i_bitmap[2]), 1,
                             CURRENT_BAD_DQ_BITMAP_RANK2 );

            l_errl->addFFDC( HWPF_COMP_ID, &i_bitmap[3],
                             sizeof(i_bitmap[3]), 1,
                             CURRENT_BAD_DQ_BITMAP_RANK3 );

            l_errl->addHwCallout(l_dimm, HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::DELAYED_DECONFIG, HWAS::GARD_Predictive);

            errlCommit( l_errl, HWPF_COMP_ID );
        }
    }while(0);

    if ( l_rc )
    {
        return l_rc;
    }

fapi_try_exit:
    return fapi2::current_err;
}

//******************************************************************************
// fapi2::platAttrSvc::__mcLogicalToDimmDqHelper function
//******************************************************************************
ReturnCode __mcLogicalToDimmDqHelper(
    const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    wiringData  i_wiringData, uint8_t i_ps, uint8_t i_mcPin,
    uint8_t &o_dimm_dq )
{
    uint64_t l_c4 = 0;

    TARGETING::ATTR_MODEL_type procType = __getChipModel();

    if ( TARGETING::MODEL_NIMBUS == procType )
    {
        Target<TARGET_TYPE_MCA> l_fapiMca =
            i_fapiDimm.getParent<TARGET_TYPE_MCA>();

        // For Nimbus, translate from MC Logical to C4 format
        FAPI_TRY( mss::rosetta_map::mc_to_c4<mss::rosetta_type::DQ>(
                  l_fapiMca, i_mcPin, l_c4 ) );

        // use wiring data to translate c4 pin to dimm dq format
        // Note: the wiring data maps from dimm dq format to c4 format
        for ( uint8_t bit = 0; bit < mss::MAX_DQ_BITS; bit++ )
        {
            // Check to see which bit in the wiring data corresponds to our
            // DIMM DQ format pin.
            if ( i_wiringData.nimbus[i_ps][bit] == l_c4 )
            {
                o_dimm_dq = bit;
                break;
            }
        }
    }
    else if ( TARGETING::MODEL_CUMULUS == procType )
    {
        // For Cumulus, MC to C4 is 1-to-1
        l_c4 = i_mcPin;

        // use wiring data to translate c4 pin to dimm dq format
        // Note: the wiring data maps from dimm dq format to c4 format
        for ( uint8_t bit = 0; bit < DIMM_BAD_DQ_NUM_BYTES; bit++ )
        {
            // Check to see which bit in the wiring data corresponds to our
            // DIMM DQ format pin.
            if ( i_wiringData.cumulus[i_ps][bit] == l_c4 )
            {
                o_dimm_dq = bit;
                break;
            }
        }
    }
    else
    {
        // Note: the wiring data for MEM_PORTs/OCMBs is 1-to-1, so there
        // is no actual need to check the wiring data right now.
        o_dimm_dq = i_mcPin;
    }

fapi_try_exit:
    return fapi2::current_err;
}

//******************************************************************************
// fapi2::platAttrSvc::__dimmDqToMcLogicalHelper function
//******************************************************************************
ReturnCode __dimmDqToMcLogicalHelper(
    const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    wiringData  i_wiringData, uint8_t i_ps, uint8_t i_dimm_dq,
    uint8_t &o_mcPin )
{
    uint64_t l_c4 = 0;

    TARGETING::ATTR_MODEL_type procType = __getChipModel();

    if ( TARGETING::MODEL_NIMBUS == procType )
    {

        // Translate from DIMM DQ format to C4 using wiring data
        // Note: the wiring data maps from dimm dq format to c4 format
        l_c4 = i_wiringData.nimbus[i_ps][i_dimm_dq];

        Target<TARGET_TYPE_MCA> l_fapiMca =
            i_fapiDimm.getParent<TARGET_TYPE_MCA>();

        // For Nimbus, translate from C4 to MC Logical format
        uint64_t l_tmp = 0;
        FAPI_TRY( mss::rosetta_map::c4_to_mc<mss::rosetta_type::DQ>(l_fapiMca,
                  l_c4, l_tmp) );
        o_mcPin = static_cast<uint8_t>(l_tmp);
    }
    else if ( TARGETING::MODEL_CUMULUS == procType )
    {

        // Translate from DIMM DQ format to C4 using wiring data
        // Note: the wiring data maps from dimm dq format to c4 format
        l_c4 = i_wiringData.cumulus[i_ps][i_dimm_dq];

        // For Cumulus, C4 to MC Logical is 1-to-1
        o_mcPin = l_c4;
    }
    else
    {
        // Note: the wiring data for MEM_PORTs/OCMBs is 1-to-1, so there
        // is no actual need to check the wiring data right now.
        o_mcPin = i_dimm_dq;
    }

fapi_try_exit:
    return fapi2::current_err;

}

//******************************************************************************
// fapi2::platAttrSvc::__badDqBitTranslation function
//******************************************************************************
ReturnCode __badDqBitTranslation( const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    uint8_t i_initial_bm[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT],
    uint8_t (&o_translated_bm)[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT],
    wiringData i_wiringData, uint8_t i_spareByte[mss::MAX_RANK_PER_DIMM],
    uint8_t i_ps, bool i_mcLogicalToDimmDq )
{
    memset(o_translated_bm, 0, sizeof(o_translated_bm));

    // We need to translate the bad dq bits from MC logical format to
    // Connector/DIMM DQ format or back. This may require two translations
    // depending on the chip.

    // MC Logical/PHY<-->Module/C4 Package<-->Connector/DIMM DQ format

    // Note: MC Logical (0-71) maps linearly to PHY DP0(lane 0-15),
    // DP1(lane 0-15)...DP4(lane 0-15)

    // loop through iv_bitmaps ranks
    for ( uint8_t rank = 0; rank < mss::MAX_RANK_PER_DIMM; rank++ )
    {
        // loop through iv_bitmaps bytes
        for ( uint8_t byte = 0; byte < mss::BAD_DQ_BYTE_COUNT; byte++ )
        {
            // if bit found on
            if ( 0 != i_initial_bm[rank][byte] )
            {
                // find the set bit
                for ( uint8_t bit = 0; bit < mss::BITS_PER_BYTE; bit++ )
                {
                    if ( i_initial_bm[rank][byte] & (0x80 >> bit) )
                    {
                        // Check the spares
                        if ( byte == SPARE_DRAM_DQ_BYTE_NUMBER_INDEX &&
                             i_spareByte[rank] & (0x80 >> bit) )
                        {
                            // The spareByte can be one of: 0x00 0x0F 0xF0
                            // 0xFF If a bit is set, then that spare is
                            // unconnected so continue to the next bit,
                            // do not translate
                            continue;
                        }

                        // get the pin/bit position
                        uint8_t l_pin = (byte*8) + bit; // pin 0-79
                        uint8_t l_translatedPin = 0;

                        if ( i_mcLogicalToDimmDq )
                        {
                            // translate the MC logical pin to DIMM DQ format
                            FAPI_TRY( __mcLogicalToDimmDqHelper(i_fapiDimm,
                                      i_wiringData, i_ps, l_pin,
                                      l_translatedPin) );
                            FAPI_INF( "__badDqBitTranslation: Bad bit set, "
                                      "rank:%d before translation:%d, after "
                                      "translation:%d", rank, l_pin,
                                      l_translatedPin );
                        }
                        else
                        {
                            // translate the DIMM DQ pin to MC logical format
                            FAPI_TRY( __dimmDqToMcLogicalHelper(i_fapiDimm,
                                      i_wiringData, i_ps, l_pin,
                                      l_translatedPin) );
                        }

                        // set bit in new o_translated_bm
                        uint8_t l_setByte = l_translatedPin/8;
                        uint8_t l_setBit  = 0x80 >> (l_translatedPin%8);
                        o_translated_bm[rank][l_setByte] |= l_setBit;

                    }
                }
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}

//******************************************************************************
// fapi2::platAttrSvc::__badDqBitmapCheckForReconfigLoop function
//******************************************************************************
ReturnCode __badDqBitmapCheckForReconfigLoop(
    const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    uint8_t i_bitmap[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT] )
{
    // If, when setting the bad dq bitmap, we find new bits are set, we will
    // want to trigger a reconfig loop.
    bool l_badDqSet = false;

    // Read current BadDqBitmap into l_prev_data
    uint8_t l_prev_data[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT];
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_BAD_DQ_BITMAP, i_fapiDimm,
              l_prev_data) );

    // Check if Bad DQ bit set
    // Loop through all ranks
    for ( uint8_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++ )
    {
        // Loop through all DQs
        for ( uint8_t j = 0; j < mss::BAD_DQ_BYTE_COUNT; j++ )
        {
            // Loop through all bits
            for ( uint8_t k = 0; k < mss::BITS_PER_BYTE; k++ )
            {
                uint8_t prevBit = (l_prev_data[i][j] >> k) & 0x01;
                uint8_t newBit  = (i_bitmap[i][j] >> k) & 0x01;
                // Check for differences, and the bit was set, not cleared
                if ( (prevBit != newBit) && (newBit != 0) )
                {
                    l_badDqSet = true;
                    break;
                }
            }
            if ( l_badDqSet ) break;
        }
        if ( l_badDqSet ) break;
    }

    // Set ATTR_RECONFIGURE_LOOP to indicate a bad DqBitMap was set
    if ( l_badDqSet )
    {
        FAPI_INF( "__badDqBitmapCheckForReconfigLoop: Reconfigure needed, "
                  "Bad DQ set" );

        fapi2::ATTR_RECONFIGURE_LOOP_Type l_reconfigAttr = 0;
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_RECONFIGURE_LOOP,
                  fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_reconfigAttr) );

        // 'OR' values in case of multiple reasons for reconfigure
        l_reconfigAttr |= fapi2::ENUM_ATTR_RECONFIGURE_LOOP_BAD_DQ_BIT_SET;

        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_RECONFIGURE_LOOP,
                  fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_reconfigAttr) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

//******************************************************************************
// fapi2::platAttrSvc::fapiAttrGetBadDqBitmap function
//******************************************************************************
ReturnCode fapiAttrGetBadDqBitmap(
    const Target<TARGET_TYPE_ALL>& i_fapiTarget,
    ATTR_BAD_DQ_BITMAP_Type (&o_data) )
{
    FAPI_INF(">>fapiAttrGetBadDqBitmap: Getting bitmap");

    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;
    uint8_t * l_badDqData =
        static_cast<uint8_t*>( malloc(DIMM_BAD_DQ_SIZE_BYTES) );

    do
    {
        // Get the TARGETING dimm target
        TARGETING::TargetHandle_t l_dimmTarget = nullptr;
        l_errl = getTargetingTarget( i_fapiTarget, l_dimmTarget );
        if ( l_errl )
        {
            FAPI_ERR( "fapiAttrGetBadDqBitmap: Error from getTargetingTarget" );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        // Get the FAPI dimm target
        Target<TARGET_TYPE_DIMM> l_fapiDimm( l_dimmTarget );

        wiringData l_wiringData;
        uint64_t l_allMnfgFlags;
        uint8_t l_ps = 0;

        FAPI_TRY( __badDqBitmapGetHelperAttrs(l_fapiDimm, l_wiringData,
                                              l_allMnfgFlags, l_ps) );

        l_errl = deviceRead( l_dimmTarget, l_badDqData, DIMM_BAD_DQ_SIZE_BYTES,
                             DEVICE_SPD_ADDRESS(SPD::DIMM_BAD_DQ_DATA) );
        if ( l_errl )
        {
            FAPI_ERR( "fapiAttrGetBadDqBitmap: Failed to read DIMM Bad DQ "
                      "data." );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        dimmBadDqDataFormat l_spdData;
        memcpy( &l_spdData, l_badDqData, sizeof(dimmBadDqDataFormat) );

        // Zero caller's data
        memset(o_data, 0, sizeof(o_data));

        // Check the magic number and version number. Note that the
        // magic number is stored in SPD in big endian format and
        // platforms of any endianness can access it
        if ( (be32toh(l_spdData.iv_magicNumber) != DIMM_BAD_DQ_MAGIC_NUMBER) ||
             (l_spdData.iv_version != DIMM_BAD_DQ_VERSION) )
        {
            FAPI_INF( "fapiAttrGetBadDqBitmap: SPD DQ not initialized." );

            // We still set the ECC and spare bytes in the output data to
            // avoid issues in the setter when SPD DQ is not initialized.
            // Set bits for any unconnected DQs.
            // First, check ECC.
            FAPI_TRY( __dimmUpdateDqBitmapEccByte(l_fapiDimm, o_data) );

            // Check spare DRAM.
            FAPI_TRY( __dimmUpdateDqBitmapSpareByte(l_fapiDimm, o_data) );
        }
        else
        {
            // Get the spare byte
            uint8_t l_spareByte[mss::MAX_RANK_PER_DIMM];
            memset( l_spareByte, 0, sizeof(l_spareByte) );

            FAPI_TRY( __dimmGetDqBitmapSpareByte(l_fapiDimm, l_spareByte) );

            // Translate bitmap from DIMM DQ to MC Logical format
            FAPI_TRY( __badDqBitTranslation(l_fapiDimm, l_spdData.iv_bitmaps,
                                            o_data, l_wiringData, l_spareByte,
                                            l_ps, false) );

            // Set bits for any unconnected DQs.
            // First, check ECC.
            FAPI_TRY( __dimmUpdateDqBitmapEccByte(l_fapiDimm, o_data) );

            // Check spare DRAM.
            FAPI_TRY( __dimmUpdateDqBitmapSpareByte(l_fapiDimm, o_data) );

            if ( l_allMnfgFlags &
                    fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_DRAM_REPAIRS )
            {
                // Flag to set if the discrepancies are found.
                bool l_mfgModeBadBitsPresent = false;

                uint8_t l_eccSpareBitmap[mss::MAX_RANK_PER_DIMM]
                                        [mss::BAD_DQ_BYTE_COUNT];

                FAPI_TRY( __compareEccAndSpare(l_fapiDimm,
                          l_mfgModeBadBitsPresent, o_data, l_eccSpareBitmap) );

                if ( l_mfgModeBadBitsPresent )
                {
                    // correct the output bit map
                    for (uint8_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++)
                    {
                        for ( uint8_t j=0; j < (mss::BAD_DQ_BYTE_COUNT);
                                j++ )
                        {
                            o_data[i][j] = l_eccSpareBitmap[i][j];
                        }
                    }
                }
            }

        }

    }while(0);

fapi_try_exit:

    FAPI_INF("<<fapiAttrGetBadDqBitmap: Finished getting bitmap");

    if ( l_badDqData != nullptr )
    {
        free( l_badDqData );
        l_badDqData = nullptr;
    }

    if ( l_rc )
    {
        return l_rc;
    }

    return fapi2::current_err;

}

//******************************************************************************
// fapi2::platAttrSvc::fapiAttrSetBadDqBitmap function
//******************************************************************************
ReturnCode fapiAttrSetBadDqBitmap(
    const Target<TARGET_TYPE_ALL>& i_fapiTarget,
    ATTR_BAD_DQ_BITMAP_Type (&i_data) )
{
    FAPI_INF(">>fapiAttrSetBadDqBitmap: Setting bitmap");

    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;
    uint8_t * l_badDqData =
        static_cast<uint8_t*>( malloc(DIMM_BAD_DQ_SIZE_BYTES) );
    do
    {
        // Get the TARGETING dimm target
        TARGETING::TargetHandle_t l_dimmTarget = nullptr;
        l_errl = getTargetingTarget( i_fapiTarget, l_dimmTarget );
        if ( l_errl )
        {
            FAPI_ERR( "fapiAttrSetBadDqBitmap: Error from getTargetingTarget" );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        // Get the FAPI dimm target
        Target<TARGET_TYPE_DIMM> l_fapiDimm( l_dimmTarget );

        wiringData l_wiringData;
        uint64_t l_allMnfgFlags;
        uint8_t l_ps = 0;

        // Get the helper attributes
        FAPI_TRY( __badDqBitmapGetHelperAttrs(l_fapiDimm, l_wiringData,
                                              l_allMnfgFlags, l_ps) );

        // Make sure to update the ecc and spare bytes in the inputted bitmap
        // just to make sure we don't see any differences there.
        uint8_t l_tmpBitmap[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT];
        memcpy( &l_tmpBitmap, &i_data, sizeof(i_data) );

        FAPI_TRY( __dimmUpdateDqBitmapEccByte(l_fapiDimm, l_tmpBitmap) );
        FAPI_TRY( __dimmUpdateDqBitmapSpareByte(l_fapiDimm, l_tmpBitmap) );

        // Check if we need to trigger a reconfig loop.
        FAPI_TRY( __badDqBitmapCheckForReconfigLoop(l_fapiDimm, l_tmpBitmap) );

        // If system is in DISABLE_DRAM_REPAIRS mode
        if ( l_allMnfgFlags &
             fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_DRAM_REPAIRS )
        {

            uint8_t l_eccSpareBitmap[mss::MAX_RANK_PER_DIMM]
                                    [mss::BAD_DQ_BYTE_COUNT];

            bool l_mfgModeBadBitsPresent = false;
            FAPI_TRY( __compareEccAndSpare(l_fapiDimm, l_mfgModeBadBitsPresent,
                                           l_tmpBitmap, l_eccSpareBitmap) );

            // Don't write bad dq bitmap if discrepancies are found
            // Break out of do while loop
            if ( l_mfgModeBadBitsPresent ) break;
        }

        // Set up the data to write to SPD
        dimmBadDqDataFormat l_spdData;
        l_spdData.iv_magicNumber = htobe32( DIMM_BAD_DQ_MAGIC_NUMBER );
        l_spdData.iv_version = DIMM_BAD_DQ_VERSION;
        l_spdData.iv_reserved1 = 0;
        l_spdData.iv_reserved2 = 0;
        l_spdData.iv_reserved3 = 0;
        memset( l_spdData.iv_bitmaps, 0, sizeof(l_spdData.iv_bitmaps) );

        // We need to make sure the rest of the data in VPD beyond the bad dq
        // bitmap is unchanged.
        l_errl = deviceRead( l_dimmTarget, l_badDqData,
                             DIMM_BAD_DQ_SIZE_BYTES,
                             DEVICE_SPD_ADDRESS(SPD::DIMM_BAD_DQ_DATA) );
        if ( l_errl )
        {
            FAPI_ERR( "fapiAttrSetBadDqBitmap: Failed to read DIMM Bad DQ "
                      "data." );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        dimmBadDqDataFormat l_prevSpdData;
        memcpy( &l_prevSpdData, l_badDqData, sizeof(dimmBadDqDataFormat) );
        memcpy( &l_spdData.iv_rowRepairData, l_prevSpdData.iv_rowRepairData,
                sizeof(l_spdData.iv_rowRepairData) );
        memcpy( &l_spdData.iv_unused, l_prevSpdData.iv_unused,
                sizeof(l_spdData.iv_unused) );

        // Get the spare byte
        uint8_t l_spareByte[mss::MAX_RANK_PER_DIMM];
        memset( l_spareByte, 0, sizeof(l_spareByte) );

        FAPI_TRY( __dimmGetDqBitmapSpareByte(l_fapiDimm, l_spareByte) );

        // Translate bitmap from MC Logical to DIMM DQ format
        FAPI_TRY( __badDqBitTranslation(l_fapiDimm, i_data,
                                        l_spdData.iv_bitmaps, l_wiringData,
                                        l_spareByte, l_ps, true) );

        l_errl = deviceWrite( l_dimmTarget, &l_spdData, DIMM_BAD_DQ_SIZE_BYTES,
                              DEVICE_SPD_ADDRESS(SPD::DIMM_BAD_DQ_DATA) );
        if ( l_errl )
        {
            FAPI_ERR( "fapiAttrSetBadDqBitmap: Failed to write DIMM "
                      "Bad DQ data." );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

    }while(0);

fapi_try_exit:

    FAPI_INF("<<fapiAttrSetBadDqBitmap: Finished setting bitmap");

    if ( l_badDqData != nullptr )
    {
        free( l_badDqData );
        l_badDqData = nullptr;
    }

    if ( l_rc )
    {
        return l_rc;
    }

    return fapi2::current_err;
}

//******************************************************************************
// fapi2::platAttrSvc::__isX4Dram function
//******************************************************************************
ReturnCode __isX4Dram( const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
                       bool & o_isX4Dram )
{
    o_isX4Dram = false;

    TARGETING::ATTR_MODEL_type procType = __getChipModel();

    // Get if drams are x4 or x8
    if ( TARGETING::MODEL_NIMBUS == procType )
    {
        // Nimbus only supports x4 DRAMs
        o_isX4Dram = true;
    }
    else if ( TARGETING::MODEL_CUMULUS == procType )
    {
        // Get the MBA
        Target<TARGET_TYPE_MBA> l_fapiMba =
            i_fapiDimm.getParent<TARGET_TYPE_MBA>();

        uint8_t l_dramWidth;
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DRAM_WIDTH, l_fapiMba,
                                l_dramWidth) );
        o_isX4Dram = ( fapi2::ENUM_ATTR_CEN_EFF_DRAM_WIDTH_X4 == l_dramWidth );
    }
    else
    {
        // Get the MEM_PORT target
        Target<TARGET_TYPE_MEM_PORT> l_fapiMemPort =
            i_fapiDimm.getParent<TARGET_TYPE_MEM_PORT>();

        // Get the dram width attr and the dimm slct
        uint8_t l_dramWidth[2];
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_DRAM_WIDTH, l_fapiMemPort,
                                l_dramWidth) );

        TARGETING::TargetHandle_t l_dimmTrgt;
        errlHndl_t l_errl = getTargetingTarget( i_fapiDimm, l_dimmTrgt );
        if ( l_errl )
        {
            FAPI_ERR("__isX4Dram: Error getting dimm from getTargetingTarget");
            fapi2::ReturnCode l_rc;
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            return l_rc;
        }
        uint8_t l_dimmSlct =
            l_dimmTrgt->getAttr<TARGETING::ATTR_POS_ON_MEM_PORT>();

        o_isX4Dram = ( fapi2::ENUM_ATTR_MEM_EFF_DRAM_WIDTH_X4 ==
                       l_dramWidth[l_dimmSlct] );
    }

fapi_try_exit:
    return fapi2::current_err;
}
//******************************************************************************
// fapi2::platAttrSvc::__dramToDq function
//******************************************************************************
ReturnCode __dramToDq( const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    uint8_t i_dram, uint8_t & o_dq )
{
    o_dq = 0;

    // Convert dram pos to symbol
    // Get if drams are x4 or x8
    bool l_isX4 = false;
    FAPI_TRY( __isX4Dram(i_fapiDimm, l_isX4) );

    o_dq = i_dram * ( l_isX4 ? 4 : 8 );

fapi_try_exit:
    return fapi2::current_err;
}

//******************************************************************************
// fapi2::platAttrSvc::__dqToDram function
//******************************************************************************
ReturnCode __dqToDram( const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    uint8_t i_dq, uint8_t & o_dram )
{
    o_dram = 0;

    // Convert symbol to dram pos
    // Get if drams are x4 or x8
    bool l_isX4 = false;
    FAPI_TRY( __isX4Dram(i_fapiDimm, l_isX4) );

    o_dram = i_dq / ( l_isX4 ? 4 : 8 );

fapi_try_exit:
    return fapi2::current_err;
}

//******************************************************************************
// fapi2::platAttrSvc::__rowRepairTranslateDramPos function
//******************************************************************************
ReturnCode __rowRepairTranslateDramPos(
    const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
    bool i_mcLogicalToDimmDq,
    ATTR_ROW_REPAIR_DATA_Type & io_translatedData )
{
    wiringData l_wiringData;
    uint64_t l_allMnfgFlags;
    uint8_t l_ps = 0;

    // Get the wiring data and port select for translation.
    FAPI_TRY( __badDqBitmapGetHelperAttrs(i_fapiDimm, l_wiringData,
                                          l_allMnfgFlags, l_ps) );

    // Loop through each rank.
    for ( uint8_t rank = 0; rank < mss::MAX_RANK_PER_DIMM; rank++ )
    {
        // The first 5 bits of the stored row repair are the dram position
        // that needs to be translated. The next three are the slave rank.
        uint8_t l_dramPosAndSrank = io_translatedData[rank][0];
        uint8_t l_dramPos = (l_dramPosAndSrank >> 3) & 0x1f;
        uint8_t l_srank = l_dramPosAndSrank & 0x07;

        // The last bit of the row repair stores the validity bit
        bool l_valid = io_translatedData[rank][mss::ROW_REPAIR_BYTE_COUNT-1]
            & 0x01;

        // If the row repair isn't valid, no need to translate anything
        if ( !l_valid ) continue;

        uint8_t l_dq = 0;
        FAPI_TRY( __dramToDq(i_fapiDimm, l_dramPos, l_dq) );

        uint8_t l_translatedDq = 0;

        if ( i_mcLogicalToDimmDq )
        {
            FAPI_TRY( __mcLogicalToDimmDqHelper(i_fapiDimm, l_wiringData,
                                                l_ps, l_dq, l_translatedDq) );
        }
        else
        {
            FAPI_TRY( __dimmDqToMcLogicalHelper(i_fapiDimm, l_wiringData,
                                                l_ps, l_dq, l_translatedDq) );
        }

        uint8_t l_translatedDram = 0;
        FAPI_TRY( __dqToDram(i_fapiDimm, l_translatedDq, l_translatedDram) );

        if ( i_mcLogicalToDimmDq )
        {
            FAPI_INF( "__rowRepairTranslateDramPos: Row repair set, rank:%d "
                      "dram pos before translation:%d, after translation:%d",
                      rank, l_dramPos, l_translatedDram );
        }

        uint8_t l_updatedData = (l_translatedDram << 3) | l_srank;

        io_translatedData[rank][0] = l_updatedData;
    }

fapi_try_exit:
    return fapi2::current_err;

}

//******************************************************************************
// fapi2::platAttrSvc::getRowRepairData function
//******************************************************************************
ReturnCode getRowRepairData( const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                             ATTR_ROW_REPAIR_DATA_Type (&o_data) )
{
    FAPI_INF(">>getRowRepairData: Getting row repair data");

    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;
    uint8_t * l_data =
        static_cast<uint8_t*>( malloc(DIMM_BAD_DQ_SIZE_BYTES) );
    do
    {
        // Get the TARGETING dimm target
        TARGETING::TargetHandle_t l_dimmTarget = nullptr;
        l_errl = getTargetingTarget( i_fapiTarget, l_dimmTarget );
        if ( l_errl )
        {
            FAPI_ERR( "getRowRepairData: Error from getTargetingTarget" );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        // Get the FAPI dimm target
        Target<TARGET_TYPE_DIMM> l_fapiDimm( l_dimmTarget );

        // Zero callers data.
        memset(o_data, 0, sizeof(o_data));

        // Read the data
        l_errl = deviceRead( l_dimmTarget, l_data, DIMM_BAD_DQ_SIZE_BYTES,
                             DEVICE_SPD_ADDRESS(SPD::DIMM_BAD_DQ_DATA) );
        if ( l_errl )
        {
            FAPI_ERR( "getRowRepairData: Failed to call deviceRead to get "
                      "l_data." );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        dimmBadDqDataFormat l_spdData;
        memcpy( &l_spdData, l_data, sizeof(dimmBadDqDataFormat) );

        // Check the header for correct data.
        if ( (be32toh(l_spdData.iv_magicNumber) != DIMM_BAD_DQ_MAGIC_NUMBER) ||
             (l_spdData.iv_version != DIMM_BAD_DQ_VERSION) )
        {
            FAPI_INF( "getRowRepairData: DIMM VPD not initialized." );
        }
        else
        {
            // Get the row repair data.
            memcpy( &o_data, &l_spdData.iv_rowRepairData,
                    sizeof(ATTR_ROW_REPAIR_DATA_Type) );

            // Translate the DRAM position in the row repair data
            FAPI_TRY( __rowRepairTranslateDramPos(l_fapiDimm, false, o_data ) );
        }

    }while(0);

fapi_try_exit:

    FAPI_INF("<<getRowRepairData: Finished getting row repair data");

    if ( l_data != nullptr )
    {
        free( l_data );
        l_data = nullptr;
    }

    if ( l_rc )
    {
        return l_rc;
    }

    return fapi2::current_err;
}

//******************************************************************************
// fapi2::platAttrSvc::setRowRepairData function
//******************************************************************************
ReturnCode setRowRepairData( const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                             ATTR_ROW_REPAIR_DATA_Type (&i_data) )
{
    FAPI_INF(">>setRowRepairData: Setting row repair data");

    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;
    uint8_t * l_data =
        static_cast<uint8_t*>( malloc(DIMM_BAD_DQ_SIZE_BYTES) );
    do
    {
        // Get the TARGETING dimm target
        TARGETING::TargetHandle_t l_dimmTarget = nullptr;
        l_errl = getTargetingTarget( i_fapiTarget, l_dimmTarget );
        if ( l_errl )
        {
            FAPI_ERR( "setRowRepairData: Error from getTargetingTarget" );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        // Get the FAPI dimm target
        Target<TARGET_TYPE_DIMM> l_fapiDimm( l_dimmTarget );

        // Get the original data.
        l_errl = deviceRead( l_dimmTarget, l_data, DIMM_BAD_DQ_SIZE_BYTES,
                             DEVICE_SPD_ADDRESS(SPD::DIMM_BAD_DQ_DATA) );
        if ( l_errl )
        {
            FAPI_ERR( "setRowRepairData: Failed to call deviceRead to get "
                      "l_data." );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        dimmBadDqDataFormat l_spdData;
        memcpy( &l_spdData, l_data, sizeof(dimmBadDqDataFormat) );

        // Update the header
        l_spdData.iv_magicNumber = htobe32( DIMM_BAD_DQ_MAGIC_NUMBER );
        l_spdData.iv_version = DIMM_BAD_DQ_VERSION;
        l_spdData.iv_reserved1 = 0;
        l_spdData.iv_reserved2 = 0;
        l_spdData.iv_reserved3 = 0;

        // Translate the input data
        ATTR_ROW_REPAIR_DATA_Type l_translatedData;
        memcpy( &l_translatedData, i_data, sizeof(ATTR_ROW_REPAIR_DATA_Type) );
        FAPI_TRY( __rowRepairTranslateDramPos(l_fapiDimm, true,
                                              l_translatedData) );
        // Update the row repair data
        memcpy( &l_spdData.iv_rowRepairData, l_translatedData,
                sizeof(ATTR_ROW_REPAIR_DATA_Type) );

        // Write the data back to VPD.
        l_errl = deviceWrite( l_dimmTarget, &l_spdData, DIMM_BAD_DQ_SIZE_BYTES,
                              DEVICE_SPD_ADDRESS(SPD::DIMM_BAD_DQ_DATA) );
        if ( l_errl )
        {
            FAPI_ERR( "setRowRepairData: Failed to call deviceWrite to set "
                      "l_spdData." );
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

    }while(0);

fapi_try_exit:

    FAPI_INF("<<setRowRepairData: Finished setting row repair data");

    if ( l_data != nullptr )
    {
        free( l_data );
        l_data = nullptr;
    }

    if ( l_rc )
    {
        return l_rc;
    }

    return fapi2::current_err;
}

//******************************************************************************
// fapi::platAttrSvc::platGetSecurityMode function
//******************************************************************************
ReturnCode platGetSecurityMode(uint8_t & o_securityMode)
{
    #ifndef __HOSTBOOT_RUNTIME
    o_securityMode = SECUREBOOT::getSbeSecurityMode();
    #else
    o_securityMode = 0xFF;
    FAPI_INF("Get SECURITY_MODE not supported from hostboot runtime");
    #endif
    return fapi2::ReturnCode();
}

//******************************************************************************
// fapi::platAttrSvc::platSetSecurityMode function
//******************************************************************************
ReturnCode platSetSecurityMode()
{
    FAPI_INF("Set SECURITY_MODE ignored when called from FAPI code");
    return fapi2::ReturnCode();
}

//-----------------------------------------------------------------------------
ReturnCode platGetControlCapableData(
                                const Target<TARGET_TYPE_ALL>& i_fapiTarget,
        ATTR_CEN_VPD_POWER_CONTROL_CAPABLE_Type& o_vpdPowerControlCapableVal
                                    )
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetControlCapableData: Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
        rc = getControlCapableData(l_fapiTarget, o_vpdPowerControlCapableVal);
    }

    return rc;
}

template<typename T1>
struct VPD_CACHING_PAIR
{
    TARGETING::ATTR_HUID_type huid;
    T1 value;

    inline bool operator==(TARGETING::ATTR_HUID_type huid_rhs) {
        return huid_rhs == huid;
    }
} ;

//-----------------------------------------------------------------------------
ReturnCode platGetDQAttrISDIMM(
                           const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                           ATTR_CEN_VPD_ISDIMMTOC4DQ_Type &o_vpdIsDimmTOC4DQVal
                              )
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    static std::vector<VPD_CACHING_PAIR<ATTR_CEN_VPD_ISDIMMTOC4DQ_Type>> l_cachedC4DQValues;
    static mutex_t l_C4DQmutex = MUTEX_INITIALIZER;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetDQAttrISDIMM: Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        mutex_lock(&l_C4DQmutex);
        auto l_huid = TARGETING::get_huid(l_pTarget);
        auto l_iterator = std::find ( l_cachedC4DQValues.begin(),
                                      l_cachedC4DQValues.end(),
                                      l_huid);

        if(l_iterator == l_cachedC4DQValues.end())
        {
            fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
            VPD_CACHING_PAIR<ATTR_CEN_VPD_ISDIMMTOC4DQ_Type> l_kvPair = VPD_CACHING_PAIR<ATTR_CEN_VPD_ISDIMMTOC4DQ_Type>();
            l_kvPair.huid = l_huid;
            rc = getDQAttrISDIMM(l_fapiTarget, l_kvPair.value);
            memcpy(o_vpdIsDimmTOC4DQVal, l_kvPair.value, sizeof(ATTR_CEN_VPD_ISDIMMTOC4DQ_Type));
            l_cachedC4DQValues.push_back(l_kvPair);
        }
        else
        {
            memcpy(o_vpdIsDimmTOC4DQVal, (*l_iterator).value, sizeof(ATTR_CEN_VPD_ISDIMMTOC4DQ_Type));
        }
        mutex_unlock(&l_C4DQmutex);
    }

    return rc;
}


//-----------------------------------------------------------------------------
ReturnCode platGetDQSAttrISDIMM(
                    const Target<TARGET_TYPE_ALL>& i_fapiTarget,
          ATTR_CEN_VPD_ISDIMMTOC4DQS_Type& o_vpdIsDimmTOC4DQSVal
                               )
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    static std::vector<VPD_CACHING_PAIR<ATTR_CEN_VPD_ISDIMMTOC4DQS_Type>> l_cachedC4DQSValues;
    static mutex_t l_C4DQSmutex = MUTEX_INITIALIZER;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetDQSAttrISDIMM: Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        mutex_lock(&l_C4DQSmutex);
        auto l_huid = TARGETING::get_huid(l_pTarget);
        auto l_iterator = std::find ( l_cachedC4DQSValues.begin(),
                                      l_cachedC4DQSValues.end(),
                                      l_huid);

        if(l_iterator == l_cachedC4DQSValues.end())
        {
            fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
            VPD_CACHING_PAIR<ATTR_CEN_VPD_ISDIMMTOC4DQS_Type>l_kvPair =
                                  VPD_CACHING_PAIR<ATTR_CEN_VPD_ISDIMMTOC4DQS_Type>();
            l_kvPair.huid = l_huid;
            rc = getDQSAttrISDIMM(l_fapiTarget, l_kvPair.value);
            memcpy(o_vpdIsDimmTOC4DQSVal, l_kvPair.value, sizeof(ATTR_CEN_VPD_ISDIMMTOC4DQS_Type));
            l_cachedC4DQSValues.push_back(l_kvPair);
        }
        else
        {
            memcpy(o_vpdIsDimmTOC4DQSVal, (*l_iterator).value, sizeof(ATTR_CEN_VPD_ISDIMMTOC4DQS_Type));
        }
        mutex_unlock(&l_C4DQSmutex);
    }

    return rc;
}

//-----------------------------------------------------------------------------
ReturnCode platGetMBvpdSensorMapPrimary(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                   ATTR_CEN_VPD_CDIMM_SENSOR_MAP_PRIMARY_Type& o_SensorMapType
                                        )
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetMBvpdSensorMapPrimary: "
                                              "Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
        rc = getMBvpdSensorMap(l_fapiTarget, fapi2::SENSOR_MAP_PRIMARY, o_SensorMapType);
    }

    return rc;
}

//-----------------------------------------------------------------------------
ReturnCode platGetMBvpdSensorMapSecondary(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                   ATTR_CEN_VPD_CDIMM_SENSOR_MAP_SECONDARY_Type& o_SensorMapType
                                        )
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetMBvpdSensorMapSecondary: "
                                              "Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
        rc = getMBvpdSensorMap(l_fapiTarget, fapi2::SENSOR_MAP_SECONDARY, o_SensorMapType);
    }

    return rc;
}

//-----------------------------------------------------------------------------
ReturnCode platGetMBvpdDramAddressMirroring(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                   ATTR_CEN_VPD_DRAM_ADDRESS_MIRRORING_Type& o_dramAddressMirroring
                                        )
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetMBvpdDramAddressMirroring: "
                                              "Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MBA> l_fapiTarget(l_pTarget);
        rc = getMBvpdAddrMirrorData(l_fapiTarget, o_dramAddressMirroring);
    }

    return rc;
}

//-----------------------------------------------------------------------------
ReturnCode platGetMBvpdDram2NModeEnabled(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                   ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED_Type& o_dram2NModeEnabled
                                        )
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetMBvpdDram2NModeEnabled: "
                                              "Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MBA> l_fapiTarget(l_pTarget);
        rc = getMBvpdDram2NModeEnabled(l_fapiTarget, o_dram2NModeEnabled);
    }

    return rc;
}

//-----------------------------------------------------------------------------
ReturnCode platGetMBvpdMemoryDataVersion(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                ATTR_CEN_VPD_VM_KEYWORD_Type& o_vpdVMKeywordVal
                                        )
{
    ReturnCode rc;

    do
    {
        // Don't need to check the type here, the FAPI_ATTR_GET macro clause
        // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
        // to enable a streamlined dump of the attributes, all plat code must
        // use the generic TARGET_TYPE_ALL -- so convert back to the correct
        // type manually
        TARGETING::Target * l_pTarget = NULL;
        errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

        if (l_errl)
        {
            FAPI_ERR("platGetMBvpdMemoryDataVersion: "
                                           "Error from getTargetingTarget");

            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(rc, l_errl);
            break;
        }
        else
        {
            fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>
                                                    l_fapiTarget(l_pTarget);

            rc = getMBvpdMemoryDataVersion(l_fapiTarget, o_vpdVMKeywordVal);
        }
    }
    while(0);

    return rc;
}

//-----------------------------------------------------------------------------
ReturnCode platGetMBvpdSPDXRecordVersion(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                ATTR_CEN_VPD_VD_KEYWORD_Type& o_vpdVDKeywordVal
                                        )
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetMBvpdSPDXRecordVersion: "
                                              "Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
        rc = getMBvpdSPDXRecordVersion(l_fapiTarget, o_vpdVDKeywordVal);
    }

    return rc;
}

//-----------------------------------------------------------------------------
ReturnCode platGetMBvpdSpareDramData(
                                  const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                 ATTR_CEN_VPD_DIMM_SPARE_Type& o_vpdDimmSpare
                                    )
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetMBvpdSpareDramData: Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MBA> l_fapiTarget(l_pTarget);
        rc = getMBvpdSpareDramData(l_fapiTarget, o_vpdDimmSpare);
    }

    return rc;
}

//-----------------------------------------------------------------------------
ReturnCode platGetMBvpdVersion(
                                 const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                 ATTR_CEN_VPD_VERSION_Type& o_vpdVersion
                               )
{
    ReturnCode rc;

    do
    {
        // Don't need to check the type here, the FAPI_ATTR_GET macro clause
        // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
        // to enable a streamlined dump of the attributes, all plat code must use
        // the generic TARGET_TYPE_ALL -- so convert back to the correct type
        // manually
        TARGETING::Target * l_pTarget = NULL;
        errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

        if (l_errl)
        {
            FAPI_ERR("platGetMBvpdVersion: Error from getTargetingTarget");
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(rc, l_errl);
        }
        else
        {
            TARGETING::TargetHandleList l_mbaList;

            // Find MBA target from DIMM target
            getParentAffinityTargets(l_mbaList,
                                     l_pTarget,
                                     TARGETING::CLASS_UNIT,
                                     TARGETING::TYPE_MBA,
                                     false);

            const bool hbSwError = true;

            if(l_mbaList.empty())
            {
                /*@
                 * @errortype
                 * @moduleid     fapi2::MOD_FAPI2_GET_ATTR_CEN_VPD_VERSION
                 * @reasoncode   fapi2::RC_NO_PARENT_MBA
                 * @userdata1    DIMM HUID
                 * @userdata2    0
                 * @devdesc      platGetMBvpdMemoryDataVersion could not find
                 *               an mba parent target from the passed in
                 *               dimm target.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                                     ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     fapi2::MOD_FAPI2_GET_ATTR_CEN_VPD_VERSION,
                                     fapi2::RC_NO_SINGLE_MBA,
                                     TARGETING::get_huid(l_pTarget),
                                     0,
                                     hbSwError);

                FAPI_ERR("platGetMBvpdVersion: "
                                "Error could not find an MBA parent for DIMM");

                // Add the error log pointer as data to the ReturnCode
                addErrlPtrToReturnCode(rc, l_errl);
                break;
            }
            else if(l_mbaList.size() != 1)
            {
                /*@
                 * @errortype
                 * @moduleid     fapi2::MOD_FAPI2_GET_ATTR_CEN_VPD_VERSION
                 * @reasoncode   fapi2::RC_NO_SINGLE_MBA
                 * @userdata1    Number of MBAs
                 * @userdata2    DIMM HUID
                 * @devdesc      platGetMBvpdMemoryDataVersion could not find
                 *               the expected 1 mba from the passed dimm target
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                                     ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     fapi2::MOD_FAPI2_GET_ATTR_CEN_VPD_VERSION,
                                     fapi2::RC_NO_SINGLE_MBA,
                                     l_mbaList.size(),
                                     TARGETING::get_huid(l_pTarget),
                                     hbSwError);

                FAPI_ERR("platGetMBvpdVersion: "
                         "Found multiple MBA chips while "
                         "seeking parent for DIMM");

                // Add the error log pointer as data to the ReturnCode
                addErrlPtrToReturnCode(rc, l_errl);
                break;
            }

            fapi2::Target<fapi2::TARGET_TYPE_MBA>
                                            l_fapiTarget(l_mbaList.front());

            rc = getMBvpdVersion(l_fapiTarget, o_vpdVersion);
        }

    }
    while(0);

    return rc;
}

//-----------------------------------------------------------------------------
ReturnCode platGetMBvpdVoltageSettingData(
                                const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                               ATTR_CEN_VPD_DW_KEYWORD_Type& o_vpdDWKeyword
                                         )
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetMBvpdVoltageSettingData: "
                                              "Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
        rc = getMBvpdVoltageSettingData(l_fapiTarget, o_vpdDWKeyword);
    }

    return rc;
}

//----------------------------------------------------------------------------
ReturnCode platGetMBvpdAttr(
                           const fapi2::Target<TARGET_TYPE_ALL>&  i_fapiTarget,
                           const fapi2::AttributeId i_attr,
                           void*   o_pVal,
                           const size_t i_valSize
                           )
{
    ReturnCode rc;
    constexpr bool hbSwError{true};

    do
    {
        // Don't need to check the type here, the FAPI_ATTR_GET macro clause
        // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
        // to enable a streamlined dump of the attributes, all plat code must
        // use the generic TARGET_TYPE_ALL -- so convert back to the correct
        // type manually
        TARGETING::Target * l_pTarget = NULL;
        errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

        if (l_errl)
        {
            FAPI_ERR("platGetMBvpdAttr: Error from getTargetingTarget");
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(rc, l_errl);
        }
        else
        {
            TARGETING::TYPE l_type =
                                l_pTarget->getAttr<TARGETING::ATTR_TYPE>();

            if(TARGETING::TYPE_MBA != l_type)
            {
                if(TARGETING::TYPE_MEMBUF != l_type)
                {
                    /*@
                     * @errortype
                     * @moduleid     fapi2::MOD_FAPI2_GET_MB_VPD_ATTR
                     * @reasoncode   fapi2::RC_INVALID_TARGET_TYPE
                     * @userdata1    Target Type
                     * @userdata2    Target HUID
                     * @devdesc      platGetMBvpdMemoryDataVersion requires
                     *               a target of type TYPE_MBA or TYPE_MEMBUF
                     */
                    l_errl = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      fapi2::MOD_FAPI2_GET_ATTR_CEN_VPD_VERSION,
                                      fapi2::RC_INVALID_TARGET_TYPE,
                                      l_type,
                                      TARGETING::get_huid(l_pTarget),
                                      hbSwError);

                    rc = ReturnCode(fapi2::RC_INVALID_TARGET_TYPE);
                    // Add the error log pointer as data to the ReturnCode
                    addErrlPtrToReturnCode(rc, l_errl);
                    FAPI_ERR("platGetMBvpdAttr: Invalid Target Type.");
                    break;
                }

                TARGETING::TargetHandleList l_mbaList;
                TARGETING::getChildAffinityTargets(l_mbaList,
                                                   l_pTarget,
                                                   TARGETING::CLASS_UNIT,
                                                   TARGETING::TYPE_MBA,
                                                   false);

                if(l_mbaList.empty())
                {
                    /*@
                     * @errortype
                     * @moduleid     fapi2::MOD_FAPI2_GET_MB_VPD_ATTR
                     * @reasoncode   fapi2::RC_NO_CHILD_MBA
                     * @userdata1    Target Type
                     * @userdata2    Target HUID
                     * @devdesc      platGetMBvpdMemoryDataVersion could not
                     *               find any child mba's from the passed in
                     *               target of type TYPE_MEMBUF
                     */
                    l_errl = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      fapi2::MOD_FAPI2_GET_ATTR_CEN_VPD_VERSION,
                                      fapi2::RC_NO_CHILD_MBA,
                                      l_type,
                                      TARGETING::get_huid(l_pTarget),
                                      hbSwError);

                    // Add the error log pointer as data to the ReturnCode
                    addErrlPtrToReturnCode(rc, l_errl);
                    FAPI_ERR("platGetMBvpdAttr: Could not find a child mba "
                             "for the passed in membuf target."
                            );
                    break;
                }

                //since we have to get the value from a child mba, try all
                //child mba's until successful.
                for(auto l_currentMba: l_mbaList)
                {
                    fapi2::Target<fapi2::TARGET_TYPE_MBA>
                                                   l_fapiTarget(l_currentMba);

                    rc = getMBvpdAttr(l_fapiTarget,
                                      i_attr,
                                      o_pVal,
                                      i_valSize);

                    if(rc == fapi2::FAPI2_RC_SUCCESS)
                    {
                        break;
                    }
                }
            }
            else
            {

                fapi2::Target<fapi2::TARGET_TYPE_MBA> l_fapiTarget(l_pTarget);
                rc = getMBvpdAttr(l_fapiTarget,
                                  i_attr,
                                  o_pVal,
                                  i_valSize);
            }
        }
    }
    while(0);

    return rc;
}

//******************************************************************************
// fapi::platAttrSvc::getPllBucket function
//******************************************************************************
ReturnCode getPllBucket(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                        uint8_t & o_bucket_val,
                        const uint8_t i_index)
{
    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;

    TARGETING::Target * l_chipTarget = nullptr;
    l_errl = getTargetingTarget(i_fapiTarget, l_chipTarget);
    if(l_errl)
    {
        FAPI_ERR("getPllBucket: Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_errl);
    }
    else
    {
        l_errl = Util::getObusPllBucket(l_chipTarget, o_bucket_val, i_index);
        if (l_errl)
        {
            FAPI_ERR("getPllBucket: Error from getObusPllBucket");
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
        }
    }
    return l_rc;
}

//-----------------------------------------------------------------------------
ReturnCode platGetMBvpdSlopeInterceptData(
                                   const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                   const uint32_t i_attr,
                                   uint32_t& o_val)
{
    ReturnCode rc;

    // Don't need to check the type here, the FAPI_ATTR_GET macro clause
    // "fapi2::Target<ID##_TargetType>(TARGET)" does it for us.  However,
    // to enable a streamlined dump of the attributes, all plat code must use
    // the generic TARGET_TYPE_ALL -- so convert back to the correct type
    // manually
    TARGETING::Target * l_pTarget = NULL;
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetMBvpdSPDXRecordVersion: "
                                              "Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        MBvpdSlopeIntercept l_val;

        switch (i_attr)
        {
            case ATTR_CEN_CDIMM_VPD_MASTER_POWER_INTERCEPT:
                l_val = MASTER_POWER_INTERCEPT;
                break;
            case ATTR_CEN_CDIMM_VPD_MASTER_POWER_SLOPE:
                l_val = MASTER_POWER_SLOPE;
                break;
            case ATTR_CEN_CDIMM_VPD_MASTER_TOTAL_POWER_INTERCEPT:
                l_val = MASTER_TOTAL_POWER_INTERCEPT;
                break;
            case ATTR_CEN_CDIMM_VPD_MASTER_TOTAL_POWER_SLOPE:
                l_val = MASTER_TOTAL_POWER_SLOPE;
                break;
            case ATTR_CEN_CDIMM_VPD_SUPPLIER_POWER_INTERCEPT:
                l_val = SUPPLIER_POWER_INTERCEPT;
                break;
            case ATTR_CEN_CDIMM_VPD_SUPPLIER_POWER_SLOPE:
                l_val = SUPPLIER_POWER_SLOPE;
                break;
            case ATTR_CEN_CDIMM_VPD_SUPPLIER_TOTAL_POWER_INTERCEPT:
                l_val = SUPPLIER_TOTAL_POWER_INTERCEPT;
                break;
            case ATTR_CEN_CDIMM_VPD_SUPPLIER_TOTAL_POWER_SLOPE:
                l_val = SUPPLIER_TOTAL_POWER_SLOPE;
                break;
            default:
                l_val = MASTER_POWER_INTERCEPT;
        }

        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
        rc = getMBvpdSlopeInterceptData(l_fapiTarget, l_val, o_val);
    }

    return rc;
}

#ifndef CONFIG_AXONE
//******************************************************************************
// fapi::platAttrSvc::platGetFreqMcaMhz function
//******************************************************************************
ReturnCode platGetFreqMcaMhz(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                             ATTR_FREQ_MCA_MHZ_Type & o_val)
{
    // The POR config for Cumulus is to run the MC/DMI clocks directly
    // off of the NEST PLL in 'sync' mode.  To support 'sync' mode FW
    // can pin ATTR_FREQ_MCA_MHZ == ATTR_FREQ_PB_MHZ.

    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;

    TARGETING::Target * l_chipTarget = nullptr;
    l_errl = getTargetingTarget(i_fapiTarget, l_chipTarget);
    if(l_errl)
    {
        FAPI_ERR("platGetFreqMcaMhz: Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(l_rc, l_errl);
    }
    else
    {
        o_val = l_chipTarget->getAttr<TARGETING::ATTR_FREQ_PB_MHZ>();
    }
    return l_rc;
}

#else

/// @brief This function is called by the FAPI_ATTR_GET functions that lookup
/// values in the MEM_PLL_FREQ_BUCKETS tree. The key's used to lookup values in that
/// tree are the ATTR_FREQ_OMI_MHZ and ATTR_OMI_PLL_VCO attributes. These are on the
/// processor target but it is expected that all of the values match.
///  @param[out] o_omiFreq  OMI Frequency of the system
///  @param[out] o_omiVco   OMI VCO of the system
///  @return ReturnCode Zero on success, else platform specified error.
errlHndl_t getOmiFreqAndVco(TARGETING::ATTR_FREQ_OMI_MHZ_type & o_omiFreq,
                            TARGETING::ATTR_OMI_PLL_VCO_type & o_omiVco)
{
    errlHndl_t l_errl = nullptr;

    // Get all functional Proc targets
    TARGETING::TargetHandleList l_procsList;
    getAllChips(l_procsList, TARGETING::TYPE_PROC);
    uint8_t l_firstValidProc = 0;
    bool l_outValueSet = false;

    // Until we are told we need to support individual processor frequency
    // assert that all of the processors have the same values
    for(uint8_t i = 0; i < l_procsList.size(); i++)
    {
        // Get a list of functional OCMB targets under this processor
        TARGETING::TargetHandleList l_childOcmbList;
        TARGETING::getChildAffinityTargets(l_childOcmbList, l_procsList[i],
                                           TARGETING::CLASS_CHIP,
                                           TARGETING::TYPE_OCMB_CHIP);
        // If there are no OCMB children for this processor then ignore it;
        if(l_childOcmbList.size() == 0)
        {
            continue;
        }

        // First valid processor's values will be used to compare against all other processors
        if(!l_outValueSet)
        {
            o_omiFreq = l_procsList[i]->getAttr<TARGETING::ATTR_FREQ_OMI_MHZ>();
            o_omiVco = l_procsList[i]->getAttr<TARGETING::ATTR_OMI_PLL_VCO>();
            l_outValueSet = true;
            l_firstValidProc = i;
            continue;
        }

        TARGETING::ATTR_FREQ_OMI_MHZ_type l_omiFreqToCmp = l_procsList[i]->getAttr<TARGETING::ATTR_FREQ_OMI_MHZ>();
        TARGETING::ATTR_OMI_PLL_VCO_type  l_omiVcoToCmp  = l_procsList[i]->getAttr<TARGETING::ATTR_OMI_PLL_VCO>();

        // If this processors OMI freq is 0 then we have not determined this proc's OMI freq yet so we can ignore it.
        // Otherwise, if we found that this processor's OMI freq / vco values do not match the first processor's values then
        // return an error
        if ((l_omiFreqToCmp != 0) &&
            (l_omiFreqToCmp != o_omiFreq ||
            l_omiVcoToCmp  != o_omiVco ))
        {
            FAPI_ERR("platGetMcPllBucket: Detected two processors with difference OMI VCO / FREQ combinations."
                      " Proc 0x%.08X has OMI freq = %d and OMI vco = %d. "
                      " Proc 0x%.08X has OMI freq = %d and OMI vco = %d. " ,
                    get_huid(l_procsList[l_firstValidProc]), o_omiFreq, o_omiVco,
                    get_huid(l_procsList[i]), l_omiFreqToCmp, l_omiVcoToCmp );

            /*@
              * @errortype
              * @moduleid     fapi2::MOD_GET_OMI_FREQ_AND_VCO
              * @reasoncode   fapi2::RC_PROC_FREQ_MISMATCH
              * @userdata1[0:31]  first ATTR_FREQ_OMI_MHZ found
              * @userdata1[32:63] first ATTR_FREQ_PLL_VCO found
              * @userdata2[0:31]  ATTR_FREQ_OMI_MHZ mismatch found
              * @userdata2[32:63] ATTR_FREQ_PLL_VCO mismatch found
              * @devdesc      Found mismatching processor attribute settings
              *               when we expect them to all be in sync
              */
            l_errl = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              fapi2::MOD_GET_OMI_FREQ_AND_VCO,
                              fapi2::RC_NO_MATCHING_FREQ,
                              TWO_UINT32_TO_UINT64(o_omiFreq, o_omiVco),
                              TWO_UINT32_TO_UINT64(l_omiFreqToCmp, l_omiVcoToCmp),
                              ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 256);
            break;
        }
    }

    return l_errl;
}

// OMI bucket descriptor
struct OmiFreqVcoBucketSelect_t
{
    uint32_t omifreq;   // OMI Frequency in MHz
    uint32_t vco;       // VCO selector
    uint8_t pll_bucket; // MCA Frequency in MHz
};


//******************************************************************************
// fapi::platAttrSvc::platGetMcPllBucket function
//******************************************************************************
ReturnCode platGetMcPllBucket(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                             ATTR_MC_PLL_BUCKET_Type & o_val)
{
    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;
    TARGETING::Target * l_sysTarget = nullptr;
    TARGETING::ATTR_FREQ_OMI_MHZ_type l_omiFreq = 0;
    TARGETING::ATTR_OMI_PLL_VCO_type  l_omiVco  = 0;
    bool l_matchFound = false;

    // There can be up to 2 matches for OMI frequencies. If only 1 match is found
    // then we ignore the VCO attribute
    std::vector<OmiFreqVcoBucketSelect_t> l_omiFreqMatches;

    do{
        // Convert to platform-style target
        l_errl = getTargetingTarget(i_fapiTarget, l_sysTarget);

        if(l_errl)
        {
            FAPI_ERR("platGetMcPllBucket: Error from getTargetingTarget");
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        // Use helper function to lookup omi frequency and omi vco for this system
        l_errl = getOmiFreqAndVco(l_omiFreq, l_omiVco);

        if(l_errl)
        {
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        // Loop through the MEM_PLL frequency buckets to see if we can find a bucket that
        // matches what we have found for omi freq and vco
        for(uint8_t i = 0; i < MEM_PLL_FREQ_BUCKETS; i++)
        {
            if(OMI_PLL_FREQ_LIST[i].omifreq == l_omiFreq)
            {
                OmiFreqVcoBucketSelect_t l_tmpBucketSelect = {OMI_PLL_FREQ_LIST[i].omifreq, OMI_PLL_FREQ_LIST[i].vco, i};
                l_omiFreqMatches.push_back(l_tmpBucketSelect);
            }
        }

        if(l_omiFreqMatches.size() > 1)
        {
            for(uint8_t i = 0; i < l_omiFreqMatches.size(); i++)
            {
                if(l_omiFreqMatches[i].vco == l_omiVco)
                {
                    FAPI_INF("Found match to be bucket %d for freq %d, vco %d",
                             l_omiFreqMatches[i].pll_bucket,
                             OMI_PLL_FREQ_LIST[i].omifreq,
                             OMI_PLL_FREQ_LIST[i].vco);
                    l_matchFound = true;
                    // Value returned in this case is the bucket number that had the matching values
                    // MC_PLL_BUCKET attribute is 1-based so increment bucket ID by 1
                    o_val = l_omiFreqMatches[i].pll_bucket + 1;
                    break;
                }
            }
        }
        else if (l_omiFreqMatches.size() == 1)
        {
            FAPI_INF("Single match for OMI freq %d found in OMI_PLL_FREQ_LIST, ignoring VCO attribute. PLL Bucket = %d",
                     l_omiFreq,
                     l_omiFreqMatches[0].pll_bucket);
            l_matchFound = true;
            // MC_PLL_BUCKET attribute is 1-based so increment bucket ID by 1
            o_val = l_omiFreqMatches[0].pll_bucket + 1;
        }

        // If not match is found return an error
        if(!l_matchFound)
        {
            FAPI_ERR("platGetMcPllBucket: Could not find matching bucket for omiFreq = %d and vco = %d",
                    l_omiFreq, l_omiVco);

            /*@
              * @errortype
              * @moduleid     fapi2::MOD_FAPI2_PLAT_GET_MC_PLL_BUCKET
              * @reasoncode   fapi2::RC_NO_MATCHING_FREQ
              * @userdata1[0:31]  ATTR_FREQ_OMI_MHZ
              * @userdata1[32:63] ATTR_FREQ_PLL_VCO
              * @userdata2    Target HUID
              * @devdesc      Invalid omi frequence and omi vco settings
              */
            l_errl = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              fapi2::MOD_FAPI2_PLAT_GET_MC_PLL_BUCKET,
                              fapi2::RC_NO_MATCHING_FREQ,
                              TWO_UINT32_TO_UINT64(l_omiFreq, l_omiVco),
                              TARGETING::get_huid(l_sysTarget),
                              ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 256);
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

    }while(0);
    return l_rc;
}

//******************************************************************************
// fapi::platAttrSvc::platGetFreqMcaMhz function
//******************************************************************************
ReturnCode platGetFreqMcaMhz(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                             ATTR_FREQ_MCA_MHZ_Type & o_val)
{
    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;
    TARGETING::Target * l_sysTarget = nullptr;
    TARGETING::ATTR_FREQ_OMI_MHZ_type l_omiFreq = 0;
    TARGETING::ATTR_OMI_PLL_VCO_type  l_omiVco  = 0;
    bool l_matchFound = false;

    // There can be up to 2 matches for OMI frequencies. If only 1 match is found
    // then we ignore the VCO attribute
    std::vector<OmiBucketDescriptor_t> l_matchingOmiBucketDescriptors;

    do{
        // Convert to platform-style target
        l_errl = getTargetingTarget(i_fapiTarget, l_sysTarget);

        if(l_errl)
        {
            FAPI_ERR("platGetFreqMcaMhz: Error from getTargetingTarget");
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        // Use helper function to lookup omi frequency and omi vco for this system
        l_errl = getOmiFreqAndVco(l_omiFreq, l_omiVco);

        if(l_errl)
        {
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

        // Loop through the MEM_PLL frequency buckets to see if we can find a bucket that
        // matches what we have found for omi freq and vco
        for(uint8_t i = 0; i < MEM_PLL_FREQ_BUCKETS; i++)
        {
            if(OMI_PLL_FREQ_LIST[i].omifreq == l_omiFreq)
            {
                l_matchingOmiBucketDescriptors.push_back(OMI_PLL_FREQ_LIST[i]);
            }
        }

        if(l_matchingOmiBucketDescriptors.size() > 1)
        {
            for(uint8_t i = 0; i < l_matchingOmiBucketDescriptors.size(); i++)
            {
                if(l_matchingOmiBucketDescriptors[i].vco == l_omiVco)
                {
                    FAPI_INF("found match for freq %d, vco %d. Mca freq = %d",
                             OMI_PLL_FREQ_LIST[i].omifreq, OMI_PLL_FREQ_LIST[i].vco);
                    l_matchFound = true;
                    // Value returned in this case is the bucket number that had the matching values
                    o_val = l_matchingOmiBucketDescriptors[i].mcafreq;
                    break;
                }
            }
        }
        else if (l_matchingOmiBucketDescriptors.size() == 1)
        {
            FAPI_INF("Single match for OMI freq %d found in OMI_PLL_FREQ_LIST, MCA freq found = %d, ignoring VCO attribute",
                     l_omiFreq,
                     l_matchingOmiBucketDescriptors[0].mcafreq);
            l_matchFound = true;
            o_val = l_matchingOmiBucketDescriptors[0].mcafreq;
        }

        if(!l_matchFound)
        {
            FAPI_ERR("platGetFreqMcaMhz: Could not find matching bucket for omiFreq = %d and vco = %d",
                    l_omiFreq, l_omiVco);

            /*@
              * @errortype
              * @moduleid     fapi2::MOD_FAPI2_PLAT_GET_FREQ_MCA_MHZ
              * @reasoncode   fapi2::RC_NO_MATCHING_FREQ
              * @userdata1[0:31]  ATTR_FREQ_OMI_MHZ
              * @userdata1[32:63] ATTR_FREQ_PLL_VCO
              * @userdata2    Target HUID
              * @devdesc      Invalid omi frequence and omi vco settings
              */
            l_errl = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              fapi2::MOD_FAPI2_PLAT_GET_FREQ_MCA_MHZ,
                              fapi2::RC_NO_MATCHING_FREQ,
                              TWO_UINT32_TO_UINT64(l_omiFreq, l_omiVco),
                              TARGETING::get_huid(l_sysTarget),
                              ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
            // Add the error log pointer as data to the ReturnCode
            addErrlPtrToReturnCode(l_rc, l_errl);
            break;
        }

    }while(0);
    return l_rc;
}



#endif

//******************************************************************************
// fapi::platAttrSvc::platIncrementCounter function
//******************************************************************************
ReturnCode platIncrementOcmbCounter(const Target<TARGET_TYPE_ALL>& i_fapiTarget,
                                    uint32_t & o_val)
{
    fapi2::ReturnCode rc;
    errlHndl_t l_errl = nullptr;

    TARGETING::Target * l_chipTarget = nullptr;
    static mutex_t l_counter_mutex = MUTEX_INITIALIZER;
    l_errl = getTargetingTarget(i_fapiTarget, l_chipTarget);
    if (l_errl)
    {
        FAPI_ERR("platIncrementOcmbCounter: Error from getTargetingTarget");
        // Add the error log pointer as data to the ReturnCode
        addErrlPtrToReturnCode(rc, l_errl);
    }
    else
    {
        mutex_lock(&l_counter_mutex);
        o_val = l_chipTarget->getAttr<TARGETING::ATTR_OCMB_COUNTER_HB>();
        if( o_val == 0 )
        {
            // seed each target with a unique number to make messages more
            //  distinct across operations
            o_val = (l_chipTarget->getAttr<TARGETING::ATTR_HUID>()
                     && 0x0000FFFF) << 16;
        }
        else
        {
            ++o_val;
        }
        l_chipTarget->setAttr<TARGETING::ATTR_OCMB_COUNTER_HB>(o_val);
        mutex_unlock(&l_counter_mutex);
    }
    return rc;
}
} // End platAttrSvc namespace

} // End fapi2 namespace
