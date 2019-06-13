/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludattribute.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errl/errludattribute.H>
#include <errl/errlreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/trace.H>

namespace ERRORLOG
{
using namespace TARGETING;
extern TARG_TD_t g_trac_errl;


//------------------------------------------------------------------------------
ErrlUserDetailsAttribute::ErrlUserDetailsAttribute(
    const Target * i_pTarget, uint32_t i_attr)
    : iv_pTarget(i_pTarget), iv_dataSize(0)
{
    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = 1;
    iv_SubSection = ERRL_UDT_ATTRIBUTE;
    // override the default of false
    iv_merge = true;

    // first, write out the HUID
    addData(ATTR_HUID);
    if (i_attr != ATTR_HUID) {
        addData(i_attr);
    }
}

//------------------------------------------------------------------------------
ErrlUserDetailsAttribute::ErrlUserDetailsAttribute(
    const Target * i_pTarget)
    : iv_pTarget(i_pTarget), iv_dataSize(0)
{
    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = 1;
    iv_SubSection = ERRL_UDT_ATTRIBUTE;
    // override the default of false
    iv_merge = true;

    // first, write out the HUID
    addData(ATTR_HUID);
}

//------------------------------------------------------------------------------
ErrlUserDetailsAttribute::~ErrlUserDetailsAttribute()
{ }
} // namespace

// Pull in the auto-generated portion
//   ::addData
//   ::dumpAll
#include <errludattribute_gen.C>

