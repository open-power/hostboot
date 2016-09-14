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
#include <runtime/interface.h>
#include <config.h>
#include <secureboot/service.H>
#include <errl/errlmanager.H>
#include <secureboot/secure_reasoncodes.H>
#include "common/securetrace.H"

#include <runtime/rt_targeting.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>


namespace SECUREBOOT
{
    using namespace TARGETING;

    bool enabled()
    {
        errlHndl_t l_errl = NULL;
        uint64_t l_regValue = 0;
        size_t l_size = sizeof(l_regValue);

        TargetService& tS = targetService();
        Target* masterProcChipTargetHandle = NULL;

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
                            DEVICE_SCOM_ADDRESS(PROC_SECURITY_SWITCH_REGISTER));
            if (l_errl)
            {
                errlCommit(l_errl, SECURE_COMP_ID);
                break;
            }

            assert(l_size == sizeof(l_regValue));
        } while (0);

        // if there was an error l_regValue is zero, so we return false.
        // Unfortunately this is all we can do. These shouldn't fail.

        return l_regValue & PROC_SECURITY_SWITCH_TRUSTED_BOOT_MASK;
    }

} // end of SECUREBOOT namespace

