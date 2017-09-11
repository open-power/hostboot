/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/attribute_service.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

#include <devicefw/driverif.H>
#include <plat_attr_override_sync.H>
#include <vpd/spdenums.H>
#include <p9_pm_get_poundv_bucket_attr.H>
#include <p9_pm_get_poundw_bucket_attr.H>
#include <errl/errlmanager.H>

#include <targeting/common/targetservice.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/util.H>
#include <../memory/lib/shared/mss_const.H>

#include <secureboot/service.H>

#include<vpd_accessors/accessMBvpdL4BankDelete.H>
#include<vpd_accessors/getControlCapableData.H>
#include<vpd_accessors/getDQAttrISDIMM.H>
#include<vpd_accessors/getDQSAttrISDIMM.H>
#include<vpd_accessors/getISDIMMTOC4DAttrs.H>
#include<vpd_accessors/getMBvpdDram2NModeEnabled.H>
#include<vpd_accessors/getMBvpdMemoryDataVersion.H>
#include<vpd_accessors/getMBvpdSPDXRecordVersion.H>
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

            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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

            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
        FAPI_ERR("platGetTargetPos: Error from getTargetingTarget");
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
        rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
        rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
};

// constant definitions
const uint8_t  SPARE_DRAM_DQ_BYTE_NUMBER_INDEX = 9;
const uint32_t DIMM_BAD_DQ_MAGIC_NUMBER = 0xbadd4471;
const uint8_t  DIMM_BAD_DQ_VERSION = 1;
size_t DIMM_BAD_DQ_SIZE_BYTES = 0x50;

//******************************************************************************
// fapi2::platAttrSvc::__getMcsAndPortSlct function
//******************************************************************************
ReturnCode __getMcsAndPortSlct( const Target<TARGET_TYPE_DIMM>& i_fapiDimm,
                                TARGETING::TargetHandle_t &o_mcsTarget,
                                uint32_t o_ps )
{
    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;

    do
    {
        // determine whether this is a Nimbus or Cumulus chip
        TARGETING::Target * masterProc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(masterProc);
        TARGETING::ATTR_MODEL_type procType =
            masterProc->getAttr<TARGETING::ATTR_MODEL>();

        TARGETING::TargetHandle_t l_port = nullptr;

        // If the proc is Cumulus, we need to get the MBA.
        if ( TARGETING::MODEL_CUMULUS == procType )
        {
            Target<TARGET_TYPE_MBA> l_fapiMba =
                i_fapiDimm.getParent<TARGET_TYPE_MBA>();
            l_errl = getTargetingTarget( l_fapiMba, l_port );
            if ( l_errl )
            {
                FAPI_ERR( "__getMcsAndPortSlct: Error from "
                          "getTargetingTarget getting MBA." );
                l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
                break;
            }

            // Get the MCS.
            TARGETING::TargetHandleList l_memBufList;
            getParentAffinityTargets( l_memBufList, l_port,
                TARGETING::CLASS_CHIP, TARGETING::TYPE_MEMBUF );

            TARGETING::TargetHandleList l_mcsList;
            getParentAffinityTargets( l_mcsList, l_memBufList[0],
                TARGETING::CLASS_UNIT, TARGETING::TYPE_MCS );
            o_mcsTarget = l_mcsList[0];

        }
        // If the proc is Nimbus, we need to get the MCA.
        else
        {
            Target<TARGET_TYPE_MCA> l_fapiMca =
                i_fapiDimm.getParent<TARGET_TYPE_MCA>();
            l_errl = getTargetingTarget( l_fapiMca, l_port );
            if ( l_errl )
            {
                FAPI_ERR( "__getMcsAndPortSlct: Error from "
                          "getTargetingTarget getting MCA." );
                l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
                break;
            }

            // Get the MCS.
            Target<TARGET_TYPE_MCS> l_fapiMcs;
            l_fapiMcs = l_fapiMca.getParent<TARGET_TYPE_MCS>();

            l_errl = getTargetingTarget( l_fapiMcs, o_mcsTarget );
            if ( l_errl )
            {
                FAPI_ERR( "__getMcsAndPortSlct: Error from "
                        "getTargetingTarget getting MCS." );
                l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
                break;
            }

        }

        o_ps = l_port->getAttr<TARGETING::ATTR_CHIP_UNIT>() %
               mss::PORTS_PER_MCS;

    }while(0);

    return l_rc;
}


