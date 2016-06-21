/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/runtime/rt_secureboot.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <config.h>

#include "common/securetrace.H"

namespace SECUREBOOT
{

int verify_container(
    const void*  i_pContainer,
    const void*  i_pHwHashKey,
    const size_t i_hwHashKeySize)
{
    int rc = 0;

   SB_ENTER(
        "verify_container: "
        "container ptr = %p, "
        "HW hash key ptr = %p, "
        "HW hash key size = %d",
        i_pContainer,i_pHwHashKey,i_hwHashKeySize);

    // TODO: RTC 156485
    // Implement guts of verify_container

    SB_EXIT(
        "verify_container: rc = %d",rc);

    return rc;
}

struct registerSecurebootRt
{
    registerSecurebootRt()
    {
        auto pRtIntf = getRuntimeInterfaces();
#ifdef CONFIG_SECUREBOOT
        pRtIntf->verify_container = &verify_container;
#else
        pRtIntf->verify_container = nullptr;
#endif
    }
};

registerSecurebootRt g_registerSecurebootRt;

} // end of SECUREBOOT namespace


