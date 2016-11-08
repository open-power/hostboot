/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/settings.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <devicefw/userif.H>
#include <secureboot/service.H>
#include "settings.H"

// SECUREBOOT : General driver traces
#include "../common/securetrace.H"

namespace SECUREBOOT
{
    using namespace TARGETING;

    void Settings::_init()
    {
        // cache only the enabled flag
        iv_enabled = (0 != (getSecuritySwitch() &
                                static_cast<uint64_t>(ProcSecurity::SabBit)));
    }

    bool Settings::getEnabled() const
    {
        return iv_enabled;
    }

    bool Settings::getJumperState() const
    {
        auto l_regValue = readSecurityRegister(
                        static_cast<uint64_t>(ProcCbsControl::StatusRegister));

        return 0 != (l_regValue &
                        static_cast<uint64_t>(ProcCbsControl::JumperStateBit));
    }

    uint64_t Settings::getSecuritySwitch() const
    {
        return readSecurityRegister(
                        static_cast<uint64_t>(ProcSecurity::SwitchRegister));
    }

    uint64_t Settings::readSecurityRegister(const uint64_t i_scomAddress) const
    {
        errlHndl_t l_errl = nullptr;
        uint64_t l_regValue = 0;
        size_t size = sizeof(l_regValue);

        // Read secure register setting from processor.
        l_errl = deviceRead(MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            &l_regValue, size,
                            DEVICE_SCOM_ADDRESS(i_scomAddress));

        if (nullptr != l_errl)
        {
            errlCommit(l_errl, SECURE_COMP_ID);
            // This assert is needed because the deviceRead returns an
            // informational error log so the system would otherwise not be
            // halted.
            assert(false,"SECUREBOOT::Settings::readSecurityRegister() Unable"
                        " to read security register");
        }
        assert(size == sizeof(l_regValue),
            "size returned from device read is not the expected size of %i",
                                                           sizeof(l_regValue));

        return l_regValue;
    }

}
