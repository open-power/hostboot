/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_host_secureboot_lockdown.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
   @file call_host_secureboot_lockdown.C
 *
 *  Support file for IStep: host_secureboot_lockdown
 *    This istep will do these things (not necessarily in this order):
 *      1) Check for TPM policies are valid
 *      2) Check for compromised SBE security
 *      3) Check for secureboot consistency between procs
 *      4) Set the SUL security bit so that SBE image cannot be updated
 *      5) Ensure that the SAB security bit is read only
 *      6) If a TPM is non functional, set the TDP (TPM Deconfig Protection)
 *         to prevent attack vector
 *      7) Check for a reason, such as a Key Clear Request, to re-IPL the
 *         system so the system owner can assert physical presence
 *      8) Check Scratch Regiser 11 (0x50182) to see if SBE is reporting a previous fail.
 *
 */

// For istep and error logging support
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <initservice/initserviceif.H>
#include <initservice/mboxRegs.H>
#include <istepHelperFuncs.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <targeting/common/targetservice.H>

// For Secureboot, Trustedboot support
#include <secureboot/service.H>
#include <secureboot/phys_presence_if.H>
#include <secureboot/service_ext.H>
#include <secureboot/trustedbootif.H>

// Secureboot lockdown HWP
#include <plat_hwp_invoker.H>
#include <p10_update_security_ctrl.H>

// PHyp/OPAL loads
#include <targeting/common/mfgFlagAccessors.H>

namespace ISTEP_10
{

void* call_host_secureboot_lockdown (void *io_pArgs)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ENTER_MRK"call_host_secureboot_lockdown");

    ISTEP_ERROR::IStepError l_istepError;
#ifndef CONFIG_VPO_COMPILE
    errlHndl_t l_err = nullptr;

    do {

    // Attempt to initialize the backup TPM.
    TRUSTEDBOOT::initBackupTpm();

    // Always poison the backup TPM because we want to ensure
    // it varies from the primary.
    l_err = TRUSTEDBOOT::poisonBackupTpm();

    if(l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_host_secureboot_lockdown: poisonBackupTpm returned an error"
                  TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(l_err));
        l_istepError.addErrorDetails(l_err);
        TARGETING::Target * backup_tpm = nullptr;
        TRUSTEDBOOT::getBackupTpm(backup_tpm);
        assert(backup_tpm != nullptr, "call_host_secureboot_lockdown: poisonBackupTpm returned an error when no backup tpm available");
        // tpmMarkFailed will ensure there is at minimum a deconfig callout for the backup
        // TPM and also set the deconfig bit to force fencing if security is enabled
        TRUSTEDBOOT::tpmMarkFailed(backup_tpm, l_err);
    }

    TARGETING::TargetHandleList l_procList;
    getAllChips(l_procList,TARGETING::TYPE_PROC);


#ifdef CONFIG_SECUREBOOT

    TARGETING::TargetHandleList l_tpmList;
    TARGETING::Target* boot_proc = nullptr;
    if(SECUREBOOT::enabled())
    {
        getAllChips(l_tpmList,TARGETING::TYPE_TPM,false);

        l_err = TARGETING::targetService().queryMasterProcChipTargetHandle(boot_proc);
        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_host_secureboot_lockdown: FAIL getting boot proc"
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));

            captureError(l_err, l_istepError, HWPF_COMP_ID);

            // If targeting can't get the boot proc, then it's broke, so break here
            break;
        }
    }
