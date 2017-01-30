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

            // If the "Secure Mode Disable" (SMD) bit is 0b1 in the CBS
            // Control/Status register, hardware security is deasserted;
            // otherwise (0b0), hardware security is asserted
            o_state = (l_regValue &
                static_cast<uint64_t>(ProcCbsControl::JumperStateBit)) ?
                     SecureJumperState::SECURITY_DEASSERTED :
                     SecureJumperState::SECURITY_ASSERTED;

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

    errlHndl_t Settings::clearSecuritySwitchBits(
        const std::vector<SECUREBOOT::ProcSecurity>& i_bits,
              TARGETING::Target* const               i_pTarget) const
    {
        uint64_t bitsToClear = 0;
        for(const auto &bit : i_bits)
        {
            bitsToClear |= static_cast<uint64_t>(bit);
        }

        auto pError = writeSecurityRegister(
            i_pTarget,
            static_cast<uint64_t>(ProcSecurity::SwitchRegisterClear),
            bitsToClear);

        if(pError)
        {
            SB_ERR("clearSecuritySwitchBits: writeSecurityRegister "
                "(SwitchRegisterClear) failed. Target HUID = 0x%08X, data = "
                "0x%016llX.",
                get_huid(i_pTarget),bitsToClear);
            SB_ERR("clearSecuritySwitchBits: plid=0x%08X, eid=0x%08X, "
                "reason=0x%04X",
                ERRL_GETPLID_SAFE(pError),
                ERRL_GETEID_SAFE(pError),
                ERRL_GETRC_SAFE(pError));
        }

        return pError;
    }

    errlHndl_t Settings::setSecuritySwitchBits(
        const std::vector<SECUREBOOT::ProcSecurity>& i_bits,
              TARGETING::Target* const               i_pTarget) const
    {
        uint64_t bitsToSet = 0;
        for(const auto &bit : i_bits)
        {
            bitsToSet |= static_cast<uint64_t>(bit);
        }

        auto pError = writeSecurityRegister(
            i_pTarget,
            static_cast<uint64_t>(ProcSecurity::SwitchRegister),
            bitsToSet);

        if(pError)
        {
            SB_ERR("setSecuritySwitchBits: writeSecurityRegister "
                "(SwitchRegister) failed. Target HUID = 0x%08X, data = "
                "0x%016llX.",
                get_huid(i_pTarget),bitsToSet);
            SB_ERR("setSecuritySwitchBits: plid=0x%08X, eid=0x%08X, "
                "reason=0x%04X",
                ERRL_GETPLID_SAFE(pError),
                ERRL_GETEID_SAFE(pError),
                ERRL_GETRC_SAFE(pError));
        }

        return pError;
    }

    errlHndl_t Settings::writeSecurityRegister(
              TARGETING::Target* const i_pTarget,
        const uint64_t                 i_scomAddress,
        const uint64_t                 i_data) const
    {
        errlHndl_t pError = nullptr;

        do
        {

        // Target must be the sentinel or some other non-NULL proc value
        if (   (i_pTarget != TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
            && (   (i_pTarget == nullptr)
                || (   (i_pTarget->getAttr<TARGETING::ATTR_TYPE>())
                    != (TARGETING::TYPE_PROC) ) ) )
        {
            SB_ERR("writeSecurityRegister: Caller invoked API with bad target; "
                "Target HUID = 0x%08X.",get_huid(i_pTarget));
            /*@
             * @errortype
             * @severity   ERRL_SEV_UNRECOVERABLE
             * @moduleid   SECUREBOOT::MOD_SECURE_WRITE_REG
             * @reasoncode SECUREBOOT::RC_SECURE_BAD_TARGET
             * @userdata1  Target pointer value
             * @userdata2  Target's HUID or 0 if NULL target pointer
             * @devdesc    Invalid target used to write security
             *             register.
             * @custdesc   Unexpected internal firmware error.
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                SECUREBOOT::MOD_SECURE_WRITE_REG,
                SECUREBOOT::RC_SECURE_BAD_TARGET,
                reinterpret_cast<uint64_t>(i_pTarget),
                TO_UINT64(get_huid(i_pTarget)),
                true);
            pError->collectTrace(SECURE_COMP_NAME, ERROR_TRACE_SIZE);
            break;
        }

        // Write security switch settings to processor
        const size_t expSize = sizeof(i_data);
        size_t actSize = expSize;
        pError = deviceWrite(
            i_pTarget,
            const_cast<uint64_t*>(&i_data), actSize,
            DEVICE_SCOM_ADDRESS(i_scomAddress));
        if (nullptr != pError)
        {
            SB_ERR("writeSecurityRegister: deviceWrite failed; target HUID = "
                "0x%08X, SCOM addr = 0x%016llX, data = 0x%016llX.",
                get_huid(i_pTarget),i_scomAddress,i_data);
            break;
        }

        assert(actSize == expSize,
            "writeSecurityRegister: BUG! size returned from device write (%d) "
            "is not the expected size of %d",actSize,expSize);

        } while(0);

        if(pError)
        {
            SB_ERR("writeSecurityRegister: plid=0x%08X, eid=0x%08X, "
                "reason=0x%04X",
                ERRL_GETPLID_SAFE(pError),
                ERRL_GETEID_SAFE(pError),
                ERRL_GETRC_SAFE(pError));
        }

        return pError;
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
