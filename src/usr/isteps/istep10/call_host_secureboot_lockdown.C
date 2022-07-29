/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_host_secureboot_lockdown.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
#include <p10_disable_ocmb_i2c.H>

// PHyp/OPAL loads
#include <targeting/common/mfgFlagAccessors.H>

#include <targeting/common/utilFilter.H> // getAllChips
#include <targeting/targplatutil.H> // getCurrentNodeTarget

#include <i2c/i2c.H>
#include <i2c/i2c_common.H>

#include <spi/spi.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_utils.H>
#include <sbeio/sbe_retry_handler.H>
#include <sbeio/sbe_psudd.H>
#include <sys/misc.h>

#include "call_proc_build_smp.H"
#include "monitor_sbe_halt.H"

// PLDM
#if defined(CONFIG_PLDM)
#include <pldm/extended/sbe_dump.H>
#endif

using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   ERRORLOG;
using   namespace   SBEIO;

namespace ISTEP_10
{

/**
 * @brief Clear FIFO and perform HRESET to secondary processor SBE
 * @param[in] i_secProc - secondary processor target
 * @param[in/out] io_StepError - failure errors will be added to this
 */
void recoverSBE( Target * i_secProc, IStepError & io_StepError )
{
    errlHndl_t l_errl = nullptr;
    bool spiLockAcquired = false;

    do {
    // Prevent HB SPI operations to this non-boot/secondary processor during SBE boot
    l_errl = SPI::spiLockProcessor(i_secProc, true);
    if (l_errl)
    {
        // This would be a firmware bug that would be hard to
        // find later so terminate with this failure
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "recoverSBE(): ERROR : SPI lock failed to target %.8X "
                  TRACE_ERR_FMT,
                  get_huid(i_secProc),
                  TRACE_ERR_ARGS(l_errl));
        forceProcDelayDeconfigCallout(i_secProc, l_errl);
        captureError(l_errl, io_StepError, ISTEP_COMP_ID, i_secProc);
        break;
    }
    spiLockAcquired = true;

    // Clear FIFO via reset
    l_errl = sendFifoReset(i_secProc);
    if (l_errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "recoverSBE(): ERROR : call sendFifoReset target %.8X "
               TRACE_ERR_FMT,
               get_huid(i_secProc),
               TRACE_ERR_ARGS(l_errl) );
        forceProcDelayDeconfigCallout(i_secProc, l_errl);
        captureError(l_errl, io_StepError, ISTEP_COMP_ID, i_secProc);
        break;
    }

