/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_build_smp.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <fsi/fsiif.H>
#include <arch/magic.H>


//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/target.H>
#include <pbusLinkSvc.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <intr/interrupt.H>

#include <spi/spi.H>

//@TODO RTC:150562 - Remove when BAR setting handled by INTRRP
#include <devicefw/userif.H>
#include <sys/misc.h>
#include <sbeio/sbeioif.H>
#include <usr/vmmconst.h>
#include <p10_build_smp.H>

#include <secureboot/trustedbootif.H>
#include <secureboot/service.H>
#include <p10_scom_proc.H>
#include <sys/time.h>
#include <istepHelperFuncs.H>
#include <sbeio/sbe_retry_handler.H>
#include <sbeio/sbe_utils.H>

using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   ERRORLOG;
using   namespace   SBEIO;

namespace ISTEP_10
{
const uint64_t MAX_SBE_WAIT_NS = 30000*NS_PER_MSEC; //=30s

// TP_LOCAL_FIR[33] - SBE - PPE in halted state
const uint64_t TP_LOCAL_FIR_SBE_PPE_HALTED_STATE =
    1ull << (63 - scomt::proc::TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_33);

/**
 * @brief Force a processor delayed_deconfig callout in the error log
 * @param[in]     i_proc  processor target to callout
 * @param[in/out] io_err  error log to check/update with callout
 */
void forceProcDelayDeconfigCallout(TargetHandle_t const i_proc,
                                   errlHndl_t& io_err)
{
    const auto search_results = io_err->queryCallouts(i_proc);
    using compare_enum = ERRORLOG::ErrlEntry::callout_search_criteria;
    // Check if we found any callouts for this Processor
    if((search_results & compare_enum::TARGET_MATCH) == compare_enum::TARGET_MATCH)
    {
        // If we found a callout for this Processor w/o a DECONFIG,
        // edit the callout to include a deconfig
        if((search_results & compare_enum::DECONFIG_FOUND) != compare_enum::DECONFIG_FOUND)
        {
            io_err->setDeconfigState(i_proc, HWAS::DELAYED_DECONFIG);
        }
    }
    else
    {
        // Add HW callout for Processor with low priority
        io_err->addHwCallout(i_proc,
                            HWAS::SRCI_PRIORITY_LOW,
                            HWAS::DELAYED_DECONFIG,
                            HWAS::GARD_NULL);
    }
}

/**
 * @brief Prevent PRD from handling SBE halted
 *        - Mask TP_LOCAL_FIR[33] - SBE - PPE in halted state
 *
 * @param[in] i_secondaryProcs - secondary/alternate processor targets
 * @param[in/out] io_StepError - istep failure errors will be added to this
 */
void preventPRDHaltHandling(const TargetHandleList& i_secondaryProcs,
                            IStepError & io_StepError)
{
    errlHndl_t errl = nullptr;

    for (auto proc : i_secondaryProcs)
    {
        // Write 0x0000000040000000 (bit 33) to 0x01040105 (mask atomic OR) to mask the attention
        uint64_t local_fir_mask = TP_LOCAL_FIR_SBE_PPE_HALTED_STATE;
        size_t local_fir_mask_size = sizeof(local_fir_mask);
        errl = deviceWrite(proc,
                          &local_fir_mask,
                          local_fir_mask_size,
                          DEVICE_SCOM_ADDRESS(scomt::proc::TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));

        if (errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"Failed to mask TP_LOCAL_FIR[33] on 0x%8X processor",
                      " tried to write 0x%016llX to SCOM address 0x%.8X",
                      get_huid(proc), local_fir_mask,
                      scomt::proc::TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR);
            forceProcDelayDeconfigCallout(proc, errl);
            // Capture error and continue to the next chip
            captureError(errl, io_StepError, ISTEP_COMP_ID, proc);
        }
    }
}

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

/**
 * @brief Poison the primary TPM
 *        Common function so only actually poisons once
 */
