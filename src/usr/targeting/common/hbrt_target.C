/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/hbrt_target.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include <targeting/common/hbrt_target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/targreasoncodes.H>
#include <runtime/customize_attrs_for_payload.H>
#include <targeting/common/trace.H>
#ifdef __HOSTBOOT_MODULE
#include <errl/errludtarget.H>
#endif

extern trace_desc_t* g_trac_hbrt;
using namespace TARGETING;

namespace TARGETING
{

errlHndl_t getRtTarget(
    const TARGETING::Target* i_pTarget,
          rtChipId_t&        o_rtTargetId)
{
    errlHndl_t pError = NULL;

    do
    {
        if(i_pTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            TARGETING::Target* masterProcChip = NULL;
            TARGETING::targetService().
                masterProcChipTargetHandle(masterProcChip);
            i_pTarget = masterProcChip;
        }

        auto hbrtHypId = RUNTIME::HBRT_HYP_ID_UNKNOWN;
        if(   (!i_pTarget->tryGetAttr<TARGETING::ATTR_HBRT_HYP_ID>(hbrtHypId))
           || (hbrtHypId == RUNTIME::HBRT_HYP_ID_UNKNOWN))
        {
            auto huid = get_huid(i_pTarget);
            auto targetingTargetType =
                i_pTarget->getAttr<TARGETING::ATTR_TYPE>();
            TRACFCOMP(g_trac_targeting, ERR_MRK
                "Targeting target type of 0x%08X not supported. "
                "HUID: 0x%08X",
                targetingTargetType,
                huid);
            /*@
             * @errortype
             * @moduleid    TARG_RT_GET_RT_TARGET
             * @reasoncode  TARG_RT_TARGET_TYPE_NOT_SUPPORTED
             * @userdata1   Target's HUID
             * @userdata2   target's targeting type
             * @devdesc     Targeting target's type not supported by runtime
             *              code
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                TARGETING::TARG_RT_GET_RT_TARGET,
                TARGETING::TARG_RT_TARGET_TYPE_NOT_SUPPORTED,
                huid,
                targetingTargetType
#ifdef __HOSTBOOT_MODULE
                ,true);

            ERRORLOG::ErrlUserDetailsTarget(i_pTarget,"Targeting Target").
                addToLog(pError);
#else
                );  // if not in hostboot code then skip last param of error log
                    // and do not create a user details section
#endif
        }

        o_rtTargetId = hbrtHypId;

    } while(0);

    return pError;
}

}