    // Perform hreset to secondary SBE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "recoverSBE(): perform hreset to secondary SBE on target %.8X",
               get_huid(i_secProc) );

    SbeRetryHandler l_SBEobj = SbeRetryHandler(
                             i_secProc,
                             SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                             SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                             EMPTY_PLID,
                             NOT_INITIAL_POWERON);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "recoverSBE(): run hreset now" );
    const bool SBE_IS_HALTED = true;
    l_SBEobj.main_sbe_handler(SBE_IS_HALTED);

    // We will judge whether or not the SBE had a successful
    // boot if it made it to runtime
    if(l_SBEobj.isSbeAtRuntime())
    {
        // Set the SBE started attribute
        i_secProc->setAttr<ATTR_SBE_IS_STARTED>(1);

        // Switch to using SBE SCOM
        ScomSwitches l_switches =
            i_secProc->getAttr<ATTR_SCOM_SWITCHES>();
        ScomSwitches l_switches_before = l_switches;

        // Turn on SBE SCOM and turn off FSI SCOM.
        l_switches.useFsiScom = 0;
        l_switches.useSbeScom = 1;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "recoverSBE(): hreset of SBE succeeded - changing SCOM"
                  " switches from 0x%.2X to 0x%.2X for proc 0x%.8X",
                  l_switches_before,
                  l_switches,
                  get_huid(i_secProc) );
        i_secProc->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"recoverSBE(): FAILURE : SMP SECUREBOOT "
                  "SBE for proc 0x%.8X did not reach runtime",
                  get_huid(i_secProc));
        /*@
         * @errortype
         * @reasoncode RC_FAILED_SBE_HRESET
         * @severity   ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_RECOVER_SBE
         * @userdata1  HUID of proc that failed to boot its SBE
         * @userdata2  Unused
         * @devdesc    Failed to boot a secondary SBE
         * @custdesc   Processor Error
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_RECOVER_SBE,
                               RC_FAILED_SBE_HRESET,
                               get_huid(i_secProc),
                               0);
        l_errl->collectTrace("ISTEPS_TRACE", 256);
        l_errl->addHwCallout( i_secProc,
                              HWAS::SRCI_PRIORITY_HIGH,
                              HWAS::DELAYED_DECONFIG,
                              HWAS::GARD_NULL );
#if defined(CONFIG_PLDM)
        // Associate the PLID of the l_errl to the dump_errl
        errlHndl_t dump_errl = PLDM::dumpSbe(i_secProc, l_errl->plid());
        if (dump_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"recoverSBE(): Failed to request SBE dump for PROC=0x%.8X which did NOT reach runtime",
                  get_huid(i_secProc));
            dump_errl->collectTrace("ISTEPS_TRACE", 256);
            dump_errl->collectTrace(SBEIO_COMP_NAME);
            dump_errl->plid(l_errl->plid());
            errlCommit(dump_errl, ISTEP_COMP_ID);
        }
#endif
        // captureError will commit l_errl which makes pulling the plid unable to dereference
        // if captureError comes before the usage of the l_errl->plid()
        captureError(l_errl, io_StepError, ISTEP_COMP_ID, i_secProc);
    }

    } while (0);

    // always try to put back into a good state
    if (spiLockAcquired)
    {
        // Enable HB SPI operations to this secondary processor after SBE boot
        l_errl = SPI::spiLockProcessor(i_secProc, false);
        if (l_errl)
        {
            // This would be a firmware bug that would be hard to
            // find later so terminate with this failure
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"recoverSBE(): ERROR : SPI unlock failed to target %.8X "
                      TRACE_ERR_FMT,
                      get_huid(i_secProc),
                      TRACE_ERR_ARGS(l_errl));
            forceProcDelayDeconfigCallout(i_secProc, l_errl);
            captureError(l_errl, io_StepError, ISTEP_COMP_ID, i_secProc);
        }
    }
} // end recoverSBE()


/**
 * @brief Enable PRD handling of SBE halted again
 *        - clear potential halt FIR
 *        - Unmask TP_LOCAL_FIR[33] - SBE - PPE in halted state
 *
 * @param[in] i_secondaryProcs - secondary/alternate processor targets
 * @param[in/out] io_StepError - istep failure errors will be added to this
 */
void enablePRDHaltHandling(const TargetHandleList& i_secondaryProcs,
                           IStepError & io_StepError)
{
    errlHndl_t errl = nullptr;

    for (auto proc : i_secondaryProcs)
    {
        // write 0xffffffffbfffffff to 0x01040101 (FIR atomic AND) to clear the FIR
        uint64_t local_fir_mask = ~TP_LOCAL_FIR_SBE_PPE_HALTED_STATE;
        size_t local_fir_mask_size = sizeof(local_fir_mask);
        errl = deviceWrite(proc,
                          &local_fir_mask,
                          local_fir_mask_size,
                          DEVICE_SCOM_ADDRESS(scomt::proc::TP_TPCHIP_TPC_LOCAL_FIR_WO_AND));

        if (errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"Failed to clear TP_LOCAL_FIR[33] on 0x%8X processor",
                      " tried to write 0x%016llX to SCOM address 0x%.8X",
                      get_huid(proc), local_fir_mask,
                      scomt::proc::TP_TPCHIP_TPC_LOCAL_FIR_WO_AND);

            forceProcDelayDeconfigCallout(proc, errl);

            // Capture error and continue to the next chip
            captureError(errl, io_StepError, ISTEP_COMP_ID, proc);
            continue;
        }

        // write 0xffffffffbfffffff to 0x01040104 (mask atomic AND) to clear the mask
        local_fir_mask = ~TP_LOCAL_FIR_SBE_PPE_HALTED_STATE;
        local_fir_mask_size = sizeof(local_fir_mask);
        errl = deviceWrite(proc,
                          &local_fir_mask,
                          local_fir_mask_size,
                          DEVICE_SCOM_ADDRESS(scomt::proc::TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND));

        if (errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"Failed to unmask TP_LOCAL_FIR[33] on 0x%8X processor,"
                      " tried to write 0x%016llX to SCOM address 0x%.8X",
                      get_huid(proc), local_fir_mask,
                      scomt::proc::TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_AND);

            forceProcDelayDeconfigCallout(proc, errl);
            // Capture error and continue to the next chip
            captureError(errl, io_StepError, ISTEP_COMP_ID, proc);
        }
    }
}