void poisonPrimaryTpm()
{
#ifdef CONFIG_TPMDD
    errlHndl_t l_errl = nullptr;

    // TPM to poison
    Target* l_primaryTpm = nullptr;
    TRUSTEDBOOT::getPrimaryTpm(l_primaryTpm);

    // only poison the primary TPM once
    if ((l_primaryTpm != nullptr) &&
        (!l_primaryTpm->getAttr<TARGETING::ATTR_TPM_POISONED>()))
    {
        // make sure TPM is functional
        auto l_tpmHwasState = l_primaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>();
        if (l_tpmHwasState.functional)
        {
            // this will poison and flushTpmQueue
            l_errl = TRUSTEDBOOT::poisonTpm(l_primaryTpm);
            if (l_errl)
            {
                // mark the TPM as non-functional as poisoning should always work
                // note: this will also commit the error log and then set it to nullptr
                TRUSTEDBOOT::tpmMarkFailed(l_primaryTpm, l_errl);
            }
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "poisonPrimaryTpm(): skipping poisoning of NON-FUNCTIONAL TPM 0x%.8X",
                TARGETING::get_huid(l_primaryTpm));
        }
    }
#endif
}

/**
 * @brief Wait until SBE Attention is reported in status register
 * @param[in] i_secProc - secondary/alternate processor target
 * @param[in] i_max_wait_time_nsec - maximum time to wait for attn in nsecs
 * @return nullptr if SBE attn found, else error
 */
errlHndl_t waitForSBEAttn( Target * i_secProc,
                           const uint64_t i_max_wait_time_nsecs )
{
    errlHndl_t l_errl = nullptr;
    uint32_t l_status_data = 0;
    size_t l_32bitSize = sizeof(l_status_data);
    uint64_t l_elapsed_time_ns = 0;

    do
    {
        l_status_data = 0;
        l_32bitSize = sizeof(l_status_data);

        // Read TP.TPVSB.FSI.W.FSI2PIB.STATUS register (0x00001007ull)
        l_errl = deviceOp(DeviceFW::READ,
                          i_secProc,
                          &l_status_data,
                          l_32bitSize,
                          DEVICE_FSI_ADDRESS(scomt::proc::TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));

        // only check SBE bit on successful read
        if (!l_errl)
        {
            // check SELFBOOT_ENGINE_ATTENTION bit (30)
            uint32_t checkBit = 0x80000000 >> scomt::proc::TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION;
            if (l_status_data & checkBit)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "waitForSBEAttn: 0x%.8X proc SBE is at SBE attn",
                   get_huid(i_secProc) );
                break;
            }
            else
            {
                if (l_elapsed_time_ns > i_max_wait_time_nsecs)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "waitForSBEAttn: Elapsed 0x%16llX nsecs - 0x%.8X proc SBE"
                       " is NOT at SBE attn (0x%08X & SBE ATTN BIT 0x%08X)",
                       l_elapsed_time_ns, get_huid(i_secProc), l_status_data,
                       checkBit );

                    /*@
                     * @errortype
                     * @moduleid   MOD_WAIT_FOR_SBE_ATTN
                     * @reasoncode RC_WAIT_ATTN_TIMEOUT
                     * @userdata1[0:31]  HUID of proc without SBE attn
                     * @userdata1[32:63] Last response status (bit 30 = SBE Attn bit)
                     * @userdata2  Max wait time in ns
                     * @devdesc    Failed to halt a secondary SBE
                     * @custdesc   Processor Error
                     */
                    l_errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                           MOD_WAIT_FOR_SBE_ATTN,
                                           RC_WAIT_ATTN_TIMEOUT,
                                           TWO_UINT32_TO_UINT64(
                                           get_huid(i_secProc),
                                           l_status_data),
                                           i_max_wait_time_nsecs);
                    // SBE says it supports halt, so this timeout should not happen
                    l_errl->addHwCallout( i_secProc,
                                          HWAS::SRCI_PRIORITY_HIGH,
                                          HWAS::DELAYED_DECONFIG,
                                          HWAS::GARD_NULL );
                    break;
                }

                // try later
                nanosleep( 0, 1000000 ); //sleep for 1ms
                l_elapsed_time_ns += 1000000;
            }
        } // errl check

    } while (!l_errl);
    return l_errl;
} // end waitForSBEAttn()


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
    //Note no PLID passed in
    SbeRetryHandler l_SBEobj = SbeRetryHandler(
            SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT);

    l_SBEobj.setSbeRestartMethod(SbeRetryHandler::
                                 SBE_RESTART_METHOD::HRESET);

    l_SBEobj.setInitialPowerOn(false);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "recoverSBE(): run hreset now" );
    bool haltStateExpected = true;
    l_SBEobj.main_sbe_handler(i_secProc, haltStateExpected);

    // We will judge whether or not the SBE had a successful
    // boot if it made it to runtime
    if(l_SBEobj.isSbeAtRuntime())
    {
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
        * @reasoncode RC_FAILED_SBE_HRESET
        * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
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

        // Need to switch SPI control register back to FSI_ACCESS mode
        // since SBE will flip the access mode into PIB_ACCESS
        l_errl = SPI::spiSetAccessMode(i_secProc, SPI::FSI_ACCESS);
        if (l_errl)
        {
            // This would be another hard to find firmware bug so terminate
            // with this failure
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"recoverSBE(): SPI access mode "
                      "switch to FSI_ACCESS failed for target %.8X "
                      TRACE_ERR_FMT,
                      get_huid(i_secProc),
                      TRACE_ERR_ARGS(l_errl));
            forceProcDelayDeconfigCallout(i_secProc, l_errl);
            captureError(l_errl, io_StepError, ISTEP_COMP_ID, i_secProc);
        }
    }
} // end recoverSBE()


