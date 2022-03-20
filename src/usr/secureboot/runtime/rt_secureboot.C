/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/runtime/rt_secureboot.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
 *  @file rt_secureboot.C
 *  @brief Provides runtime API for secure container verification
 */

#include <runtime/interface.h>

#include "common/securetrace.H"
#include <secureboot/service.H>
#include <secureboot/secure_reasoncodes.H>

#include <errl/errlmanager.H>
#include <targeting/runtime/rt_targeting.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <util/runtime/rt_fwreq_helper.H>

extern trace_desc_t* g_trac_hbrt;

namespace SECUREBOOT
{
using namespace TARGETING;

#if defined(CONFIG_SECUREBOOT) && defined(__HOSTBOOT_RUNTIME)
bool enabled()
{
    errlHndl_t l_errl = nullptr;
    uint64_t l_regValue = 0;
    size_t l_size = sizeof(l_regValue);

    TargetService& tS = targetService();
    Target* masterProcChipTargetHandle = nullptr;

    do
    {
        l_errl = tS.queryMasterProcChipTargetHandle(
                                            masterProcChipTargetHandle);

        if (l_errl)
        {
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }

        l_errl = deviceRead(masterProcChipTargetHandle,
                        &l_regValue, l_size,
                        DEVICE_SCOM_ADDRESS(
                          static_cast<uint64_t>(ProcSecurity::SwitchRegister)));
        if (l_errl)
        {
            errlCommit(l_errl, SECURE_COMP_ID);
            break;
        }

        assert(l_size == sizeof(l_regValue));
    } while (0);

    // if there was an error l_regValue is zero, so we return false.
    // Unfortunately this is all we can do. These shouldn't fail.

    return l_regValue & static_cast<uint64_t>(ProcSecurity::SabBit);
}
#endif

#ifdef __HOSTBOOT_RUNTIME
bool allowAttrOverrides()
{
    bool retVal = false;

    if (enabled())
    {
        // Check attribute to see if overrides are allowed in secure mode
        TARGETING::TargetService& tS = TARGETING::targetService();
        TARGETING::Target* sys = nullptr;
        (void) tS.getTopLevelTarget( sys );
        assert(sys, "SECUREBOOT::allowAttrOverrides() system target is NULL");

        retVal = sys->getAttr<
            TARGETING::ATTR_ALLOW_ATTR_OVERRIDES_IN_SECURE_MODE>();

        SB_INF("SECUREBOOT::allowAttrOverrides: Inside Attr check: retVal=0x%X",
               retVal);
    }
    else
    {
        // Allow Attribute Overrides in unsecure mode
        retVal = true;
    }

    return retVal;
}
#endif

int verify_container(
    const void*  i_pContainer,
    const void*  i_pHwKeyHash,
    const size_t i_hwKeyHashSize)
{
    int rc = 0;

    TRACFCOMP(g_trac_hbrt, ENTER_MRK" verify_container" );
    SB_ENTER(
        "verify_container: "
        "container ptr = %p, "
        "HW keys' hash ptr = %p, "
        "HW keys' hash size = %d",
        i_pContainer,i_pHwKeyHash,i_hwKeyHashSize);

    // TODO: RTC 156485
    // Implement guts of verify_container

    SB_EXIT(
        "verify_container: rc = %d",rc);
    TRACFCOMP(g_trac_hbrt, EXIT_MRK" verify_container: rc=0x%X", rc );

    return rc;
}


struct registerSecurebootRt
{
    registerSecurebootRt()
    {
        auto pRtIntf = getRuntimeInterfaces();
#ifdef CONFIG_SECUREBOOT
        pRtIntf->verify_container = DISABLE_MCTP_WRAPPER(verify_container);
#else
        pRtIntf->verify_container = nullptr;
#endif
    }
};

registerSecurebootRt g_registerSecurebootRt;

} // end of SECUREBOOT namespace