void* call_host_secureboot_lockdown (void *io_pArgs)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ENTER_MRK"call_host_secureboot_lockdown");

    IStepError l_istepError;
#ifndef CONFIG_VPO_COMPILE
    errlHndl_t l_err = nullptr;

    do {

    // Now that we've IPLed past the SBE update step, commit any errors caused
    // by unsupported SBE PSU chipops (because now we know that an SBE update
    // won't fix the problem).
    SbePsu::getTheInstance().commitUnsupportedCmdErrors();

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
        Target * backup_tpm = nullptr;
        TRUSTEDBOOT::getBackupTpm(backup_tpm);
        assert(backup_tpm != nullptr, "call_host_secureboot_lockdown: poisonBackupTpm returned an error when no backup tpm available");
        // tpmMarkFailed will ensure there is at minimum a deconfig callout for the backup
        // TPM and also set the deconfig bit to force fencing if security is enabled
        TRUSTEDBOOT::tpmMarkFailed(backup_tpm, l_err);
    }

    TargetHandleList l_procList;
    getAllChips(l_procList,TYPE_PROC);


#ifdef CONFIG_SECUREBOOT

    TargetHandleList l_tpmList;
    Target* boot_proc = nullptr;
    if(SECUREBOOT::enabled())
    {
        getAllChips(l_tpmList,TYPE_TPM,false);

        l_err = targetService().queryMasterProcChipTargetHandle(boot_proc);
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

        if (l_err && l_err->sev() != ERRL_SEV_UNRECOVERABLE)
        {
            // Just commit the error since we're not in mfg mode.
            errlCommit(l_err, ISTEP_COMP_ID);
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
                auto l_physPath = l_proc->getAttr<ATTR_PHYS_PATH>();

                auto l_tpmInfo = itpm->getAttr<ATTR_SPI_TPM_INFO>();

                if (l_tpmInfo.spiMasterPath == l_physPath) // Stage 1 check
                {
                    auto hwasState = itpm->getAttr<ATTR_HWAS_STATE>();

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
                    ATTR_SECUREBOOT_PROTECT_DECONFIGURED_TPM
                                                                    >(l_set_protectTpm);
            }

            // Check for compromised SBE security
            uint32_t l_sbe_compromised_eid = l_proc->getAttr<ATTR_SBE_COMPROMISED_EID>();
            if (l_sbe_compromised_eid)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    ERR_MRK"call_host_secureboot_lockdown: Found compromised SBE"
                    " for Proc HUID 0x%08x - see EID 0x%08X for more details",
                    get_huid(l_proc), l_sbe_compromised_eid );
                /*@
                 * @errortype
                 * @moduleid   MOD_CALL_HOST_SECUREBOOT_LOCKDOWN
                 * @reasoncode RC_SBE_COMPROMISED
                 * @userdata1  Huid of processor with compromised SBE
                 * @userdata2  EID with more details of why compromised
                 * @devdesc    SBE security compromise detected in 10.1 and not resolved
                 * @custdesc   Platform security problem detected
                 */
                l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                      MOD_CALL_HOST_SECUREBOOT_LOCKDOWN,
                                      RC_SBE_COMPROMISED,
                                      get_huid(l_proc),
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
                const auto l_scratchRegs = UTIL::assertGetToplevelTarget()->
                                             getAttrAsStdArr<ATTR_MASTER_MBOX_SCRATCH>();

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
                              get_huid(l_proc),
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
                          get_huid(l_proc), scratch_reg_value, scratch_reg_mask,
                          TRACE_ERR_ARGS(l_err));

               /*@
                 * @errortype
                 * @moduleid         MOD_SECUREBOOT_LOCKDOWN
                 * @reasoncode       RC_SBE_REPORTED_FFDC
                 * @userdata1        HUID of Processor Target target
                 * @userdata2[0:31]  Scratch Register Data
                 * @userdata2[32:63] Scratch Register Mask
                 * @devdesc          SBE or HBBL put FFDC data into Scratch Register 11
                 * @custdesc         A problem occurred during the IPL of the
                 *                   system and the system will reboot.
                 */
                l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                MOD_SECUREBOOT_LOCKDOWN,
                                RC_SBE_REPORTED_FFDC,
                                get_huid(l_proc),
                                TWO_UINT32_TO_UINT64(scratch_reg_value,
                                                     scratch_reg_mask));

                l_err->addHwCallout( l_proc,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::DELAYED_DECONFIG,
                                     HWAS::GARD_NULL );

                // Add the register to the log
                ErrlUserDetailsLogRegister(l_proc,
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
            I2C::ocmb_data_t l_ocmb_data = {};

            // see I2C::calcOcmbPortMaskForEngine for details
            I2C::calcOcmbPortMaskForEngine(l_proc, l_ocmb_data);

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "call_host_secureboot_lockdown: FSI_ENGINE_A_DEVICE_PROTECTION_DEVADDR=0x%X "
                "portlist_A=0x%llx",
                l_ocmb_data.devAddr, l_ocmb_data.portlist_A);

            // Need to configure the SUL OCMB lock PRIOR to setting SULbit
            // Protected PORTs of I2C Engine A, can only be updated when SUL=0
            //
            // Each PROC defines its configurable Engine Device Protection devAddr
            // The devAddr is used to allow the DD2 HW to block reads and writes to
            // the OCMB via I2C

            const bool overrideForceDisable = false;  // No need to force security
            const bool overrideSULsetup = true;       // Flag for SUL stage OCMB lock,
                                                      // i.e. configure just Engine A
                                                      // to block OCMB I2C reads and writes
                                                      // SUL (SEEPROM UPDATE LOCK)
            const bool overrideSOLsetup = false;      // Flag to skip SOL stage OCMB lock
                                                      // SOL OCMB logic happens in
                                                      // call_host_secure_rng
                                                      // SOL (Secure OCMB Lock),
                                                      // i.e. configure Engine B, C, E
                                                      // to block OCMB I2C reads and writes
            FAPI_INVOKE_HWP(l_err,
                            p10_disable_ocmb_i2c,
                            l_fapiProc,
                            l_ocmb_data.devAddr,      // devAddr ENGINE A
                            l_ocmb_data.devAddr,      // devAddr ENGINE B
                            l_ocmb_data.devAddr,      // devAddr ENGINE C
                            l_ocmb_data.devAddr,      // devAddr ENGINE E
                            l_ocmb_data.portlist_A,   // portlist for A
                            l_ocmb_data.portlist_B,   // portlist for B
                            l_ocmb_data.portlist_C,   // portlist for C
                            l_ocmb_data.portlist_E,   // portlist for E
                            overrideForceDisable,
                            overrideSULsetup,
                            overrideSOLsetup);
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_host_secureboot_lockdown: p10_disable_ocmb_i2c "
                    "failed for Proc HUID 0x%08x "
                    TRACE_ERR_FMT, TARGETING::get_huid(l_proc),
                    TRACE_ERR_ARGS(l_err));
                // Knock out the OCMBs but allow to continue
                TARGETING::TargetHandleList l_ocmb_list;
                // get the functional OCMBs
                getChildAffinityTargets(l_ocmb_list, l_proc,
                                        TARGETING::CLASS_CHIP,
                                        TARGETING::TYPE_OCMB_CHIP);
                for (const auto& l_ocmb : l_ocmb_list)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_host_secureboot_lockdown: Deconfiguring OCMBs "
                        "due to HWP p10_disable_ocmb_i2c failure: "
                        "PROC HUID=0x%08X OCMB HUID=0x%08X ",
                        get_huid(l_proc), get_huid(l_ocmb));
                    l_err->addHwCallout(l_ocmb,
                                        HWAS::SRCI_PRIORITY_MED,
                                        HWAS::DECONFIG,
                                        HWAS::GARD_NULL);
                }
                l_err->collectTrace(ISTEP_COMP_NAME);
                ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
            }
            else // all good so set attribute to skip engine A diagnostic reset during MPIPL
            {
                TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_A_type l_engine_A_inhibit =
                    l_proc->getAttr<TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_A>();
                // Log some informational traces for MPIPL flows if needed
                TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_host_secureboot_lockdown: "
                    "DIAG MODE RESET GET Engine A=%d", l_engine_A_inhibit);
                // FSI Engine A persists as always being inhibited from doing diagnostic resets
                // The setAttr for Engine A is to clearly identify the security lock down logic
                l_proc->setAttr<TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_A>(0x1);
                l_engine_A_inhibit = l_proc->getAttr<TARGETING::ATTR_I2C_INHIBIT_DIAGNOSTIC_RESET_ENGINE_A>();
                TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_host_secureboot_lockdown: "
                    "DIAG MODE RESET SET Engine A=%d", l_engine_A_inhibit);
            }

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
                          "call_host_secureboot_lockdown: p10_update_security_ctrl "
                          "failed for Proc HUID 0x%08x "
                          TRACE_ERR_FMT, TARGETING::get_huid(l_proc),
                          TRACE_ERR_ARGS(l_err));
                l_istepError.addErrorDetails(l_err);
                errlCommit(l_err, ISTEP_COMP_ID);
                // Try to run the HWP on all procs regardless of error.
            }

            // Lock OPAL keystore if in PHyp boot
            if (is_phyp_load())
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
                        TRACE_ERR_FMT, get_huid(l_proc),
                        TRACE_ERR_ARGS(l_err));
                    l_istepError.addErrorDetails(l_err);
                    errlCommit(l_err, ISTEP_COMP_ID);
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
                        TRACE_ERR_FMT, get_huid(l_proc),
                        TRACE_ERR_ARGS(l_err));
                    l_istepError.addErrorDetails(l_err);
                    errlCommit(l_err, ISTEP_COMP_ID);
                }
            }
        } // end of SECUREBOOT::enabled() check
