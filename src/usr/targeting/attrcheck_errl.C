/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/attrcheck_errl.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
 *  @file targeting/attrcheck_errl.C
 *
 *  @brief Error handling for enum value and numeric range checking of
 *         persistent read/write attributes.
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This component
#include <targeting/common/attributes.H>
#include <targeting/attrrp.H>
#include <targeting/common/util.H>
#include <targeting/common/trace.H>
#include <targeting/common/predicates/predicateattrval.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributeTank.H>
#include <targeting/common/targreasoncodes.H>
#include <targeting/common/target.H>

// Other components
#include <secureboot/service.H>

namespace TARGETING
{
#ifndef __HOSTBOOT_RUNTIME
void handleEnumCheckFailure(const Target* i_pTarget,
                            const ATTRIBUTE_ID i_attr,
                            const uint64_t i_invalidValue)
{
    TRACFCOMP(g_trac_targeting,
        "ATTRIBUTE_ID enum check failed! Attribute ID = 0x%x with invalid value"
        " 0x%llX", i_attr, i_invalidValue);
   /*@
    * @errortype
    * @moduleid          TARGETING::TARG_HANDLE_ENUM_CHECK_FAILURE
    * @reasoncode        TARGETING::TARG_RC_ATTRIBUTE_ENUM_CHECK_FAIL
    * @userdata1[00:31]  Target's HUID
    * @userdata1[32:63]  Attribute ID
    * @userdata2         Invalid value
    * @devdesc           Invalid enum value for attribute.
    * @custdesc          Unexpected internal firmware error.
    */
    auto err = new ERRORLOG::ErrlEntry(
        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
        TARGETING::TARG_HANDLE_ENUM_CHECK_FAILURE,
        TARGETING::TARG_RC_ATTRIBUTE_ENUM_CHECK_FAIL,
        TWO_UINT32_TO_UINT64(
            get_huid(i_pTarget),
            i_attr),
        i_invalidValue,
        true);

    // handle the secureboot failure in the normal secureboot way
    // The 'true' below indicates that we want to wait for shutdown, which
    // is advisable in most cases, including this one.
    SECUREBOOT::handleSecurebootFailure(err, true);
}

void handleRangeCheckFailure(const Target* i_pTarget,
                             const ATTRIBUTE_ID i_attr,
                             const uint64_t i_outOfRangeValue)
{
    TRACFCOMP(g_trac_targeting,
        "ATTRIBUTE_ID range check failed! Attribute ID = 0x%x "
        "with out of range value 0x%llX", i_attr, i_outOfRangeValue);

    /*@
     * @errortype
     * @moduleid         TARGETING::TARG_HANDLE_RANGE_CHECK_FAILURE
     * @reasoncode       TARGETING::TARG_RC_ATTRIBUTE_RANGE_CHECK_FAIL
     * @userdata1[00:31] Target's HUID
     * @userdata1[32:64] Attribute ID
     * @userdata2        Value that was out of range
     * @devdesc          Invalid range for attribute value.
     * @custdesc         Unexpected internal firmware error.
     */
    auto err = new ERRORLOG::ErrlEntry(
        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
        TARGETING::TARG_HANDLE_RANGE_CHECK_FAILURE,
        TARGETING::TARG_RC_ATTRIBUTE_RANGE_CHECK_FAIL,
        TWO_UINT32_TO_UINT64(
            get_huid(i_pTarget),
            i_attr),
        i_outOfRangeValue,
        true);

    // handle the secureboot failure in the normal secureboot way
    // The 'true' below indicates that we want to wait for shutdown, which
    // is advisable in most cases, including this one.
    SECUREBOOT::handleSecurebootFailure(err, true);
}
#endif

} // End namespace TARGETING
