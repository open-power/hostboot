/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/ody_secureboot.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
#include <errl/errlmanager.H>
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

/**
 * @brief This function compares the contents of the measurement registers on
 *        the given OCMB to the measured.hash in the OCMBFW partition. Both bootloader
 *        and runtime OCMB images are verified. On successful verification, the
 *        measured hash gets extended into TPM's PCR2 reg.
 *
 * @param[in] i_ocmb The Odyssey to run the verification on
 * @return nullptr on success; valid error log on error
 */
errlHndl_t verifyOdyMeasurementRegs(Target* i_ocmb)
{
    errlHndl_t l_errl = nullptr;

    const uint32_t BL_MEASUREMENT_REG_START = 0x000501A0;
    const uint32_t BL_MEASUREMENT_REG_END   = 0x000501AB;
    const uint32_t RT_MEASUREMENT_REG_START = 0x000501AC;
    const uint32_t RT_MEASUREMENT_REG_END   = 0x000501B7;

    const size_t SPPE_MEASUREMENT_HASH_SIZE_BYTES = 48;
    uint32_t l_sppeBlMeasurementData[SPPE_MEASUREMENT_HASH_SIZE_BYTES/sizeof(uint32_t)]{};
    uint32_t l_sppeRtMeasurementData[SPPE_MEASUREMENT_HASH_SIZE_BYTES/sizeof(uint32_t)]{};

    static bool l_extendBlMeasurementOnce = false;
    static bool l_extendRtMeasurementOnce = false;

    uint64_t l_tempReadData = 0;
    size_t l_readSize = sizeof(l_tempReadData);

    auto l_pnorMeasurementData = i_ocmb->getAttrAsStdArr<ATTR_SPPE_BOOTLOADER_MEASUREMENT_HASH>();

    // Read out the bootloader measurement registers and compare the
    // result to boot/measured.hash (truncated to 48 bytes)
    for(uint32_t l_addr = BL_MEASUREMENT_REG_START, i = 0; l_addr <= BL_MEASUREMENT_REG_END; ++l_addr, ++i)
    {
        l_errl = deviceRead(i_ocmb,
                            &l_tempReadData,
                            l_readSize,
                            DEVICE_SCOM_ADDRESS(l_addr));
        if(l_errl)
        {
            SB_ERR("verifyOdyMeasurementRegs: Could not read BL measurement reg 0x%x for Odyssey 0x%x",
                    l_addr, get_huid(i_ocmb));
            goto ERROR_EXIT;
        }

        l_tempReadData = l_tempReadData >> 32; // The actual data from the SCOM read is in the top 32 bits
        l_sppeBlMeasurementData[i] = l_tempReadData;
    }

    if(memcmp(l_sppeBlMeasurementData, l_pnorMeasurementData.data(), SPPE_MEASUREMENT_HASH_SIZE_BYTES))
    {
        SB_ERR("verifyOdyMeasurementRegs: Failed bootloader measurement verification for Odyssey 0x%x",
               get_huid(i_ocmb));
        SB_INF_BIN("verifyOdyMeasurementRegs: bootloader measurement hash from PNOR", l_pnorMeasurementData.data(), SPPE_MEASUREMENT_HASH_SIZE_BYTES);
        SB_INF_BIN("verifyOdyMeasurementRegs: bootloader measurement hash from SPPE", l_sppeBlMeasurementData, SPPE_MEASUREMENT_HASH_SIZE_BYTES);

        /*@
         * @errortype
         * @moduleid MOD_VERIFY_ODY_MEASUREMENT_REGS
         * @reasoncode RC_ODY_BOOT_MEASUREMENT_FAIL
         * @userdata1 Odyssey Chip HUID
         * @userdata2 Unused
         * @devdesc Odyssey failed bootloader measurement hash verification
         * @custdesc Secureboot failure
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_VERIFY_ODY_MEASUREMENT_REGS,
                               RC_ODY_BOOT_MEASUREMENT_FAIL,
                               get_huid(i_ocmb),
                               0, // userdata2,
                               ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        goto ERROR_EXIT;
    }
    else
    {
        // All Odyssey measurement hashes should match, so only extend them once
        if(!l_extendBlMeasurementOnce)
        {
            char l_pcrExtendMessage[100];
            snprintf(l_pcrExtendMessage, 100, "Odyssey BOOT FW\n");
            l_errl = pcrExtend(PCR_2,
                               EV_PLATFORM_CONFIG_FLAGS,
                               reinterpret_cast<const uint8_t*>(l_sppeBlMeasurementData),
                               SPPE_MEASUREMENT_HASH_SIZE_BYTES,
                               reinterpret_cast<const uint8_t*>(l_pcrExtendMessage),
                            strlen(l_pcrExtendMessage));
            if(l_errl)
            {
                SB_ERR("verifyOdyMeasurementRegs: Could not extend SPPE bootloader measurement");
                goto ERROR_EXIT;
            }
            else
            {
                l_extendBlMeasurementOnce = true;
            }
        }
    }

    // Read out the runtime measurement registers and compare the
    // result to  rt/measured.hash (truncated to 48 bytes)
    for(uint32_t l_addr = RT_MEASUREMENT_REG_START, i = 0; l_addr <= RT_MEASUREMENT_REG_END; ++l_addr, ++i)
    {
        l_errl = deviceRead(i_ocmb,
                            &l_tempReadData,
                            l_readSize,
                            DEVICE_SCOM_ADDRESS(l_addr));
        if(l_errl)
        {
            SB_ERR("verifyOdyMeasurementRegs: Could not read RT measurement reg 0x%x for Odyssey 0x%x",
                    l_addr, get_huid(i_ocmb));
            goto ERROR_EXIT;
        }

        l_tempReadData = l_tempReadData >> 32; // The actual data from the SCOM read is in the top 32 bits
        l_sppeRtMeasurementData[i] = l_tempReadData;
    }

    l_pnorMeasurementData = i_ocmb->getAttrAsStdArr<ATTR_SPPE_RUNTIME_MEASUREMENT_HASH>();
    if(memcmp(l_sppeRtMeasurementData, l_pnorMeasurementData.data(), SPPE_MEASUREMENT_HASH_SIZE_BYTES))
    {
        SB_ERR("verifyOdyMeasurementRegs: Failed runtime measurement verification for Odyssey 0x%x",
               get_huid(i_ocmb));
        SB_INF_BIN("verifyOdyMeasurementRegs: runtime measurement hash from PNOR", l_pnorMeasurementData.data(), SPPE_MEASUREMENT_HASH_SIZE_BYTES);
        SB_INF_BIN("verifyOdyMeasurementRegs: runtime measurement hash from SPPE", l_sppeRtMeasurementData, SPPE_MEASUREMENT_HASH_SIZE_BYTES);

        /*@
         * @errortype
         * @moduleid MOD_VERIFY_ODY_MEASUREMENT_REGS
         * @reasoncode RC_ODY_RT_MEASUREMENT_FAIL
         * @userdata1 Odyssey Chip HUID
         * @userdata2 Unused
         * @devdesc Odyssey failed runtime measurement hash verification
         * @custdesc Secureboot failure
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_VERIFY_ODY_MEASUREMENT_REGS,
                               RC_ODY_RT_MEASUREMENT_FAIL,
                               get_huid(i_ocmb),
                               0, // userdata2,
                               ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        goto ERROR_EXIT;
    }
    else
    {
        // All Odyssey measurement hashes should match, so only extend them once
        if(!l_extendRtMeasurementOnce)
        {
            char l_pcrExtendMessage[100];
            snprintf(l_pcrExtendMessage, 100, "Odyssey RUNTIME FW\n");
            l_errl = pcrExtend(PCR_2,
                               EV_PLATFORM_CONFIG_FLAGS,
                               reinterpret_cast<const uint8_t*>(l_sppeRtMeasurementData),
                               SPPE_MEASUREMENT_HASH_SIZE_BYTES,
                               reinterpret_cast<const uint8_t*>(l_pcrExtendMessage),
                            strlen(l_pcrExtendMessage));
            if(l_errl)
            {
                SB_ERR("verifyOdyMeasurementRegs: Could not extend SPPE bootloader measurement");
                goto ERROR_EXIT;
            }
            else
            {
                l_extendRtMeasurementOnce = true;
            }
        }
    }

ERROR_EXIT:
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

        // Also verify that Odyssey MSV (comes from the BL SB control reg) is not less than the MSV set by P10 SBE
        if(l_controlReg == BL_SB_CONTROL_REG)
        {
            if(l_ocmbSBConfigReg.fields.minimumSecureVersion < SECUREBOOT::getMinimumSecureVersion())
            {
                SB_ERR("odySecurebootVerification: Odyssey 0x%x MSV value (0x%x) is less than system MSV (0x%x)",
                       get_huid(i_ocmb),
                       l_ocmbSBConfigReg.fields.minimumSecureVersion,
                       SECUREBOOT::getMinimumSecureVersion());
                uint32_t l_ocmbMSV = l_ocmbSBConfigReg.fields.minimumSecureVersion;
                /*@
                 * @errortype
                 * @moduleid MOD_ODY_SECUREBOOT_VERIF
                 * @reasoncode RC_ODY_BAD_MSV
                 * @userdata1 Odyssey Chip HUID
                 * @userdata2[0:31] Odyssey MSV
                 * @userdata2[32:63] System MSV (set by P10 SBE)
                 * @devdesc Odyssey Minimum Secure Version is less than the
                 *          Minimum Secure Version set by P10 SBE.
                 * @custdesc Secureboot failure
                 */
                l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                       MOD_ODY_SECUREBOOT_VERIF,
                                       RC_ODY_BAD_MSV,
                                       get_huid(i_ocmb),
                                       SrcUserData(bits{0,31}, l_ocmbMSV,
                                                   bits{32,63}, SECUREBOOT::getMinimumSecureVersion()),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                goto EXIT;
            }
        }
    }

    // Step 3/4: Verify that the SPPE image measurements from PNOR match those running on SPPE
    l_errl = verifyOdyMeasurementRegs(i_ocmb);
    if(l_errl)
    {
        SB_ERR("odySecurebootVerification: failed Odyssey measurement hash verification for Odyssey 0x%x",
               get_huid(i_ocmb));
        goto EXIT;
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
        auto l_fsmErrl = ody_upd_process_event(i_ocmb,
                                               MEAS_REGS_MISMATCH,
                                               errlOwner(l_errl));
        l_errl = nullptr;

        if(l_fsmErrl)
        {
            SB_ERR("odySecurebootVerification: Odyssey FSM returned an error");
            l_errl = l_fsmErrl.release();
        }
    }

    SB_INF("odySecurebootVerification end");
    return l_errl;
}
