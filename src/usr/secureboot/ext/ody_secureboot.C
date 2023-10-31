/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/ody_secureboot.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
#include <secureboot/ody_secureboot.H>
#include <targeting/odyutil.H>
#include <secureboot/service.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/trustedbootif.H>
#include <errl/hberrltypes.H>
#include <secureboot/common/securetrace.H>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <ocmbupd/ody_upd_fsm.H>

using namespace ERRORLOG;
using namespace SECUREBOOT;
using namespace errl_util;
using namespace ocmbupd;
using namespace TRUSTEDBOOT;

errlHndl_t verifyOdySecuritySettings(Target* i_ocmb,
                                     const ody_secureboot_config_reg_t& i_odySecurebootReg,
                                     const ocmb_boot_flags_t& i_ocmbBootFlags)
{
    errlHndl_t l_errl = nullptr;
    if(i_odySecurebootReg.fields.securebootEnforcement != SECUREBOOT::enabled() ||
       i_odySecurebootReg.fields.ECDSAVerificationEnable != i_ocmbBootFlags.fields.enableECDSASignature ||
       i_odySecurebootReg.fields.dilithiumVerificationEnable != i_ocmbBootFlags.fields.enableDilithiumSignature ||
       i_odySecurebootReg.fields.ECIDVerificationEnable != i_ocmbBootFlags.fields.enableECIDVerification ||
       i_odySecurebootReg.fields.hwKeyHashVerificationEnable != i_ocmbBootFlags.fields.enableHWKeyHashVerification||
       i_odySecurebootReg.fields.secureModeEnable != SECUREBOOT::enabled() ||
       i_odySecurebootReg.fields.enableHashCalculation != i_ocmbBootFlags.fields.enableFileHashCalculation ||
       i_odySecurebootReg.fields.bootComplete != 1)
    {
        SB_ERR("verifyOdySecuritySettings: Verification failed for OCMB 0x%x", get_huid(i_ocmb));
        /*@
         * @errortype
         * @moduleid MOD_VERIFY_ODY_SECURITY_SETTINGS
         * @reasoncode RC_ODY_SECURE_SETTINGS_MISMATCH
         * @userdata1 Odyssey Chip HUID
         * @userdata2[0] Ody Secureboot Reg: secureboot enabled
         * @userdata2[1] Ody Secureboot Reg: ECDSA verification enabled
         * @userdata2[2] Ody Secureboot Reg: Dilithium verification enabled
         * @userdata2[3] Ody Secureboot Reg: ECID verification enabled
         * @userdata2[4] Ody Secureboot Reg: HW Key hash verification enabled
         * @userdata2[5] Ody Secureboot Reg: secure mode enabled
         * @userdata2[6] Ody Secureboot Reg: File hash calculation enabled
         * @userdata2[7] System: secureboot enabled
         * @userdata2[8] OCMB_BOOT_FLAGS: ECDSA signature enabled
         * @userdata2[9] OCMB_BOOT_FLAGS: Dilithium signature enabled
         * @userdata2[10] OCMB_BOOT_FLAGS: ECID verification enabled
         * @userdata2[11] OCMB_BOOT_FLAGS: HW Key hash verification enabled
         * @userdata2[12] System: secureboot enabled
         * @userdata2[13] OCMB_BOOT_FLAGS: File hash calculation enabled
         * @userdata2[14] Ody Secureboot Reg: Odyssey boot complete flag
         * @devdesc Odyssey secureboot settings don't match between the Odyssey
         *          chip and the system.
         * @custdesc Secureboot failure
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_VERIFY_ODY_SECURITY_SETTINGS,
                               RC_ODY_SECURE_SETTINGS_MISMATCH,
                               get_huid(i_ocmb),
                               SrcUserData(bits{0}, i_odySecurebootReg.fields.securebootEnforcement,
                                           bits{1}, i_odySecurebootReg.fields.ECDSAVerificationEnable,
                                           bits{2}, i_odySecurebootReg.fields.dilithiumVerificationEnable,
                                           bits{3}, i_odySecurebootReg.fields.ECIDVerificationEnable,
                                           bits{4}, i_odySecurebootReg.fields.hwKeyHashVerificationEnable,
                                           bits{5}, i_odySecurebootReg.fields.secureModeEnable,
                                           bits{6}, i_odySecurebootReg.fields.enableHashCalculation,
                                           bits{7}, SECUREBOOT::enabled(),
                                           bits{8}, i_ocmbBootFlags.fields.enableECDSASignature,
                                           bits{9}, i_ocmbBootFlags.fields.enableDilithiumSignature,
                                           bits{10}, i_ocmbBootFlags.fields.enableECIDVerification,
                                           bits{11}, i_ocmbBootFlags.fields.enableHWKeyHashVerification,
                                           bits{12}, SECUREBOOT::enabled(),
                                           bits{13}, i_ocmbBootFlags.fields.enableFileHashCalculation,
                                           bits{14}, i_odySecurebootReg.fields.bootComplete),
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }
    return l_errl;
}

errlHndl_t odySecurebootVerification(Target* i_ocmb)
{
    SB_INF("odySecurebootVerification begin");
    errlHndl_t l_errl = nullptr;
    const uint32_t SROM_SB_CONTROL_REG = 0x501b8;
    const uint32_t BL_SB_CONTROL_REG = 0x501b9;

    ocmb_boot_flags_t l_ocmbBootFlags;
    l_ocmbBootFlags.value = i_ocmb->getAttr<ATTR_OCMB_BOOT_FLAGS>();
    ody_secureboot_config_reg_t l_ocmbSBConfigReg;
    size_t l_readSize = sizeof(uint64_t);

    if(!UTIL::isOdysseyChip(i_ocmb))
    {
        goto EXIT;
    }

    for(auto l_controlReg = SROM_SB_CONTROL_REG; l_controlReg <= BL_SB_CONTROL_REG; ++l_controlReg)
    {
        // Step 1/2: Verify that the secureboot settings in SROM/BL SB control reg
        // of the Odyssey match those settings we programmed into OCMB using
        // ATTR_OCMB_BOOT_FLAGS.
        l_errl = deviceRead(i_ocmb,
                            &(l_ocmbSBConfigReg.value),
                            l_readSize,
                            DEVICE_SCOM_ADDRESS(l_controlReg));
        if(l_errl)
        {
            SB_ERR("odySecurebootVerification: could not read Ody SB control reg 0x%x for OCMB 0x%x",
                   l_controlReg, get_huid(i_ocmb));
            goto EXIT;
        }

        l_errl = verifyOdySecuritySettings(i_ocmb, l_ocmbSBConfigReg, l_ocmbBootFlags);
        if(l_errl)
        {
            SB_ERR("odySecurebootVerification: Secureboot verification of SB control reg 0x%x failed for OCMB 0x%x",
                   l_controlReg, get_huid(i_ocmb));
            goto EXIT;
        }
    }

EXIT:

    if(!l_errl)
    {
        // Extend the secure register settings into the PCR3 of the TPM (only one set
        // of settings needs to be extended, since they need to match).
        for(auto l_controlReg = SROM_SB_CONTROL_REG; l_controlReg <= BL_SB_CONTROL_REG; ++l_controlReg)
        {
            char l_pcrExtendMessage[100];
            if(l_controlReg == SROM_SB_CONTROL_REG)
            {
                snprintf(l_pcrExtendMessage, 100, "Odyssey SROM SB\n");
            }
            else if(l_controlReg == BL_SB_CONTROL_REG)
            {
                snprintf(l_pcrExtendMessage, 100, "Odyssey BOOT SB\n");
            }
            l_errl = pcrExtend(PCR_3,
                            EV_PLATFORM_CONFIG_FLAGS,
                            reinterpret_cast<const uint8_t*>(&(l_ocmbSBConfigReg.value)),
                            sizeof(l_ocmbSBConfigReg.value),
                            reinterpret_cast<const uint8_t*>(l_pcrExtendMessage),
                            strlen(l_pcrExtendMessage));
            if(l_errl)
            {
                SB_ERR("verifyOdyMeasurementRegs: Could not extend SPPE bootloader measurement");
                // Fall through, the error will be caught below
            }
        }
    }

    if(l_errl)
    {
        // Tell the Odyssey FSM that there's been a secureboot failure so that
        // it can perform the right actions.
        errlHndl_t l_fsmErrl = ody_upd_process_event(i_ocmb,
                                                     MEAS_REGS_MISMATCH,
                                                     l_errl);
        if(l_fsmErrl)
        {
            SB_ERR("odySecurebootVerification: Odyssey FSM returned an error");
            l_errl = l_fsmErrl;
        }
    }

    SB_INF("odySecurebootVerification end");
    return l_errl;
}