/**
 * @brief Check if SAB (Secure Access Bit) is set in PERV_CBS_CS register via FSI
 * @param[in]  i_procTarget - secondary processor target
 * @param[out] o_set - setting of SAB
 * @return nullptr | FSI read error
 */
errlHndl_t isSecureAccessSet(const TargetHandle_t i_procTarget, bool & o_set)
{
    o_set = false; // default to not set
    errlHndl_t l_err = nullptr;
    // FSI_BYTE Register PERV_CBS_CS
    uint64_t l_fsiAddr = static_cast<uint64_t>(SECUREBOOT::ProcCbsControl::StatusRegisterFsi);
    const uint32_t CBS_CS_SECURE_ACCESS_BIT = 0x08000000; // Bit 4
    uint32_t l_data = 0;
    size_t l_size = sizeof(l_data);

    l_err = deviceRead( i_procTarget, &l_data, l_size,
                        DEVICE_FSI_ADDRESS(l_fsiAddr) );
    if (l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
           ERR_MRK"isSecureAccessSet(0x%.8X) read failed, default is not secure",
           get_huid(i_procTarget) );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
           "isSecureAccessSet(0x%.8X) address 0x%.8X read 0x%08X",
           get_huid(i_procTarget),
           l_fsiAddr,
           l_data );
        if (l_data & CBS_CS_SECURE_ACCESS_BIT)
        {
            o_set = true;
        }
    }
    return l_err;
}


/**
 * @brief Read SAB value via FSI from A|S SBE and validate it matches
 *        the primary SBE value.
 *        If mismatch is detected:
 *        - poison primary TPM
 *        - set ATTR_SBE_COMPROMISED_EID to mismatch error ID
 * @param[in] i_secondaryProcs - secondary/alternate processor targets
 * @param[in/out] io_StepError - istep failure errors will be added to this
 */
