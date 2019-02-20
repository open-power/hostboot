/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/smf/smf_utils.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <secureboot/smf_utils.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/util.H>
#include <secureboot/secure_reasoncodes.H>
#include <assert.h>
#include <limits.h>

namespace SECUREBOOT
{

namespace SMF
{

const uint64_t MIN_SMF_MEMORY_AMT = 256 * MEGABYTE;
const uint64_t MIN_MEM_RESERVED_FOR_HB = 8 * GIGABYTE;

bool isSmfEnabled()
{
    uint8_t l_smfEnabled = true;

    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    crit_assert(l_sys != nullptr);
    l_smfEnabled = l_sys->getAttr<TARGETING::ATTR_SMF_ENABLED>();
    return l_smfEnabled;
}

errlHndl_t checkRiskLevelForSmf()
{
    errlHndl_t l_errl = nullptr;

    do {

    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    crit_assert(l_sys);
    auto l_riskLevel = l_sys->getAttr<TARGETING::ATTR_RISK_LEVEL>();

    TARGETING::Target* l_pMasterProc = nullptr;
    l_errl = TARGETING::targetService()
                                .queryMasterProcChipTargetHandle(l_pMasterProc);
    if(l_errl)
    {
        break;
    }

    auto l_masterProcModel = l_pMasterProc->getAttr<TARGETING::ATTR_MODEL>();

    // SMF is enabled by default on Axone, so need to check the risk level
    // only on P9C/P9N.
    // WARNING: If more risk levels are added in the future that don't
    // support SMF, the below check needs to be altered accordingly.
    if(l_riskLevel <TARGETING::UTIL::P9N23_P9C13_NATIVE_SMF_RUGBY_FAVOR_SECURITY
       && (
            (l_masterProcModel == TARGETING::MODEL_CUMULUS) ||
            (l_masterProcModel == TARGETING::MODEL_NIMBUS)
          )
      )
    {
        /*@
        * @errortype
        * @reasoncode  SECUREBOOT::RC_RISK_LEVEL_TOO_LOW
        * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
        * @moduleid    SECUREBOOT::MOD_CHECK_RISK_LEVEL_FOR_SMF
        * @userdata1   Current risk level of the system
        * @userdata2   Minimum risk level required
        * @devdesc     SMF is enabled on the system of incorrect risk level
        * @custdesc    A problem occurred during the IPL of the system.
        */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       SECUREBOOT::MOD_CHECK_RISK_LEVEL_FOR_SMF,
                                       SECUREBOOT::RC_RISK_LEVEL_TOO_LOW,
                                       l_riskLevel,
                                       TARGETING::UTIL::P9N23_P9C13_NATIVE_SMF_RUGBY_FAVOR_SECURITY,
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        break;
    }

    } while(0);

    return l_errl;
}

} // namespace SMF

} // namespace SECUREBOOT