//******************************************************************************
// fapi2::platAttrSvc::__badDqBitmapGetHelperAttrs function
//******************************************************************************
ReturnCode __badDqBitmapGetHelperAttrs(
    const TARGETING::TargetHandle_t i_dimmTarget,
    uint8_t  (&o_wiringData)[mss::PORTS_PER_MCS][mss::MAX_DQ_BITS],
    uint64_t &o_allMnfgFlags, uint32_t o_ps )
{
    fapi2::ReturnCode l_rc;

    do
    {
        // memset to avoid known syntax issue with previous compiler versions
        // and ensure zero initialized array.
        memset( o_wiringData, 0, sizeof(o_wiringData) );

        Target<TARGET_TYPE_DIMM> l_fapiDimm( i_dimmTarget );
        TARGETING::TargetHandle_t l_mcsTarget = nullptr;

        __getMcsAndPortSlct( l_fapiDimm, l_mcsTarget, o_ps );

        // Get the DQ to DIMM Connector DQ Wiring attribute.
        // Note that for C-DIMMs, this will return a simple 1:1 mapping.
        // This code cannot tell the difference between C-DIMMs and IS-DIMMs.
        l_rc = FAPI_ATTR_GET( fapi2::ATTR_MSS_VPD_DQ_MAP, l_mcsTarget,
                              o_wiringData );
        if ( l_rc )
        {
            FAPI_ERR( "__badDqBitmapGetHelperAttrs: Unable to read attribute - "
                      "ATTR_MSS_VPD_DQ_MAP" );
            break;
        }

        // Manufacturing flags attribute
        o_allMnfgFlags = 0;

        // Get the manufacturing flags bitmap to be used in both get and set
        l_rc = FAPI_ATTR_GET( fapi2::ATTR_MNFG_FLAGS,
                              fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                              o_allMnfgFlags );
        if ( l_rc )
        {
            FAPI_ERR( "__badDqBitmapGetHelperAttrs: Unable to read attribute - "
                      "ATTR_MNFG_FLAGS" );
            break;
        }

    }while(0);

    return l_rc;
}