void checkForSecurityAccessMismatch(const TargetHandleList& i_secondaryProcs,
                                    IStepError & io_StepError)
{
    errlHndl_t l_errl = nullptr;

    bool poisonTpm = false;

    // SAB setting
    bool l_primarySecureAccessSet = false;
    bool l_secondarySecureAccessSet = false;

    // check primary setting first
    l_primarySecureAccessSet = SECUREBOOT::enabled();

    for ( auto curproc : i_secondaryProcs)
    {
        // compare Secure Access settings
        l_errl = isSecureAccessSet(curproc, l_secondarySecureAccessSet);
        if (l_errl)
        {
            // unable to read SAB from hw
            forceProcDelayDeconfigCallout(curproc, l_errl);
            captureError(l_errl, io_StepError, ISTEP_COMP_ID, curproc);
            continue;  // go to next secondary processor
        }

        if (l_secondarySecureAccessSet != l_primarySecureAccessSet)
        {
            // need to notify security can't be trusted
            poisonTpm = true;

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                "SAB for 0x%.8X processor (%d) mismatches master setting (%d)",
                get_huid(curproc), l_secondarySecureAccessSet, l_primarySecureAccessSet);

            /*@
             * @errortype
             * @moduleid   MOD_CHECK_FOR_SECURITY_ACCESS_MISMATCH
             * @reasoncode RC_SAB_MISMATCH_DETECTED
             * @userdata1  Huid of secondary processor
             * @userdata2[0:31]   Primary processor SAB
             * @userdata2[32:63]  Secondary processor SAB
             * @devdesc    Security Access mismatch
             * @custdesc   Platform security problem detected
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             MOD_CHECK_FOR_SECURITY_ACCESS_MISMATCH,
                                             RC_SAB_MISMATCH_DETECTED,
                                             get_huid(curproc),
                                             TWO_UINT32_TO_UINT64(
                                             l_primarySecureAccessSet,
                                             l_secondarySecureAccessSet
                                             ));
            l_errl->addHwCallout( curproc,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::NO_DECONFIG,
                                  HWAS::GARD_NULL );
            if (!SECUREBOOT::enabled())
            {
              TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "checkForSecurityAccessMismatch: security is off, "
                  "so just log the SAB Mismatch (EID: 0x%08X) as informational",
                  l_errl->eid() );
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            }

            // only mark compromised if not already marked
            if (!curproc->getAttr<ATTR_SBE_COMPROMISED_EID>())
            {
                // update attribute with EID of poisoning reason
                curproc->setAttr<ATTR_SBE_COMPROMISED_EID>(l_errl->eid());
            }

            SECUREBOOT::addSecurityRegistersToErrlog(l_errl);
            l_errl->collectTrace(ISTEP_COMP_NAME);

            // IPL should be able to continue, so just log the mismatch error
            errlCommit(l_errl, ISTEP_COMP_ID);
        }
    }

    if (poisonTpm)
    {
        poisonPrimaryTpm();
    }
}



/**
 * @brief XSCOM TPM measurements for the secondary chips
 *        1. Validates PCR6 security state values matches between all SBEs
 *        2. Mismatch will cause primary TPM to be poisoned,
 *           indicating we are in an invalid security state
 *        3. Extend all measurements (except PCR6) from secondary/alternate
 *           procs to TPM and append to log
 *
 * @param[in] i_primaryProc    - primary sentinal processor target
 * @param[in] i_secondaryProcs - secondary/alternate processor targets
 * @param[in/out] io_StepError - istep failure errors will be added to this
 */

void retrieveAndExtendSecondaryMeasurements(
                                const TargetHandle_t i_primaryProc,
                                const TargetHandleList& i_secondaryProcs,
                                IStepError & io_StepError )
{
    errlHndl_t  l_errl  =   nullptr;
    bool l_poison_tpm = false;

    // structure to report what mismatched
    typedef union {
      uint8_t full_reason;
      struct
      {
        uint8_t rsvd          : 5;
        uint8_t PCR6_regs_0   : 1; // SBE Security State - PCR6 version
        uint8_t PCR6_regs_1   : 1; // HW Key Hash- PCR6 version
        uint8_t PCR6_regs_4_7 : 1; // Hash of SBE Secureboot Validation Image
      } PACKED;
    } mismatch_reason_t;

    // TPM to log/extend measurements (or potentially poison)
    Target* l_primaryTpm = nullptr;

    // measurement data
    TRUSTEDBOOT::TPM_sbe_measurements_regs_grouped l_primarySbeMeasuredGroups;
    TRUSTEDBOOT::TPM_sbe_measurements_regs_grouped l_secondarySbeMeasuredGroups;

    uint32_t poison_eid = 0; // EID of error that caused poisoning of TPM

    do {
    // TPM to log/extend measurements (or potentially poison)
    TRUSTEDBOOT::getPrimaryTpm(l_primaryTpm);
    auto l_tpmHwasState = l_primaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>();

    // grab primary values first
    l_errl = TRUSTEDBOOT::groupSbeMeasurementRegs(i_primaryProc, l_primarySbeMeasuredGroups);
    if (l_errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
           ERR_MRK"ERROR : retrieveAndExtendSecondaryMeasurements: "
           "groupSbeMeasurementRegs returned error for 0x%.8X primary processor "
           TRACE_ERR_FMT,
           get_huid(i_primaryProc),
           TRACE_ERR_ARGS(l_errl) );
        // this indicates XSCOM failure on primary processor so make this fatal
        forceProcDelayDeconfigCallout(i_primaryProc, l_errl);
        captureError(l_errl, io_StepError, ISTEP_COMP_ID, i_primaryProc);
        break;
    }

    // secondary chips
    for ( auto curproc : i_secondaryProcs)
    {
        l_errl = TRUSTEDBOOT::groupSbeMeasurementRegs(curproc, l_secondarySbeMeasuredGroups);
        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ERR_MRK"ERROR : retrieveAndExtendSecondaryMeasurements: "
               "groupSbeMeasurementRegs returned error for 0x%.8X processor "
               TRACE_ERR_FMT,
               get_huid(curproc),
               TRACE_ERR_ARGS(l_errl) );
            forceProcDelayDeconfigCallout(curproc, l_errl);
            captureError(l_errl, io_StepError, ISTEP_COMP_ID, curproc);
            continue;
        }

        mismatch_reason_t l_mismatch = {0};
        // compare PCR6 for mismatch - register 0/security state
        if (memcmp(l_primarySbeMeasuredGroups.sbe_measurement_regs_0,
                   l_secondarySbeMeasuredGroups.sbe_measurement_regs_0,
                   TRUSTEDBOOT::TPM_SBE_MEASUREMENT_REGS_0_SIZE))
        {
            l_mismatch.PCR6_regs_0 = 1;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK"Mismatch found: 0x%08X processor PCR6 register 0/security state",
                get_huid(curproc) );
            TRACFBIN( ISTEPS_TRACE::g_trac_isteps_trace, "Primary PCR6 Reg 0/security state",
                l_primarySbeMeasuredGroups.sbe_measurement_regs_0,
                TRUSTEDBOOT::TPM_SBE_MEASUREMENT_REGS_0_SIZE );
            TRACFBIN( ISTEPS_TRACE::g_trac_isteps_trace, "Secondary PCR6 Reg 0/security state",
                l_secondarySbeMeasuredGroups.sbe_measurement_regs_0,
                TRUSTEDBOOT::TPM_SBE_MEASUREMENT_REGS_0_SIZE );
        }
        // compare PCR6 for mismatch - register 1/HW key hash
        if (memcmp(l_primarySbeMeasuredGroups.sbe_measurement_regs_1,
                   l_secondarySbeMeasuredGroups.sbe_measurement_regs_1,
                   TRUSTEDBOOT::TPM_SBE_MEASUREMENT_REGS_1_SIZE))
        {
            l_mismatch.PCR6_regs_1 = 1;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK"Mismatch found: 0x%08X processor PCR6 register 1/HW key hash",
                get_huid(curproc) );
            TRACFBIN( ISTEPS_TRACE::g_trac_isteps_trace, "Primary PCR6 Reg 1/HW key hash",
                l_primarySbeMeasuredGroups.sbe_measurement_regs_1,
                TRUSTEDBOOT::TPM_SBE_MEASUREMENT_REGS_1_SIZE );
            TRACFBIN( ISTEPS_TRACE::g_trac_isteps_trace, "Secondary PCR6 Reg 1/HW key hash",
                l_secondarySbeMeasuredGroups.sbe_measurement_regs_1,
                TRUSTEDBOOT::TPM_SBE_MEASUREMENT_REGS_1_SIZE );
        }
        // compare PCR6 for mismatch - registers 4 to 7/Hash of SBE secureboot validation image
        if (memcmp(l_primarySbeMeasuredGroups.sbe_measurement_regs_4_7,
                   l_secondarySbeMeasuredGroups.sbe_measurement_regs_4_7,
                   TRUSTEDBOOT::TPM_SBE_MEASUREMENT_REGS_4_7_SIZE))
        {
            l_mismatch.PCR6_regs_4_7 = 1;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK"Mismatch found: 0x%08X processor PCR6 registers 4-7/SBE secureboot validation image",
                get_huid(curproc) );
            TRACFBIN( ISTEPS_TRACE::g_trac_isteps_trace, "Primary PCR6 Reg 4-7/SBE secureboot validation image",
                l_primarySbeMeasuredGroups.sbe_measurement_regs_4_7,
                TRUSTEDBOOT::TPM_SBE_MEASUREMENT_REGS_4_7_SIZE);
            TRACFBIN( ISTEPS_TRACE::g_trac_isteps_trace, "Secondary PCR6 Reg 4-7/SBE secureboot validation image",
                l_secondarySbeMeasuredGroups.sbe_measurement_regs_4_7,
                TRUSTEDBOOT::TPM_SBE_MEASUREMENT_REGS_4_7_SIZE);
        }

        if (l_mismatch.full_reason != 0)
        {
            l_poison_tpm = true;

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                "creating error for mismatch (0x%.08X) on proc 0x%.8X",
                l_mismatch.full_reason, get_huid(curproc) );

            /*@
             * @errortype
             * @moduleid   MOD_RETRIEVE_EXTEND_SECONDARY_MEASUREMENTS
             * @reasoncode RC_PCR6_MISMATCH_DETECTED
             * @userdata1  Huid of secondary processor
             * @userdata2  Mismatch found (bitwise 0x02 = PCR6 0, 0x01 = PCR6 4-7)
             * @devdesc    Unable to confirm PCR6 match between primary and secondary SBE
             * @custdesc   Platform security problem detected
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             MOD_RETRIEVE_EXTEND_SECONDARY_MEASUREMENTS,
                                             RC_PCR6_MISMATCH_DETECTED,
                                             get_huid(curproc),
                                             l_mismatch.full_reason);
            l_errl->addHwCallout( curproc,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::NO_DECONFIG,
                                  HWAS::GARD_NULL );
            if (!SECUREBOOT::enabled())
            {
              TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "retrieveAndExtendSecondaryMeasurements: security is off, "
                  "so just log the PCR6 Mismatch (EID: 0x%08X) as informational",
                  l_errl->eid() );
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            }
            poison_eid = l_errl->eid();
            l_errl->collectTrace(ISTEP_COMP_NAME);
            SECUREBOOT::addSecurityRegistersToErrlog(l_errl);

            // allow the istep to continue for just a mismatch error
            errlCommit(l_errl, ISTEP_COMP_ID);
        }

        // primaryTpm must be functional to log/extend measurements
        if (l_tpmHwasState.functional)
        {
            // log and extend measurements (good or mismatched ones)
            l_errl = TRUSTEDBOOT::logSbeMeasurementRegs(l_primaryTpm, curproc, l_secondarySbeMeasuredGroups, true);
            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    ERR_MRK"retrieveAndExtendSecondaryMeasurements: "
                    "log/extend measurements for 0x%08X processor SBE",
                    get_huid(curproc));
                forceProcDelayDeconfigCallout(curproc, l_errl);
                captureError(l_errl, io_StepError, ISTEP_COMP_ID, curproc);
            }
        }

        if (poison_eid)
        {
            // If not already compromised, set to this poison_eid
            if (!curproc->getAttr<ATTR_SBE_COMPROMISED_EID>())
            {
                // update attribute with EID of poisoning reason
                curproc->setAttr<ATTR_SBE_COMPROMISED_EID>(poison_eid);
            }
            // clear it out for next secondary processor
            poison_eid = 0;
        }
    } // secondary chip loop
    } while (0);

    if(l_poison_tpm)
    {
        poisonPrimaryTpm();
    }
}


// Main function
void* call_proc_build_smp (void *io_pArgs)
{
    IStepError l_StepError;

    // General flow of this istep
    // a) phase 1 build SMP
    // b) halt all non-boot chip SBEs
    // c) check for Secure Access mismatch via FSI to non-boot chips
    // d) call HWP to specifically enable SMP fabric (pb hotplug)
    // e) get all the measurements/extend to TPM, etc
    // f) HRESET secondary SBEs and bring them back up

    // TODO RTC:268503 - remove by GA as all SBEs will support halt
    TARGETING::ATTR_SBE_FIFO_CAPABILITIES_type l_sbe_capabilities = {};

    do
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_proc_build_smp entry" );

        errlHndl_t  l_errl  =   nullptr;
        TargetHandleList l_cpuTargetList;

        TargetHandleList l_secondaryProcsList;  // all secondary/non-boot procs

        // TODO RTC:268503 - change l_procSupportHalt to l_secondaryProcsList
        //                   since all should support HALT by GA
        TargetHandleList l_procsSupportHalt;    // procs with halt-capable SBE
        getAllChips(l_cpuTargetList, TYPE_PROC);

        //  Identify the boot processor
        Target * l_bootProc =   nullptr;
        Target * l_bootNode =   nullptr;
        bool l_onlyFunctional = true; // Make sure bootproc is functional
        l_errl = targetService().queryMasterProcChipTargetHandle(
                                                 l_bootProc,
                                                 l_bootNode,
                                                 l_onlyFunctional);
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call_proc_build_smp: "
                       "queryMasterProcChipTargetHandle() "
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(l_errl) );
            captureError(l_errl, l_StepError, ISTEP_COMP_ID);
            break;
        }

        // FAPI2 list for HWP
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> l_procList;

        // Loop through all proc chips and convert them to FAPI targets
        for (const auto & curproc: l_cpuTargetList)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                    l_fapi2_proc_target (curproc);
            l_procList.push_back(l_fapi2_proc_target);

            // build list of non-boot processors too
            if (curproc != l_bootProc)
            {
                // include all secondary processors
                l_secondaryProcsList.push_back(curproc);

                ////////////
                // TODO RTC:268503 - remove capabilites check by GA
                // check capabilites to see if HALT is supported
                if (curproc->tryGetAttr<TARGETING::ATTR_SBE_FIFO_CAPABILITIES>(l_sbe_capabilities))
                {
                    if ((l_sbe_capabilities[SBEIO::SBE_CAPABILITY_HALT_OFFSET] & SBEIO::SBE_CMD_HALT_SUPPORTED)
                         == SBEIO::SBE_CMD_HALT_SUPPORTED)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "HALT supported for proc 0x%08X SBE",
                            TARGETING::get_huid(curproc));
                        // include just halt-capable procs/sbe
                        l_procsSupportHalt.push_back(curproc);
                    }
                    else
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "HALT NOT supported for proc 0x%08X SBE - read 0x%08X at offset %d",
                            TARGETING::get_huid(curproc), l_sbe_capabilities[SBEIO::SBE_CAPABILITY_HALT_OFFSET], SBEIO::SBE_CAPABILITY_HALT_OFFSET);
                    }
                }
                else
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "HALT NOT supported for proc 0x%08X SBE",
                            TARGETING::get_huid(curproc));
                }
                //////////////
            }
        }

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                            l_fapi2_boot_proc (l_bootProc);


        // a) phase 1 build SMP
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Call p10_build_smp(SMP_ACTIVATE_PHASE1)" );
        FAPI_INVOKE_HWP( l_errl, p10_build_smp,
                         l_procList,
                         l_fapi2_boot_proc,
                         SMP_ACTIVATE_PHASE1 );

        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call p10_build_smp(SMP_ACTIVATE_PHASE1) "
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(l_errl) );
            //@FIXME-RTC:254475-Remove once this works everywhere
            if( MAGIC_INST_CHECK_FEATURE(MAGIC_FEATURE__IGNORESMPFAIL) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "WORKAROUND> Ignoring error for now - p10_build_smp" );
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit( l_errl, HWPF_COMP_ID );
            }
            else
            {
                captureError(l_errl, l_StepError, HWPF_COMP_ID);
                break;
            }
        }

        // Mask appropriate bits to prevent PRDF handling of SBE halt
        preventPRDHaltHandling(l_procsSupportHalt, l_StepError);
        if (!l_StepError.isNull())
        {
            // NOTE: no need to try to re-enable PRD halt handling on
            // the non-failed processors.  It will happen automatically
            // during the reconfig loop after bad processors are deconfigured
            break;
        }

        // b) halt all non-boot chip SBEs
        for (auto l_proc : l_procsSupportHalt)
        {
            // send halt request
            l_errl = SBEIO::sendSecondarySbeHaltRequest(l_proc);
            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR : call_proc_build_smp: sendSecondarySbeHaltRequest returned error" );
                forceProcDelayDeconfigCallout(l_proc, l_errl);
                captureError(l_errl, l_StepError, ISTEP_COMP_ID, l_proc);
                continue;  // no sense waiting for SBE attn
            }

            // monitor for halt completion
            l_errl = waitForSBEAttn(l_proc, MAX_SBE_WAIT_NS);
            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR : call_proc_build_smp: waitForSBEAttn returned error" );
                forceProcDelayDeconfigCallout(l_proc, l_errl);
                captureError(l_errl, l_StepError, ISTEP_COMP_ID, l_proc);
            }
        }
        if (!l_StepError.isNull())
        {
            // break out on istep failure
            break;
        }

        // c) check for Secure Access mismatch via FSI to non-boot chips
        checkForSecurityAccessMismatch(l_secondaryProcsList, l_StepError);
        if (!l_StepError.isNull())
        {
            // break out on istep failure
            break;
        }

        // d) Call HWP to specifically enable SMP fabric (pb hotplug)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Call p10_build_smp(SMP_ACTIVATE_SWITCH)" );
        FAPI_INVOKE_HWP( l_errl, p10_build_smp,
                         l_procList,
                         l_fapi2_boot_proc,
                         SMP_ACTIVATE_SWITCH );
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR : call p10_build_smp(SMP_ACTIVATE_SWITCH) "
                TRACE_ERR_FMT,
                TRACE_ERR_ARGS(l_errl) );
            captureError(l_errl, l_StepError, HWPF_COMP_ID);
            break;
        }


        // At the point where we can now change the proc chips to use
        // XSCOM rather than SBESCOM which is the default.
        for (auto l_proc_target : l_cpuTargetList)
        {
            // If the proc chip supports xscom..
            if (l_proc_target->getAttr<ATTR_PRIMARY_CAPABILITIES>()
                .supportsXscom)
            {
                ScomSwitches l_switches =
                  l_proc_target->getAttr<ATTR_SCOM_SWITCHES>();

                // If Xscom is not already enabled.
                if ((l_switches.useXscom != 1) || (l_switches.useSbeScom != 0))
                {
                    l_switches.useSbeScom = 0;
                    l_switches.useXscom = 1;

                    // Turn off SBE scom and turn on Xscom.
                    l_proc_target->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
                }
            }
        }

        // e) get all the measurements/extend to TPM and check
        //    Note: this uses XSCOM to do the readings
        retrieveAndExtendSecondaryMeasurements(l_bootProc, l_secondaryProcsList, l_StepError);
        if (!l_StepError.isNull())
        {
            // break out on istep failure
            break;
        }

        // f) HRESET SBEs and bring them back up
        for (auto l_proc : l_procsSupportHalt)
        {
            // Clear FIFO and perform hreset to secondary SBE
            recoverSBE(l_proc, l_StepError);

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
        if (!l_StepError.isNull())
        {
            // break out on istep failure
            break;
        }

        // Call SMP_ACTIVATE_POST
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Call p10_build_smp(SMP_ACTIVATE_POST)" );
        FAPI_INVOKE_HWP( l_errl, p10_build_smp,
                         l_procList,
                         l_fapi2_boot_proc,
                         SMP_ACTIVATE_POST );
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call p10_build_smp(SMP_ACTIVATE_POST) "
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(l_errl) );
            captureError(l_errl, l_StepError, HWPF_COMP_ID);
            break;
        }

        // re-enable PRD to handle SBE Halt
        enablePRDHaltHandling(l_procsSupportHalt, l_StepError);
        if (!l_StepError.isNull())
        {
            // break out on istep failure
            break;
        }

        for (auto l_proc_target : l_secondaryProcsList)
        {
            // Switch from FSI to PIB SPI access for secondary processors
            l_errl = SPI::spiSetAccessMode(l_proc_target, SPI::PIB_ACCESS);
            if(l_errl)
            {
                // Since this is a hard failure to detect later
                // (via SPI failures), error out here
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                  "call_proc_build_smp> Unable to switch SPI access to "
                  "PIB_ACCESS for 0x%.8X",
                  get_huid(l_proc_target) );
                captureError(l_errl, l_StepError, ISTEP_COMP_ID, l_proc_target);
                break;
            }

            //Enable PSIHB Interrupts for secondary proc -- moved from above
            l_errl = INTR::enablePsiIntr(l_proc_target);
            if(l_errl)
            {
                captureError(l_errl, l_StepError, HWPF_COMP_ID, l_proc_target);
                break;
            }

            // Now that the SMP is connected, it's possible to establish
            // untrusted memory windows for non-master processor SBEs.  Open
            // up the Hostboot read-only memory range for each one to allow
            // Hostboot dumps / attention handling via any processor chip.
            const auto hbHrmor = cpu_spr_value(CPU_SPR_HRMOR);
            l_errl = SBEIO::openUnsecureMemRegion( hbHrmor,
                                                   VMM_MEMORY_SIZE,
                                                   false, // False = read-only
                                                   l_proc_target);
            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK "Failed attempting to open Hostboot's "
                          "VMM region in SBE of non-master processor chip "
                          "with HUID=0x%08X.  Requested address=0x%016llX, "
                          "size=0x%08X",
                          get_huid(l_proc_target),
                          hbHrmor, VMM_MEMORY_SIZE);

                captureError(l_errl, l_StepError, HWPF_COMP_ID, l_proc_target);
                break;
            }
        }
        if (!l_StepError.isNull())
        {
            // break out on istep failure
            break;
        }

        // Set a flag so that the ATTN code will check ALL processors
        // the next time it gets called versus just the master proc.
        uint8_t    l_useAllProcs = 1;
        // Get a handle to the System target
        TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();
        l_systemTarget->setAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_useAllProcs);

    } while (0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_proc_build_smp exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
