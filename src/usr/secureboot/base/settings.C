/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/settings.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#include <secureboot/secure_reasoncodes.H>
#include <targeting/common/util.H>
#include <targeting/common/target.H>
#include <initservice/initserviceif.H>
#include <secureboot/settings.H>

// SECUREBOOT : General driver traces
#include "../common/securetrace.H"

namespace SECUREBOOT
{
    using namespace TARGETING;
    using namespace ERRORLOG;

    // symbolic constant for the trace size
    enum {
        ERROR_TRACE_SIZE = 256,
    };

    void Settings::_init()
    {
        uint64_t l_regValue = 0;

        // read security switch register
        auto l_errl = getSecuritySwitch(l_regValue,
                                        MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

        if (NULL != l_errl)
        {

            // Grab errlog reason code before committing.
            uint16_t l_rc = l_errl->reasonCode();

            errlCommit(l_errl, SECURE_COMP_ID);
            // we need to shutdown here because getSecuritySwitch does not
            // return a fatal error log in some cases
            INITSERVICE::doShutdown(l_rc);
        }

        // cache only the enabled flag
        iv_enabled = (0 != (l_regValue &
                            static_cast<uint64_t>(ProcSecurity::SabBit)));

        SB_INF("getEnabled() state:%i",iv_enabled);
    }

    bool Settings::getEnabled() const
    {
        return iv_enabled;
    }

    errlHndl_t Settings::getJumperState(SecureJumperState& o_state,
                                        Target* i_targ) const
    {
        uint64_t l_regValue = 0;
        o_state = SecureJumperState::SECURITY_DEASSERTED;

        errlHndl_t l_errl = nullptr;

        do
        {
            // the supplied target input parameter is validated in one place
            // inside the readSecurityRegister function
            l_errl = readSecurityRegister(i_targ,
                    static_cast<uint64_t>(ProcCbsControl::StatusRegister),
                    l_regValue);

            SB_DBG("getJumperState() err:%i reg:%.16llX huid:%.8X",
                !!l_errl, l_regValue, get_huid(i_targ));

            if (l_errl)
            {
                break;
            }
            o_state = (l_regValue &
                static_cast<uint64_t>(ProcCbsControl::JumperStateBit)) ?
                     SecureJumperState::SECURITY_ASSERTED :
                     SecureJumperState::SECURITY_DEASSERTED;

            SB_INF("getJumperState() state:%i huid:%.8X", o_state,
                                                            get_huid(i_targ));

        } while(0);

        return l_errl;
    }

    errlHndl_t Settings::getSecuritySwitch(uint64_t& o_regValue,
                                           Target* i_targ) const
    {
        auto l_errl = readSecurityRegister(i_targ,
                    static_cast<uint64_t>(ProcSecurity::SwitchRegister),
                    o_regValue);
        SB_INF("getSecuritySwitch() err:%i reg:%.16llX huid:%.8X",
            !!l_errl, o_regValue, get_huid(i_targ));

        return l_errl;
    }

    errlHndl_t Settings::readSecurityRegister(Target* i_targ,
                                            const uint64_t i_scomAddress,
                                            uint64_t& o_regValue) const
    {
        errlHndl_t l_errl = nullptr;
        size_t size = sizeof(o_regValue);

        do
        {

        // make sure we are not passed a null target pointer or the wrong
        // target type (must be a processor target) or the sentinel
        if ( i_targ != MASTER_PROCESSOR_CHIP_TARGET_SENTINEL &&
            (i_targ == nullptr || i_targ->getAttr<ATTR_TYPE>() != TYPE_PROC)
           )
        {
            /*@
             * @errortype
             * @moduleid         SECUREBOOT::MOD_SECURE_READ_REG
             * @reasoncode       SECUREBOOT::RC_SECURE_BAD_TARGET
             * @userdata1        Target pointer value
             * @userdata2        Target's HUID or 0 if null
             *                   target pointer.
             * @devdesc          Invalid target used to read security
             *                   switch register.
             * @custdesc         Internal Firmware error.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         SECUREBOOT::MOD_SECURE_READ_REG,
                                         SECUREBOOT::RC_SECURE_BAD_TARGET,
                                         reinterpret_cast<uint64_t>(i_targ),
                                         TO_UINT64(get_huid(i_targ)),
                                         true /* Add HB Software Callout */ );
            l_errl->collectTrace(SECURE_COMP_NAME, ERROR_TRACE_SIZE);
            break;
        }

        // Read security switch setting from processor.
        l_errl = deviceRead(i_targ,
                            &o_regValue, size,
                            DEVICE_SCOM_ADDRESS(i_scomAddress));

        if (nullptr != l_errl)
        {
            break;
        }
        assert(size == sizeof(o_regValue),
            "size returned from device read is not the expected size of %i",
                                                           sizeof(o_regValue));

        } while(0);

        return l_errl;
    }

}