#endif

    for(const auto& l_proc : l_procList)
    {
        // Check that the measurement seeproms are the approriate level for a "blessed" route of trust on the sytem
        // and that the fuse has been blown. In mnfg mode, failing these will result in a termination of the IPL but
        // in production an informational log will be committed instead.
        l_err = SECUREBOOT::verifyMeasurementSeepromSecurity(l_proc);

        if (l_err && l_err->sev() != ERRORLOG::ERRL_SEV_UNRECOVERABLE)
        {
            // Just commit the error since we're not in mfg mode.
            ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
        }
        else if (l_err)
        {
            captureError(l_err, l_istepError, ISTEP_COMP_ID, l_proc);
        }

#ifdef CONFIG_SECUREBOOT
        if(SECUREBOOT::enabled())
        {
            // Check if processor has a TPM that needs to be protected by setting the TDP bit
            // Stage 0: Assume the proc does NOT have a TPM connected to it
            //          - If a proc is not connected to a TPM then set its TDP bit
            // Stage 1: See if the proc has a TPM assigned to it according to the MRW
            //          - for each TPM in the list compare SPI master path with
            //            the path of the current processor to see if they are connected
            // Stage 2: If they are connected and the TPM is functional then there is no need
            //          to protect it.  Otherwise, the TPM needs to be protected.
            bool l_protectTpm = true; // Stage 0 assumption
            for (auto itpm : l_tpmList)
            {
                auto l_physPath = l_proc->getAttr<TARGETING::ATTR_PHYS_PATH>();

                auto l_tpmInfo = itpm->getAttr<TARGETING::ATTR_SPI_TPM_INFO>();

                if (l_tpmInfo.spiMasterPath == l_physPath) // Stage 1 check
                {
                    auto hwasState = itpm->getAttr<TARGETING::ATTR_HWAS_STATE>();

                    if (hwasState.functional == true) // Stage 2 check
                    {
                        l_protectTpm = false;
                    }

                    // Only one possible TPM per processor so break from the TPM loop here
                    break;
                }
            }
            if (l_protectTpm)
            {
                uint8_t l_set_protectTpm = 1;
                l_proc->setAttr<
                    TARGETING::ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM
                                                                    >(l_set_protectTpm);
            }

            // Check for compromised SBE security
            uint32_t l_sbe_compromised_eid = l_proc->getAttr<TARGETING::ATTR_SBE_COMPROMISED_EID>();
            if (l_sbe_compromised_eid)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    ERR_MRK"call_host_secureboot_lockdown: Found compromised SBE"
                    " for Proc HUID 0x%08x - see EID 0x%08X for more details",
                    TARGETING::get_huid(l_proc), l_sbe_compromised_eid );
                /*@
                 * @errortype
                 * @moduleid   ISTEP::MOD_CALL_HOST_SECUREBOOT_LOCKDOWN
                 * @reasoncode ISTEP::RC_SBE_COMPROMISED
                 * @userdata1  Huid of processor with compromised SBE
                 * @userdata2  EID with more details of why compromised
                 * @devdesc    SBE security compromise detected in 10.1 and not resolved
                 * @custdesc   Platform security problem detected
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                ISTEP::MOD_CALL_HOST_SECUREBOOT_LOCKDOWN,
                                                ISTEP::RC_SBE_COMPROMISED,
                                                TARGETING::get_huid(l_proc),
                                                l_sbe_compromised_eid);

                // Note: secureboot is enabled, so deconfig
                l_err->addHwCallout( l_proc,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::DELAYED_DECONFIG,
                                     HWAS::GARD_NULL );

                l_err->collectTrace(ISTEP_COMP_NAME);

                // Associate the previous error with this one so as not
                // to report a new problem
                l_err->plid(l_sbe_compromised_eid);
                SECUREBOOT::addSecurityRegistersToErrlog(l_err);
                captureError(l_err, l_istepError, ISTEP_COMP_ID, l_proc);

                // no sense in continuing on this compromised proc
                continue;
            }

            // Check that the SBE did not use Scratch Register 11 (0x50182) to pass FFDC
            // on a secureboot validation error up to hostboot to log an error
            // NOTE: While scoms store data in uint64_t's, scratch registers only have
            //       a uint32_t worth of valid data - the left-justified data of the scom
            uint64_t scomData = 0x0;
            size_t op_size = sizeof(scomData);
            uint32_t scratch_reg_value = 0x0;

            // For boot proc read from attribute that was saved off at the start of the IPL
            if (l_proc == boot_proc)
            {
                const auto l_scratchRegs = TARGETING::UTIL::assertGetToplevelTarget()->
                                             getAttrAsStdArr<TARGETING::ATTR_MASTER_MBOX_SCRATCH>();

                // MboxScratch11_t::REG_IDX is a uint32_t
                scratch_reg_value = l_scratchRegs[INITSERVICE::SPLESS::MboxScratch11_t::REG_IDX];

            }
            // For non-boot procs read Scratch Register 11 (0x50182) directly from HW
            else
            {
                l_err = deviceRead(
                            l_proc,
                            &scomData,
                            op_size,
                            DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch11_t::REG_ADDR));
                if(l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "call_host_secureboot_lockdown: SCOM Read of MAILBOX_SCRATCH_REG_11 "
                              "(0x%X) failed for Proc HUID 0x%08x "
                              TRACE_ERR_FMT,
                              INITSERVICE::SPLESS::MboxScratch11_t::REG_ADDR,
                              TARGETING::get_huid(l_proc),
                              TRACE_ERR_ARGS(l_err));

                    // Among other things, this will add the proc target to the log
                    captureError(l_err, l_istepError, HWPF_COMP_ID, l_proc);

                    // Try to run the HWP on all procs regardless of error.
                    continue;
                }

                // Use the left-justified 4 bytes of scomData for the scratch reg
                scratch_reg_value = static_cast<uint32_t>(scomData >> 32);
            }

            // Only look for verification fails in the scratch register
            // See mboxRegs.H for official scratch register bit definition, but it looks like this:
            // 0xAABBCCDD  where AA=reserved,
            //                   BB=tpm fail,
            //                   CC=HBBL verification fail,
            //                   DD=SBE verification fail
            uint32_t scratch_reg_mask = 0x0000FFFF;

            if ((scratch_reg_value & scratch_reg_mask) != 0x0)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_host_secureboot_lockdown: SBE reported FFDC Data in Scratch Reg 11 "
                          "(addr=0x%X) for Proc HUID 0x%08X: data = 0x%.8X (mask = 0x%.8X)"
                          TRACE_ERR_FMT,
                          INITSERVICE::SPLESS::MboxScratch11_t::REG_ADDR,
                          TARGETING::get_huid(l_proc), scratch_reg_value, scratch_reg_mask,
                          TRACE_ERR_ARGS(l_err));

               /*@
                 * @errortype
                 * @moduleid         ISTEP::MOD_SECUREBOOT_LOCKDOWN
                 * @reasoncode       ISTEP::RC_SBE_REPORTED_FFDC
                 * @userdata1        HUID of Processor Target target
                 * @userdata2[0:31]  Scratch Register Data
                 * @userdata2[32:63] Scratch Register Mask
                 * @devdesc          SBE or HBBL put FFDC data into Scratch Register 11
                 * @custdesc         A problem occurred during the IPL of the
                 *                   system and the system will reboot.
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                ISTEP::MOD_SECUREBOOT_LOCKDOWN,
                                ISTEP::RC_SBE_REPORTED_FFDC,
                                TARGETING::get_huid(l_proc),
                                TWO_UINT32_TO_UINT64(scratch_reg_value,
                                                     scratch_reg_mask));

                l_err->addHwCallout( l_proc,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::DELAYED_DECONFIG,
                                     HWAS::GARD_NULL );

                // Add the register to the log
                ERRORLOG::ErrlUserDetailsLogRegister(l_proc,
                              &scratch_reg_value,
                              sizeof(scratch_reg_value),
                              DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch11_t::REG_ADDR))
                                  .addToLog(l_err);

                // Among other things, this will add the proc target to the log
                captureError(l_err, l_istepError, HWPF_COMP_ID, l_proc);

                // Try to run the HWP on all procs regardless of error.
                continue;
            }


            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
            const bool DO_NOT_FORCE_SECURITY = false; // No need to force security
            const bool DO_NOT_LOCK_ABUS_MAILBOXES = false; // Do not lock abus mailboxes
            FAPI_INVOKE_HWP(l_err,
                            p10_update_security_ctrl,
                            l_fapiProc,
                            DO_NOT_FORCE_SECURITY,
                            DO_NOT_LOCK_ABUS_MAILBOXES);
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_host_secureboot_lockdown: p10_update_security_ctrl failed for Proc HUID 0x%08x "
                          TRACE_ERR_FMT, TARGETING::get_huid(l_proc),
                          TRACE_ERR_ARGS(l_err));
                l_istepError.addErrorDetails(l_err);
                ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
                // Try to run the HWP on all procs regardless of error.
            }
            // Lock OPAL keystore if in PHyp boot
            if (TARGETING::is_phyp_load())
            {
                l_err = SECUREBOOT::setSecuritySwitchBits({ SECUREBOOT::ProcSecurity::KsOpalBank0WrLock,
                    SECUREBOOT::ProcSecurity::KsOpalBank0RdLock,
                    SECUREBOOT::ProcSecurity::KsOpalBank1WrLock,
                    SECUREBOOT::ProcSecurity::KsOpalBank1RdLock,
                    SECUREBOOT::ProcSecurity::KsOpalQueueWrLock,
                    SECUREBOOT::ProcSecurity::KsOpalQueueRdLock },
                    l_proc);
                if (l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_host_secureboot_lockdown: "
                        "Cannot lock OPAL keystore on PROC 0x%08x ",
                        TRACE_ERR_FMT, TARGETING::get_huid(l_proc),
                        TRACE_ERR_ARGS(l_err));
                    l_istepError.addErrorDetails(l_err);
                    ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
                }
            }
            else
            {
                // Lock Phyp keystore if in OPAL boot
                l_err = SECUREBOOT::setSecuritySwitchBits({ SECUREBOOT::ProcSecurity::KsPhypWrLock,
                    SECUREBOOT::ProcSecurity::KsPhypRdLock },
                    l_proc);
                if (l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_host_secureboot_lockdown: "
                        "Cannot lock PHyp keystore on PROC 0x%08x ",
                        TRACE_ERR_FMT, TARGETING::get_huid(l_proc),
                        TRACE_ERR_ARGS(l_err));
                    l_istepError.addErrorDetails(l_err);
                    ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
                }
            }
        } // end of SECUREBOOT::enabled() check
#endif
    } // end of loop on procs
    if(l_istepError.getErrorHandle())
    {
        break;
    }

#ifdef CONFIG_SECUREBOOT
    SECUREBOOT::validateSecuritySettings();
#endif

#ifdef CONFIG_PHYS_PRES_PWR_BUTTON
    // Check to see if a Physical Presence Window should be opened,
    // and if so, open it.  This could result in the system being shutdown
    // to allow the system administrator to assert physical presence
    l_err = SECUREBOOT::handlePhysPresenceWindow();
    if (l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_host_secureboot_lockdown: Error back from "
                   "SECUREBOOT::handlePhysPresence: "
                   TRACE_ERR_FMT,
                   TRACE_ERR_ARGS(l_err));
        l_istepError.addErrorDetails(l_err);
        ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
        break;
    }
#endif
    }while(0);

#endif // CONFIG_VPO_COMPILE

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                EXIT_MRK"call_host_secureboot_lockdown");

    return l_istepError.getErrorHandle();
}

};