//******************************************************************************
// fapi2::platAttrSvc::__dimmUpdateDqBitmapEccByte function
//******************************************************************************
errlHndl_t __dimmUpdateDqBitmapEccByte(
    TARGETING::TargetHandle_t i_dimm,
    uint8_t (&o_data)[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT] )
{
    errlHndl_t l_errl = nullptr;

    const uint8_t ECC_DQ_BYTE_NUMBER_INDEX = 8;
    const uint8_t ENUM_ATTR_SPD_MODULE_MEMORY_BUS_WIDTH_WE8 = 0x08;
    size_t MEM_BUS_WIDTH_SIZE = 0x01;

    do
    {
        uint8_t *l_eccBits = static_cast<uint8_t*>(malloc(MEM_BUS_WIDTH_SIZE));

        l_errl = deviceRead( i_dimm,
                l_eccBits,
                MEM_BUS_WIDTH_SIZE,
                DEVICE_SPD_ADDRESS(SPD::MODULE_MEMORY_BUS_WIDTH) );
        if ( l_errl )
        {
            FAPI_ERR( "__dimmUpdateDqBitmapEccByte: Failed to get "
                      "SPD::MODULE_MEMORY_BUS_WIDTH." );
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

    return l_errl;
}

//******************************************************************************
// fapi2::platAttrSvc::__dimmGetDqBitmapSpareByte function
//******************************************************************************
ReturnCode __dimmGetDqBitmapSpareByte( TARGETING::TargetHandle_t i_dimm,
    uint8_t (&o_spareByte)[mss::MAX_RANK_PER_DIMM])
{
    ReturnCode l_rc;

    do
    {
        // Spare DRAM Attribute: Returns spare DRAM availability for
        // all DIMMs associated with the target MCS.
        uint8_t l_dramSpare[mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT]
                           [mss::MAX_RANK_PER_DIMM] = {};

        Target<TARGET_TYPE_DIMM> l_fapiDimm( i_dimm );

        uint32_t l_ds = i_dimm->getAttr<TARGETING::ATTR_FAPI_POS>() %
                        mss::MAX_DIMM_PER_PORT;

        TARGETING::TargetHandle_t l_mcsTarget = nullptr;
        uint32_t l_ps = 0;
        __getMcsAndPortSlct( l_fapiDimm, l_mcsTarget, l_ps );

        l_rc = FAPI_ATTR_GET( fapi2::ATTR_EFF_DIMM_SPARE, l_mcsTarget,
                              l_dramSpare );
        if ( l_rc )
        {
            FAPI_ERR( "__dimmGetDqBitmapSpareByte: Error getting DRAM Spare "
                     "data." );
            break;
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

    }while(0);

    return l_rc;

}

//******************************************************************************
// fapi2::platAttrSvc::__dimmUpdateDqBitmapSpareByte function
//******************************************************************************
ReturnCode __dimmUpdateDqBitmapSpareByte(
    TARGETING::TargetHandle_t i_dimm,
    uint8_t (&o_data)[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT] )
{
    ReturnCode l_rc;

    do
    {
        uint8_t spareByte[mss::MAX_RANK_PER_DIMM];
        memset( spareByte, 0, sizeof(spareByte) );

        l_rc = __dimmGetDqBitmapSpareByte( i_dimm, spareByte );

        if ( l_rc )
        {
            FAPI_ERR("__dimmUpdateDqBitmapSpareByte: Error getting spare byte");
            break;
        }

        for ( uint32_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++ )
        {
            o_data[i][SPARE_DRAM_DQ_BYTE_NUMBER_INDEX] |= spareByte[i];
        }

    }while(0);

    return l_rc;
}

//******************************************************************************
// fapi2::platAttrSvc::__compareEccAndSpare function
//******************************************************************************
ReturnCode __compareEccAndSpare(TARGETING::TargetHandle_t i_dimm,
    bool & o_mfgModeBadBitsPresent,
    uint8_t i_callersData[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT],
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
        // Zero-initialize the o_eccSpareBitmap bad dq bitmap.
        memset( o_eccSpareBitmap, 0, sizeof(o_eccSpareBitmap) );

        // Check ECC.
        l_errl = __dimmUpdateDqBitmapEccByte(i_dimm, o_eccSpareBitmap);
        if ( l_errl )
        {
            FAPI_ERR( "__compareEccAndSpare: Error getting ECC data "
                      "(Mfg mode)" );
            l_rc = fapi2::FAPI2_RC_INVALID_ATTR_GET;
            break;
        }

        // Check spare DRAM.
        l_rc = __dimmUpdateDqBitmapSpareByte(i_dimm, o_eccSpareBitmap);
        if ( l_rc )
        {
            FAPI_ERR( "__compareEccAndSpare: Error getting spare DRAM data "
                      "(Mfg mode)" );
            break;
        }

        // Compare o_eccSpareBitmap to i_callersData.
        for ( uint8_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++ )
        {
            for (uint8_t j = 0; j < mss::BAD_DQ_BYTE_COUNT; j++)
            {
                if ( i_callersData[i][j] !=
                     o_eccSpareBitmap[i][j] )
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
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    MOD_FAPI2_BAD_DQ_BITMAP,
                    RC_BAD_DQ_MFG_MODE_BITS,
                    TARGETING::get_huid(i_dimm) );

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

            l_errl->addFFDC( HWPF_COMP_ID, &i_callersData[0],
                             sizeof(i_callersData[0]), 1,
                             CURRENT_BAD_DQ_BITMAP_RANK0 );

            l_errl->addFFDC( HWPF_COMP_ID, &i_callersData[1],
                             sizeof(i_callersData[1]), 1,
                             CURRENT_BAD_DQ_BITMAP_RANK1 );

            l_errl->addFFDC( HWPF_COMP_ID, &i_callersData[2],
                             sizeof(i_callersData[2]), 1,
                             CURRENT_BAD_DQ_BITMAP_RANK2 );

            l_errl->addFFDC( HWPF_COMP_ID, &i_callersData[3],
                             sizeof(i_callersData[3]), 1,
                             CURRENT_BAD_DQ_BITMAP_RANK3 );

            errlCommit( l_errl, HWPF_COMP_ID );
        }
    }while(0);

    return l_rc;
}

//******************************************************************************
// fapi2::platAttrSvc::fapiAttrGetBadDqBitmap function
//******************************************************************************
ReturnCode fapiAttrGetBadDqBitmap(
    const Target<TARGET_TYPE_ALL>& i_dimmFapiTarget,
    ATTR_BAD_DQ_BITMAP_Type (&o_data) )
{
    FAPI_INF(">>fapiAttrGetBadDqBitmap: Getting bitmap");

    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;
    TARGETING::TargetHandle_t l_dimmTarget = nullptr;

    do
    {
        l_errl = getTargetingTarget( i_dimmFapiTarget, l_dimmTarget );
        if ( l_errl )
        {
            FAPI_ERR( "fapiAttrGetBadDqBitmap: Error from getTargetingTarget" );
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
            break;
        }

        uint8_t  l_wiringData[mss::PORTS_PER_MCS][mss::MAX_DQ_BITS];
        uint64_t l_allMnfgFlags;
        uint32_t l_ps = 0;

        l_rc = __badDqBitmapGetHelperAttrs( l_dimmTarget, l_wiringData,
                                            l_allMnfgFlags, l_ps );
        if ( l_rc )
        {
            FAPI_ERR( "fapiAttrGetBadDqBitmap: Error - unable to read "
                      "attributes" );
            break;
        }

        uint8_t * l_badDqData =
            static_cast<uint8_t*>( malloc(DIMM_BAD_DQ_SIZE_BYTES) );

        l_errl = deviceRead(l_dimmTarget, l_badDqData,
                            DIMM_BAD_DQ_SIZE_BYTES,
                            DEVICE_SPD_ADDRESS(SPD::DIMM_BAD_DQ_DATA));
        if ( l_errl )
        {
            FAPI_ERR( "fapiAttrGetBadDqBitmap: Failed to read DIMM Bad DQ "
                      "data." );
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
            break;
        }

        dimmBadDqDataFormat l_spdData;
        memcpy( &l_spdData, l_badDqData, sizeof(dimmBadDqDataFormat) );

        // Zero caller's data
        memset(o_data, 0, sizeof(o_data));

        // Check the magic number and version number. Note that the
        // magic number is stored in SPD in big endian format and
        // platforms of any endianness can access it
        if ( (be32toh(l_spdData.iv_magicNumber) !=
                    DIMM_BAD_DQ_MAGIC_NUMBER) ||
                (l_spdData.iv_version != DIMM_BAD_DQ_VERSION) )
        {
            FAPI_INF( "fapiAttrGetBadDqBitmap: SPD DQ not initialized." );
        }
        else
        {
            // Translate bitmap from DIMM DQ to Centaur DQ point of view
            // for each rank
            for (uint8_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++)
            {
                // Iterate through all the DQ bits in the rank
                for (uint8_t j = 0; j < mss::MAX_DQ_BITS; j++)
                {
                    // There is a byte for each 8 DQs, j/8 gives the
                    // byte number. The MSB in each byte is the lowest
                    // DQ, (0x80 >> (j % 8)) gives the bit mask
                    // corresponding to the DQ within the byte
                    if ((l_spdData.iv_bitmaps[i][j/8]) &
                            (0x80 >> (j % 8)))
                    {
                        // DIMM DQ bit is set in SPD data.
                        // Set Centaur DQ bit in caller's data.
                        // The wiring data maps Centaur DQ to DIMM DQ
                        // Find the Centaur DQ that maps to this DIMM DQ
                        uint8_t k = 0;
                        for (; k < mss::MAX_DQ_BITS; k++)
                        {
                            if (l_wiringData[l_ps][k] == j)
                            {
                                o_data[i][k/8] |= (0x80 >> (k % 8));
                                break;
                            }
                        }

                        if (k == mss::MAX_DQ_BITS)
                        {
                            FAPI_INF( "fapiAttrGetBadDqBitmap: "
                                      "Centaur DQ not found for %d!",j);
                        }
                    }
                }
            }

            // Set bits for any unconnected DQs.
            // First, check ECC.
            l_errl = __dimmUpdateDqBitmapEccByte( l_dimmTarget, o_data );
            if ( l_errl )
            {
                FAPI_ERR( "fapiAttrGetBadDqBitmap: Error getting ECC data" );
                l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
                break;
            }

            // Check spare DRAM.
            l_rc = __dimmUpdateDqBitmapSpareByte( l_dimmTarget, o_data );
            if ( l_rc )
            {
                FAPI_ERR( "fapiAttrGetBadDqBitmap: Error getting spare DRAM "
                          "data" );
                break;
            }

            if ( l_allMnfgFlags &
                    fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_DRAM_REPAIRS )
            {
                // Flag to set if the discrepancies are found.
                bool mfgModeBadBitsPresent = false;

                uint8_t l_eccSpareBitmap[mss::MAX_RANK_PER_DIMM]
                                        [mss::BAD_DQ_BYTE_COUNT];

                l_rc = __compareEccAndSpare( l_dimmTarget,
                                             mfgModeBadBitsPresent, o_data,
                                             l_eccSpareBitmap);
                if ( l_rc )
                {
                    FAPI_ERR( "fapiAttrGetBadDqBitmap: Error comparing bitmap "
                              "with ECC/Spare bits set with caller's data" );
                    break;
                }

                if ( mfgModeBadBitsPresent )
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

    return l_rc;
}

//******************************************************************************
// fapi2::platAttrSvc::fapiAttrSetBadDqBitmap function
//******************************************************************************
ReturnCode fapiAttrSetBadDqBitmap(
    const Target<TARGET_TYPE_ALL>& i_dimmFapiTarget,
    ATTR_BAD_DQ_BITMAP_Type (&i_data) )
{
    fapi2::ReturnCode l_rc;
    errlHndl_t l_errl = nullptr;
    TARGETING::TargetHandle_t l_dimmTarget = nullptr;

    do
    {
        l_errl = getTargetingTarget(i_dimmFapiTarget, l_dimmTarget);
        if ( l_errl )
        {
            FAPI_ERR( "fapiAttrSetBadDqBitmap: Error from getTargetingTarget" );
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
            break;
        }

        uint8_t  l_wiringData[mss::PORTS_PER_MCS][mss::MAX_DQ_BITS];
        uint64_t l_allMnfgFlags;
        uint32_t l_ps = 0;

        l_rc = __badDqBitmapGetHelperAttrs( l_dimmTarget, l_wiringData,
                                            l_allMnfgFlags, l_ps );

        // Read current BadDqBitmap into l_prev_data
        uint8_t l_prev_data[mss::MAX_RANK_PER_DIMM][mss::BAD_DQ_BYTE_COUNT];

        bool badDqSet = false;
        l_rc = FAPI_ATTR_GET( fapi2::ATTR_BAD_DQ_BITMAP, l_dimmTarget,
                              l_prev_data );
        if (l_rc)
        {
            FAPI_ERR("fapiAttrSetBadDqBitmap: Error getting DQ bitmap");
            break;
        }

        // Flag to set if the discrepancies are found
        bool mfgModeBadBitsPresent = false;

        // Check if Bad DQ bit set
        // Loop through all ranks
        for ( uint8_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++ )
        {
            // Loop through all DQs
            for (uint8_t j = 0; j < mss::BAD_DQ_BYTE_COUNT; j++)
            {
                if ( i_data[i][j] != l_prev_data[i][j] )
                {
                    badDqSet = true;
                    break;
                }
            }
            if ( badDqSet ) break;
        }

        // Set ATTR_RECONFIGURE_LOOP to indicate a bad DqBitMap was set
        if ( badDqSet )
        {
            FAPI_INF("fapiAttrSetBadDqBitmap: Reconfigure needed, Bad DQ set");

            fapi2::ATTR_RECONFIGURE_LOOP_Type l_reconfigAttr = 0;
            l_rc = FAPI_ATTR_GET( fapi2::ATTR_RECONFIGURE_LOOP,
                                  fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                  l_reconfigAttr );
            if ( l_rc )
            {
                FAPI_ERR( "fapiAttrSetBadDqBitmap: Error getting "
                          "ATTR_RECONFIGURE_LOOP" );
                break;
            }

            // 'OR' values in case of multiple reasons for reconfigure
            l_reconfigAttr |= fapi2::ENUM_ATTR_RECONFIGURE_LOOP_BAD_DQ_BIT_SET;

            #ifndef CONFIG_VPD_GETMACRO_USE_EFF_ATTR
            // TODO RTC 164707
            // Restore DRAM Repairs not finished yet so commenting out the
            // reconfig loop for now.
            //l_rc = FAPI_ATTR_SET( fapi2::ATTR_RECONFIGURE_LOOP,
            //                      fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
            //                      l_reconfigAttr );
            //if ( l_rc )
            //{
            //    FAPI_ERR( "fapiAttrSetBadDqBitmap: Error setting "
            //              "ATTR_RECONFIGURE_LOOP" );
            //    break;
            //}
            #endif
        }

        // If system is in DISABLE_DRAM_REPAIRS mode
        if ( l_allMnfgFlags &
             fapi2::ENUM_ATTR_MNFG_FLAGS_MNFG_DISABLE_DRAM_REPAIRS )
        {

            uint8_t l_eccSpareBitmap[mss::MAX_RANK_PER_DIMM]
                                    [mss::BAD_DQ_BYTE_COUNT];

            l_rc = __compareEccAndSpare( l_dimmTarget, mfgModeBadBitsPresent,
                                         i_data, l_eccSpareBitmap );
            if ( l_rc )
            {
                FAPI_ERR( "fapiAttrSetBadDqBitmap: Error comparing "
                          "bitmap with ECC/Spare bits set with "
                          "caller's data." );
                break;
            }
            // Don't write bad dq bitmap if discrepancies are found
            // Break out of do while loop
            if ( mfgModeBadBitsPresent ) break;
        }

        // Set up the data to write to SPD
        dimmBadDqDataFormat l_spdData;
        l_spdData.iv_magicNumber = htobe32( DIMM_BAD_DQ_MAGIC_NUMBER );
        l_spdData.iv_version = DIMM_BAD_DQ_VERSION;
        l_spdData.iv_reserved1 = 0;
        l_spdData.iv_reserved2 = 0;
        l_spdData.iv_reserved3 = 0;
        memset( l_spdData.iv_bitmaps, 0, sizeof(l_spdData.iv_bitmaps) );

        // Get the spare byte
        uint8_t spareByte[mss::MAX_RANK_PER_DIMM];
        memset( spareByte, 0, sizeof(spareByte) );

        l_rc = __dimmGetDqBitmapSpareByte( l_dimmTarget, spareByte );
        if ( l_rc )
        {
            FAPI_ERR( "fapiAttrSetBadDqBitmap: Error getting spare byte" );
            break;
        }

        // Translate bitmap from Centaur DQ to DIMM DQ point of view
        // for each rank
        for (uint8_t i = 0; i < mss::MAX_RANK_PER_DIMM; i++)
        {
            // Iterate through all the DQ bits in the rank
            for (uint8_t j = 0; j < mss::MAX_DQ_BITS; j++)
            {
                if ((j/8) == SPARE_DRAM_DQ_BYTE_NUMBER_INDEX)
                {
                    // The spareByte can be one of: 0x00 0x0F 0xF0
                    // 0xFF If a bit is set, then that spare is
                    // unconnected so continue to the next num_dqs,
                    // do not translate
                    if (spareByte[i] & (0x80 >> (j % 8)))
                    {
                        continue;
                    }
                }
                if ((i_data[i][j/8]) & (0x80 >> (j % 8)))
                {
                    // Centaur DQ bit set in callers data.
                    // Set DIMM DQ bit in SPD data.
                    // The wiring data maps Centaur DQ to DIMM DQ
                    uint8_t dBit = l_wiringData[l_ps][j];
                    l_spdData.iv_bitmaps[i][dBit/8] |= (0x80 >> (dBit % 8));
                }
            }
        }

        l_errl = deviceWrite( l_dimmTarget, &l_spdData, DIMM_BAD_DQ_SIZE_BYTES,
                              DEVICE_SPD_ADDRESS(SPD::DIMM_BAD_DQ_DATA) );
        if ( l_errl )
        {
            FAPI_ERR( "fapiAttrSetBadDqBitmap: Failed to write DIMM "
                      "Bad DQ data." );
            l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
            break;
        }

    }while(0);

    return l_rc;
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
        rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
        rc = getControlCapableData(l_fapiTarget, o_vpdPowerControlCapableVal);
    }

    return rc;
}

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
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetDQAttrISDIMM: Error from getTargetingTarget");
        rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
        rc = getDQAttrISDIMM(l_fapiTarget, o_vpdIsDimmTOC4DQVal);
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
    errlHndl_t l_errl = getTargetingTarget(i_fapiTarget, l_pTarget);

    if (l_errl)
    {
        FAPI_ERR("platGetDQSAttrISDIMM: Error from getTargetingTarget");
        rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
    }
    else
    {
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapiTarget(l_pTarget);
        rc = getDQSAttrISDIMM(l_fapiTarget,o_vpdIsDimmTOC4DQSVal);
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
        rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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

            rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
        rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
        rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
            rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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

                rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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

                rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
        rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
    FAPI_INF("platGetMBvpdAttr: Enter");
    FAPI_INF("platGetMBvpdAttr: Attr: 0x%08X", i_attr);

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
            rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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
                    rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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

                    rc.setPlatDataPtr(reinterpret_cast<void *> (l_errl));
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

} // End platAttrSvc namespace

} // End fapi2 namespace