#endif
    } // end of loop on procs
    if(!l_istepError.isNull())
    {
        break;
    }

#ifdef CONFIG_SECUREBOOT
    SECUREBOOT::validateSecuritySettings();
#endif

    // All secondary/non-boot procs
    TargetHandleList l_secondaryProcsList;

    // Identify the boot processor
    Target * l_bootProc =   nullptr;
    Target * l_bootNode =   nullptr;
    bool l_onlyFunctional = true; // Make sure bootproc is functional
    l_err = targetService().queryMasterProcChipTargetHandle(
                                                l_bootProc,
                                                l_bootNode,
                                                l_onlyFunctional);
    if(l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR : call_host_secureboot_lockdown: "
                    "queryMasterProcChipTargetHandle() "
                    TRACE_ERR_FMT,
                    TRACE_ERR_ARGS(l_err) );
        captureError(l_err, l_istepError, ISTEP_COMP_ID);
        break;
    }

    // Build list of secondary/non-boot processors too
    for (const auto & curproc: l_procList)
    {
        if (curproc != l_bootProc)
        {
            l_secondaryProcsList.push_back(curproc);
        }
    }

    // Get the capability attribute from the node
    TargetHandle_t l_nodeTarget = UTIL::getCurrentNodeTarget();
    auto l_sbeExtend =
        l_nodeTarget->getAttr<TARGETING::ATTR_SBE_HANDLES_SMP_TPM_EXTEND>();

    if (!l_sbeExtend)
    {
        // get all the measurements/extend to TPM and check
        //    Note: this uses XSCOM to do the readings
        retrieveAndExtendSecondaryMeasurements(l_bootProc,
                                               l_secondaryProcsList,
                                               true, // extendToTpm
                                               l_istepError);
        if (!l_istepError.isNull())
        {
            // break out on istep failure
            break;
        }
    }

    const bool isMpipl = TARGETING::UTIL::assertGetToplevelTarget()->
        getAttr<TARGETING::ATTR_IS_MPIPL_HB>();

    if(!isMpipl && !l_sbeExtend)
    {
        // Unhalt the SBEs if they were halted in istep 10.1.  See that
        // step for detailed explanation on the criteria for performing a halt.
        bool unhaltSbes = true;
        const bool isImprint = SECUREBOOT::getSbeSecurityBackdoor();
        if(isImprint)
        {
            for (auto l_proc : l_secondaryProcsList)
            {
                if(!l_proc->getAttr<TARGETING::ATTR_SBE_SUPPORTS_HALT_STATUS>())
                {
                    unhaltSbes = false;
                    break;
                }
            }
        }

        if(unhaltSbes)
        {
            // HRESET SBEs and bring them back up
            for (auto l_proc : l_secondaryProcsList)
            {
                // Don't restart compromised secondary SBEs
                if (l_proc->getAttr<ATTR_SBE_COMPROMISED_EID>())
                {
                    continue;
                }

                // remove from halt monitoring thread
                MONITOR_SBE_HALT::removeSbeProc(l_proc);

                // Clear FIFO and perform hreset to secondary SBE
                recoverSBE(l_proc, l_istepError);

                // recoverSBE will set useSbeScom if successful, so
                // change to XSCOM if the proc chips supports it
                if (l_proc->getAttr<ATTR_PRIMARY_CAPABILITIES>()
                    .supportsXscom)
                {
                    ScomSwitches l_switches =
                        l_proc->getAttr<ATTR_SCOM_SWITCHES>();

                    // If Xscom is not already enabled.
                    if ((l_switches.useXscom != 1) || (l_switches.useSbeScom != 0))
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "After hreset, switching back to useXscom from 0x%.2X for proc 0x%.8X",
                                l_switches,
                                get_huid(l_proc));

                        l_switches.useSbeScom = 0;
                        l_switches.useXscom = 1;

                        // Turn off SBE scom and turn on Xscom.
                        l_proc->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
                    }
                }
            }
            if (!l_istepError.isNull())
            {
                // break out on istep failure
                break;
            }

            // re-enable PRD to handle SBE Halt
            enablePRDHaltHandling(l_secondaryProcsList, l_istepError);
            if (!l_istepError.isNull())
            {
                // break out on istep failure
                break;
            }
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
                "call_host_secureboot_lockdown: Skipped unhalting SBEs because "
                "firmware was imprint signed and one or more SBEs did not "
                "support reporting Hostboot requested halts to service "
                "processor.");
        }
    }

    for (auto l_proc_target : l_secondaryProcsList)
    {
        // Now that the SMP is connected, it's possible to establish
        // untrusted memory windows for non-boot processor SBEs.  Open
        // up the Hostboot read-only memory range for each one to allow
        // Hostboot dumps / attention handling via any processor chip.

        // Don't open window for secondary SBEs not started
        if (!l_proc_target->getAttr<ATTR_SBE_IS_STARTED>())
        {
            continue;
        }

        const auto hbHrmor = cpu_spr_value(CPU_SPR_HRMOR);
        l_err = openUnsecureMemRegion( hbHrmor,
                                       VMM_MEMORY_SIZE,
                                       false, // False = read-only
                                       l_proc_target);
        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        ERR_MRK "Failed attempting to open Hostboot's "
                        "VMM region in SBE of non-boot processor chip "
                        "with HUID=0x%08X.  Requested address=0x%016llX, "
                        "size=0x%08X",
                        get_huid(l_proc_target),
                        hbHrmor, VMM_MEMORY_SIZE);

            captureError(l_err, l_istepError, HWPF_COMP_ID, l_proc_target);
        }
    }

    if (!l_istepError.isNull())
    {
        // break out on istep failure
        break;
    }

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
        errlCommit(l_err, ISTEP_COMP_ID);
        break;
    }
#endif
    }while(0);

#endif // CONFIG_VPO_COMPILE

    // stop this thread if it is still running
    MONITOR_SBE_HALT::stopSbeHaltMonitor();

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                EXIT_MRK"call_host_secureboot_lockdown");

    return l_istepError.getErrorHandle();
}

};
